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

bool esta(Genero g, Lista<Genero> gs);
Lista<Pelicula> pelisDelGenero(Lista<Pelicula> ps, Genero g);

Lista<std::pair<Genero,Lista<Pelicula> > > Pelicula::agruparPelisPorGeneroP(Lista<Pelicula> ps) const {
		Lista<std::pair<Genero,Lista<Pelicula> > > res;
		res.agregar(make_pair(Aventura,pelisDelGenero(ps,Aventura)));
		res.agregar(make_pair(Comedia,pelisDelGenero(ps,Comedia)));
		res.agregar(make_pair(Drama,pelisDelGenero(ps,Drama)));
		res.agregar(make_pair(Romantica,pelisDelGenero(ps,Romantica)));
		res.agregar(make_pair(Terror,pelisDelGenero(ps,Terror)));
		return res;
}	
	
Lista<Pelicula> pelisDelGenero(Lista<Pelicula> ps, Genero g) {
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

bool esta(Genero g, Lista<Genero> gs) {
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

Lista<Pelicula> generarSagaDePeliculasP(Lista<Actor> as, Lista<Genero> gs, Lista<Nombre> nombres) const {
	Lista<Pelicula> res;
	int i = 0;
	while (i < nombres.longitud()) {
		res.agregar(Pelicula(nombres.iesimo(i), gs, as, false));
		i++;
	}
	return res;
}

 
