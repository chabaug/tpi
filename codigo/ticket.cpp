#include "ticket.h"

Ticket::Ticket(const Pelicula &p, Sala s, bool u){
	pelicula_ = p;
	sala_ = s;
	usado_ = u;
}

const Pelicula & Ticket::peliculaT() const {
	return pelicula_;
}

Sala Ticket::salaT() const {
	return sala_;
}

bool Ticket::usadoT() const {
	return usado_;
}

void Ticket::usarT() {
	usado_ = true;
}
	
Pelicula peliculaMenosVistaT(const Lista<Ticket> &ts) const {
	
	

Lista<Ticket> filtrarUsados(Lista<Ticket> &ts) {
	Lista<Ticket> res;
	int i = 0;
	while (i < ts.longitud()) {
		if (ts.iesimo(i).usadoT()) {
			res.agregar(ts.iesimo(i));
		}
		i++;
	}
	return res;
}

int cuentaPelis(Lista<Pelicula> &ps, Pelicula p) {
	int res = 0;
	int i = 0;
	while (i < ps.longitud()) {
		if (p == ps.iesimo(i)) {
			res++;
		}
		i++;
	}
	return res;
}

Lista<Pelicula> peliculasT(const Lista<Ticket> &ts) {
	Lista<Pelicula> res;
	
	int i = 0;
