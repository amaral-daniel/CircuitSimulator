#include "FonteDePulsosDeCorrente.h"

FonteDePulsosDeCorrente::FonteDePulsosDeCorrente(double novoAmplitude1,double novoAmplitude2,double novoAtraso,double novoTempoDeSubida, double novoTempoDescida,double novoTempoLigada,double novoPeriodo,double novoNCiclos,int A,int B){

    a = A;
    b = B;
    amplitude1 = novoAmplitude1;
    amplitude2  = novoAmplitude2;
    atraso = novoAtraso;
    tempoDeSubida = novoTempoDeSubida;
    tempoDeDescida = novoTempoDescida;
    tempoLigada = novoTempoLigada;
    periodo = novoPeriodo;
    nCiclos = novoNCiclos;


    tipo = FONTEDEPULSOSDECORRENTETYPE;

}

bool FonteDePulsosDeCorrente::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

  double correnteInstantanea = amplitude1;
  double tempo = instante*passo;
  if(tempo <= atraso)//nao começou
  {
      correnteInstantanea = amplitude1;
  }
  else if(tempo < (atraso + nCiclos*periodo))//ta rolando
  {
            double tempoRelativo = tempo - atraso;
            while(tempoRelativo >= periodo)
            {
                tempoRelativo -=periodo;
            }

            if(tempoRelativo < (tempoDeSubida))//tasubindo
            {
                correnteInstantanea = amplitude1 + ((amplitude2-amplitude1)/tempoDeSubida)*(tempoRelativo);
            }
            else if( tempoRelativo < (tempoDeSubida + tempoLigada))//ligou
            {
                correnteInstantanea = amplitude2;

            }
            else if(tempoRelativo < (tempoDeSubida + tempoLigada + tempoDeDescida))//descendo
            {

                correnteInstantanea = amplitude2 - ((amplitude2 - amplitude1)/tempoDeDescida)*(tempoRelativo -(tempoDeSubida + tempoLigada));
            }
            else
            {
                correnteInstantanea = amplitude1;

            }
  }
  else
  {
      correnteInstantanea = amplitude1;
  }

  matrizCircuito[a][nVariaveis + 1]-=correnteInstantanea;
  matrizCircuito[b][nVariaveis + 1]+=correnteInstantanea;

  return true;


}

bool FonteDePulsosDeCorrente::atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis)
{

//    corrente[(int)instante] = amplitude*sin(2*PI *frequencia*instante*passo);

  //  matrizCircuito[indiceCorrente][nVariaveis + 1]+=tensao[instante -1];
  //  matrizCircuito[indiceCorrente][nVariaveis + 1]-=tensao[instante];

    return true;


}

void FonteDePulsosDeCorrente::print(){//consertar aqui
    cout<<"Fonte senoidal amplitude "<<amplitude1<<" e periodo "<<periodo<<" saindo de "<<a<<" entrando em "<<b<<endl;


}


int FonteDePulsosDeCorrente::aumentoVariaveis(int n)
{
    //indiceCorrente = n + 1;
    //cout<<"indice da corrente da fonte d corrente"<<indiceCorrente<<endl;
    return 0;


}

int FonteDePulsosDeCorrente::quantasCorrentes()
{
    return 1;

}
