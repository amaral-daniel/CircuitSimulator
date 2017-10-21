#ifndef FONTEDECORRENTECONTROLADAACORRENTEH
#define FONTEDECORRENTECONTROLADAACORRENTEH
#define FONTEDECORRENTECONTROLADAACORRENTETYPE       3
#include "Elemento.h"


class FonteDeCorrenteControladaACorrente : public Elemento {
  public :
      FonteDeCorrenteControladaACorrente(double v,int A, int B, int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double F;
      int indiceCorrente;
};

#endif
