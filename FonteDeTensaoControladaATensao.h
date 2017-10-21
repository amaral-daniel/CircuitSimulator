#ifndef FONTEDETENSAOCONTROLADAATENSAOH
#define FONTEDETENSAOCONTROLADAATENSAOH
#define FONTEDETENSAOCONTROLADAATENSAOTYPE       7
#include "Elemento.h"

//TEM QUE TESTAR ESSA ESTAMPA!!!
class FonteDeTensaoControladaATensao : public Elemento {
  public :
      FonteDeTensaoControladaATensao(double v,int A, int B, int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();
        
    private:

      double E;
      int indiceCorrente;

};

#endif
