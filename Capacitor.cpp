#include "Capacitor.h"
Capacitor::Capacitor(double c,int A, int B){

    a = A;

    b = B;
    fontesDeCorrentesAnteriores[0] = 0;
    capacitancia = c;
    condutancia = 10000000000;
    tipo = CAPACITORTYPE;
  //  fontesDeCorrentesAnteriores[1] = 1000;

}

bool Capacitor::estampar(double matrizCircuito[][MAX_NOS + 2], int nVariaveis, vector<double> estadoAnterior)
{

  //NAO SEI PORQUE, MAS NAO PRECISO colocar nada em fontesdecorrentes[1] para ela funcionar. bizarrissimo
  double G0 = 2*capacitancia/passo;

  double Ic;

    if(instante == 0)//inicia como uma aberto
    {

              matrizCircuito[a][a] += condutancia;
              matrizCircuito[b][b] += condutancia;
              matrizCircuito[b][a] -= condutancia;
              matrizCircuito[a][b] -= condutancia;
              matrizCircuito[a][nVariaveis + 1]+=0;
              matrizCircuito[b][nVariaveis + 1]-=0;
              fontesDeCorrentesAnteriores[0] = 0;
    }
    else if(instante == 1)
    {
              double tensao_anterior = estadoAnterior[a] - estadoAnterior[b];
              Ic = G0*tensao_anterior;
              fontesDeCorrentesAnteriores[1] = 0;
    //          cout<<"corrente aqui,instante:"<<(int)instante<<"::::"<<fontesDeCorrentesAnteriores[(int)instante]<<","<<  fontesDeCorrentesAnteriores[1]<<endl;;
            //  fontesDeCorrentesAnteriores[(int)instante] = Ic;

          /*    cout<<"fonte :::"<<Ic<<endl;
              cout<<"corrente anterior:::"<<(estadoAnterior[a] - estadoAnterior[b])*condutancia<<endl;
              cout<<"tensao anterior:::"<<tensao_anterior<<endl;
              cout<<"condutancia::"<<G0<<endl;
              cout<<endl;
*/

              matrizCircuito[a][a] += G0;
              matrizCircuito[b][b] += G0;
              matrizCircuito[b][a] -= G0;
              matrizCircuito[a][b] -= G0;
              matrizCircuito[a][nVariaveis + 1]+=Ic;
              matrizCircuito[b][nVariaveis + 1]-=Ic;
    }
    else
    {
            double tensao_anterior = estadoAnterior[a] - estadoAnterior[b];
            double corrente_anterior = G0*tensao_anterior - fontesDeCorrentesAnteriores[(int)(instante -1)];
            Ic = G0*tensao_anterior + corrente_anterior;
      //      if(instante == 2)
      //      cout<<"corrente aqui"<<fontesDeCorrentesAnteriores[((int)instante -1)];
            fontesDeCorrentesAnteriores[(int)instante] = Ic;
      /*      if(instante <= 20)
            {
                  cout<<instante<<"fonte:"<<Ic<<endl;
                  cout<<"corrente anterior:"<<corrente_anterior<<endl;
                  cout<<"tensao anterior:"<<tensao_anterior<<endl;
                  cout<<"condutancia::"<<G0<<endl;
                  cout<<endl;
            }
        */    matrizCircuito[a][a] += G0;
            matrizCircuito[b][b] += G0;
            matrizCircuito[b][a] -= G0;
            matrizCircuito[a][b] -= G0;
            matrizCircuito[a][nVariaveis + 1]+=Ic;
            matrizCircuito[b][nVariaveis + 1]-=Ic;
    }
	return true;

}

void Capacitor::print()
{
    cout<<"Capacitor valor "<<capacitancia<<" saindo de "<<a<<" entrando em "<<b<<endl;

}


int Capacitor::aumentoVariaveis(int n)
{

    return 0;


}

int Capacitor::quantasCorrentes()
{
    return 0;

}
