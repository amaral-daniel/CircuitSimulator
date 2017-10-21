#include "Transformador.h"

Transformador::Transformador(double n,int A, int B, int C, int D)
{

    a = A;
    b = B;
    N = n;
    c = C;
    d = D;
    tipo = TRANSFORMADORTYPE;

}

bool Transformador::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

          matrizCircuito[a][indiceCorrente]-=N;
          matrizCircuito[b][indiceCorrente]+=N;
          matrizCircuito[c][indiceCorrente]+=1;
          matrizCircuito[d][indiceCorrente]-=1;
          matrizCircuito[indiceCorrente][a]+=N;
          matrizCircuito[indiceCorrente][b]-=N;
          matrizCircuito[indiceCorrente][c]-=1;
          matrizCircuito[indiceCorrente][d]+=1;


  return true;


}

void Transformador::print()
{
    cout<<"Transformador com N "<<N<<" saindo de "<<a<<" entrando em "<<b<<" controlada pelos nos "<<c<<" e "<<d<<endl;

}


int Transformador::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
    return 1;

}

int Transformador::quantasCorrentes()
{
    return 1;

}
