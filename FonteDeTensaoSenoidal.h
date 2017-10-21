#ifndef FONTEDETENSAOSENOIDALH
#define FONTEDETENSAOSENOIDALH
#define FONTEDETENSAOSENOIDALTYPE       9
#include "Elemento.h"


class FonteDeTensaoSenoidal : public Elemento {
  public :
      FonteDeTensaoSenoidal(double novoNivelDC,double novaAmp,double novaFrequencia,double novoAtraso,double novoAmortecimento,double novaDefasagem,double novoNumeroDeCiclos,int A, int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      bool atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:

      double nivelDC;
      double atraso;
      double amortecimento;
      double defasagem;

      double tensao[MAX_DURACAO];
      int indiceCorrente;
      double frequencia;
      double amplitude;
      double numeroDeCiclos;
      double parar;
};

#endif
