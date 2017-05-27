#include "commands.h"


//serial sempre envia chars (8 bits)


using namespace serial_app;

System::Void serial_app::commands::DisconnJoy_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SDLWin->JoystickDisconnect();
}

bool serial_app::commands::SendSerial(String^ str)
{
	if (!serialbusy) {
		serialbusy = true;
		serial->Write(str);
		serialbusy = false;
		return true;
	}
	else return false;
}


commands::commands(System::String^ Port, System::Int32 Baud)
{
	InitializeComponent();
	serial = gcnew SerialPort(Port, Baud);
	serial->ReadTimeout = 50;
	LastAxVal = new int[6];
	try
	{
		serial->Open();
	}
	catch (Exception^ e)
	{
		throw e;
	}
}

commands::~commands()
{
	if (components)
	{
		delete components;
	}
}

Void commands::commands_Load(System::Object^  sender, System::EventArgs^  e) {
	SDLWin = new SDLWindow;
	if (!SDLWin->Start()) MessageBox::Show("SDLStart ERROR!");
	SerialTimer->Enabled = true;
	listJoys();
}

void commands::listJoys() {
	JoyLst->Items->Clear();
	for (int i = 1; i <= SDLWin->JoystickCount(); i++) {
		JoyLst->Items->Add(i);
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
			serial->Write(Write);
			serialbusy = true;
			Historico->Text += "W - " + Write + "\n";
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

Void commands::ConnJoys_Click(System::Object^  sender, System::EventArgs^  e) {
	if (SDLWin->JoystickConnect(Convert::ToInt16(JoyLst->Text)-1)) MessageBox::Show("sucesso!");
	else MessageBox::Show("Erro!");
	SDLWin->Start();
	
}

System::Void serial_app::commands::RefreshJoys_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	listJoys();
}

int commands::JoyToHB(int axis) {
	return (int)SDLWin->JoystickGetAxis(axis) / 128.3;
}

void commands::JoystickWatch()
{
	if (!serialbusy) {
		//Bufferlbl->Text = Convert::ToString(JoyToHB(0));
		Ax0Val->Text = Convert::ToString(JoyToHB(0));
		Ax1Val->Text = Convert::ToString(JoyToHB(1));
		Ax2Val->Text = Convert::ToString(JoyToHB(2));
		Ax3Val->Text = Convert::ToString(JoyToHB(3));
		Ax4Val->Text = Convert::ToString(JoyToHB(4));
		Ax5Val->Text = Convert::ToString(JoyToHB(5));

		if (JoyToHB(1) != LastAxVal[1]) {
			if(SetMotor(1, -LastAxVal[1])) LastAxVal[1] = JoyToHB(1);
		}
		if (JoyToHB(4) != LastAxVal[4]) {
			if(SetMotor(2, -LastAxVal[4])) LastAxVal[4] = JoyToHB(4);
		}
	}
}

bool commands::SetMotor(int motor, int speed) {
	int dir = 0;
	if (abs(speed) >= 20) {
		if (speed >= 0) dir = 1;
	}
	else {
		speed = 0;
	}
		String^ msg = "s" + motor + "." + abs(speed) + "." + dir + ".";
		//MessageBox::Show(msg);
		Bufferlbl->Text = msg;
		if (SendSerial(msg)) return true;
		else return false;
}