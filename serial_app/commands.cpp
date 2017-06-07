#include "commands.h"


//serial sempre envia chars (8 bits)


using namespace serial_app;

bool commands::SendSerial(String^ str)
{
	//if (!serialbusy) {
		serialbusy = true;
		serial->Write(str);
		serialbusy = false;
		return true;
	//}
	return false;
}

System::Void serial_app::commands::CorrectionChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	correctionmotor[0][0] = (int) R0M0Corr->Value;
	correctionmotor[0][1] = (int) R0M1Corr->Value;
	correctionmotor[1][0] = (int) R1M0Corr->Value;
	correctionmotor[1][1] = (int) R1M1Corr->Value;
}


commands::commands(System::String^ Port, System::Int32 Baud)
{
	InitializeComponent();
	serial = gcnew SerialPort(Port, Baud);
	serial->ReadTimeout = 50;
	LastAxVal = new int*[2];
	LastAxVal[0] = new int[6];
	LastAxVal[1] = new int[6];
	try
	{
		serial->Open();
	}
	catch (Exception^ e)
	{
		throw e;
	}
	
	this->Text = Port->ToUpper() + " - Serial commands - CWBOTS";
}

commands::~commands()
{
	if (components)
	{
		delete components;
	}
}

Void commands::commands_Load(System::Object^  sender, System::EventArgs^  e) {
	
	//alocando matriz
	correctionmotor = new int*[2];
	correctionmotor[0] = new int[2];
	correctionmotor[1] = new int[2];
	//matriz alocada
	correctionmotor[0][0] = correctionmotor[0][1] = correctionmotor[1][0] = correctionmotor[1][1] = 0;
	SDLWin = new SDLWindow;
	if (!SDLWin->Start()) MessageBox::Show("SDLStart ERROR!");
	SerialTimer->Enabled = true;
	listJoys();
}

void commands::listJoys() {
	if (!SDLWin->IsJoyConnected(0)) J0Lst->Items->Clear();
	if (!SDLWin->IsJoyConnected(1)) J1Lst->Items->Clear();
	for (int i = 1; i <= SDLWin->JoystickCount(); i++) {
		if (!SDLWin->IsJoyConnected(0)) J0Lst->Items->Add(i);
		if (!SDLWin->IsJoyConnected(1)) J1Lst->Items->Add(i);
	}
}

Void commands::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		CmdTimer->Interval = Convert::ToInt32(TimerMilis->Text);
		CmdTimer->Enabled = TimerEnable->Checked;
	}
	catch (Exception^ e)
	{
		if (TimerEnable->Checked == true)
			if (e->HResult == -2146233086) MessageBox::Show("Valor em milis invalido!");
			else MessageBox::Show(Convert::ToString(e->HResult));
			TimerEnable->Checked = false;
	}
}

Void commands::Console_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (DirEn->Checked && !serialbusy) {
		String^ Write = "";
		switch (e->KeyData)
		{
		case Keys::Up:
			Write += (CmdUP->Text);
			break;
		case Keys::Down:
			Write += (CmdDOWN->Text);
			break;
		case Keys::Left:
			Write += (CmdLEFT->Text);
			break;
		case Keys::Right:
			Write += (CmdRIGHT->Text);
			break;
		default:
			Write = "";
			break;
		}
		if (Write != "")
		{
			if (Write[0] == 's') {
				serialbusy = true;
				serial->Write(Write);
				serialbusy = false;
				Historico->Text += "W - " + Write + "\n";
			}
		}
		else
		{
			Historico->Text += "No Data To Transmit!\n";
			return;
		}
	}
}

Void commands::commands_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	SerialTimer->Enabled = false;
	serial->Close();
	CmdTimer->Enabled = false;
}

Void commands::Historico_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	Historico->SelectionStart = Historico->Text->Length;
	Historico->ScrollToCaret();
}

Void commands::Console_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	Console->Clear();
}

Void commands::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (TimerCmd->Text != "")
		serial->Write(TimerCmd->Text);
	Historico->Text += "W - " + TimerCmd->Text + "\n";
}

Void commands::TimerMilis_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	CmdTimer->Interval = Convert::ToInt32(TimerMilis->Text);
}

