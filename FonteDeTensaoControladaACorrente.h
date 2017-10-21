#ifndef FONTEDETENSAOCONTROLADAACORRENTEH
#define FONTEDETENSAOCONTROLADAACORRENTEH
#define FONTEDETENSAOCONTROLADAACORRENTETYPE       6
#include "Elemento.h"

//TEM QUE TESTAR ESSA ESTAMPA
class FonteDeTensaoControladaACorrente : public Elemento {
  public :
      FonteDeTensaoControladaACorrente(double v,int A, int B, int C, int D);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      int aumentoVariaveis(int n);
        int quantasCorrentes();
        
    private:

      double H;
      int indiceCorrente,indiceCorrente2;
};

#endif
