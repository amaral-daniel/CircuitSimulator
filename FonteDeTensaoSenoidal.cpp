#include "FonteDeTensaoSenoidal.h"

FonteDeTensaoSenoidal::FonteDeTensaoSenoidal(double novoNivelDC,double novaAmp,double novaFrequencia,double novoAtraso,double novoAmortecimento,double novaDefasagem,double novoNumeroDeCiclos,int A, int B)
{
    a = A;
    b = B;
    amplitude = novaAmp;
    defasagem = novaDefasagem;
    amortecimento = novoAmortecimento;
    numeroDeCiclos = novoNumeroDeCiclos;

    frequencia = novaFrequencia;
    nivelDC = novoNivelDC;
    tipo = FONTEDETENSAOSENOIDALTYPE;
    parar = atraso + numeroDeCiclos/frequencia;

}

bool FonteDeTensaoSenoidal::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{
    matrizCircuito[a][indiceCorrente]+=1;
    matrizCircuito[b][indiceCorrente]-=1;
    matrizCircuito[indiceCorrente][a]-=1;
    matrizCircuito[indiceCorrente][b]+=1;
    if(passo*instante <= parar)
        matrizCircuito[indiceCorrente][nVariaveis + 1]-=(nivelDC + amplitude*exp(-amortecimento*(instante*passo - atraso))*sin(2*PI*(frequencia*instante*passo- atraso) + PI*defasagem/180));
    else
        matrizCircuito[indiceCorrente][nVariaveis + 1]-=nivelDC;

  //  cout<<"tensao na fonte: "<<(nivelDC + amplitude*sin(2.0*PI*frequencia*instante*passo))<<endl;
  return true;


}

bool FonteDeTensaoSenoidal::atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis)
{

  //  tensao[(int)instante] = amplitude*sin(2*PI *frequencia*instante*passo);

    return true;


}

void FonteDeTensaoSenoidal::print(){
    cout<<"Fonte senoidal amplitude "<<amplitude<<" e frequencia "<<frequencia<<" saindo de "<<a<<" entrando em" <<b<<endl;


}


int FonteDeTensaoSenoidal::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
  //  cout<<"indice da corrente da fonte d tensao"<<indiceCorrente<<endl;
    return 1;


}

int FonteDeTensaoSenoidal::quantasCorrentes()
{
    return 1;


}
