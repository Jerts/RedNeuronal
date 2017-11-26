#include "bmpReadClass.h"
//Constructor
imagen::imagen(char *nombre){
  cout<<nombre<<endl;
  ruta=nombre;
}

//Función sin terminar, falta voltear los bytes
void imagen::header() {
  if((this->img = fopen(this->ruta,"rb")) !=NULL ){
    cout<<"Archivo encontrado"<<endl;
    fread(&magic_number, sizeof(unsigned int), 1,img);
    fread(&img_num, sizeof(unsigned int), 1,img);
    fread(&row_num, sizeof(unsigned int), 1,img);
    fread(&col_num, sizeof(unsigned int), 1,img);
    cout<<magic_number<<endl;
    cout<<img_num<<endl;
    cout<<row_num<<endl;
    cout<<col_num<<endl;
    fclose(img);
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
}

//Lee la cantidad index de imagenes desde el archivo indicado
void imagen::read_img(int index){
  current_index=16+(index*784);           //Inicia en el byte 16 empezando a contar desde la imagen 0
  if((img = fopen(ruta,"rb")) !=NULL ){
    fseek(img,current_index,SEEK_SET);    //Posiciona el puntero del archivo en la posición current_index
    int num=ftell(img);
    cout<<"Archivo encontrado index: "<<current_index<<"Posicion: "<<num<<endl;

    for (int i = 0; i < 28; i++) {
      for (int j = 0; j < 28; j++) {
        fread(&dataAux,1,1,img); //Lee byte a byte el archivo desde current_index
        if(dataAux){
          data[i][j]=1;       //Si el byte es distinto de 0 guarda un 1
        }else{
          data[i][j]=0;
        }
      }
    }

    fclose(img);
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
}
