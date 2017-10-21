#include "FonteDeTensaoControladaATensao.h"

FonteDeTensaoControladaATensao::FonteDeTensaoControladaATensao(double e,int A, int B, int C, int D)
{

    a = A;
    b = B;
    E = e;
    c = C;
    d = D;
    tipo = FONTEDETENSAOCONTROLADAATENSAOTYPE;

}

bool FonteDeTensaoControladaATensao::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{
//O QUE EH x??????????? Consertar isso aqui!!!! Arrumar AumentoVariaveis tambem!!!
      matrizCircuito[a][indiceCorrente]+=1;
      matrizCircuito[indiceCorrente][b]+=1;
      matrizCircuito[b][indiceCorrente]-=1;
      matrizCircuito[indiceCorrente][a]-=1;
      matrizCircuito[indiceCorrente][c]+=E;
      matrizCircuito[indiceCorrente][d]-=E;


  return true;


}

void FonteDeTensaoControladaATensao::print()
{
    cout<<"Fonte de tensao controlada a Tensao com E "<<E<<" saindo de "<<a<<" entrando em "<<b<<" controlada pelos nos "<<c<<" e "<<d<<endl;


}


int FonteDeTensaoControladaATensao::aumentoVariaveis(int n)
{

  //arrumar isso aqui!!!
    indiceCorrente = n + 1;
    return 1;

}

int FonteDeTensaoControladaATensao::quantasCorrentes()
{
    return 1;

}
