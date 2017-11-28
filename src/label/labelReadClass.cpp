#include "LabelReadClass.h"

//Constructor
Etiqueta::Etiqueta(char *nombre){
  cout<<nombre<<endl;
  ruta=nombre;
}

//Función sin terminar, falta voltear los bytes
void Etiqueta::header() {
  if((this->lbl = fopen(this->ruta,"rb")) !=NULL ){
    cout<<"Archivo encontrado"<<endl;
    fread(&magic_number, sizeof(unsigned int), 1,lbl);
    fread(&lbl_num, sizeof(unsigned int), 1,lbl);
    cout<<magic_number<<endl;
    cout<<lbl_num<<endl;
    fclose(lbl);
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
}

//Lee la cantidad index de imagenes desde el archivo indicado
void Etiqueta::read_lbl(int index){
  current_index=8+(index*1);           //Inicia en el byte 16 empezando a contar desde la imagen 0
  if((lbl = fopen(ruta,"rb")) !=NULL ){
    fseek(lbl,current_index,SEEK_SET);    //Posiciona el puntero del archivo en la posición current_index
    int num=ftell(lbl);
    cout<<"Archivo encontrado index: "<<current_index<<" Posicion: "<<num<<endl;
    
    fread(&dataAux,1,1,lbl);

   
   data=(int)(*(unsigned char*)(&dataAux));
    cout<<data<<endl;
    fclose(lbl);
  }

  else{
    cout<<"Archivo no encontrado"<<endl;
  }
}
