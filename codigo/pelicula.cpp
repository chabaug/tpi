#include "pelicula.h"


Pelicula::Pelicula(Nombre n, Lista<Genero> gs, Lista<Actor> as, bool b){
	nombre_ = n;
	generos_ = gs;
	actores_ = as;
	es3D_ = b;
}

string Pelicula::nombreP() const {
	return nombre_;
}

Lista<Genero> Pelicula::generosP() const {
	return generos_;
}
	
Lista<Actor> Pelicula::actoresP() const {
	return actores_;
}

bool Pelicula::es3DP() const {
	return es3D_;
}

Lista<std::pair<Genero,Lista<Pelicula> > > Pelicula::agruparPelisPorGeneroP(Lista<Pelicula> ps) const {
	Lista<std::pair<Genero,Lista<Pelicula> > > res;
	res.agregar(make_pair(Aventura,pelisDelGenero(ps,Aventura)));
	res.agregar(make_pair(Comedia,pelisDelGenero(ps,Comedia)));
	res.agregar(make_pair(Drama,pelisDelGenero(ps,Drama)));
	res.agregar(make_pair(Romantica,pelisDelGenero(ps,Romantica)));
	res.agregar(make_pair(Terror,pelisDelGenero(ps,Terror)));
	return res;
}	
	
Lista<Pelicula> Pelicula::pelisDelGenero(Lista<Pelicula> ps, Genero g) const {
	Lista<Pelicula> res;
	int i = 0;
	while (i < ps.longitud()){
		if (esta (g, ps.iesimo(i).generosP())) {
			res.agregar(ps.iesimo(i));
		}
		i++;
	}
	return res;
}

bool Pelicula::esta(Genero g, Lista<Genero> gs) const {
	int i = 0;
	bool encontre = false;
	while (!encontre && i < gs.longitud()) {
		if (g == gs.iesimo(i)) {
			encontre = true;
		}
		i++;
	}
	return encontre;
}

Lista<Pelicula> Pelicula::generarSagaDePeliculasP(Lista<Actor> as, Lista<Genero> gs, Lista<Nombre> nombres) const {
	Lista<Pelicula> res;
	int i = 0;
	while (i < nombres.longitud()) {
		res.agregar(Pelicula(nombres.iesimo(i), gs, as, false));
		i++;
	}
	return res;
}

void Pelicula::mostrar(std::ostream& os) const {
	os<< "P |" << this->nombreP() << "| [";
	int i = 0;
	while (i < this->generosP().longitud()) {
		os<< "|" << this->generosP().iesimo(i) << "|";
		if (i != this->generosP().longitud() - 1) {
			os<< ", ";
		}
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < this->actoresP().longitud()) {
		os<< "|" << this->actoresP().iesimo(i) << "|";
		if (i != this->actoresP().longitud() - 1) {
			os<< ", ";
		}
		i++;
	}
	os<< "] ";
	if (this->es3DP()) {
		os<< "V" << endl;
	}
	else {
		os<< "F" << endl;
	}
}	 
	 
void Pelicula::guardar(std::ostream& os) const {
	os<< "P |" << this->nombreP() << "| [";
	int i = 0;
	while (i < this->generosP().longitud()) {
		os<< "|" << this->generosP().iesimo(i) << "|";
		if (i != this->generosP().longitud() - 1) {
			os<< ", ";
		}
		i++;
	}
	os<< "] [";
	i = 0;
	while (i < this->actoresP().longitud()) {
		os<< "|" << this->actoresP().iesimo(i) << "|";
		if (i != this->actoresP().longitud() - 1) {
			os<< ", ";
		}
		i++;
	}
	os<< "] ";
	if (this->es3DP()) {
		os<< "V" << endl;
	}
	else {
		os<< "F" << endl;
	}
}
			
void Pelicula::cargar (std::istream& is) {
	char c;
	is>> c;
	is>> c;
	string nombre;
	getline(is, nombre, '|');
	is>> c;
	Lista<Genero> generos;
	string g;
	while (c != ']') {
		is>> c;
		getline(is, g, '|');
		is>> c;
		if (g == "Aventura") {
			generos.agregarAtras(Aventura);
		}
		else {
			if (g == "Comedia") {
				generos.agregarAtras(Comedia);
			}
			else {
				if (g == "Drama") {
					generos.agregarAtras(Drama);
				}
				else {
					if (g == "Romantica") {
						generos.agregarAtras(Romantica);
					}
					else {
						generos.agregarAtras(Terror);
					}
				}
			}
		}
	}
	is>> c;
	Lista<Actor> actores;
	Actor a;
	while (c != ']') {
		is>> c;
		getline(is, a, '|');
		is>> c;
		actores.agregarAtras(a);
	}
	is>> c;
	bool b;
	if (c == 'V') {
		b = true;
	}
	else {
		b = false;
	}
	nombre_ = nombre;
	generos_ = generos;
	actores_ = actores;
	es3D_ = b;
}
	
  
  
  
  
  
