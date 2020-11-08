#pragma once
using namespace System::Drawing;
ref class ObjAnimado {
protected:
	short x, y;
	short ancho, alto;
	short filas, columnas;
	short idx, idy;
	Bitmap^ bmp;
public:
	ObjAnimado(Bitmap^ bmp, short filas, short columnas) :bmp(bmp), filas(filas), columnas(columnas) {
		idx = idy = 0;
		ancho = bmp->Width / columnas;
		alto = bmp->Height / filas;
	}
	~ObjAnimado() { delete bmp; }
	short getX() { return x; }
	short getY() { return y; }
	short getAlto() { return alto; }
	void setX(short x) { this->x = x; }
	void setY(short y) { this->y = y; }
	virtual void dibujar(Graphics^)abstract;
	virtual void mover() {}

};