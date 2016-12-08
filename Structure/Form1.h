#pragma once
namespace Structure {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Threading;
	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			SetStyle(ControlStyles::UserPaint, true);
			SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			SetStyle(ControlStyles::DoubleBuffer, true);
			Control::CheckForIllegalCrossThreadCalls = false;
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::IContainer^  components;
		float H_up, X_uleft, H_down, X_dleft;
		PointF MiddleL, UpL, DownL,JLU,JLD,UpR,MiddleR,DownR;
		const float wid = 200;
		const float side = 50;
		const float radius = 5;
		const float sense = 5;
		int oldsize_X, oldsize_Y;
		float Graphics_DeltaX;
		float Graphics_DeltaY;
		bool up;
		bool down;
		bool middle;
		PointF StartMousePointF;
		int AngleUp, AngleDown;
		bool um, dm, mid;
		Drawing::Size RFS = Drawing::Size(wid, 2 * sense);
		Pen ^Joint = gcnew Pen(Color::Purple, 1);
		Pen ^Normal = gcnew Pen(Color::Blue, 2);
		Pen ^Chosen = gcnew Pen(Color::Red, 4);
		array<int>^Angle=gcnew array<int>(8);
		Thread^ Trecv;
		bool MoveComplete = true;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::TextBox^  TPort;

	private: System::Windows::Forms::Button^  BActivateConn;

