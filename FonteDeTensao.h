#ifndef FONTEDETENSAOH
#define FONTEDETENSAOH
#define FONTEDETENSAOTYPE       3
#include "Elemento.h"


class FonteDeTensao : public Elemento {
  public :
      FonteDeTensao(double v,int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double tensao;
      int indiceCorrente;
};

#endif
