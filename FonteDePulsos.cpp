#include "FonteDePulsos.h"

FonteDePulsos::FonteDePulsos(double novoAmplitude1,double novoAmplitude2,double novoAtraso,double novoTempoDeSubida, double novoTempoDescida,double novoTempoLigada,double novoPeriodo,double novoNCiclos,int A,int B){

    a = A;
    b = B;
    amplitude1 = novoAmplitude1; //amplitude nivel alto
    amplitude2  = novoAmplitude2; // amplitude nivel baixo
    atraso = novoAtraso;
    tempoDeSubida = novoTempoDeSubida;
    tempoDeDescida = novoTempoDescida;
    tempoLigada = novoTempoLigada;
    periodo = novoPeriodo;
    nCiclos = novoNCiclos;


    tipo = FONTEDEPULSOSTYPE;

}

bool FonteDePulsos::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

    double tensaoInstantanea = amplitude1;
    double tempo = instante*passo;
    //if(instante != 0)
  //  cout<<"corente na fonte de pulso"<<estadoAnterior[indiceCorrente]<<endl;
    if(tempo <= atraso)//nao começou
    {
        tensaoInstantanea = amplitude1;
    }
    else if(tempo < (atraso + nCiclos*periodo))//ta rolando
    {
              double tempoRelativo = tempo - atraso;

          //    {
      //          cout<<"diminui tempo"<<tempoRelativo<<","<<periodo<<endl;
        //      }
              while(tempoRelativo >= periodo)
              {
                  tempoRelativo -=periodo;
  /*                if(instante == 0)
                  {
                    cout<<"diminui tempo"<<tempoRelativo<<","<<periodo<<endl;
                  }
    */          }

              if(tempoRelativo < (tempoDeSubida))//tasubindo
              {
                  tensaoInstantanea = amplitude1 + ((amplitude2-amplitude1)/tempoDeSubida)*(tempoRelativo);
              }
              else if( tempoRelativo < (tempoDeSubida + tempoLigada))//ligou
              {
                  tensaoInstantanea = amplitude2;

              }
              else if(tempoRelativo < (tempoDeSubida + tempoLigada + tempoDeDescida))//descendo
              {

                  tensaoInstantanea = amplitude2 - ((amplitude2 - amplitude1)/tempoDeDescida)*(tempoRelativo -(tempoDeSubida + tempoLigada));
              }
              else
              {
                  tensaoInstantanea = amplitude1;

              }
    }
    else
    {
        tensaoInstantanea = amplitude1;
    }

    matrizCircuito[a][indiceCorrente]+=1;
    matrizCircuito[b][indiceCorrente]-=1;
    matrizCircuito[indiceCorrente][a]-=1;
    matrizCircuito[indiceCorrente][b]+=1;
    matrizCircuito[indiceCorrente][nVariaveis + 1]-=tensaoInstantanea;



  return true;


}

bool FonteDePulsos::atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis)
{

//    tensao[(int)instante] = amplitude*sin(2*PI *frequencia*instante*passo);

  //  matrizCircuito[indiceCorrente][nVariaveis + 1]+=tensao[instante -1];
  //  matrizCircuito[indiceCorrente][nVariaveis + 1]-=tensao[instante];

    return true;


}

void FonteDePulsos::print(){//consertar aqui
    cout<<"Fonte de pulsos amplitude "<<amplitude1<<" e frequencia "<<" saindo de "<<a<<" entrando em "<<b<<endl;
    cout<<"amp1:"<<amplitude1;
    cout<<" amp2:"<<amplitude2;
    cout<<" atraso:"<<atraso;
    cout<<" subida:"<<tempoDeSubida;
    cout<<" ligada:"<<tempoLigada;
    cout<<" periodo:"<<periodo;
    cout<<" ciclos:"<<nCiclos<<endl;;



}


int FonteDePulsos::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
  //  cout<<"indice da corrente da fonte d tensao"<<indiceCorrente<<endl;
    return 1;


}


int FonteDePulsos::quantasCorrentes()
{
  return 1;

}