	private: System::Windows::Forms::TextBox^  ConsoleT;
	private: System::Windows::Forms::Button^  BSend;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label16;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// 设计器支持所需的方法 - 不要
			 /// 使用代码编辑器修改此方法的内容。
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
				 this->TPort = (gcnew System::Windows::Forms::TextBox());
				 this->BActivateConn = (gcnew System::Windows::Forms::Button());
				 this->ConsoleT = (gcnew System::Windows::Forms::TextBox());
				 this->BSend = (gcnew System::Windows::Forms::Button());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->SuspendLayout();
				 // 
				 // TPort
				 // 
				 this->TPort->Location = System::Drawing::Point(138, 6);
				 this->TPort->Name = L"TPort";
				 this->TPort->Size = System::Drawing::Size(100, 21);
				 this->TPort->TabIndex = 4;
				 this->TPort->TextChanged += gcnew System::EventHandler(this, &Form1::TPort_TextChanged);
				 // 
				 // BActivateConn
				 // 
				 this->BActivateConn->ForeColor = System::Drawing::SystemColors::ControlText;
				 this->BActivateConn->Location = System::Drawing::Point(244, 6);
				 this->BActivateConn->Name = L"BActivateConn";
				 this->BActivateConn->Size = System::Drawing::Size(102, 23);
				 this->BActivateConn->TabIndex = 5;
				 this->BActivateConn->Text = L"ConnectToPort";
				 this->BActivateConn->UseVisualStyleBackColor = true;
				 this->BActivateConn->Click += gcnew System::EventHandler(this, &Form1::BActivateConn_Click);
				 // 
				 // ConsoleT
				 // 
				 this->ConsoleT->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->ConsoleT->Location = System::Drawing::Point(0, 356);
				 this->ConsoleT->Multiline = true;
				 this->ConsoleT->Name = L"ConsoleT";
				 this->ConsoleT->ScrollBars = System::Windows::Forms::ScrollBars::Both;
				 this->ConsoleT->Size = System::Drawing::Size(519, 118);
				 this->ConsoleT->TabIndex = 6;
				 // 
				 // BSend
				 // 
				 this->BSend->Location = System::Drawing::Point(432, 33);
				 this->BSend->Name = L"BSend";
				 this->BSend->Size = System::Drawing::Size(75, 23);
				 this->BSend->TabIndex = 7;
				 this->BSend->Text = L"SentTest";
				 this->BSend->UseVisualStyleBackColor = true;
				 this->BSend->Click += gcnew System::EventHandler(this, &Form1::BSend_Click);
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(138, 35);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(288, 21);
				 this->textBox2->TabIndex = 8;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(0, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(17, 12);
				 this->label1->TabIndex = 9;
				 this->label1->Text = L"A1";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(0, 12);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(17, 12);
				 this->label2->TabIndex = 10;
				 this->label2->Text = L"A2";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(0, 24);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(17, 12);
				 this->label3->TabIndex = 11;
				 this->label3->Text = L"A3";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(0, 36);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(17, 12);
				 this->label4->TabIndex = 12;
				 this->label4->Text = L"A4";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(0, 49);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(17, 12);
				 this->label5->TabIndex = 13;
				 this->label5->Text = L"A5";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(0, 61);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(17, 12);
				 this->label6->TabIndex = 14;
				 this->label6->Text = L"A6";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(0, 73);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(17, 12);
				 this->label7->TabIndex = 15;
				 this->label7->Text = L"A7";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(0, 85);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(17, 12);
				 this->label8->TabIndex = 16;
				 this->label8->Text = L"A8";
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(47, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(41, 12);
				 this->label9->TabIndex = 24;
				 this->label9->Text = L"label9";
				 this->label9->Click += gcnew System::EventHandler(this, &Form1::label9_Click);
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(47, 12);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(47, 12);
				 this->label10->TabIndex = 23;
				 this->label10->Text = L"label10";
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(47, 24);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(47, 12);
				 this->label11->TabIndex = 22;
				 this->label11->Text = L"label11";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(47, 36);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(47, 12);
				 this->label12->TabIndex = 21;
				 this->label12->Text = L"label12";
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(47, 48);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(47, 12);
				 this->label13->TabIndex = 20;
				 this->label13->Text = L"label13";
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Location = System::Drawing::Point(47, 60);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(47, 12);
				 this->label14->TabIndex = 19;
				 this->label14->Text = L"label14";
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Location = System::Drawing::Point(47, 73);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(47, 12);
				 this->label15->TabIndex = 18;
				 this->label15->Text = L"label15";
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(47, 85);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(47, 12);
				 this->label16->TabIndex = 17;
				 this->label16->Text = L"label16";
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(429, 13);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(78, 16);
				 this->checkBox1->TabIndex = 25;
				 this->checkBox1->Text = L"SendToDev";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(519, 474);
				 this->Controls->Add(this->checkBox1);
				 this->Controls->Add(this->label9);
				 this->Controls->Add(this->label10);
				 this->Controls->Add(this->label11);
				 this->Controls->Add(this->label12);
				 this->Controls->Add(this->label13);
				 this->Controls->Add(this->label14);
				 this->Controls->Add(this->label15);
				 this->Controls->Add(this->label16);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->label7);
				 this->Controls->Add(this->label6);
				 this->Controls->Add(this->label5);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->BSend);
				 this->Controls->Add(this->ConsoleT);
				 this->Controls->Add(this->BActivateConn);
				 this->Controls->Add(this->TPort);
				 this->MinimumSize = System::Drawing::Size(535, 513);
				 this->Name = L"Form1";
				 this->Text = L"Form1";
				 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				 this->ResizeEnd += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
				 this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
				 this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
				 this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
				 this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

ref struct Circle
	{
		PointF center;
		float r;
		Circle(PointF p, float ir) :center(p), r(ir){};
	};
//Data I/O
private:static void Recv(Object^ Fthis)
	{
		System::IO::Ports::SerialPort^ SP = ((Form1^)Fthis)->serialPort1;
		((Form1^)Fthis)->WriteConsole("Recv Thread Actived");
		while (SP->IsOpen)
		{
			try
			{
				String^ message = SP->ReadLine();
				((Form1^)Fthis)->WriteConsole("Data Recived-> "+message);
				if (message == "#MC")
					((Form1^)Fthis)->MoveComplete = true;
			}
			catch (Exception ^) {}
		}
	}
private: System::Void SendToDevice(int SLV){
	if (!serialPort1->IsOpen)
		BActivateConn_Click(this, gcnew EventArgs());
	String ^tmp="#";
	    tmp += "i" + SLV + "#";
		
		tmp += "a"+Angle[1]+"#";
		tmp += "b" + Angle[0] + "#";
		tmp += "c" + Angle[5] + "#";
		tmp += "d" + Angle[4] + "#";
			
		
	try{
		serialPort1->WriteLine(tmp);
		WriteConsole("Message: " + tmp + " sent to " + serialPort1->PortName);
	}
	catch (Exception ^e)
	{
		WriteConsole(e->ToString());
	}
	
}
private: System::Void BActivateConn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (serialPort1->IsOpen)
	{
		try{
			serialPort1->Close();
			Trecv->Join();
			BActivateConn->ForeColor = Color::Black;
			BActivateConn->Text = "ConnectToPort";
			WriteConsole("Port Closed");
			WriteConsole("Recv Thread Terminated");
		}
		catch (Exception ^E)
		{
			WriteConsole(e->ToString());
		}
		return;
	}
	try{
			serialPort1->Open();
			WriteConsole("Port Opened.");
			Trecv = gcnew Thread(gcnew ParameterizedThreadStart(&Recv));
			Trecv->Start((Object^)this);
			BActivateConn->ForeColor=Color::Green;
			BActivateConn->Text = "Opened";
		}
		catch (Exception ^e)
		{
			WriteConsole(e->ToString());
		}
	}
