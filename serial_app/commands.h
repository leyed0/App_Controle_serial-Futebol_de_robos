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
	private: bool serialbusy = false;
	private: bool Directionalcontroll = false;
	private: String^ tmpstr;
			 ///<summary>
			 ///app created objects.
			 ///</summary>
	private: int *LastAxVal;
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
	private: System::Windows::Forms::ComboBox^  JoyLst;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  ConnJoy;
	private: System::Windows::Forms::Button^  RefreshJoys;
	private: System::Windows::Forms::GroupBox^  JoystickBox;
	private: System::Windows::Forms::Label^  Ax5Val;
	private: System::Windows::Forms::Label^  Ax5lbl;
	private: System::Windows::Forms::Label^  Ax3Val;
	private: System::Windows::Forms::Label^  Ax3lbl;
	private: System::Windows::Forms::Label^  Ax1Val;
	private: System::Windows::Forms::Label^  Ax1lbl;
	private: System::Windows::Forms::Label^  Ax4Val;
	private: System::Windows::Forms::Label^  Ax4lbl;
	private: System::Windows::Forms::Label^  Ax2Val;
	private: System::Windows::Forms::Label^  Ax2lbl;
	private: System::Windows::Forms::Label^  Ax0Val;
	private: System::Windows::Forms::Label^  Ax0Lbl;
	private: System::Windows::Forms::Button^  DisconnJoy;

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
			this->JoyLst = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ConnJoy = (gcnew System::Windows::Forms::Button());
			this->RefreshJoys = (gcnew System::Windows::Forms::Button());
			this->JoystickBox = (gcnew System::Windows::Forms::GroupBox());
			this->DisconnJoy = (gcnew System::Windows::Forms::Button());
			this->Ax5Val = (gcnew System::Windows::Forms::Label());
			this->Ax5lbl = (gcnew System::Windows::Forms::Label());
			this->Ax3Val = (gcnew System::Windows::Forms::Label());
			this->Ax3lbl = (gcnew System::Windows::Forms::Label());
			this->Ax1Val = (gcnew System::Windows::Forms::Label());
			this->Ax1lbl = (gcnew System::Windows::Forms::Label());
			this->Ax4Val = (gcnew System::Windows::Forms::Label());
			this->Ax4lbl = (gcnew System::Windows::Forms::Label());
			this->Ax2Val = (gcnew System::Windows::Forms::Label());
			this->Ax2lbl = (gcnew System::Windows::Forms::Label());
			this->Ax0Val = (gcnew System::Windows::Forms::Label());
			this->Ax0Lbl = (gcnew System::Windows::Forms::Label());
			this->CommandsBox->SuspendLayout();
			this->SerialTimerBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->BeginInit();
			this->JoystickBox->SuspendLayout();
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
			// JoyLst
			// 
			this->JoyLst->FormattingEnabled = true;
			this->JoyLst->Location = System::Drawing::Point(60, 23);
			this->JoyLst->Name = L"JoyLst";
			this->JoyLst->Size = System::Drawing::Size(28, 21);
			this->JoyLst->TabIndex = 9;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Joystick:";
			// 
			// ConnJoy
			// 
			this->ConnJoy->Location = System::Drawing::Point(94, 23);
			this->ConnJoy->Name = L"ConnJoy";
			this->ConnJoy->Size = System::Drawing::Size(55, 23);
			this->ConnJoy->TabIndex = 11;
			this->ConnJoy->Text = L"Connect";
			this->ConnJoy->UseVisualStyleBackColor = true;
			this->ConnJoy->Click += gcnew System::EventHandler(this, &commands::ConnJoys_Click);
			// 
			// RefreshJoys
			// 
			this->RefreshJoys->Location = System::Drawing::Point(155, 24);
			this->RefreshJoys->Name = L"RefreshJoys";
			this->RefreshJoys->Size = System::Drawing::Size(49, 23);
			this->RefreshJoys->TabIndex = 11;
			this->RefreshJoys->Text = L"Reload";
			this->RefreshJoys->UseVisualStyleBackColor = true;
			this->RefreshJoys->Click += gcnew System::EventHandler(this, &commands::RefreshJoys_Click);
			// 
			// JoystickBox
			// 
			this->JoystickBox->Controls->Add(this->DisconnJoy);
			this->JoystickBox->Controls->Add(this->Ax5Val);
			this->JoystickBox->Controls->Add(this->Ax5lbl);
			this->JoystickBox->Controls->Add(this->Ax3Val);
			this->JoystickBox->Controls->Add(this->Ax3lbl);
			this->JoystickBox->Controls->Add(this->Ax1Val);
			this->JoystickBox->Controls->Add(this->Ax1lbl);
			this->JoystickBox->Controls->Add(this->Ax4Val);
			this->JoystickBox->Controls->Add(this->Ax4lbl);
			this->JoystickBox->Controls->Add(this->Ax2Val);
			this->JoystickBox->Controls->Add(this->Ax2lbl);
			this->JoystickBox->Controls->Add(this->Ax0Val);
			this->JoystickBox->Controls->Add(this->Ax0Lbl);
			this->JoystickBox->Controls->Add(this->label8);
			this->JoystickBox->Controls->Add(this->RefreshJoys);
			this->JoystickBox->Controls->Add(this->JoyLst);
			this->JoystickBox->Controls->Add(this->ConnJoy);
			this->JoystickBox->Location = System::Drawing::Point(522, 14);
			this->JoystickBox->Name = L"JoystickBox";
			this->JoystickBox->Size = System::Drawing::Size(213, 229);
			this->JoystickBox->TabIndex = 12;
			this->JoystickBox->TabStop = false;
			this->JoystickBox->Text = L"Joystick";
			// 
			// DisconnJoy
			// 
			this->DisconnJoy->Location = System::Drawing::Point(119, 52);
			this->DisconnJoy->Name = L"DisconnJoy";
			this->DisconnJoy->Size = System::Drawing::Size(75, 23);
			this->DisconnJoy->TabIndex = 13;
			this->DisconnJoy->Text = L"Disconnect";
			this->DisconnJoy->UseVisualStyleBackColor = true;
			this->DisconnJoy->Click += gcnew System::EventHandler(this, &commands::DisconnJoy_Click);
			// 
			// Ax5Val
			// 
			this->Ax5Val->AutoSize = true;
			this->Ax5Val->Location = System::Drawing::Point(60, 205);
			this->Ax5Val->Name = L"Ax5Val";
			this->Ax5Val->Size = System::Drawing::Size(0, 13);
			this->Ax5Val->TabIndex = 12;
			// 
			// Ax5lbl
			// 
			this->Ax5lbl->AutoSize = true;
			this->Ax5lbl->Location = System::Drawing::Point(20, 205);
			this->Ax5lbl->Name = L"Ax5lbl";
			this->Ax5lbl->Size = System::Drawing::Size(34, 13);
			this->Ax5lbl->TabIndex = 12;
			this->Ax5lbl->Text = L"axis5:";
			// 
			// Ax3Val
			// 
			this->Ax3Val->AutoSize = true;
			this->Ax3Val->Location = System::Drawing::Point(60, 160);
			this->Ax3Val->Name = L"Ax3Val";
			this->Ax3Val->Size = System::Drawing::Size(0, 13);
			this->Ax3Val->TabIndex = 12;
			// 
			// Ax3lbl
			// 
			this->Ax3lbl->AutoSize = true;
			this->Ax3lbl->Location = System::Drawing::Point(20, 160);
			this->Ax3lbl->Name = L"Ax3lbl";
			this->Ax3lbl->Size = System::Drawing::Size(34, 13);
			this->Ax3lbl->TabIndex = 12;
			this->Ax3lbl->Text = L"axis3:";
			// 
			// Ax1Val
			// 
			this->Ax1Val->AutoSize = true;
			this->Ax1Val->Location = System::Drawing::Point(60, 114);
			this->Ax1Val->Name = L"Ax1Val";
			this->Ax1Val->Size = System::Drawing::Size(0, 13);
			this->Ax1Val->TabIndex = 12;
			// 
			// Ax1lbl
			// 
			this->Ax1lbl->AutoSize = true;
			this->Ax1lbl->Location = System::Drawing::Point(20, 114);
			this->Ax1lbl->Name = L"Ax1lbl";
			this->Ax1lbl->Size = System::Drawing::Size(34, 13);
			this->Ax1lbl->TabIndex = 12;
			this->Ax1lbl->Text = L"axis1:";
			// 
			// Ax4Val
			// 
			this->Ax4Val->AutoSize = true;
			this->Ax4Val->Location = System::Drawing::Point(60, 182);
			this->Ax4Val->Name = L"Ax4Val";
			this->Ax4Val->Size = System::Drawing::Size(0, 13);
			this->Ax4Val->TabIndex = 12;
			// 
			// Ax4lbl
			// 
			this->Ax4lbl->AutoSize = true;
			this->Ax4lbl->Location = System::Drawing::Point(20, 182);
			this->Ax4lbl->Name = L"Ax4lbl";
			this->Ax4lbl->Size = System::Drawing::Size(34, 13);
			this->Ax4lbl->TabIndex = 12;
			this->Ax4lbl->Text = L"axis4:";
			// 
			// Ax2Val
			// 
			this->Ax2Val->AutoSize = true;
			this->Ax2Val->Location = System::Drawing::Point(60, 137);
			this->Ax2Val->Name = L"Ax2Val";
			this->Ax2Val->Size = System::Drawing::Size(0, 13);
			this->Ax2Val->TabIndex = 12;
			// 
			// Ax2lbl
			// 
			this->Ax2lbl->AutoSize = true;
			this->Ax2lbl->Location = System::Drawing::Point(20, 137);
			this->Ax2lbl->Name = L"Ax2lbl";
			this->Ax2lbl->Size = System::Drawing::Size(34, 13);
			this->Ax2lbl->TabIndex = 12;
			this->Ax2lbl->Text = L"axis2:";
			// 
			// Ax0Val
			// 
			this->Ax0Val->AutoSize = true;
			this->Ax0Val->Location = System::Drawing::Point(60, 91);
			this->Ax0Val->Name = L"Ax0Val";
			this->Ax0Val->Size = System::Drawing::Size(0, 13);
			this->Ax0Val->TabIndex = 12;
			// 
			// Ax0Lbl
			// 
			this->Ax0Lbl->AutoSize = true;
			this->Ax0Lbl->Location = System::Drawing::Point(20, 91);
			this->Ax0Lbl->Name = L"Ax0Lbl";
			this->Ax0Lbl->Size = System::Drawing::Size(34, 13);
			this->Ax0Lbl->TabIndex = 12;
			this->Ax0Lbl->Text = L"axis0:";
			// 
			// commands
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 275);
			this->Controls->Add(this->JoystickBox);
			this->Controls->Add(this->SerialTimerBox);
			this->Controls->Add(this->Historico);
			this->Controls->Add(this->CommandsBox);
			this->Controls->Add(this->Bufferlbl);
			this->Controls->Add(this->Console);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->DirEn);
			this->Name = L"commands";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SerialCommunication";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &commands::commands_FormClosing);
			this->Load += gcnew System::EventHandler(this, &commands::commands_Load);
			this->CommandsBox->ResumeLayout(false);
			this->CommandsBox->PerformLayout();
			this->SerialTimerBox->ResumeLayout(false);
			this->SerialTimerBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->EndInit();
			this->JoystickBox->ResumeLayout(false);
			this->JoystickBox->PerformLayout();
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
	private: int JoyToHB(int);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: void JoystickWatch();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: bool SetMotor(int, int);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void DisconnJoy_Click(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: bool SendSerial(String^); //master
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
}