#include "FonteDeTensaoControladaACorrente.h"

FonteDeTensaoControladaACorrente::FonteDeTensaoControladaACorrente(double h,int A, int B, int C, int D)
{

    a = A;
    b = B;
    H = h;
    c = C;
    d = D;
    tipo = FONTEDETENSAOCONTROLADAACORRENTETYPE;

}

bool FonteDeTensaoControladaACorrente::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{
//O QUE EH x e y??????????? Consertar isso aqui!!!! Arrumar AumentoVariaveis tambem!!!
      matrizCircuito[a][indiceCorrente2]+=1;
      matrizCircuito[b][indiceCorrente2]-=1;
      matrizCircuito[c][indiceCorrente] +=1;
      matrizCircuito[d][indiceCorrente]-=1;
      matrizCircuito[indiceCorrente][c] -=1;
      matrizCircuito[indiceCorrente][d] +=1;
      matrizCircuito[indiceCorrente2][a]-=1;
      matrizCircuito[indiceCorrente2][b] +=1;
      matrizCircuito[indiceCorrente2][indiceCorrente]+=H;

  return true;


}

void FonteDeTensaoControladaACorrente::print()
{
    cout<<"Fonte de tensao controlada a Corrente com H "<<H<<" saindo de "<<a<<" entrando em "<<b<<" controlada pelos nos "<<c<<" e "<<d<<endl;


}


int FonteDeTensaoControladaACorrente::aumentoVariaveis(int n)
{
        indiceCorrente = n + 1;
        indiceCorrente2 = n + 2;

    return 2;


}

int FonteDeTensaoControladaACorrente::quantasCorrentes()
{
    return 2;

}