private: System::Void WriteConsole(System::String^ text){
		DateTime MsgTime = DateTime::Now;
		ConsoleT->SelectedText = "[" + MsgTime + "] " + text + "\r\n";
		ConsoleT->ScrollToCaret();
	}
private: System::Void BSend_Click(System::Object^  sender, System::EventArgs^  e) {
		try{
			serialPort1->Write(textBox2->Text);
			WriteConsole("Message: " + textBox2->Text + " sent to " + serialPort1->PortName);
		}
		catch (Exception ^e)
		{
			WriteConsole(e->ToString());
		}
	}
private: System::Void TPort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 serialPort1->PortName = TPort->Text;
}
//FormAction////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		UpL = PointF(0,2*side);
		MiddleL = PointF(0, 0);
		DownL = PointF(0,-2 * side);
		Graphics_DeltaX = (float)Width / 2 - (float)wid / 2;
		Graphics_DeltaY = (float)Height / 3;
		ConsoleT->Height = Height / 4;
	}
private: System::Void Form1_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
		Graphics_DeltaX = (float)Width / 2 - (float)wid / 2;
		Graphics_DeltaY = (float)Height / 3;
		ConsoleT->Height = this->Height *3/ 8;
		Invalidate();
	}
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int i = LocationOn(e->Location);
		if (i == 1)
		{
			up = true;
			Invalidate(Rectangle(MathToScreen(Point(UpL.X,UpL.Y+sense)),RFS));
		}
		else if (i == -1)
		{
			down = true;
			Invalidate(Rectangle(MathToScreen(Point(DownL.X, DownL.Y+ sense)), RFS));
		}
		else if (i == 0)
		{
			middle = true;
			Invalidate(Rectangle(MathToScreen(Point(MiddleL.X, MiddleL.Y + sense)), RFS));
		}
		else if (up == true || down == true||middle == true)
		{
			up = false;
			down = false;
			middle = false;
			Invalidate(Rectangle(MathToScreen(Point(UpL.X, UpL.Y + sense)), RFS));
			Invalidate(Rectangle(MathToScreen(Point(DownL.X, DownL.Y + sense)), RFS));
			Invalidate(Rectangle(MathToScreen(Point(MiddleL.X, MiddleL.Y + sense)), RFS));
		}

		if (um)
		{
			UpL.Y -= (float)e->Y - StartMousePointF.Y;
			UpL.X += (float)e->X - StartMousePointF.X;
			UpL = CheckIfOut(UpL, MiddleL, side ,2 * side);
			JLU = CalJoint(UpL, MiddleL, 1);
			if (JLU.X - MiddleL.X>0)
			{
				UpL.X -= JLU.X - MiddleL.X;
			}
			else if (JLU.X - UpL.X >0)
			{
				UpL.X +=  JLU.X-UpL.X;
			}
			StartMousePointF.X = (float)e->X;
			StartMousePointF.Y = (float)e->Y;
			Invalidate();
		}
		else if (dm)
		{
			DownL.Y -= (float)e->Y - StartMousePointF.Y;
			DownL.X += (float)e->X - StartMousePointF.X;
			DownL = CheckIfOut(DownL, MiddleL, side,2 * side);
			JLD = CalJoint(MiddleL, DownL, 1);
			if (JLD.X - MiddleL.X>0)
			{
				DownL.X -= JLD.X - MiddleL.X;
			}
			else if (JLD.X - DownL.X >0)
			{
				DownL.X += JLD.X - DownL.X;
			}
			StartMousePointF.Y = (float)e->Y;
			StartMousePointF.X = (float)e->X;
			Invalidate();
		}
		else if (mid)
		{
			MiddleL.Y -= (float)e->Y - StartMousePointF.Y;
			MiddleL.X += (float)e->X - StartMousePointF.X;
			MiddleL = CheckIfOut(MiddleL, DownL, side, 2 * side);
			MiddleL = CheckIfOut(MiddleL, UpL, side,2 * side);
			JLD = CalJoint(MiddleL, DownL, 1);
			JLU = CalJoint(UpL, MiddleL, 1);
			if (JLD.X - MiddleL.X>0)
			{
				MiddleL.X += JLD.X - MiddleL.X;
			}
			else if (JLD.X - DownL.X >0)
			{
				MiddleL.X -= JLD.X - DownL.X;
			}
			if (JLU.X - MiddleL.X>0)
			{
				MiddleL.X += JLU.X - MiddleL.X;
			}
			else if (JLU.X - UpL.X >0)
			{
				MiddleL.X -= JLU.X - UpL.X;
			}
			StartMousePointF.Y = (float)e->Y;
			StartMousePointF.X = (float)e->X;
			Invalidate();
		}
	}
