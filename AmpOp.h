#ifndef AMPOPH
#define AMPOPH
#define AMPOPTYPE       8
#include "Elemento.h"


class AmpOp : public Elemento {
  public :
      AmpOp(int A, int B , int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      int indiceCorrente;
};

#endif
