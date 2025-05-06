#pragma once
using namespace System::Drawing;

#define HABILIDADES 7
#define ANCHO 70
#define ALTO 128
#define FACTORZOOM 0.6

ref class Moneda
{
private:
	float velocidadRotacion;
	float anguloMaximoRotacion;	
	float limiteRotacion;
	int sentidoRotacion; // 1 = sentido horario, -1 = sentido antihorario
	Point posicionMoneda;
	float radio;
	int x;		// posicion en el eje X
	int y;		// posicion en el eje y

public:
	Moneda();
	Moneda(float velocidadRotacion, float limiteRotacion, Point posicionMoneda);
	~Moneda();
	void Dibujar(Graphics^ g, Bitmap^ bmpMoneda);
	void RotarMoneda(Graphics^ g, Bitmap^ bmpMoneda);


	void setVelocidadRotacion(float velocidadRotacion);
	float getVelocidadRotacion();
	void setAnguloMaximoRotacion(float anguloMaximoRotacion);
	float getAnguloMaximoRotacion();
	void setLimiteRotacion(float limiteRotacion);
	float getLimiteRotacion();
	void setSentidoRotacion(int sentidoRotacion);
	int getSentidoRotacion();
	void setPosicionMoneda(Point posicionMoneda);
	Point getPosicionMoneda();
	void setRadio(float radio);
	float getRadio();

};

