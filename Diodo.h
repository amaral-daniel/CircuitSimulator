#ifndef DIODOH
#define DIODOH
#define DIODOTYPE       15
#include "Elemento.h"


class Diodo : public Elemento {
  public :
      Diodo(int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior, bool primeiro);
      int aumentoVariaveis(int n);
      int quantasCorrentes();

    private:

      int indiceCorrente;
      bool aberto;
};

#endif
