#ifndef FONTEDEPULSOSDECORRENTEH
#define FONTEDEPULSOSDECORRENTEH
#define FONTEDEPULSOSDECORRENTETYPE       17
#include "Elemento.h"


class FonteDePulsosDeCorrente : public Elemento {
  public :
      FonteDePulsosDeCorrente(double amplitude1,double amplitude2,double atraso,double t_subida, double t_descida,double t_ligada,double periodo,double n_ciclos,int A,int B);
      void print ();
      bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior);
      bool atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis);
      int aumentoVariaveis(int n);
        int quantasCorrentes();

    private:


      double tempoDeSimulacao;
      double amplitude1;
      double amplitude2;
      double atraso;
      double tempoDeSubida;
      double tempoDeDescida;
      double tempoLigada;
      double periodo;
      double nCiclos;

};

#endif
