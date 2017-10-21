#include "FonteDeCorrenteControladaATensao.h"

FonteDeCorrenteControladaATensao::FonteDeCorrenteControladaATensao(double g,int A, int B, int C, int D)
{

      transCondutancia = g;
      a = A;
      b = B;
      c = C;
      d = D;

      tipo = FONTEDECORRENTECONTROLADAATENSAOTYPE;

}

bool FonteDeCorrenteControladaATensao::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{

    matrizCircuito[a][c]+= transCondutancia;
    matrizCircuito[a][d]-= transCondutancia;
    matrizCircuito[b][c]-= transCondutancia;
    matrizCircuito[b][d]+= transCondutancia;
  return true;


}

void FonteDeCorrenteControladaATensao::print()
{
    cout<<"Fonte de corrente controlada a tensao com G "<<transCondutancia<<" saindo de "<<a<<" entrando em "<<b<<" controlada pelos nos "<<c<<" e "<<d<<endl;


}


int FonteDeCorrenteControladaATensao::aumentoVariaveis(int n)
{
    return 0;


}

int FonteDeCorrenteControladaATensao::quantasCorrentes()
{
    return 0;

}
