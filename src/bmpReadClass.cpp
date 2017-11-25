#include "bmpReadClass.h"
void imagen::header() {
  FILE *img;
  char ruta[] = "../rsc/testImages.idx3-ubyte";
  if((img = fopen(ruta,"rb")) !=NULL ){
    cout<<"Archivo encontrado"<<endl;
    fread(&this->magic_number, sizeof(unsigned int), 1,img);
    fread(&this->img_num, sizeof(unsigned int), 1,img);
    fread(&this->row_num, sizeof(unsigned int), 1,img);
    fread(&this->col_num, sizeof(unsigned int), 1,img);
    cout<<this->magic_number<<endl;
    cout<<this->img_num<<endl;
    cout<<this->row_num<<endl;
    cout<<this->col_num<<endl;
    fclose(img);
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
}
