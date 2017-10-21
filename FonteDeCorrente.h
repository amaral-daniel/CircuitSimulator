#ifndef FONTEDECORRENTEH
#define FONTEDECORRENTEH
#define FONTEDECORRENTETYPE       2
#include "Elemento.h"


class FonteDeCorrente : public Elemento {
  public :
      FonteDeCorrente(double r,int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double corrente;
};

#endif
