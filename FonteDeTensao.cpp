#include "FonteDeTensao.h"

FonteDeTensao::FonteDeTensao(double v,int A, int B){

    a = A;
    b = B;
    tensao = v;
    tipo = FONTEDETENSAOTYPE;

}

bool FonteDeTensao::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

    matrizCircuito[a][indiceCorrente]+=1;
    matrizCircuito[b][indiceCorrente]-=1;
    matrizCircuito[indiceCorrente][a]-=1;
    matrizCircuito[indiceCorrente][b]+=1;
    matrizCircuito[indiceCorrente][nVariaveis + 1]-=tensao;

  return true;


}

void FonteDeTensao::print(){
    cout<<"Fonte de tensao DC valor "<<tensao<<" saindo de "<<a<<" entrando em "<<b<<endl;


}


int FonteDeTensao::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
//    cout<<"indice da corrente da fonte d tensao"<<indiceCorrente<<endl;
    return 1;


}

int FonteDeTensao::quantasCorrentes()
{
    return 1;

}
