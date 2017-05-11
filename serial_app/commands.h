#pragma once
#include "SDL.h"
//https://github.com/wjwwood/serial biblioteca crossplatform para Comunicação Serial

namespace serial_app {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for commands
	/// </summary>
	public ref class commands : public System::Windows::Forms::Form
	{
	public:
		
		commands(System::String^ Port, System::Int32 Baud)
		{
			InitializeComponent();
			serial = gcnew SerialPort(Port, Baud);
			serial->ReadTimeout = 50;
			try
			{
				serial->Open();
			}
			catch (Exception^ e)
			{
				throw e;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~commands()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool serialbusy = false;
	private: bool Directionalcontroll = false;
	private: System::IO::Ports::SerialPort^  serial;
	private: System::Windows::Forms::CheckBox^  DirEn;
	private: String^ tmpstr;
	private: System::Windows::Forms::Timer^  CmdTimer;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  CmdRIGHT;
	private: System::Windows::Forms::TextBox^  CmdDOWN;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  CmdLEFT;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  CmdUP;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::RichTextBox^  Historico;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  TimerMilis;
	private: System::Windows::Forms::TextBox^  TimerCmd;
	private: System::Windows::Forms::CheckBox^  TimerEnable;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Console;
	private: System::Windows::Forms::Timer^  SerialTimer;
	private: System::Windows::Forms::Label^  Bufferlbl;




	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->DirEn = (gcnew System::Windows::Forms::CheckBox());
			this->CmdTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->CmdRIGHT = (gcnew System::Windows::Forms::TextBox());
			this->CmdDOWN = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CmdLEFT = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CmdUP = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Historico = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->TimerMilis = (gcnew System::Windows::Forms::NumericUpDown());
			this->TimerCmd = (gcnew System::Windows::Forms::TextBox());
			this->TimerEnable = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Console = (gcnew System::Windows::Forms::TextBox());
			this->SerialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Bufferlbl = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->BeginInit();
			this->SuspendLayout();
			// 
			// serial
			// 
			this->serial->RtsEnable = true;
			this->serial->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &commands::serial_DataReceived);
			// 
			// DirEn
			// 
			this->DirEn->AutoSize = true;
			this->DirEn->Location = System::Drawing::Point(13, 13);
			this->DirEn->Name = L"DirEn";
			this->DirEn->Size = System::Drawing::Size(158, 17);
			this->DirEn->TabIndex = 4;
			this->DirEn->Text = L"Controle Por Caixa de Texto";
			this->DirEn->UseVisualStyleBackColor = true;
			this->DirEn->CheckedChanged += gcnew System::EventHandler(this, &commands::DirEn_CheckedChanged);
			// 
			// CmdTimer
			// 
			this->CmdTimer->Tick += gcnew System::EventHandler(this, &commands::timer1_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->CmdRIGHT);
			this->groupBox1->Controls->Add(this->CmdDOWN);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->CmdLEFT);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->CmdUP);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(13, 136);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 124);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Comandos:";
			// 
			// CmdRIGHT
			// 
			this->CmdRIGHT->Location = System::Drawing::Point(48, 95);
			this->CmdRIGHT->Name = L"CmdRIGHT";
			this->CmdRIGHT->Size = System::Drawing::Size(100, 20);
			this->CmdRIGHT->TabIndex = 3;
			// 
			// CmdDOWN
			// 
			this->CmdDOWN->Location = System::Drawing::Point(48, 43);
			this->CmdDOWN->Name = L"CmdDOWN";
			this->CmdDOWN->Size = System::Drawing::Size(100, 20);
			this->CmdDOWN->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 98);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"RIGHT";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"DOWN";
			// 
			// CmdLEFT
			// 
			this->CmdLEFT->Location = System::Drawing::Point(48, 69);
			this->CmdLEFT->Name = L"CmdLEFT";
			this->CmdLEFT->Size = System::Drawing::Size(100, 20);
			this->CmdLEFT->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"LEFT";
			// 
			// CmdUP
			// 
			this->CmdUP->Location = System::Drawing::Point(48, 17);
			this->CmdUP->Name = L"CmdUP";
			this->CmdUP->Size = System::Drawing::Size(100, 20);
			this->CmdUP->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"UP";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 42);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(147, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Manter a caixa de texto ativa:";
			// 
			// Historico
			// 
			this->Historico->Location = System::Drawing::Point(240, 11);
			this->Historico->Name = L"Historico";
			this->Historico->Size = System::Drawing::Size(276, 231);
			this->Historico->TabIndex = 7;
			this->Historico->Text = L"";
			this->Historico->TextChanged += gcnew System::EventHandler(this, &commands::Historico_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->TimerMilis);
			this->groupBox2->Controls->Add(this->TimerCmd);
			this->groupBox2->Controls->Add(this->TimerEnable);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(12, 65);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 65);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Timer";
			// 
			// TimerMilis
			// 
			this->TimerMilis->Location = System::Drawing::Point(7, 39);
			this->TimerMilis->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->TimerMilis->Name = L"TimerMilis";
			this->TimerMilis->Size = System::Drawing::Size(65, 20);
			this->TimerMilis->TabIndex = 6;
			this->TimerMilis->ValueChanged += gcnew System::EventHandler(this, &commands::TimerMilis_ValueChanged);
			// 
			// TimerCmd
			// 
			this->TimerCmd->Location = System::Drawing::Point(78, 38);
			this->TimerCmd->Name = L"TimerCmd";
			this->TimerCmd->Size = System::Drawing::Size(95, 20);
			this->TimerCmd->TabIndex = 5;
			// 
			// TimerEnable
			// 
			this->TimerEnable->AutoSize = true;
			this->TimerEnable->Location = System::Drawing::Point(179, 41);
			this->TimerEnable->Name = L"TimerEnable";
			this->TimerEnable->Size = System::Drawing::Size(15, 14);
			this->TimerEnable->TabIndex = 4;
			this->TimerEnable->UseVisualStyleBackColor = true;
			this->TimerEnable->CheckedChanged += gcnew System::EventHandler(this, &commands::checkBox1_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(92, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Command:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Milis:";
			// 
			// Console
			// 
			this->Console->Location = System::Drawing::Point(168, 39);
			this->Console->Name = L"Console";
			this->Console->Size = System::Drawing::Size(65, 20);
			this->Console->TabIndex = 5;
			this->Console->TextChanged += gcnew System::EventHandler(this, &commands::Console_TextChanged);
			this->Console->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &commands::Console_KeyDown);
			// 
			// SerialTimer
			// 
			this->SerialTimer->Interval = 1;
			this->SerialTimer->Tick += gcnew System::EventHandler(this, &commands::SerialTimer_Tick);
			// 
			// Bufferlbl
			// 
			this->Bufferlbl->AutoSize = true;
			this->Bufferlbl->Location = System::Drawing::Point(459, 250);
			this->Bufferlbl->Name = L"Bufferlbl";
			this->Bufferlbl->Size = System::Drawing::Size(35, 13);
			this->Bufferlbl->TabIndex = 1;
			this->Bufferlbl->Text = L"Buffer";
			// 
			// commands
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 272);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->Historico);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Bufferlbl);
			this->Controls->Add(this->Console);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->DirEn);
			this->Name = L"commands";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"commands";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &commands::commands_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &commands::commands_FormClosed);
			this->Load += gcnew System::EventHandler(this, &commands::commands_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			CmdTimer->Interval = Convert::ToInt32(TimerMilis->Text);
			CmdTimer->Enabled = TimerEnable->Checked;
		}
		catch (Exception^ e)
		{
			if(TimerEnable->Checked == true)
				if(e->HResult == -2146233086) MessageBox::Show("Valor em milis invalido!");
				else MessageBox::Show(Convert::ToString(e->HResult));
			TimerEnable->Checked = false;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public: System::Void commands_Load(System::Object^  sender, System::EventArgs^  e) {
		SDL_Init(SDL_INIT_EVERYTHING);
		SerialTimer->Enabled = true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void Console_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (DirEn->Checked && !serialbusy) {
			String^ Write="";
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void commands_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		SerialTimer->Enabled = false;
		serial->Close();
		CmdTimer->Enabled = false;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void commands_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	}
private: System::Void Historico_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	Historico->SelectionStart = Historico->Text->Length;
	Historico->ScrollToCaret();
}
private: System::Void Console_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	Console->Clear();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if(TimerCmd->Text != "")
		serial->Write(TimerCmd->Text);
		Historico->Text += "W - " + TimerCmd->Text + "\n";
}
private: System::Void DirEn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void TimerMilis_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	CmdTimer->Interval = Convert::ToInt32(TimerMilis->Text);
}
private: System::Void serial_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
	MessageBox::Show("teste");
}
private: System::Void SerialTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
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
			try
			{
				serial->Open();
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message);
			}
		}
	}
}
};
}