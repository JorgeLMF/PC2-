#pragma once
using namespace System::Drawing;
using namespace System::Windows::Forms;
ref class CFondo {
	Bitmap^ trasero;
	Bitmap^ delantero;
public:
	CFondo(Bitmap^ delantero, Bitmap^ trasero) {
		this->delantero = delantero;
		this->trasero = trasero;
	}
	void dibujar(Graphics^ g, Rectangle area) {
		g->DrawImage(trasero, 0, 0, area.Width, area.Height);
		g->DrawImage(delantero, 0, 0, area.Width, area.Height);
	}
};