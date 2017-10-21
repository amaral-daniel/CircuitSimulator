#ifndef RESISTORH
#define RESISTORH
#include "Elemento.h"
#define RESISTORTYPE  1

class Resistor : public Elemento {
  public :
      Resistor(double r,int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      virtual int aumentoVariaveis(int n);
        int quantasCorrentes();
        
    private:
      double resistencia;

};
#endif
