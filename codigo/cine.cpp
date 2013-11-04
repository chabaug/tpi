#include "cine.h"

Cine::Cine(Nombre n) {
	nombre_ = n;
}

string Cine::nombreC() const {
	return nombre_;
}

Lista<Pelicula> Cine::peliculasC() const {
	return peliculas_;
}

Lista<Sala> Cine::salasC() const {
	return salasSinUsar_;
}

Sala salaC(const Nombre &p) const;
 
int Cine::espectadoresC(Sala s) const {
	return espectadores_;
}

Lista<Ticket> Cine::ticketsVendidosSinUsarC() const {
	return ticketsVendidos_;
}

void abrirSalaC(Sala s) {
	



