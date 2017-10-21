#include "Indutor.h"
Indutor::Indutor(double l,int A, int B){
  //  cout<<"construtor de indutor chamado"<<endl;
    a = A;
    b = B;
    indutancia = l;
    tipo = INDUTORTYPE;
    condutancia = 1e-10;//10000000000;
}

bool Indutor::estampar(double matrizCircuito[][MAX_NOS + 2], int nVariaveis, vector<double> estadoAnterior)
{
    //cout<<"instante no indutor"<<instante<<endl;
    if (instante == 0)//ponto de operacao
    {
    //  cout<<"entrou aqui"<<endl;
	           matrizCircuito[a][a]+= condutancia;
	           matrizCircuito[b][b]+= condutancia;
	           matrizCircuito[a][b]-= condutancia;
	           matrizCircuito[b][a]-= condutancia;
	           matrizCircuito[indiceCorrente][a]-=1;
	           matrizCircuito[indiceCorrente][b]+=1;
             matrizCircuito[a][indiceCorrente]+=1;
             matrizCircuito[b][indiceCorrente]-=1;
	           matrizCircuito[indiceCorrente][indiceCorrente]+= condutancia;

    }


    else{

              double tensao_no_indutor = estadoAnterior[a] - estadoAnterior[b];
              double corrente_no_indutor = estadoAnterior[indiceCorrente];
              double G0 = 2.0*indutancia/passo;
          //    cout<<"estado anterior tensao: "<<tensao_no_indutor<<"corrente: "<<corrente_no_indutor<<endl;
              matrizCircuito[a][indiceCorrente]+=1;
              matrizCircuito[b][indiceCorrente]-=1;
              matrizCircuito[indiceCorrente][a]-=1;
              matrizCircuito[indiceCorrente][b]+=1;
              matrizCircuito[indiceCorrente][indiceCorrente] += G0  ;
              matrizCircuito[indiceCorrente][nVariaveis + 1] +=( G0*corrente_no_indutor + tensao_no_indutor);
    }
	return true;

}

void Indutor::print(){
    cout<<"Indutor valor "<<indutancia<<" saindo de "<<a<<" entrando em "<<b<<endl;

}


int Indutor::aumentoVariaveis(int n){
  //  cout<<"Indutor aumentando variavel"<<endl;
    indiceCorrente = n+1;
    return 1;


}

int Indutor::quantasCorrentes()
{
    return 1;

}
