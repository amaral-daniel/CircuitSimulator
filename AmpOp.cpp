#include "AmpOp.h"

AmpOp::AmpOp(int A, int B ,int C, int D)
{

    a = A;
    b = B;
    c = C;
    d = D;
    tipo = AMPOPTYPE;

}

bool AmpOp::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis, vector<double> estadoAnterior)
{

  matrizCircuito[a][indiceCorrente]+=1;
  matrizCircuito[b][indiceCorrente]-=1;
  matrizCircuito[indiceCorrente][c]+=1;
  matrizCircuito[indiceCorrente][d]-=1;


  return true;


}

void AmpOp::print(){
    cout<<"Amplificador operacional terminal -, +, saida, referencia: "<<a<<b<<c<<d<<endl;


}


int AmpOp::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
    return 1;


}
int AmpOp::quantasCorrentes()
{
    return 1;

}
