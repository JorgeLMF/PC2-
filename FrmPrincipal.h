#pragma once
#include "Controlador.h"
namespace Pc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmPrincipal
	/// </summary>
	public ref class FrmPrincipal : public System::Windows::Forms::Form
	{
	public:
		FrmPrincipal(bool validar, short cant)
		{
			InitializeComponent();
			buffer = BufferedGraphicsManager::Current->Allocate(CreateGraphics(), this->ClientRectangle);
			juego = gcnew CControlador(validar, cant);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		BufferedGraphics^ buffer;
		CControlador^ juego;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmPrincipal::timer1_Tick);
			// 
			// FrmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 690);
			this->Name = L"FrmPrincipal";
			this->Text = L"FrmPrincipal";
			this->Load += gcnew System::EventHandler(this, &FrmPrincipal::FrmPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmPrincipal::FrmPrincipal_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(SystemColors::Control);
		juego->ejecutarJuego(buffer->Graphics, this->ClientRectangle);
		buffer->Graphics->DrawString(gcnew String(" X: " + juego->getJugador()->getX() + "     Y: " + juego->getJugador()->getY() + "    "), gcnew System::Drawing::Font("Times New Roman", 24), Brushes::Red, 0, 0);
		buffer->Render(this->CreateGraphics());
	}
	private: System::Void FrmPrincipal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::A: juego->getJugador()->mover(izquierda,this->ClientRectangle); break;
		case Keys::D: juego->getJugador()->mover(derecha, this->ClientRectangle); break;
		default:
			break;
		}
	}
	};
}
