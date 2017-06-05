#pragma once
#include "SDLWindow.h"
//https://github.com/wjwwood/serial biblioteca crossplatform para Comunicação Serial

namespace serial_app {
	using namespace Windows;
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
		
		commands(System::String^ Port, System::Int32 Baud);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~commands();

		///<summary>
		///user created variables.
		///</summary>
	private: int **correctionmotor;
	private: bool serialbusy = false;
	private: bool Directionalcontroll = false;
	private: String^ tmpstr;
			 ///<summary>
			 ///app created objects.
			 ///</summary>
	private: int **LastAxVal;
	private: SDLWindow *SDLWin;
	private: System::IO::Ports::SerialPort^  serial;
	private: System::Windows::Forms::CheckBox^  DirEn;
	private: System::Windows::Forms::Timer^  CmdTimer;
	private: System::Windows::Forms::GroupBox^  CommandsBox;
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
	private: System::Windows::Forms::GroupBox^  SerialTimerBox;
	private: System::Windows::Forms::NumericUpDown^  TimerMilis;
	private: System::Windows::Forms::TextBox^  TimerCmd;
	private: System::Windows::Forms::CheckBox^  TimerEnable;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Console;
	private: System::Windows::Forms::Timer^  SerialTimer;
	private: System::Windows::Forms::Label^  Bufferlbl;
	private: System::Windows::Forms::ComboBox^  Joy1Lst;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  ConnJoy1;
	private: System::Windows::Forms::Button^  RefreshJoys1;


	private: System::Windows::Forms::GroupBox^  Joystick1Box;
	private: System::Windows::Forms::Label^  J1Ax5Val;


	private: System::Windows::Forms::Label^  J1Ax5lbl;
	private: System::Windows::Forms::Label^  J1Ax3Val;


	private: System::Windows::Forms::Label^  J1Ax3lbl;
	private: System::Windows::Forms::Label^  J1Ax1Val;


	private: System::Windows::Forms::Label^  J1Ax1lbl;
	private: System::Windows::Forms::Label^  J1Ax4Val;


	private: System::Windows::Forms::Label^  J1Ax4lbl;
	private: System::Windows::Forms::Label^  J1Ax2Val;


	private: System::Windows::Forms::Label^  J1Ax2lbl;
	private: System::Windows::Forms::Label^  J1Ax0Val;


	private: System::Windows::Forms::Label^  J1Ax0Lbl;

	private: System::Windows::Forms::Button^  DisconnJoy1;
	private: System::Windows::Forms::NumericUpDown^  Mt0R1corr;
	private: System::Windows::Forms::NumericUpDown^  Mt1R1corr;












	private: System::Windows::Forms::GroupBox^  Joystick2Box;
	private: System::Windows::Forms::NumericUpDown^  Mt1R2corr;


	private: System::Windows::Forms::Button^  DisconnJoy2;
	private: System::Windows::Forms::NumericUpDown^  Mt0R2corr;
	private: System::Windows::Forms::Label^  J2Ax5Val;



	private: System::Windows::Forms::Label^  J2Ax5Lbl;
private: System::Windows::Forms::Label^  J2Ax3Val;


	private: System::Windows::Forms::Label^  J2Ax3Lbl;
private: System::Windows::Forms::Label^  J2Ax1Val;


private: System::Windows::Forms::Label^  J2Ax1Lbl;
private: System::Windows::Forms::Label^  J2Ax4Val;


private: System::Windows::Forms::Label^  J2Ax4Lbl;
private: System::Windows::Forms::Label^  J2Ax2Val;


private: System::Windows::Forms::Label^  J2Ax2Lbl;
private: System::Windows::Forms::Label^  J2Ax0Val;


private: System::Windows::Forms::Label^  J2Ax0Lbl;


	private: System::Windows::Forms::Label^  label21;