Void commands::SerialTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	SerialTimer->Stop();
	JoystickWatch();
	if(!SDLWin->Busy()) SDLWin->MainLoop();
	if (serial->IsOpen) {
		if (serial->BytesToRead > 0)
		{
			Historico->Text += "R - " + serial->ReadExisting() + "\n";
			serialbusy = false;
		}
	}
	else {
		Historico->Text += "Erro: Serial Desconectado.";
		
		while (!serial->IsOpen) {
			if (MessageBox::Show("Conexão com dispositivo perdida. Reconectar?", "Error!", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK) {
				try
				{
					serial->Open();
				}
				catch (Exception^)
				{
				}
			}
		}
	}
	SerialTimer->Start();
}

bool commands::SetMotors(int robot, int v1, int v2) {
	int dir[2] = { 0,0 };
	int speed[2] = { v1, v1 };

	//define speed in sterring
	if (v2 < 0 && speed[0] >= 0 || v2 >= 0 && speed[0] < 0) speed[0] += v2*0.3;
	else speed[1] -=v2*0.3;

	//define positive direction
	if (speed[0] >= 0) dir[0] = 1;
	if (speed[1] >= 0) dir[1] = 1;
	
	//applying correction factors
	if (correctionmotor[robot][0] != 0) speed[0] -= (speed[0]*((float)correctionmotor[robot][0] / 100));
	if (correctionmotor[robot][1] != 0) speed[1] -= (speed[1] * ((float)correctionmotor[robot][1] / 100));

	//modulate the data to be sent
	String^ msg = "M" + robot + "." + abs(speed[0]) + "." + dir[0]+"."+ abs(speed[0]) + "." + dir[0] + ".";
	Bufferlbl->Text = msg;
	if (SendSerial(msg)) return true;
	return false;
}

//Should be Better
int commands::JoyToHB(int joy, int axis) {
	return (int)(SDLWin->JoystickGetAxis(joy, axis) / 128.3);
}

//OK
System::Void serial_app::commands::RefreshJoys_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	listJoys();
}

//OK
void commands::JoystickWatch()
{
	if (!serialbusy) {
		//Bufferlbl->Text = Convert::ToString(JoyToHB(0));
		J0A1Val->Text = Convert::ToString(-JoyToHB(0, 1));
		J0A3Val->Text = Convert::ToString(JoyToHB(0, 3));
		if (-JoyToHB(0, 1) != LastAxVal[0][1] || JoyToHB(0, 3) != LastAxVal[0][3])
			if (SetMotors(0, -JoyToHB(0, 1), JoyToHB(0, 3))) {
				LastAxVal[0][1] = -JoyToHB(0, 1);
				LastAxVal[0][3] = JoyToHB(0, 3);
			}


		J1A1Val->Text = Convert::ToString(-JoyToHB(1, 1));
		J1A3Val->Text = Convert::ToString(JoyToHB(1, 3));
		if (-JoyToHB(1, 1) != LastAxVal[1][1] || JoyToHB(1, 3) != LastAxVal[1][3])
			if (SetMotors(1, -JoyToHB(1, 1), JoyToHB(1, 3))) {
				LastAxVal[1][1] = -JoyToHB(1, 1);
				LastAxVal[1][3] = JoyToHB(1, 3);
			}
	}
}

//OK
System::Void serial_app::commands::J0Conn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (SDLWin->JoystickConnect(0, Convert::ToInt16(J0Lst->Text) - 1)) MessageBox::Show("Joystick" + (Convert::ToInt16(J0Lst->Text) - 1) + "Conectado!");
	else MessageBox::Show("Erro!");
	SDLWin->Start();
}

//OK
System::Void serial_app::commands::J1Conn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (SDLWin->JoystickConnect(1, Convert::ToInt16(J1Lst->Text) - 1)) MessageBox::Show("Joystick" + (Convert::ToInt16(J1Lst->Text) - 1) + "Conectado!");
	else MessageBox::Show("Erro!");
	SDLWin->Start();
}

//OK
System::Void serial_app::commands::J0Disconn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SDLWin->JoystickDisconnect(0);
}

//OK
System::Void serial_app::commands::J1Disconn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SDLWin->JoystickDisconnect(1);
}
