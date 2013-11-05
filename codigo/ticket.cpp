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

Pelicula Ticket::peliculaMenosVistaT(const Lista<Ticket> &ts)  {
	Lista<Pelicula> vistas = peliculasT(filtrarUsados(ts));
	Lista<int> cuentas;
	int i = 0;
	while (i < ts.longitud()) {
		cuentas.agregarAtras(cuentaPelis(vistas, vistas.iesimo(i)));
		i++;
	}
	i = 1;
	int min = cuentas.cabeza();
	int indice = 1;
	while (i < ts.longitud()) {
		if (cuentas.iesimo(i) < min) {
			min = cuentas.iesimo(i);
			indice = i;
		}
		i++;
	}
	return vistas.iesimo(i);
}				

Lista<Ticket> Ticket::filtrarUsados(const Lista<Ticket> &ts) {
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

int Ticket::cuentaPelis(Lista<Pelicula> &ps, Pelicula p) {
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

Lista<Pelicula> Ticket::peliculasT(const Lista<Ticket> &ts) {
	Lista<Pelicula> res;
	int i = 0;
	while (i < ts.longitud()) {
		res.agregar(ts.iesimo(i).peliculaT());
		i++;
	}
	return res;
}

bool Ticket::todosLosTicketsParaLaMismaSalaT(const Lista<Ticket> &ts) const {
	bool res = true;
	int i = 0;
	while (res && i < ts.longitud()) {
		if (ts.cabeza().salaT() != ts.iesimo(i).salaT()) {
			res = false;
		}
		i++;
	}
	return res;
}

Lista<Ticket> Ticket::cambiarSalaT(const Lista<Ticket> &ts, Sala vieja, Sala nueva) const {
	Lista<Ticket> res;
	int i = ts.longitud() - 1;
	while (i >= 0) {
		if (ts.iesimo(i).salaT() == vieja) {
			res.agregar(Ticket(ts.iesimo(i).peliculaT(), nueva, ts.iesimo(i).usadoT()));
		}
		else {
			res.agregar(ts.iesimo(i));
		}
		i = i - 1;
	}
	return  res;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
