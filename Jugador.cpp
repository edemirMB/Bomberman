#include "Jugador.h"

CJugador::CJugador() {};

CJugador::~CJugador() {};

CJugador::CJugador(int x, int y) {
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	ultimaTecla = EDireccion::Abajo;
	direccion = EDireccion::Ninguna;
	indiceX = 0;
	indiceY = 2;
  for (int i = 0; i < HABILIDADES; i++) {
    habilidades[i] = false;
  }    
}

void CJugador::setDireccion(EDireccion direccion) {
  this->direccion = direccion;
}

void CJugador::Dibujar(Graphics^ g, Bitmap^ bmpJugador) {
	 Rectangle rectangulo = Rectangle(indiceX * ANCHO, indiceY * ALTO, ANCHO, ALTO);
	 Rectangle zoom = Rectangle(x, y, ANCHO * FACTORZOOM, ALTO * FACTORZOOM);
   g->DrawImage(bmpJugador, zoom, rectangulo, GraphicsUnit::Pixel);
	 x += dx;
	 y += dy;
}

void CJugador::Mover(Graphics^ g, Bitmap^ bmpJugador) {
  switch (direccion) {
    case EDireccion::Arriba:
      indiceY = 0;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 0;
      dy = -10;
      ultimaTecla = EDireccion::Arriba;
      break;
    case EDireccion::Abajo:
      indiceY = 2;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 0;
      dy = 10;
      ultimaTecla = EDireccion::Abajo;
      break;
    case EDireccion::Izquierda:
      indiceY = 3;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = -10;
      dy = 0;
      ultimaTecla = EDireccion::Izquierda;
      break;
    case EDireccion::Derecha:
      indiceY = 1;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 10;
      dy = 0;
      ultimaTecla = EDireccion::Derecha;
      break;
    case EDireccion::Ninguna:
      dx = 0;
      dy = 0;
      switch (ultimaTecla) {
        case EDireccion::Abajo:
          indiceX = 0;
          indiceY = 2;
          break;
        case EDireccion::Arriba:
          indiceX = 0;
          indiceY = 0;
          break;
        case EDireccion::Izquierda:
          indiceX = 1;                /* PRACTICA_1EJERCICIO2*/
          indiceY = 3;
          break;        
        case EDireccion::Derecha:
          indiceX = 0;
          indiceY = 1;
          break;
      }
      break;      
  }

  Dibujar(g, bmpJugador);
}