	private: System::Windows::Forms::ComboBox^  Joy2Lst;
	private: System::Windows::Forms::Button^  ConnJoy2;
private: System::Windows::Forms::Button^  RefreshJoys2;














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
			this->CommandsBox = (gcnew System::Windows::Forms::GroupBox());
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
			this->SerialTimerBox = (gcnew System::Windows::Forms::GroupBox());
			this->TimerMilis = (gcnew System::Windows::Forms::NumericUpDown());
			this->TimerCmd = (gcnew System::Windows::Forms::TextBox());
			this->TimerEnable = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Console = (gcnew System::Windows::Forms::TextBox());
			this->SerialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Bufferlbl = (gcnew System::Windows::Forms::Label());
			this->Joy1Lst = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ConnJoy1 = (gcnew System::Windows::Forms::Button());
			this->RefreshJoys1 = (gcnew System::Windows::Forms::Button());
			this->Joystick1Box = (gcnew System::Windows::Forms::GroupBox());
			this->Mt1R1corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->DisconnJoy1 = (gcnew System::Windows::Forms::Button());
			this->Mt0R1corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->J1Ax5Val = (gcnew System::Windows::Forms::Label());
			this->J1Ax5lbl = (gcnew System::Windows::Forms::Label());
			this->J1Ax3Val = (gcnew System::Windows::Forms::Label());
			this->J1Ax3lbl = (gcnew System::Windows::Forms::Label());
			this->J1Ax1Val = (gcnew System::Windows::Forms::Label());
			this->J1Ax1lbl = (gcnew System::Windows::Forms::Label());
			this->J1Ax4Val = (gcnew System::Windows::Forms::Label());
			this->J1Ax4lbl = (gcnew System::Windows::Forms::Label());
			this->J1Ax2Val = (gcnew System::Windows::Forms::Label());
			this->J1Ax2lbl = (gcnew System::Windows::Forms::Label());
			this->J1Ax0Val = (gcnew System::Windows::Forms::Label());
			this->J1Ax0Lbl = (gcnew System::Windows::Forms::Label());
			this->Joystick2Box = (gcnew System::Windows::Forms::GroupBox());
			this->Mt1R2corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->DisconnJoy2 = (gcnew System::Windows::Forms::Button());
			this->Mt0R2corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->J2Ax5Val = (gcnew System::Windows::Forms::Label());
			this->J2Ax5Lbl = (gcnew System::Windows::Forms::Label());
			this->J2Ax3Val = (gcnew System::Windows::Forms::Label());
			this->J2Ax3Lbl = (gcnew System::Windows::Forms::Label());
			this->J2Ax1Val = (gcnew System::Windows::Forms::Label());
			this->J2Ax1Lbl = (gcnew System::Windows::Forms::Label());
			this->J2Ax4Val = (gcnew System::Windows::Forms::Label());
			this->J2Ax4Lbl = (gcnew System::Windows::Forms::Label());
			this->J2Ax2Val = (gcnew System::Windows::Forms::Label());
			this->J2Ax2Lbl = (gcnew System::Windows::Forms::Label());
			this->J2Ax0Val = (gcnew System::Windows::Forms::Label());
			this->J2Ax0Lbl = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->RefreshJoys2 = (gcnew System::Windows::Forms::Button());
			this->Joy2Lst = (gcnew System::Windows::Forms::ComboBox());
			this->ConnJoy2 = (gcnew System::Windows::Forms::Button());
			this->CommandsBox->SuspendLayout();
			this->SerialTimerBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->BeginInit();
			this->Joystick1Box->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt1R1corr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt0R1corr))->BeginInit();
			this->Joystick2Box->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt1R2corr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt0R2corr))->BeginInit();
			this->SuspendLayout();
			// 
			// serial
			// 
			this->serial->RtsEnable = true;
			// 
			// DirEn
			// 
			this->DirEn->AutoSize = true;
			this->DirEn->Location = System::Drawing::Point(12, 14);
			this->DirEn->Name = L"DirEn";
			this->DirEn->Size = System::Drawing::Size(103, 17);
			this->DirEn->TabIndex = 4;
			this->DirEn->Text = L"TextBox Controll";
			this->DirEn->UseVisualStyleBackColor = true;
			// 
			// CmdTimer
			// 
			this->CmdTimer->Tick += gcnew System::EventHandler(this, &commands::timer1_Tick);
			// 
			// CommandsBox
			// 
			this->CommandsBox->Controls->Add(this->CmdRIGHT);
			this->CommandsBox->Controls->Add(this->CmdDOWN);
			this->CommandsBox->Controls->Add(this->label6);
			this->CommandsBox->Controls->Add(this->label4);
			this->CommandsBox->Controls->Add(this->CmdLEFT);
			this->CommandsBox->Controls->Add(this->label5);
			this->CommandsBox->Controls->Add(this->CmdUP);
			this->CommandsBox->Controls->Add(this->label3);
			this->CommandsBox->Location = System::Drawing::Point(12, 137);
			this->CommandsBox->Name = L"CommandsBox";
			this->CommandsBox->Size = System::Drawing::Size(200, 124);
			this->CommandsBox->TabIndex = 3;
			this->CommandsBox->TabStop = false;
			this->CommandsBox->Text = L"Commands:";
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
			this->label7->Location = System::Drawing::Point(9, 43);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Keep TextBox active to send :";
			// 
			// Historico
			// 
			this->Historico->Location = System::Drawing::Point(239, 12);
			this->Historico->Name = L"Historico";
			this->Historico->Size = System::Drawing::Size(276, 231);
			this->Historico->TabIndex = 7;
			this->Historico->Text = L"";
			this->Historico->TextChanged += gcnew System::EventHandler(this, &commands::Historico_TextChanged);
			// 
			// SerialTimerBox
			// 
			this->SerialTimerBox->Controls->Add(this->TimerMilis);
			this->SerialTimerBox->Controls->Add(this->TimerCmd);
			this->SerialTimerBox->Controls->Add(this->TimerEnable);
			this->SerialTimerBox->Controls->Add(this->label2);
			this->SerialTimerBox->Controls->Add(this->label1);
			this->SerialTimerBox->Location = System::Drawing::Point(11, 66);
			this->SerialTimerBox->Name = L"SerialTimerBox";
			this->SerialTimerBox->Size = System::Drawing::Size(200, 65);
			this->SerialTimerBox->TabIndex = 8;
			this->SerialTimerBox->TabStop = false;
			this->SerialTimerBox->Text = L"Timer";
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
			this->Console->Location = System::Drawing::Point(167, 40);
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
			this->Bufferlbl->Location = System::Drawing::Point(480, 255);
			this->Bufferlbl->Name = L"Bufferlbl";
			this->Bufferlbl->Size = System::Drawing::Size(35, 13);
			this->Bufferlbl->TabIndex = 1;
			this->Bufferlbl->Text = L"Buffer";
			// 
			// Joy1Lst
			// 
			this->Joy1Lst->FormattingEnabled = true;
			this->Joy1Lst->Location = System::Drawing::Point(63, 23);
			this->Joy1Lst->Name = L"Joy1Lst";
			this->Joy1Lst->Size = System::Drawing::Size(28, 21);
			this->Joy1Lst->TabIndex = 9;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Joystick 1:";
			// 
			// ConnJoy1
			// 
			this->ConnJoy1->Location = System::Drawing::Point(94, 23);
			this->ConnJoy1->Name = L"ConnJoy1";
			this->ConnJoy1->Size = System::Drawing::Size(55, 23);
			this->ConnJoy1->TabIndex = 11;
			this->ConnJoy1->Text = L"Connect";
			this->ConnJoy1->UseVisualStyleBackColor = true;
			this->ConnJoy1->Click += gcnew System::EventHandler(this, &commands::ConnJoys_Click);
			// 
			// RefreshJoys1
			// 
			this->RefreshJoys1->Location = System::Drawing::Point(155, 24);
			this->RefreshJoys1->Name = L"RefreshJoys1";
			this->RefreshJoys1->Size = System::Drawing::Size(49, 23);
			this->RefreshJoys1->TabIndex = 11;
			this->RefreshJoys1->Text = L"Reload";
			this->RefreshJoys1->UseVisualStyleBackColor = true;
			this->RefreshJoys1->Click += gcnew System::EventHandler(this, &commands::RefreshJoys_Click);
			// 
			// Joystick1Box
			// 
			this->Joystick1Box->Controls->Add(this->Mt1R1corr);
			this->Joystick1Box->Controls->Add(this->DisconnJoy1);
			this->Joystick1Box->Controls->Add(this->Mt0R1corr);
			this->Joystick1Box->Controls->Add(this->J1Ax5Val);
			this->Joystick1Box->Controls->Add(this->J1Ax5lbl);
			this->Joystick1Box->Controls->Add(this->J1Ax3Val);
			this->Joystick1Box->Controls->Add(this->J1Ax3lbl);
			this->Joystick1Box->Controls->Add(this->J1Ax1Val);
			this->Joystick1Box->Controls->Add(this->J1Ax1lbl);
			this->Joystick1Box->Controls->Add(this->J1Ax4Val);
			this->Joystick1Box->Controls->Add(this->J1Ax4lbl);
			this->Joystick1Box->Controls->Add(this->J1Ax2Val);
			this->Joystick1Box->Controls->Add(this->J1Ax2lbl);
			this->Joystick1Box->Controls->Add(this->J1Ax0Val);
			this->Joystick1Box->Controls->Add(this->J1Ax0Lbl);
			this->Joystick1Box->Controls->Add(this->label8);
			this->Joystick1Box->Controls->Add(this->RefreshJoys1);
			this->Joystick1Box->Controls->Add(this->Joy1Lst);
			this->Joystick1Box->Controls->Add(this->ConnJoy1);
			this->Joystick1Box->Location = System::Drawing::Point(522, 14);
			this->Joystick1Box->Name = L"Joystick1Box";
			this->Joystick1Box->Size = System::Drawing::Size(215, 229);
			this->Joystick1Box->TabIndex = 12;
			this->Joystick1Box->TabStop = false;
			this->Joystick1Box->Text = L"Joystick 1 - Robot 1";
			// 
			// Mt1R1corr
			// 
			this->Mt1R1corr->Location = System::Drawing::Point(60, 52);
			this->Mt1R1corr->Name = L"Mt1R1corr";
			this->Mt1R1corr->Size = System::Drawing::Size(38, 20);
			this->Mt1R1corr->TabIndex = 1;
			this->Mt1R1corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// DisconnJoy1
			// 
			this->DisconnJoy1->Location = System::Drawing::Point(119, 52);
			this->DisconnJoy1->Name = L"DisconnJoy1";
			this->DisconnJoy1->Size = System::Drawing::Size(75, 23);
			this->DisconnJoy1->TabIndex = 13;
			this->DisconnJoy1->Text = L"Disconnect";
			this->DisconnJoy1->UseVisualStyleBackColor = true;
			this->DisconnJoy1->Click += gcnew System::EventHandler(this, &commands::DisconnJoy_Click);
			// 
			// Mt0R1corr
			// 
			this->Mt0R1corr->Location = System::Drawing::Point(6, 52);
			this->Mt0R1corr->Name = L"Mt0R1corr";
			this->Mt0R1corr->Size = System::Drawing::Size(38, 20);
			this->Mt0R1corr->TabIndex = 1;
			this->Mt0R1corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// J1Ax5Val
			// 
			this->J1Ax5Val->AutoSize = true;
			this->J1Ax5Val->Location = System::Drawing::Point(60, 205);
			this->J1Ax5Val->Name = L"J1Ax5Val";
			this->J1Ax5Val->Size = System::Drawing::Size(0, 13);
			this->J1Ax5Val->TabIndex = 12;
			// 
			// J1Ax5lbl
			// 
			this->J1Ax5lbl->AutoSize = true;
			this->J1Ax5lbl->Location = System::Drawing::Point(20, 205);
			this->J1Ax5lbl->Name = L"J1Ax5lbl";
			this->J1Ax5lbl->Size = System::Drawing::Size(34, 13);
			this->J1Ax5lbl->TabIndex = 12;
			this->J1Ax5lbl->Text = L"axis5:";
			// 
			// J1Ax3Val
			// 
			this->J1Ax3Val->AutoSize = true;
			this->J1Ax3Val->Location = System::Drawing::Point(60, 160);
			this->J1Ax3Val->Name = L"J1Ax3Val";
			this->J1Ax3Val->Size = System::Drawing::Size(0, 13);
			this->J1Ax3Val->TabIndex = 12;
			// 
			// J1Ax3lbl
			// 
			this->J1Ax3lbl->AutoSize = true;
			this->J1Ax3lbl->Location = System::Drawing::Point(20, 160);
			this->J1Ax3lbl->Name = L"J1Ax3lbl";
			this->J1Ax3lbl->Size = System::Drawing::Size(34, 13);
			this->J1Ax3lbl->TabIndex = 12;
			this->J1Ax3lbl->Text = L"axis3:";
			// 
			// J1Ax1Val
			// 
			this->J1Ax1Val->AutoSize = true;
			this->J1Ax1Val->Location = System::Drawing::Point(60, 114);
			this->J1Ax1Val->Name = L"J1Ax1Val";
			this->J1Ax1Val->Size = System::Drawing::Size(0, 13);
			this->J1Ax1Val->TabIndex = 12;
			// 
			// J1Ax1lbl
			// 
			this->J1Ax1lbl->AutoSize = true;
			this->J1Ax1lbl->Location = System::Drawing::Point(20, 114);
			this->J1Ax1lbl->Name = L"J1Ax1lbl";
			this->J1Ax1lbl->Size = System::Drawing::Size(34, 13);
			this->J1Ax1lbl->TabIndex = 12;
			this->J1Ax1lbl->Text = L"axis1:";
			// 
			// J1Ax4Val
			// 
			this->J1Ax4Val->AutoSize = true;
			this->J1Ax4Val->Location = System::Drawing::Point(60, 182);
			this->J1Ax4Val->Name = L"J1Ax4Val";
			this->J1Ax4Val->Size = System::Drawing::Size(0, 13);
			this->J1Ax4Val->TabIndex = 12;
			// 
			// J1Ax4lbl
			// 
			this->J1Ax4lbl->AutoSize = true;
			this->J1Ax4lbl->Location = System::Drawing::Point(20, 182);
			this->J1Ax4lbl->Name = L"J1Ax4lbl";
			this->J1Ax4lbl->Size = System::Drawing::Size(34, 13);
			this->J1Ax4lbl->TabIndex = 12;
			this->J1Ax4lbl->Text = L"axis4:";
			// 
			// J1Ax2Val
			// 
			this->J1Ax2Val->AutoSize = true;
			this->J1Ax2Val->Location = System::Drawing::Point(60, 137);
			this->J1Ax2Val->Name = L"J1Ax2Val";
			this->J1Ax2Val->Size = System::Drawing::Size(0, 13);
			this->J1Ax2Val->TabIndex = 12;
			// 
			// J1Ax2lbl
			// 
			this->J1Ax2lbl->AutoSize = true;
			this->J1Ax2lbl->Location = System::Drawing::Point(20, 137);
			this->J1Ax2lbl->Name = L"J1Ax2lbl";
			this->J1Ax2lbl->Size = System::Drawing::Size(34, 13);
			this->J1Ax2lbl->TabIndex = 12;
			this->J1Ax2lbl->Text = L"axis2:";
			// 
			// J1Ax0Val
			// 
			this->J1Ax0Val->AutoSize = true;
			this->J1Ax0Val->Location = System::Drawing::Point(60, 91);
			this->J1Ax0Val->Name = L"J1Ax0Val";
			this->J1Ax0Val->Size = System::Drawing::Size(0, 13);
			this->J1Ax0Val->TabIndex = 12;
			// 
			// J1Ax0Lbl
			// 
			this->J1Ax0Lbl->AutoSize = true;
			this->J1Ax0Lbl->Location = System::Drawing::Point(20, 91);
			this->J1Ax0Lbl->Name = L"J1Ax0Lbl";
			this->J1Ax0Lbl->Size = System::Drawing::Size(34, 13);
			this->J1Ax0Lbl->TabIndex = 12;
			this->J1Ax0Lbl->Text = L"axis0:";
			// 
			// Joystick2Box
			// 
			this->Joystick2Box->Controls->Add(this->Mt1R2corr);
			this->Joystick2Box->Controls->Add(this->DisconnJoy2);
			this->Joystick2Box->Controls->Add(this->Mt0R2corr);
			this->Joystick2Box->Controls->Add(this->J2Ax5Val);
			this->Joystick2Box->Controls->Add(this->J2Ax5Lbl);
			this->Joystick2Box->Controls->Add(this->J2Ax3Val);
			this->Joystick2Box->Controls->Add(this->J2Ax3Lbl);
			this->Joystick2Box->Controls->Add(this->J2Ax1Val);
			this->Joystick2Box->Controls->Add(this->J2Ax1Lbl);
			this->Joystick2Box->Controls->Add(this->J2Ax4Val);
			this->Joystick2Box->Controls->Add(this->J2Ax4Lbl);
			this->Joystick2Box->Controls->Add(this->J2Ax2Val);
			this->Joystick2Box->Controls->Add(this->J2Ax2Lbl);
			this->Joystick2Box->Controls->Add(this->J2Ax0Val);
			this->Joystick2Box->Controls->Add(this->J2Ax0Lbl);
			this->Joystick2Box->Controls->Add(this->label21);
			this->Joystick2Box->Controls->Add(this->RefreshJoys2);
			this->Joystick2Box->Controls->Add(this->Joy2Lst);
			this->Joystick2Box->Controls->Add(this->ConnJoy2);
			this->Joystick2Box->Location = System::Drawing::Point(743, 14);
			this->Joystick2Box->Name = L"Joystick2Box";
			this->Joystick2Box->Size = System::Drawing::Size(215, 229);
			this->Joystick2Box->TabIndex = 12;
			this->Joystick2Box->TabStop = false;
			this->Joystick2Box->Text = L"Joystick 2 - Robot 2";
			// 
			// Mt1R2corr
			// 
			this->Mt1R2corr->Location = System::Drawing::Point(60, 52);
			this->Mt1R2corr->Name = L"Mt1R2corr";
			this->Mt1R2corr->Size = System::Drawing::Size(38, 20);
			this->Mt1R2corr->TabIndex = 1;
			this->Mt1R2corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// DisconnJoy2
			// 
			this->DisconnJoy2->Location = System::Drawing::Point(119, 52);
			this->DisconnJoy2->Name = L"DisconnJoy2";
			this->DisconnJoy2->Size = System::Drawing::Size(75, 23);
			this->DisconnJoy2->TabIndex = 13;
			this->DisconnJoy2->Text = L"Disconnect";
			this->DisconnJoy2->UseVisualStyleBackColor = true;
			this->DisconnJoy2->Click += gcnew System::EventHandler(this, &commands::DisconnJoy_Click);
			// 
			// Mt0R2corr
			// 
			this->Mt0R2corr->Location = System::Drawing::Point(6, 52);
			this->Mt0R2corr->Name = L"Mt0R2corr";
			this->Mt0R2corr->Size = System::Drawing::Size(38, 20);
			this->Mt0R2corr->TabIndex = 1;
			this->Mt0R2corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// J2Ax5Val
			// 
			this->J2Ax5Val->AutoSize = true;
			this->J2Ax5Val->Location = System::Drawing::Point(60, 205);
			this->J2Ax5Val->Name = L"J2Ax5Val";
			this->J2Ax5Val->Size = System::Drawing::Size(0, 13);
			this->J2Ax5Val->TabIndex = 12;
			// 
			// J2Ax5Lbl
			// 
			this->J2Ax5Lbl->AutoSize = true;
			this->J2Ax5Lbl->Location = System::Drawing::Point(20, 205);
			this->J2Ax5Lbl->Name = L"J2Ax5Lbl";
			this->J2Ax5Lbl->Size = System::Drawing::Size(34, 13);
			this->J2Ax5Lbl->TabIndex = 12;
			this->J2Ax5Lbl->Text = L"axis5:";
			// 
			// J2Ax3Val
			// 
			this->J2Ax3Val->AutoSize = true;
			this->J2Ax3Val->Location = System::Drawing::Point(60, 160);
			this->J2Ax3Val->Name = L"J2Ax3Val";
			this->J2Ax3Val->Size = System::Drawing::Size(0, 13);
			this->J2Ax3Val->TabIndex = 12;
			// 
			// J2Ax3Lbl
			// 
			this->J2Ax3Lbl->AutoSize = true;
			this->J2Ax3Lbl->Location = System::Drawing::Point(20, 160);
			this->J2Ax3Lbl->Name = L"J2Ax3Lbl";
			this->J2Ax3Lbl->Size = System::Drawing::Size(34, 13);
			this->J2Ax3Lbl->TabIndex = 12;
			this->J2Ax3Lbl->Text = L"axis3:";
			// 
			// J2Ax1Val
			// 
			this->J2Ax1Val->AutoSize = true;
			this->J2Ax1Val->Location = System::Drawing::Point(60, 114);
			this->J2Ax1Val->Name = L"J2Ax1Val";
			this->J2Ax1Val->Size = System::Drawing::Size(0, 13);
			this->J2Ax1Val->TabIndex = 12;
			// 
			// J2Ax1Lbl
			// 
			this->J2Ax1Lbl->AutoSize = true;
			this->J2Ax1Lbl->Location = System::Drawing::Point(20, 114);
			this->J2Ax1Lbl->Name = L"J2Ax1Lbl";
			this->J2Ax1Lbl->Size = System::Drawing::Size(34, 13);
			this->J2Ax1Lbl->TabIndex = 12;
			this->J2Ax1Lbl->Text = L"axis1:";
			// 
			// J2Ax4Val
			// 
			this->J2Ax4Val->AutoSize = true;
			this->J2Ax4Val->Location = System::Drawing::Point(60, 182);
			this->J2Ax4Val->Name = L"J2Ax4Val";
			this->J2Ax4Val->Size = System::Drawing::Size(0, 13);
			this->J2Ax4Val->TabIndex = 12;
			// 
			// J2Ax4Lbl
			// 
			this->J2Ax4Lbl->AutoSize = true;
			this->J2Ax4Lbl->Location = System::Drawing::Point(20, 182);
			this->J2Ax4Lbl->Name = L"J2Ax4Lbl";
			this->J2Ax4Lbl->Size = System::Drawing::Size(34, 13);
			this->J2Ax4Lbl->TabIndex = 12;
			this->J2Ax4Lbl->Text = L"axis4:";
			// 
			// J2Ax2Val
			// 
			this->J2Ax2Val->AutoSize = true;
			this->J2Ax2Val->Location = System::Drawing::Point(60, 137);
			this->J2Ax2Val->Name = L"J2Ax2Val";
			this->J2Ax2Val->Size = System::Drawing::Size(0, 13);
			this->J2Ax2Val->TabIndex = 12;
			// 
			// J2Ax2Lbl
			// 
			this->J2Ax2Lbl->AutoSize = true;
			this->J2Ax2Lbl->Location = System::Drawing::Point(20, 137);
			this->J2Ax2Lbl->Name = L"J2Ax2Lbl";
			this->J2Ax2Lbl->Size = System::Drawing::Size(34, 13);
			this->J2Ax2Lbl->TabIndex = 12;
			this->J2Ax2Lbl->Text = L"axis2:";
			// 
			// J2Ax0Val
			// 
			this->J2Ax0Val->AutoSize = true;
			this->J2Ax0Val->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->J2Ax0Val->Location = System::Drawing::Point(60, 91);
			this->J2Ax0Val->Name = L"J2Ax0Val";
			this->J2Ax0Val->Size = System::Drawing::Size(0, 13);
			this->J2Ax0Val->TabIndex = 12;
			// 
			// J2Ax0Lbl
			// 
			this->J2Ax0Lbl->AutoSize = true;
			this->J2Ax0Lbl->Location = System::Drawing::Point(20, 91);
			this->J2Ax0Lbl->Name = L"J2Ax0Lbl";
			this->J2Ax0Lbl->Size = System::Drawing::Size(34, 13);
			this->J2Ax0Lbl->TabIndex = 12;
			this->J2Ax0Lbl->Text = L"axis0:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(6, 26);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(57, 13);
			this->label21->TabIndex = 10;
			this->label21->Text = L"Joystick 2:";
			// 
			// RefreshJoys2
			// 
			this->RefreshJoys2->Location = System::Drawing::Point(155, 24);
			this->RefreshJoys2->Name = L"RefreshJoys2";
			this->RefreshJoys2->Size = System::Drawing::Size(49, 23);
			this->RefreshJoys2->TabIndex = 11;
			this->RefreshJoys2->Text = L"Reload";
			this->RefreshJoys2->UseVisualStyleBackColor = true;
			this->RefreshJoys2->Click += gcnew System::EventHandler(this, &commands::RefreshJoys_Click);
			// 
			// Joy2Lst
			// 
			this->Joy2Lst->FormattingEnabled = true;
			this->Joy2Lst->Location = System::Drawing::Point(63, 23);
			this->Joy2Lst->Name = L"Joy2Lst";
			this->Joy2Lst->Size = System::Drawing::Size(28, 21);
			this->Joy2Lst->TabIndex = 9;
			// 
			// ConnJoy2
			// 
			this->ConnJoy2->Location = System::Drawing::Point(94, 23);
			this->ConnJoy2->Name = L"ConnJoy2";
			this->ConnJoy2->Size = System::Drawing::Size(55, 23);
			this->ConnJoy2->TabIndex = 11;
			this->ConnJoy2->Text = L"Connect";
			this->ConnJoy2->UseVisualStyleBackColor = true;
			this->ConnJoy2->Click += gcnew System::EventHandler(this, &commands::ConnJoys_Click);
			// 
			// commands
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(965, 275);
			this->Controls->Add(this->Joystick2Box);
			this->Controls->Add(this->Joystick1Box);
			this->Controls->Add(this->SerialTimerBox);
			this->Controls->Add(this->Historico);
			this->Controls->Add(this->CommandsBox);
			this->Controls->Add(this->Bufferlbl);
			this->Controls->Add(this->Console);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->DirEn);
			this->Name = L"commands";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L".";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &commands::commands_FormClosing);
			this->Load += gcnew System::EventHandler(this, &commands::commands_Load);
			this->CommandsBox->ResumeLayout(false);
			this->CommandsBox->PerformLayout();
			this->SerialTimerBox->ResumeLayout(false);
			this->SerialTimerBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->EndInit();
			this->Joystick1Box->ResumeLayout(false);
			this->Joystick1Box->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt1R1corr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt0R1corr))->EndInit();
			this->Joystick2Box->ResumeLayout(false);
			this->Joystick2Box->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt1R2corr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Mt0R2corr))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: void listJoys();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public: System::Void commands_Load(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Console_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void commands_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Historico_TextChanged(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Console_TextChanged(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void TimerMilis_ValueChanged(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void SerialTimer_Tick(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void ConnJoys_Click(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void RefreshJoys_Click(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: int JoyToHB(int, int);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: void JoystickWatch();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: bool SetMotor(int, int, int);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void DisconnJoy_Click(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: bool SendSerial(String^); //master
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void CorrectionChanged(System::Object^  sender, System::EventArgs^  e);
};
}