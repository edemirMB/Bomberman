#pragma once
#include "Cancha.h"
#include "Jugador.h"

class CControladora {
private:
	CCancha* cancha;
	CJugador* jugador;

public:
	CControladora();
	~CControladora() {};

	void DibujarCancha();
	void Dibujar(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible);
	void DibujarJugador(Graphics^ g, Bitmap^ bmpJugador);
	void MoverJugador(Graphics^ g, Bitmap^ bmpJugador);
	CJugador* getJugador();
};