private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (!MoveComplete)
		return;
	if ((!um) && (LocationOn(e->Location) == 1))
		{
			StartMousePointF = e->Location;
			um = true;
		}
		else if ((!dm) && (LocationOn(e->Location) == -1))
		{
			StartMousePointF = e->Location;
			dm = true;
		}
		else if ((!mid) && (LocationOn(e->Location) == 0))
		{
			StartMousePointF = e->Location;
			mid = true;
		}
	}
private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int S = -1;
	if (um == true){ um = false; S = 2; }
	else if (mid == true){ mid = false; S = 1; }
	else if (dm == true){ dm = false; S = 0; }
	if (checkBox1->Checked && S!=-1)
		SendToDevice(S);
	}
//Drawing/////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void RefreshTheAngle(array < PointF > ^List)
	{
		Angle[0] = Rad2Angle((Math::Asin((List[4].X - List[3].X) / distance(List[0], List[1]))));
		Angle[1] = Rad2Angle((Math::Asin((List[2].X - List[1].X) / distance(List[0], List[1]))));
		Angle[2] = Rad2Angle((Math::Asin((List[4].X - List[3].X) / distance(List[0], List[1]))));
		Angle[3] = Rad2Angle((Math::Asin((List[4].X - List[5].X) / distance(List[0], List[1]))));
		Angle[4] = Rad2Angle((Math::Asin((List[6].X - List[7].X) / distance(List[0], List[1]))));
		Angle[5] = Rad2Angle((Math::Asin((List[8].X - List[7].X) / distance(List[0], List[1]))));
		Angle[6] = Rad2Angle((Math::Asin((List[10].X - List[9].X) / distance(List[0], List[1]))));
		Angle[7] = Rad2Angle((Math::Asin((List[10].X - List[11].X) / distance(List[0], List[1]))));

		label9->Text = Angle[0]+"°";
		label10->Text = Angle[1] + "°";
		label11->Text = Angle[2] + "°";
		label12->Text = Angle[3] + "°";
		label13->Text = Angle[4] + "°";
		label14->Text = Angle[5] + "°";
		label15->Text = Angle[6] + "°";
		label16->Text = Angle[7] + "°";
		
	}
