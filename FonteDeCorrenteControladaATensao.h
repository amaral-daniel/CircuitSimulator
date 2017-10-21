#ifndef FONTEDECORRENTECONTROLADAATENSAOH
#define FONTEDECORRENTECONTROLADAATENSAOH
#define FONTEDECORRENTECONTROLADAATENSAOTYPE       4
#include "Elemento.h"

//TEM QUE TESTAR A ESTAMPA
class FonteDeCorrenteControladaATensao : public Elemento {
  public :
      FonteDeCorrenteControladaATensao(double v,int A, int B, int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double transCondutancia;

};

#endif
