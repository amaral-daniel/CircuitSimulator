#ifndef CHAVEH
#define CHAVEH
#define CHAVETYPE       16
#include "Elemento.h"


class Chave : public Elemento {
  public :
      Chave(double Vlim,int A, int B, int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior, bool primeiro);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      int indiceCorrente;
      bool aberto;
      double vlim;
};

#endif