private: int Rad2Angle(float rad)
	{
		int rs = Math::Round(rad * 180 / 3.14159265F);
		if (rs > 90||rs<-90){
			if (rs > 0)
				return 90;
			return -90;
		}
		return rs;
	}
private: System::Void JointShow(array<PointF> ^JointIn,Graphics ^DrawGr)
	{
		for (int i = 0; i < JointIn->Length; i++)
		{
			DrawGr->DrawEllipse(Joint, RectangleF(JointIn[i].X - radius, JointIn[i].Y - radius, 2.0F * radius, 2.0F * radius));
		}
	}
private: PointF MathToScreen(PointF In){
		return PointF(In.X + Graphics_DeltaX, Graphics_DeltaY-In.Y);
	}
private: Point MathToScreen(Point In){
		return Point(In.X + Graphics_DeltaX, Graphics_DeltaY - In.Y);
	 }
private: PointF ScreenToMath(PointF In){
		return PointF(In.X - Graphics_DeltaX, Graphics_DeltaY-In.Y);
	}
private: int LocationOn(PointF Mouse)
	{
		PointF Temp = ScreenToMath(Mouse);
		if (Temp.Y > UpL.Y - sense
			&& Temp.Y < UpL.Y + sense
			&& Temp.X > UpL.X
			&& Temp.X < UpL.X + wid)
			return 1;
		if (Temp.Y > DownL.Y - sense
			&& Temp.Y < DownL.Y + sense
			&& Temp.X > DownL.X
			&& Temp.X < DownL.X + wid)
			return -1;
		if (Temp.Y >MiddleL.Y - sense
			&& Temp.Y < MiddleL.Y + sense
			&& Temp.X > MiddleL.X
			&& Temp.X < MiddleL.X + wid)
			return 0;
		return -2;

	}
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->TranslateTransform(Graphics_DeltaX, Graphics_DeltaY);
		e->Graphics->ScaleTransform(1.0F, -1.0F);
		e->Graphics->SmoothingMode = Drawing::Drawing2D::SmoothingMode::AntiAlias;
		UpR = OtherSide(UpL);
		MiddleR = OtherSide(MiddleL);
		DownR = OtherSide(DownL);
		
		 JLU = CalJoint(UpL, MiddleL, 1);
		 JLD = CalJoint(MiddleL, DownL, 1);
		
		PointF JRU = CalJoint(UpR, MiddleR, 2);
		PointF JRD = CalJoint(MiddleR, DownR, 2);
		
		array < PointF > ^Plist = 
		{ MiddleL,JLU , UpL, UpR,JRU , MiddleR, MiddleL,JLD , DownL, DownR,JRD, MiddleR};
		//Draw All Side
		e->Graphics->DrawLines(Normal, Plist);
		//Chosen Side Draw
		if (up)
			e->Graphics->DrawLine(Chosen, UpL, OtherSide(UpL));
		else if (down)
			e->Graphics->DrawLine(Chosen, DownL, OtherSide(DownL));
		else if (middle)
			e->Graphics->DrawLine(Chosen, MiddleL, OtherSide(MiddleL));
		//DrawJoint
		JointShow(Plist,e->Graphics);
		RefreshTheAngle(Plist);
	}
