#pragma once
#include "ObjAnimado.h"
using namespace System::Drawing;
enum direccion {
	derecha, izquierda
};
ref class CJugador: public ObjAnimado {
	Bitmap^ regreso;
	short cantBalas;
	short dx;
	short dy;
public:
	CJugador(Bitmap^ bmp, short filas, short columnas, short n) :ObjAnimado(bmp, filas, columnas), cantBalas(n),dx(0),dy(0) {}
	void dibujar(Graphics^ g) override {
		if(dx>0)
			g->DrawImage(bmp, x, y, ancho/2, alto/2);
		else g->DrawImage(regreso, x, y, ancho / 2, alto / 2);
	}
	void mover(direccion dir, Rectangle area) {
		if (x >= 265 || x >= 75 && x <= 125) y = 340;
		else dy = 0;
		if (x >= 10 && x < 75 || x>=220 && x<=270) dy = 1;
		else if (x >= 135 && x <= 170)dy = -1;
		else dy = 0;
		if (x <= 20)y = 290;
		switch (dir)
		{
		case derecha:
			dx = 1;
			if (x + dx < 0 || x+dx+ancho>area.Width)dx = 0;
			y += dy;
			x += dx;
			break;
		case izquierda:
			dx = -1;
			if (x + dx < 0 || x + dx + ancho>area.Width)dx = 0;
			y -= dy;
			x += dx;
			break;
		default:
			dx = dy = 0;
			break;
		}
		
	}
	void setCantBalas(short n) { cantBalas = n; }
	short getCantBalas() { return cantBalas; }
	void setRegreso(Bitmap^ aux) { regreso = aux; }
};