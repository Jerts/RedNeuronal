#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct imagenes{
  unsigned int magic_number;
  unsigned int img_num;
  unsigned int row_num;
  unsigned int col_num;
};


int main(){
  struct imagenes imagen;
  FILE *dataSet;
  char nombre[]="../rsc/test";
  if((dataSet = fopen(nombre,"rb")) !=NULL ){
    cout<<"Archivo encontrado"<<endl;
    fread(&imagen, sizeof(unsigned int), 4,dataSet);
    cout<<imagen.magic_number<<endl;
    cout<<imagen.img_num<<endl;
    cout<<imagen.row_num<<endl;
    cout<<imagen.col_num<<endl;
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
  system("PAUSE");
  return 0;
}