private: PointF OtherSide(PointF Left)
	{
		return PointF(Left.X + wid, Left.Y);
	}
private: PointF CheckIfOut(PointF P1, PointF P2, float YMin,float RMax)
	{
		float DP1P2 = distance(P1, P2);
		if (Math::Abs(P1.Y - P2.Y) < YMin)
		{
			if (P1.Y - P2.Y > 0)
				P1.Y = P2.Y + YMin;
			else
				P1.Y = P2.Y - YMin;
		}
		if (DP1P2 > RMax)
		{
			float deltaX = (P2.X - P1.X)*RMax / DP1P2;
			float deltaY = (P2.Y - P1.Y)*RMax / DP1P2;
			return PointF(P2.X - deltaX, P2.Y - deltaY);
		}
		return P1;

	}

private: PointF CheckIfOut(PointF P1, PointF P2, float YMin, float XMin,float RMax)
		 {
			 float DP1P2 = distance(P1, P2);
			 if (Math::Abs(P1.Y - P2.Y) < YMin)
			 {
				 if (P1.Y - P2.Y > 0)
					 P1.Y = P2.Y + YMin;
				 else
					 P1.Y = P2.Y - YMin;
			 }
			 if (Math::Abs(P1.X - P2.X) > XMin)
			 {

				 if (P1.X - P2.X > 0)
					 P1.X = P2.X + YMin;
				 else
					 P1.X = P2.X - YMin;
			 }
			 if (DP1P2 > RMax)
			 {
				 float deltaX = (P2.X - P1.X)*RMax / DP1P2;
				 float deltaY = (P2.Y - P1.Y)*RMax / DP1P2;

				 return PointF(P2.X - deltaX, P2.Y - deltaY);
			 }
			
			 return P1;
		 }

