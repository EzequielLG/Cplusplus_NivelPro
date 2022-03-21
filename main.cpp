// Autor: LozanoSoft

#include "Libro.h"

int main(){

  Libro miLibro(100);

  // Escribir el contenido de las páginas

  cout << miLibro.escribirContenido(19, "Cuento", "Este es un cuento.") << endl;
  cout << miLibro.escribirContenido(560, "Leyenda", "Esta es una leyenda.") << endl;
  cout << miLibro.escribirContenido(10, "Fábula", "Esta es una fábula.") << "\n" << endl;

  // Leer el contenido de las páginas

  cout << miLibro.leerPagina(10) << endl;
  cout << miLibro.leerPagina(199) << endl;
  cout << miLibro.leerPagina(56) << "\n" << endl;

  miLibro.lecturaCompleta(miLibro.getPortada()); // Lectura de todo el libro
  return 0; // Fin del programa

}
