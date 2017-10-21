#include "FonteDeCorrenteSenoidal.h"

FonteDeCorrenteSenoidal::FonteDeCorrenteSenoidal(double novoNivelDC,double novaAmp,double novaFrequencia,double novoAtraso,double novoAmortecimento,double novaDefasagem,double novoNumeroDeCiclos,int A, int B)
{

  a = A;
  b = B;
  amplitude = novaAmp;
  defasagem = novaDefasagem;
  amortecimento = novoAmortecimento;
  numeroDeCiclos = novoNumeroDeCiclos;

  frequencia = novaFrequencia;
  nivelDC = novoNivelDC;
  tipo = FONTEDECORRENTESENOIDALTYPE;
  parar = atraso + numeroDeCiclos/frequencia;
}

bool FonteDeCorrenteSenoidal::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

    if(passo*instante <= parar)
    {
        matrizCircuito[a][nVariaveis + 1]-=(nivelDC + amplitude*exp(-amortecimento*(instante*passo - atraso))*sin(2*PI*(frequencia*instante*passo- atraso) + PI*defasagem/180));
        matrizCircuito[b][nVariaveis + 1]+=(nivelDC + amplitude*exp(-amortecimento*(instante*passo - atraso))*sin(2*PI*(frequencia*instante*passo- atraso) + PI*defasagem/180));
    }
    else
    {
        matrizCircuito[a][nVariaveis + 1]-=(nivelDC );
        matrizCircuito[b][nVariaveis + 1]+=(nivelDC );

    }
  return true;


}

bool FonteDeCorrenteSenoidal::atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis)
{


    return true;


}

void FonteDeCorrenteSenoidal::print(){
    cout<<"Fonte senoidal amplitude "<<amplitude<<" e frequencia "<<frequencia<<" saindo de "<<a<<" entrando em "<<b<<endl;


}


int FonteDeCorrenteSenoidal::aumentoVariaveis(int n)
{
  //  indiceCorrente = n + 1;
  //  cout<<"indice da corrente da fonte d corrente de pulsos "<<indiceCorrente<<endl;
    return 0;


}

int FonteDeCorrenteSenoidal::quantasCorrentes()
{
    return 0;

}
