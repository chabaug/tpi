#include "cine.h"

string Cine::nombreC() const {
	return nombre_;
}

Lista<Pelicula> Cine::peliculasC() const {
	Lista<Pelicula> res;
	int i = 0;
	while (i < peliculas_.longitud()) {
		res.agregarAtras(peliculas_.iesimo(i).first);
		i++;
	}
	return res;
}  

Lista<Sala> Cine::salasC() const {
	Lista<Sala> res;
	int i = 0;
	while (i < peliculas_.longitud()) {
		res.agregarAtras(peliculas_.iesimo(i).second);
		i++;
	}
	return res;
}

Sala Cine::salaC(const Nombre &p) const {
	Sala res;
	int i = 0;
	while (i < peliculas_.longitud()) {
		if (peliculas_.iesimo(i).first.nombreP() == p) {
			res = peliculas_.iesimo(i).second;
		}
		i++;
	}
	return res;
}
		
int Cine::espectadoresC(Sala s) const {
	int res;
	int i = 0;
	while (i < espectadores_.longitud()) {
		if (s == espectadores_.iesimo(i).first) {
			res = espectadores_.iesimo(i).second;
		}
		i++;
	}
	return res;
}

Lista<Ticket> Cine::ticketsVendidosSinUsarC() const {
	return ticketsVendidos_;
}

void Cine::abrirSalaC(Sala s) {
	salasSinUsar_.agregarAtras(s);
}

void Cine::agregarPeliculaC(const Pelicula &c, Sala s) {
	peliculas_.agregarAtras(make_pair(c,s));
}
