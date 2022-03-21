// Autor: LozanoSoft

#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Pagina{

  int numeroFolio;
  string tipoPagina;
  string contenido;
  struct Pagina *siguientePagina;

};

class Libro{

  private:
    struct Pagina *portada = NULL;

  public:

    explicit Libro(int numeroPaginas){

      for(int i = 0; i < numeroPaginas; i++){

        struct Pagina *nuevaPagina = new Pagina;

        nuevaPagina -> numeroFolio = i + 1;
        nuevaPagina -> tipoPagina = "Sin categoría";
        nuevaPagina -> contenido = "Esta página está vacía";
        nuevaPagina -> siguientePagina = NULL;

        if(portada == NULL){
          portada = nuevaPagina;
        }
        else{

          struct Pagina *paginaTmp = portada;

          while((paginaTmp -> siguientePagina) != NULL){
            paginaTmp = paginaTmp -> siguientePagina;
          }

          paginaTmp -> siguientePagina = nuevaPagina;

        }

      }

    }

    Pagina *buscarPagina(int folioPagina){

      struct Pagina *paginaBusqueda = portada;

      if(paginaBusqueda != NULL){

        while(paginaBusqueda != NULL && (paginaBusqueda -> numeroFolio) != folioPagina){
          paginaBusqueda = paginaBusqueda -> siguientePagina;
        }

      }

      return paginaBusqueda;

    }

    string escribirContenido(int folioPagina, string tipoPagina, string contenido){

      try{

        struct Pagina *paginaTmp = buscarPagina(folioPagina);

        if(paginaTmp == NULL){
          throw -1;
        }
        else{

          paginaTmp -> tipoPagina = tipoPagina;
          paginaTmp -> contenido = contenido;

          return "Página agregada exitosamente.";

        }

      }
      catch(int e){
        return "Hubo un error :c";
      }

    }

    string leerPagina(int folioPagina){

      try{

        Pagina *paginaTmp = buscarPagina(folioPagina);

        if(paginaTmp == NULL){
          throw -1;
        }
        else{
          return paginaTmp -> contenido;
        }

      }
      catch(int e){
        return "No existe la página seleccionada.";
  		}

    }

    Pagina *getPortada(){
      return portada;
    }

    void lecturaCompleta(Pagina *paginaTmp){

      if(paginaTmp != NULL){

        cout << "Folio: " << paginaTmp -> numeroFolio << "\nTipo de página: " << paginaTmp -> tipoPagina << "\nContenido: " << paginaTmp -> contenido << "\n" << endl;
        lecturaCompleta(paginaTmp -> siguientePagina);

      }

    }

};

#endif
