#ifndef TRANSFORMADORH
#define TRANSFORMADORH
#define TRANSFORMADORTYPE       14
#include "Elemento.h"

class Transformador : public Elemento {
  public :
      Transformador(double n,int A, int B, int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double N;
      int indiceCorrente;

};

#endif