//JointCalculation////////////////////////////////////////////////////////////////////////////////////////	
private: PointF CalJoint(PointF UpEr, PointF LowEr,int Out){
	return insect(gcnew array < Circle^ > {gcnew Circle(UpEr, side), gcnew Circle(LowEr, side)},Out);
}
private: PointF insect(array<Circle^> ^circles,int Out)
		 {
			 array<PointF> ^points = {PointF(0.0F,0.0F),PointF(0.0F,0.0F)};
			 try{
				 float d, a, b, c, p, q, r;
				 float cos_value[2], sin_value[2];
				 if (double_equals(circles[0]->center.X, circles[1]->center.X)
					 && double_equals(circles[0]->center.Y, circles[1]->center.Y)
					 && double_equals(circles[0]->r, circles[1]->r)) {
					 throw(-1);
				 }

				 d = distance(circles[0]->center, circles[1]->center);
				 if (d > circles[0]->r + circles[1]->r
					 || d < Math::Abs(circles[0]->r - circles[1]->r)) {
					 throw(0);
				 }

				 a = 2.0F * circles[0]->r * (circles[0]->center.X - circles[1]->center.X);
				 b = 2.0F * circles[0]->r * (circles[0]->center.Y - circles[1]->center.Y);
				 c = circles[1]->r * circles[1]->r - circles[0]->r * circles[0]->r
					 - distance_sqr(circles[0]->center, circles[1]->center);
				 p = a * a + b * b;
				 q = -2.0F * a * c;
				 if (double_equals(d, circles[0]->r + circles[1]->r)
					 || double_equals(d, Math::Abs(circles[0]->r - circles[1]->r))) {
					 cos_value[0] = -q / p / 2.0F;
					 sin_value[0] = Math::Sqrt(1.0F - cos_value[0] * cos_value[0]);

					 points[0].X = circles[0]->r * cos_value[0] + circles[0]->center.X;
					 points[0].Y = circles[0]->r * sin_value[0] + circles[0]->center.Y;

					 if (!double_equals(distance_sqr(points[0], circles[1]->center),
						 circles[1]->r * circles[1]->r)) {
						 points[0].Y = circles[0]->center.Y - circles[0]->r * sin_value[0];
					 }
					 throw(1);
				 }

				 r = c * c - b * b;
				 cos_value[0] = ((float)Math::Sqrt(q * q - 4.0F * p * r) - q) / p / 2.0F;
				 cos_value[1] = (-(float)Math::Sqrt(q * q - 4.0F * p * r) - q) / p / 2.0F;
				 sin_value[0] = (float)Math::Sqrt(1.0F - cos_value[0] * cos_value[0]);
				 sin_value[1] = (float)Math::Sqrt(1.0F - cos_value[1] * cos_value[1]);

				 points[0].X = circles[0]->r * cos_value[0] + circles[0]->center.X;
				 points[1].X = circles[0]->r * cos_value[1] + circles[0]->center.X;
				 points[0].Y = circles[0]->r * sin_value[0] + circles[0]->center.Y;
				 points[1].Y = circles[0]->r * sin_value[1] + circles[0]->center.Y;

				 if (!double_equals(distance_sqr(points[0], circles[1]->center),
					 circles[1]->r * circles[1]->r)) {
					 points[0].Y = circles[0]->center.Y - circles[0]->r * sin_value[0];
				 }
				 if (!double_equals(distance_sqr(points[1], circles[1]->center),
					 circles[1]->r * circles[1]->r)) {
					 points[1].Y = circles[0]->center.Y - circles[0]->r * sin_value[1];
				 }
				 if (double_equals(points[0].Y, points[1].Y)
					 && double_equals(points[0].X, points[1].X)) {
					 if (points[0].Y > 0) {
						 points[1].Y = -points[1].Y;
					 }
					 else {
						 points[0].Y = -points[0].Y;
					 }
				 }
				 throw(2);
			 }
			 catch (int Result)
			 {
				 switch (Result)
				 {
				 case -1:
					 return MiddlePoint(circles[0]->center, circles[1]->center);
				 case 0:
					 return MiddlePoint(circles[0]->center, circles[1]->center);
				 case 1:
					 return MiddlePoint(circles[0]->center, circles[1]->center);
				 case 2:
					 if (Out == 1)
						 return ReturnTheLP(points, gcnew array < PointF > {PointF(circles[0]->center),PointF(circles[1]->center)});
					 else 
						 return ReturnTheRP(points, gcnew array < PointF > {PointF(circles[0]->center), PointF(circles[1]->center)});
				 default:
					 break;
				 }
			 }
			 return MiddlePoint(circles[0]->center, circles[1]->center);
}
private: PointF MiddlePoint(PointF P1, PointF P2)
	{
		return PointF((P1.X+P2.X)/2,(P1.Y+P2.Y)/2);
	}
private: PointF ReturnTheLP(array<PointF> ^IN,array<PointF> ^ce){
	if (IN[0].X > IN[1].X)
		return IN[1];
	else if (IN[0].X == IN[1].X)
	{
		if (double_equals(distance(IN[0], ce[0]), side) || double_equals(distance(IN[0], ce[1]), side))
			return IN[0];
		else
			return IN[1];
	}
	else return IN[0];
	}
private: PointF ReturnTheRP(array<PointF> ^IN, array<PointF> ^ce){
				 if (IN[0].X < IN[1].X)
					 return IN[1];
				 else if (IN[0].X == IN[1].X)
				 {
					 if (double_equals(distance(IN[0], ce[0]), side) || double_equals(distance(IN[0], ce[1]), side))
						 return IN[0];
					 else
						 return IN[1];
				 }
				 else return IN[0];
			 }
private: float distance_sqr(PointF a, PointF b)
	{
	    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
	}
private: float distance(PointF a, PointF b)
	{
		return (float)Math::Sqrt(distance_sqr(a, b));
	}
private: int double_equals(float const a, float const b)
	{
		static const float ZERO = (float)1e-9;
		return Math::Abs(a - b) < ZERO;
	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

