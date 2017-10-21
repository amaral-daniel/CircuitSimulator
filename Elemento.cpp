#include "Elemento.h"




Elemento::Elemento()
{
    //cout<<"construtor padrao de Elemento chamado, deu ruim"<<endl;
    a = b = c = d = 0;
    instante = 0;
}

void Elemento::print(){
    cout<<"Elemento nao inicializado"<<endl;

}

bool Elemento::atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis)
{
    return true;
}

bool Elemento::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior)
{
    cout<<"Elemento nao inicializado nao pode ser estampado"<<endl;
    return false;
//    return false;
}
bool Elemento::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior, bool primeiro)
{
  cout<<"elemento nao inicializado sendo chamado"<<endl;
  return false;

}

int Elemento::aumentoVariaveis(int n)
{
    cout<<"Elemento nao inicializado nao aumenta variaveis"<<endl;
    return -1;
}

int Elemento::getA()
{
    return a;
}

int Elemento::getB()
{
    return b;
}

int Elemento::getC()
{
    return c;
}

int Elemento::getD()
{
    return d;
}


int Elemento::getTipo()
{
  return tipo;
}
void Elemento::aumentarInstante()
{
    instante++;
}
void Elemento::zerarInstante()
{
    instante = 0;
}

void Elemento::setPasso(double p)
{
  passo = p;
  instante = 0;
}


void Elemento::setNome(char *novoNome)
{
    strcpy(nome,novoNome);

}

char* Elemento::getNome()
{
    return nome;

}
int Elemento::quantasCorrentes()
{
    cout<<"ERRO!!!Elemento nao inicializado"<<endl;
    return 0;

}
