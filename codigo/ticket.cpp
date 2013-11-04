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

Lista<Ticket> filtrarUsados(Lista<Ticket> &ts);
int cuentaPelis(Lista<Pelicula> &ps, Pelicula p);
Lista<Pelicula> peliculasT(const Lista<Ticket> &ts);

Pelicula peliculaMenosVistaT(const Lista<Ticket> &ts) const {
	Pelicula res;
	Lista<int> cuentas;
	int i = 0;
	while (i < ts.longitud()) {
		cuentas.agregar(cuentaPelis(ts.filtrarUsados().peliculasT().iesimo(i),ts.filtrarUsados().peliculasT()));
		i++;
	}
	int i = 0;
	while (i < ts.longitud()) {
		if (cuentas.iesimo(i) >= cuentas.iesimo(i+1)) {
			cuentas.sacar(cuentas.iesimo(i+1));
		}
		else {
			cuentas.sacar(cuentas.iesimo(i))
		}
		i++;
	}
	int i = 0;
	int maximo = cuentas.head();
	while (i < ts.longitud()) {
		if (maximo == cuentaPelis(ts.filtrarUsados().peliculasT().iesimo(i),ts.filtrarUsados().peliculasT())) {
			res = ts.filtrarUsados().peliculasT().iesimo(i);
		}
		i++;
	}
	return res;
}				

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
	while (i < ts.longitud()) {
		res.agregar(ts.iesimo(i).peliculaT());
		i++;
	}
	return res;
}

bool todosLosTicketsParaLaMismaSalaT(const Lista<Ticket> &ts) const {
	bool res = true;
	int i = 0;
	while (res && i < ts.longitud()) {
		if (ts.head().salaT() != ts.iesimo(i).salaT()) {
			res = false;
		}
		i++;
	}
	return res;
}

Lista<Ticket> cambiarSalaT(const Lista<Ticket> &ts, Sala vieja, Sala nueva) const {
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
