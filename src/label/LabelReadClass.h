#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

#ifndef _LABEL_H_INCLUDED_
#define _LABEL_H_INCLUDED_

class Etiqueta {
private:
  unsigned int magic_number;
  unsigned int lbl_num;
  char *ruta; //Guarda el puntero a la cadena que indica la ruta del archivo
  int current_index=0;

public:
  FILE *lbl;  //Puntero al archivo
  char dataAux;

  int data[1];
  void header(); //Imprime el header del archivo
  void read_lbl(int index); //Lee la imagen con indice: index
  Etiqueta(char *nombre); //Constructor, recibe el apuntador al archivo

};

#endif

