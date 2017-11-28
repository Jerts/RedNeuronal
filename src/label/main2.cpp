#include "labelReadClass.h"


using namespace std;
int main(){
  char ruta[] = "../rsc/t10k-labels.idx1-ubyte";
  Etiqueta prueba(ruta); //Creación del objeto prueba
  prueba.header(); //Se imprime el header

//Lee 10 imagenes
  for (int n = 0; n < 10; n++) {
    prueba.read_lbl(n);
    
  }
      cout<<endl;
  system("PAUSE");
  return 0;
}
