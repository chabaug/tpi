
#ifndef TICKET_H_
#define TICKET_H_

#include "lista.h"
#include "pelicula.h"
#include "tipos.h"

class Ticket {
 public:
  Ticket(){}
  Ticket(const Pelicula &p, Sala s, bool u);
  const Pelicula &peliculaT() const;
  Sala salaT() const;
  bool usadoT() const;
  void usarT();
  Pelicula peliculaMenosVistaT(const Lista<Ticket> &ts) ;
  bool todosLosTicketsParaLaMismaSalaT(const Lista<Ticket> &ts) const;
  Lista<Ticket> cambiarSalaT(const Lista<Ticket> &ts, Sala vieja, Sala nueva) const;
  // ingresarASalaC esta en cine.cpp
  //Ticket ingresarASalaC(Sala s, const Ticket &t);  
  Lista<Ticket> filtrarUsados(const Lista<Ticket> &ts) ;
  int cuentaPelis(Lista<Pelicula> &ps, Pelicula p);
  Lista<Pelicula> peliculasT(const Lista<Ticket> &ts);

  bool operator==(const Ticket &otro) const {
    return pelicula_ == otro.pelicula_ && sala_ == otro.sala_ && usado_ == otro.usado_;
  }

  void mostrar(std::ostream& os) const;
  void guardar(std::ostream& os) const;
  void cargar (std::istream& is);

 private:
  Pelicula pelicula_;
  Sala sala_;
  bool usado_;

};

std::ostream & operator<<(std::ostream & os,const Ticket & t);
std::istream & operator>>(std::istream & is, Ticket & t);


#endif // TICKET_H_
