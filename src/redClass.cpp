#include "redClass.h"

double NeuNet::sigmoide(double x) {
    return 1.0 / (1.0 + exp(-x));
}
double NeuNet::square_error(){
    double res = 0.0;
    for (int i = 0; i < n3; i++) {
        res += (out3[i] - expected[i]) * (out3[i] - expected[i]);
	}
    res *= 0.5;
    return res;
}
void NeuNet::input(int img[784], double esperados[10]){
  for (int i = 0; i < 784; i++) {
    out1[i]=img[i];
  }
  for (int i = 0; i < 10; i++) {
    expected[i]=esperados[i];
  }
}

void NeuNet::reset(){
  // Initialization for weights from Input layer to Hidden layer
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            int sign = rand() % 2;
            w1[i][j] = (double)(rand() % 6) / 10.0;
            if (sign == 1) {
				          w1[i][j] = - w1[i][j];
			       }
        }
	}

	// Initialization for weights from Hidden layer to Output layer
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n3; j++) {
          int sign = rand() % 2;
          w2[i][j] = (double)(rand() % 10 + 1) / (10.0 * n3);
          if (sign == 1) {
				        w2[i][j] = - w2[i][j];
			    }
        }
	  }

}
void NeuNet::guardarMat(){
  FILE *arch;
  arch = fopen("model-neural-network.dat","wb");
  if (arch != NULL) {
    cout<<"Entro"<<endl;
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        fprintf(arch, "%f ",w1[i][j]);
        //printf("%f ",w1[i][j]);
      }
      fprintf(arch,"\n");
      //printf("\n");
    }

    for (int i = 0; i < n2; i++) {
      for (int j = 0; j < n3; j++) {
        fprintf(arch, "%f ",w2[i][j]);
        //printf("%f ",w1[i][j]);
      }
      fprintf(arch,"\n");
      //printf("\n");
    }
    fclose(arch);
  }

  else{
    cout<<"Problema al guardar los pesos"<<endl;
  }
}

void NeuNet::perceptron(){
  for (int i = 0; i < n2; i++) {
		in2[i] = 0.0;
	}

  for (int i = 0; i < n3; i++) {
		in3[i] = 0.0;
	}

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            in2[j] += out1[i] * w1[i][j];
		}
	}

  for (int i = 0; i < n2; i++) {
		out2[i] = sigmoide(in2[i]);
	}

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n3; j++) {
            in3[j] += out2[i] * w2[i][j];
		}
	}

  for (int i = 0; i < n3; i++) {
		out3[i] = sigmoide(in3[i]);
	}
}

void NeuNet::back_propagation() {
    double sum;

    for (int i = 0; i < n3; i++) {
        theta3[i] = out3[i] * (1 - out3[i]) * (expected[i] - out3[i]);
	}

    for (int i = 0; i < n2; i++) {
        sum = 0.0;
        for (int j = 0; j < n3; j++) {
            sum += w2[i][j] * theta3[j];
		    }
        theta2[i] = out2[i] * (1 - out2[i]) * sum;
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n3; j++) {
            delta2[i][j] = (learning_rate * theta3[j] * out2[i]) + (momentum * delta2[i][j]);
            w2[i][j] += delta2[i][j];
        }
	}

    for (int i = 0; i < n1; i++) {
        for (int j = 0 ; j < n2 ; j++ ) {
            delta1[i][j] = (learning_rate * theta2[j] * out1[i]) + (momentum * delta1[i][j]);
            w1[i][j] += delta1[i][j];
        }
	}
}
int NeuNet::learning_process() {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
			       delta1[i][j] = 0.0;
		    }
	}

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n3; j++) {
			       delta2[i][j] = 0.0;
		    }
	}

    for (int i = 0; i < epochs; i++) {
        perceptron();
        back_propagation();
        if (square_error() < epsilon) {
			       return i;
		   }
    }
    return epochs;
}
void NeuNet::load_model() {
  ifstream file("model-neural-network.dat", ios::in);


    cout<<"Entro"<<endl;
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        file >> w1[i][j];
        //printf("%f ",w1[i][j]);
      }
        //fscanf(arch, "%c ",aux);
      //printf("\n");
    }

    for (int i = 0; i < n2; i++) {
      for (int j = 0; j < n3; j++) {
        file >> w2[i][j];
        //printf("%f ",w1[i][j]);
      }
      //printf("\n");
    }
    file.close();


}
