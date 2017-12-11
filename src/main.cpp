#include "bmpReadClass.h"
#include "LabelReadClass.h"
#include "redClass.h"
using namespace std;



int main(){
  system("PAUSE");
  int op;
  char ruta[] = "../rsc/testImages.idx3-ubyte";
  char rutalbl[]="../rsc/t10k-labels.idx1-ubyte";
  NeuNet Net;
  Net.reset();
  imagen IMG(ruta); //Creación del objeto prueba
  Etiqueta LABEL(rutalbl);
  int nCorrect = 0;


    cout<<"1.-Entrenar la red"<<endl;
    cout<<"2.-Probar la red"<<endl;
    cin>>op;
    switch (op) {
      case 1:
            //IMG.header(); //Se imprime el header
            Net.guardarMat();
            //Lee 20 imagenes
            for (int n = 0; n < 4000; n++) {
              IMG.read_img(n);
              LABEL.read_lbl(n);
              Net.input(IMG.dataLineal, LABEL.dataVect);
              //Imprime las imagenes
              /*for (int i = 0; i < 28; i++) {
                for (int j = 0; j < 28; j++) {
                  cout<<IMG.data[i][j]<<" ";
                }
                cout<<endl;
              }*/
              cout<<"Porcentaje: %"<< n*100/2000 <<endl;


              int nIterations = Net.learning_process();
              cout << "No. iterations: " << nIterations << endl;
              printf("Error: %0.6lf\n\n", Net.square_error());
              if (n%100==0) {
                Net.guardarMat();
              }
            }
            break;
      case 2:
            Net.reset();
            Net.load_model(); // Carga los pesos

            for (int n = 0; n < 200; n++) {
                cout << "Ejemplo " << n << endl;

                // Lee la imagen y la etiqueta
                IMG.read_img(n);
                LABEL.read_lbl(n);
                Net.input(IMG.dataLineal, LABEL.dataVect);

                // Calcula las salidas
                Net.perceptron();

                // Prediction
                int predict = 0;
                for (int i = 0; i < 10; i++) {
                    cout<<Net.out3[i]<<" ";
                    if (Net.out3[i] > Net.out3[predict]) {
                      predict = i;
                    }
                    cout<<endl;
                }

                // Write down the classification result and the squared error
                double error = Net.square_error();
                printf("Error: %0.6lf\n", error);

                if (LABEL.data == predict) {
                  nCorrect++;
                  cout << "Classification: YES. Label = " << LABEL.data << ". Predict = " << predict << endl << endl;
                  for (int i = 0; i < 28; i++) {
                    for (int j = 0; j < 28; j++) {
                      cout<<IMG.data[i][j]<<" ";
                    }
                    cout<<endl;
                  }

                }
                else {
                  cout << "Classification: NO.  Label = " << LABEL.data << ". Predict = " << predict << endl;
                  cout << "Image:" << endl;
                  for (int i = 0; i < 28; i++) {
                    for (int j = 0; j < 28; j++) {
                      cout<<IMG.data[i][j]<<" ";
                    }
                    cout<<endl;
                  }
                  cout << endl;

                }
            }
            cout<<"Valores correctos "<<nCorrect<<" de 200 imagenes"<<endl;
            break;
      default :
        cout<<"Valor fuera de rango"<<endl;
    }


  system("pause");
  return 0;
}
