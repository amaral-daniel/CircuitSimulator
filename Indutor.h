#ifndef INDUTORH
#define INDUTORH
#include "Elemento.h"
#define INDUTORTYPE  12

class Indutor : public Elemento {
  public :
      Indutor(double l,int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      virtual int aumentoVariaveis(int n);
        int quantasCorrentes();
        
    private:

       double indutancia;
	     int  indiceCorrente;
	     double pontoDeOperacao;
       double condutancia;

};
#endif
