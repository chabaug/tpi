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
	while (i < filtrarUsados(ts).longitud()) {
		cuentas.agregarAtras(cuentaPelis(vistas, vistas.iesimo(i)));
		i++;
	}
	i = 1;
	int min = cuentas.cabeza();
	int indice = 1;
	while (i < filtrarUsados(ts).longitud()) {
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
		res.agregarAtras(ts.iesimo(i).peliculaT());
		i++;
	}
	return res;
}


bool Ticket::todosLosTicketsParaLaMismaSalaT(const Lista<Ticket> &ts) const {
	bool res = true;
	int i = 1;
	while (res && i < ts.longitud()) {
		res = (ts.cabeza().salaT() == ts.iesimo(i).salaT());
		i++;
	}
	return res;
}

// Pc: i == 0 && res == []
// Qc: i == ts.longitud() &&
// B: (i < ts.longitud());

Lista<Ticket> Ticket::cambiarSalaT(const Lista<Ticket> &ts, Sala vieja, Sala nueva) const {
	// modifica ts;
	// estado a; 
	// vale Pc;
	Lista<Ticket> res;
	int i = 0;
	while (i < ts.longitud()) {
		// estado b;
		// invariante I: 0 <= i <= ts.longitud();
		// vale B && I;
		if (ts.iesimo(i).salaT() == vieja) {
			// vale ts.iesimo(i).salaT() == vieja;
			res.agregarAtras(Ticket(ts.iesimo(i).peliculaT(), nueva, ts.iesimo(i).usadoT()));
		}
		else {
			res.agregarAtras(ts.iesimo(i));
		}
		i++;
		// vale I; vale i == i@b + 1; 
	}
	// vale (I && ¬B); implica Qc
	return res;
}
	
void Ticket::mostrar(std::ostream& os) const {
	os<< "T (" ;
	this->peliculaT().mostrar(os);
	os<< ") " << this->salaT() << " ";
	if (this->usadoT()) {
		os<< "V" << endl;
	}
	else {
		os<< "F" << endl;
	}
}	

void Ticket::guardar(std::ostream& os) const {
	os<< "T (";
	this->peliculaT().guardar(os);
	os<< ") " << this->salaT() << " ";
	if (this->usadoT()) {
		os<< "V" << endl;
	}
	else {
		os<< "F" << endl;
	}
}

void Ticket::cargar (std::istream& is) {
	char c;
	is>> c;
	is>> c;
	Pelicula p;
	p.cargar(is);
	is>> c;
	int s;
	is>> s;
	bool b;
	is>> c;
	if (c == 'V') {
		b = true;
	}
	else {
		b = false;
	}
	pelicula_ = p;
	sala_ = s;
	usado_ = b;
}
	
	
	
	
	
	
	
	
	
	
		
		
