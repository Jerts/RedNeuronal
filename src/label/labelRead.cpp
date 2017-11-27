#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Etiquetas{
  unsigned int magic_number;
  unsigned int lbl_num;
};


int main(){
  struct Etiquetas label;
  FILE *dataSet;
  char nombre[]="../rsc/test";
  if((dataSet = fopen(nombre,"rb")) !=NULL ){
    cout<<"Archivo encontrado"<<endl;
    fread(&label, sizeof(unsigned int), 4,dataSet);
    cout<<label.magic_number<<endl;
    cout<<label.lbl_num<<endl;

  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
  system("PAUSE");
  return 0;
}
