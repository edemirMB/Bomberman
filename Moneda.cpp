#include "Moneda.h"

Moneda::Moneda() {
	// Constructor por defecto
	this->velocidadRotacion = 0.0f;
	this->anguloMaximoRotacion = 0.0f;
	this->limiteRotacion = 0.0f;
	this->sentidoRotacion = 0;
	this->posicionMoneda = Point(0.0f, 0.0f);
	this->radio = 0.0f;
}
Moneda::Moneda(float velocidadRotacion, float limiteRotacion, Point posicionMoneda) {
	// Constructor con parámetros
	this->velocidadRotacion = velocidadRotacion;
	this->limiteRotacion = limiteRotacion;
	this->posicionMoneda = posicionMoneda;
	this->anguloMaximoRotacion = 0.0f;
	this->sentidoRotacion = 1; // Por defecto sentido horario
	this->radio = 20.0f; // Radio por defecto
}

Moneda::~Moneda() {
	// Destructor
}

void Moneda::Dibujar(Graphics^ g, Bitmap^ bmpMoneda) {
	int indiceX = 0;
	int indiceY = 0;
	Rectangle rectangulo = Rectangle(indiceX * ANCHO, indiceY * ALTO, ANCHO, ALTO);
	Rectangle zoom = Rectangle(x, y, ANCHO * FACTORZOOM, ALTO * FACTORZOOM);
	g->DrawImage(bmpMoneda, zoom, rectangulo, GraphicsUnit::Pixel);
}

void Moneda::RotarMoneda(Graphics^ g, Bitmap^ bmpMoneda) {
	// Rotar la moneda
	anguloMaximoRotacion += velocidadRotacion * sentidoRotacion;
	//cambio de sentido
	if (anguloMaximoRotacion >= limiteRotacion) {
		sentidoRotacion = -1;
	}
	else if (anguloMaximoRotacion <= -limiteRotacion) {
		sentidoRotacion = 1;
	}
}

void Moneda::setVelocidadRotacion(float velocidadRotacion) {
	this->velocidadRotacion = velocidadRotacion;
}
float Moneda::getVelocidadRotacion() {
	return velocidadRotacion;
}
void Moneda::setAnguloMaximoRotacion(float anguloMaximoRotacion) {
	this->anguloMaximoRotacion = anguloMaximoRotacion;
}

float Moneda::getAnguloMaximoRotacion() {
	return anguloMaximoRotacion;
}

void Moneda::setLimiteRotacion(float limiteRotacion) {
	this->limiteRotacion = limiteRotacion;
}
float Moneda::getLimiteRotacion() {
	return limiteRotacion;
}
void Moneda::setSentidoRotacion(int sentidoRotacion) {
	this->sentidoRotacion = sentidoRotacion;
}
int Moneda::getSentidoRotacion() {
	return sentidoRotacion;
}
void Moneda::setPosicionMoneda(Point posicionMoneda) {
	this->posicionMoneda = posicionMoneda;
}
Point Moneda::getPosicionMoneda() {
	return posicionMoneda;
}
void Moneda::setRadio(float radio) {
	this->radio = radio;
}
float Moneda::getRadio() {
	return radio;
}

