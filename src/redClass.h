
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;

#ifndef _REDCLASS_H_INCLUDED_
#define _REDCLASS_H_INCLUDED_
class NeuNet {
private:
    // Pesos
  constexpr static char model_fn[] = "model-neural-network.dat";

  // Reporte
  constexpr static char report_fn[] = "training-report.dat";

  // Número de imagenes de entrenamiento
  const static int nTraining = 60000;

  // n1 = Numero de neuronas de entrada
  // n2 = Número de neuronas de la capa oculta
  // n3 = Número de neuronas de salida
  // epochs = Número de iteraciones para el backpropagation
  // learning_rate = Ratio de aprendizaje
  // momentum = Momentum
  // epsilon = Establece el mínimo error permitido

  const static int n1 = 784; // = 784, without bias neuron
  const static int n2 = 128;
  const static int n3 = 10; // Ten classes: 0 - 9
  const static int epochs = 512;
  constexpr static double learning_rate = 1e-3;
  constexpr static double momentum = 0.9;
  constexpr static double epsilon = 1e-3;



public:
  void reset();
  void guardarMat();
  void perceptron();
  double square_error();
  double sigmoide(double x);
  void input(int img[784], double esperados[10]);
  void back_propagation();
  int learning_process();
  void load_model();

  //  Capa de entrada - Capa oculta
  double  w1[n1][n2], delta1[n1][n2], out1[n1];

  // Capa oculta - capa de salida
  double w2[n2][n3], delta2[n2][n3], in2[n2], out2[n2], theta2[n2];

  // Capa de salida
  double in3[n3], out3[n3], theta3[n3];
  double expected[n3];

  int soloUnNumeroRandom;

};
#endif
