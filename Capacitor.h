#ifndef CAPACITORH
#define CAPACITORH

#include "Elemento.h"
#define CAPACITORTYPE  13

class Capacitor : public Elemento {
  public :
      Capacitor(double C,int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis, vector<double> estadoAnterior);
      virtual int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double capacitancia;
	     int  indiceCorrente;
       double fontesDeCorrentesAnteriores[MAX_PASSOS];
       double condutancia;

};
#endif
