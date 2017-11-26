
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#ifndef _BMPREADCLASS_H_INCLUDED_
#define _BMPREADCLASS_H_INCLUDED_

class imagen {
private:
  unsigned int magic_number;
  unsigned int img_num;
  unsigned int row_num;
  unsigned int col_num;
  char *ruta; //Guarda el puntero a la cadena que indica la ruta del archivo
  int current_index=0;

public:
  FILE *img;  //Puntero al archivo
  char dataAux;
  int data[28][28]; //Contiene la imagen en 1's y 0's
  void header(); //Imprime el header del archivo
  void read_img(int index); //Le la imagen con indice: index
  imagen(char *nombre); //Constructor, recibe el apuntador al archivo
};

#endif
