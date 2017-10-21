#ifndef ELEMENTOH
#define ELEMENTOH

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdlib>


#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348
#define MAX_NOS 100
#define MAX_DURACAO   100000
#define MAX_NOME    100
#define TOLG 1e-9
#define MAX_PASSOS 100000

using namespace std;
class Elemento{
    public:
      Elemento();
      void setNome(char *novoNome);
      int getA();
      int getB();
      int getC();
      int getD();
      void aumentarInstante();
      void zerarInstante();
      void setPasso(double p);
      int getTipo();
      char* getNome();
      virtual bool atualizarEstampa(double matrizCircuito[][MAX_NOS + 2],int nVariaveis);
      virtual void print ();
      virtual bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double>  estadoAnterior);
      virtual bool estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis,vector<double> estadoAnterior, bool primeiro);
      virtual int aumentoVariaveis(int n);
      virtual int quantasCorrentes();



    protected:
      int a,b,c,d;
      int tipo;
      double instante;
      double passo;
      char nome[MAX_NOME];

};

#endif
