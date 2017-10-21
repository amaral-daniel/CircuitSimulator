#include "FonteDeCorrente.h"

FonteDeCorrente::FonteDeCorrente(double r,int A, int B){

    a = A;
    b = B;
    corrente = r;
    tipo = FONTEDECORRENTETYPE;

}

bool FonteDeCorrente::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

  matrizCircuito[a][nVariaveis + 1]-=corrente;
  matrizCircuito[b][nVariaveis + 1]+=corrente;

  return true;


}

void FonteDeCorrente::print(){
    cout<<"Fonte de corrente valor "<<corrente<<" saindo de "<<a<<" entrando em "<<b<<endl;


}


int FonteDeCorrente::aumentoVariaveis(int n){
    return 0;


}

int FonteDeCorrente::quantasCorrentes(){

    return 0;

}
