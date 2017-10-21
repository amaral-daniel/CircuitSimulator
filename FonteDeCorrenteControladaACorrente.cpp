#include "FonteDeCorrenteControladaACorrente.h"

FonteDeCorrenteControladaACorrente::FonteDeCorrenteControladaACorrente(double f,int A , int B, int C, int D)
{

    F=f;
    a = A;
    b = B;
    c = C;
    d = D;

    tipo = FONTEDECORRENTECONTROLADAACORRENTETYPE;

}

bool FonteDeCorrenteControladaACorrente::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis, vector<double> estadoAnterior)
{
      matrizCircuito[a][indiceCorrente]+=F;
      matrizCircuito[b][indiceCorrente]-=F;
      matrizCircuito[c][indiceCorrente]+=1;
      matrizCircuito[d][indiceCorrente]-=1;
      matrizCircuito[indiceCorrente][c]-=1;
      matrizCircuito[indiceCorrente][d]+=1;
  return true;


}

void FonteDeCorrenteControladaACorrente::print()
{
    cout<<"Fonte de corrente controlada a corrente com F "<<F<<" saindo de "<<a<<" entrando em "<<b<<" controlada pelos nos "<<c<<" e "<<d<<endl;


}


int FonteDeCorrenteControladaACorrente::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
  //  cout<<"indice da corrente da fonte d tensao"<<indiceCorrente<<endl;
    return 1;


}


int FonteDeCorrenteControladaACorrente::quantasCorrentes()
{
      return 1;
}
