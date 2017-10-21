#include "Resistor.h"
Resistor::Resistor(double r,int A, int B){
  //  cout<<"construtor de resistor chamado"<<endl;
    a = A;
    b = B;
    resistencia = r;
    tipo = RESISTORTYPE;

}

bool Resistor::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{
//  cout<<"estampar do resistor chamado"<<endl;
  double condutancia = 1/resistencia;
  matrizCircuito[a][a]+= condutancia;
  matrizCircuito[b][b]+= condutancia;
  matrizCircuito[a][b]-= condutancia;
  matrizCircuito[b][a]-= condutancia;

  return true;


}

void Resistor::print(){
    cout<<"Resistor valor "<<resistencia<<" saindo de "<<a<<" entrando em "<<b<<endl;


}


int Resistor::aumentoVariaveis(int n){
  //  cout<<"Resistor aumentando variavel"<<endl;
    return 0;


}


int Resistor::quantasCorrentes()
{
    return 0;

}
