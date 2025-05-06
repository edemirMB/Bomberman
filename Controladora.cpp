#include "Controladora.h"
#include "Jugador.h"

CControladora::CControladora() {
	cancha = new CCancha();
	cancha->DefinirCancha();     // Asegúrate de definir la cancha primero
	cancha->Inicializar();       // Inicializa las paredes y otros bloques

	Point pos = cancha->GetPosicionAleatoriaLibre();
	jugador = new CJugador(pos.X, pos.Y);
	//jugador = new CJugador(ANCHOIMAGEN, ALTOIMAGEN);
}

void CControladora::DibujarCancha() {
	cancha->Inicializar();
};

void CControladora::Dibujar(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible) {
	cancha->PintarCancha(g, bmpPiso);
	cancha->PintarMatriz(g, bmpIrrompible, bmpRrompible);
};

void CControladora::DibujarJugador(Graphics^ g, Bitmap^ bmpJugador) {
	jugador->Dibujar(g, bmpJugador);
}

void CControladora::MoverJugador(Graphics^ g, Bitmap^ bmpJugador) {
	jugador->Mover(g, bmpJugador);
}

CJugador* CControladora::getJugador() {
	return jugador;
}
