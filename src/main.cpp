#include "bmpReadClass.h"

using namespace std;
int main(){
  char ruta[] = "../rsc/testImages.idx3-ubyte";
  imagen prueba(ruta); //Creación del objeto prueba
  prueba.header(); //Se imprime el header
  
//Lee 10 imagenes
  for (int n = 0; n < 10; n++) {
    prueba.read_img(n);
    //Imprime las imagenes
    for (int i = 0; i < 28; i++) {
      for (int j = 0; j < 28; j++) {
        cout<<prueba.data[i][j]<<" ";
      }
      cout<<endl;
    }

  }


  system("pause");
  return 0;
}
