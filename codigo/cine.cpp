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
	while (i < espectadores_.longitud()) {
		res.agregarAtras(espectadores_.iesimo(i).first);
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

void Cine::cerrarSalaC(Sala s) {
	int i = 0;
	while (i < salasSinUsar_.longitud()) {
		if (s == salasSinUsar_.iesimo(i))
			salasSinUsar_.sacar(salasSinUsar_.iesimo(i));
		i++;
	}
	i = 0;
	while (i < espectadores_.longitud()) {
		if (s == espectadores_.iesimo(i).first)
			espectadores_.sacar(espectadores_.iesimo(i));
		i++;
	}
	i = 0;
	while (i < peliculas_.longitud()) {
		if (s == peliculas_.iesimo(i).second) 
			peliculas_.sacar(peliculas_.iesimo(i));
		i++;
	}
}
	
void Cine::cerrarSalasC(int e) {
	int i = 0;
	while (i < espectadores_.longitud()) {
		if (e > espectadores_.iesimo(i).second) {
			cerrarSalaC(espectadores_.iesimo(i).first);
			i = i - 1;
		}
		i++;
	}
}
 
//~ void Cine::cerrarSalasDeLaCadenaC(Lista<Cine> &cs, int e) const {
	//~ int i = 0;
	//~ while (i < cs.longitud()) {
		//~ cs.iesimo(i).cerrarSalasC(e);
		//~ i++;
	//~ }
//~ }


Pelicula Cine::peliculaC(Sala s) const {
	int i = 0;
	Pelicula res;
	while (i < peliculas_.longitud()) {
		if (s == peliculas_.iesimo(i).second)
			res = peliculas_.iesimo(i).first;
		i++;
	}
	return res;
}

Ticket Cine::venderTicketC(const Nombre &p) {
	int i = 0;
	Ticket res;
	while (i < peliculas_.longitud()) {
		if (p == peliculas_.iesimo(i).first.nombreP()) {
			res = Ticket(peliculas_.iesimo(i).first, peliculas_.iesimo(i).second, false);
			ticketsVendidos_.agregarAtras(res);
		}
		i++;
	}
	return res;
}

Ticket Cine::ingresarASalaC(Sala s, const Ticket &t) {
	Ticket res = t;
	int i = 0;
	while (i < espectadores_.longitud()) {
		//if (s == espectadores_.iesimo(i).first)
			//espectadores_.iesimo(i) = make_pair(s, espectadores_.iesimo(i).second + 1);
		i++;
	}
	ticketsVendidos_.sacar(t);
	res.usarT();
	return res;
}

Pelicula Cine::pasarA3DUnaPeliculaC(Nombre n) {
	Pelicula res;
	int i = 0;
	while (i < peliculas_.longitud()) {
		if (n == peliculas_.iesimo(i).first.nombreP()) {
			res = hacer3D(peliculas_.iesimo(i).first);
			//peliculas_.iesimo(i) = make_pair(res, salaC(res.nombreP()));
		}
		i++;
	}
	return res;
}

Pelicula Cine::hacer3D(Pelicula p) {
	if (!p.es3DP())
		p = Pelicula(p.nombreP(), p.generosP(), p.actoresP(), true);
	return p;
}
		
void Cine::mostrar(std::ostream& os) const {
	os<< "C |" << this->nombreC() << "| [";
	int i = 0;
	Lista<Sala> salas = this->salasC();
	Lista<Sala> salassinusar = salasSinUsar(salas);
	Lista<Sala> salasusadas = salasUsadas(salas);
	while (i < salassinusar.longitud()) {
		os<< salassinusar.iesimo(i);
		if (i != salassinusar.longitud() - 1) 
			os<< ", ";
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < salas.longitud()) {
		os<< "(" << salas.iesimo(i) << ", " << this->espectadoresC(salas.iesimo(i)) << ")";
		if (i != salas.longitud() - 1)
			os<< ", ";
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < salasusadas.longitud()) {
		os<< "(" << salasusadas.iesimo(i) << ", " << this->ticketsVendidosSinUsarParaLaSala(salasusadas.iesimo(i)).longitud() << ")";
		if (i != salasusadas.longitud() - 1) 
			os<< ", ";
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < this->peliculasC().longitud()) {
		os<< "(" << this->salaC(this->peliculasC().iesimo(i).nombreP()) << ", ";
		this->peliculasC().iesimo(i).mostrar(os);
		os<< ")";
		if (i != this->peliculasC().longitud() - 1) 
			os<< ", ";
		i++;
	}
	os<< "]" << endl;
}


void Cine::guardar(std::ostream& os) const {
	os<< "C |" << this->nombreC() << "| [";
	int i = 0;
	Lista<Sala> salas = this->salasC();
	Lista<Sala> salassinusar = salasSinUsar(salas);
	Lista<Sala> salasusadas = salasUsadas(salas);
	while (i < salassinusar.longitud()) {
		os<< salassinusar.iesimo(i);
		if (i != salassinusar.longitud() - 1) 
			os<< ", ";
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < salas.longitud()) {
		os<< "(" << salas.iesimo(i) << ", " << this->espectadoresC(salas.iesimo(i)) << ")";
		if (i != salas.longitud() - 1)
			os<< ", ";
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < salasusadas.longitud()) {
		os<< "(" << salasusadas.iesimo(i) << ", " << this->ticketsVendidosSinUsarParaLaSala(salasusadas.iesimo(i)).longitud() << ")";
		if (i != salasusadas.longitud() - 1) 
			os<< ", ";
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < this->peliculasC().longitud()) {
		os<< "(" << this->salaC(this->peliculasC().iesimo(i).nombreP()) << ", ";
		this->peliculasC().iesimo(i).guardar(os);
		os<< ")";
		if (i != this->peliculasC().longitud() - 1) 
			os<< ", ";
		i++;
	}
	os<< "]" << endl;
}

Lista<Ticket> Cine::ticketsVendidosSinUsarParaLaSala(Sala s) const {
	Lista<Ticket> res;
	int i = 0;
	while (i < ticketsVendidos_.longitud()) {
		if (s == ticketsVendidos_.iesimo(i).salaT()) {
			res.agregarAtras(ticketsVendidos_.iesimo(i));
		}
		i++;
	}
	return res;
}

void Cine::cargar (std::istream& is) {
	char c;
	is>> c;
	is>> c;
	string nombre;
	getline(is, nombre, '|');
	Lista<Sala> salasSinUsar;
	Sala s;
	is>> c;
	while (c != ']') {
		is>> s;
		salasSinUsar.agregarAtras(s);
		is>> c;
	}
	Lista<pair<Sala, int> > espectadores;
	int e;
	is>> c;
	while (c != ']') {
		is>> c;
		is>> s;
		is>> c;
		is>> e;
		is>> c;
		espectadores.agregarAtras(make_pair(s,e));
		is>> c;
	}
	Lista<Ticket> ticketsVendidos;
	int f;
	is>> c;
	while (c != ']') {
		int i = 1;
		is>> c;
		is>> s;
		is>> c;
		is>> f;
		is>> c;
		while (i <= f) {
			ticketsVendidos.agregarAtras(Ticket(this->peliculaC(s), s, false));
			i++;
		}
		is>> c;
	}
	Lista<pair<Pelicula,Sala> > peliculas;
	Pelicula p;
	is>> c;
	while (c != ']') {
		is>> c;
		is>> s;
		is>> c;
		p.cargar(is);
		peliculas.agregarAtras(make_pair(p,s));
		is>> c;
	}
	nombre_ = nombre;
	salasSinUsar_ = salasSinUsar;
	espectadores_ = espectadores;
	ticketsVendidos_ = ticketsVendidos;
	peliculas_ = peliculas;
}


Lista<Sala> Cine::salasSinUsar(Lista<Sala> s) const{
	Lista<Sala> res;
	int i = 0;
	while (i < s.longitud()) {
		if (!tienePelicula(s.iesimo(i)))
			res.agregarAtras(s.iesimo(i));
		i++;
	}
	return res;
}

Lista<Sala> Cine::salasUsadas(Lista<Sala> s) const{
	Lista<Sala> res;
	int i = 0;
	while (i < s.longitud()) {
		if (tienePelicula(s.iesimo(i)))
			res.agregarAtras(s.iesimo(i));
		i++;
	}
	return res;
}

bool Cine::tienePelicula(Sala s) const{
	int i = 0;
	bool res = false;
	while (!res && i < peliculas_.longitud()) {
		if (s == peliculas_.iesimo(i).second)
			res = true;
		i++;
	}
	return res;
}


