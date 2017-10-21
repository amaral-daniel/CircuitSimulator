#ifndef CIRCUITOH
#define CIRCUITOH


#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <cmath>
//#include <ctgmath>
#include "funcoesAuxiliares.h"
#include "Resistor.h"//1
#include "FonteDeCorrente.h" //2
#include "FonteDeTensao.h" // 3
#include "FonteDeCorrenteControladaACorrente.h" //4
#include "FonteDeCorrenteControladaATensao.h" //5
#include "FonteDeTensaoControladaACorrente.h" //6
#include "FonteDeTensaoControladaATensao.h" //7
#include "AmpOp.h" //8
#include "FonteDeTensaoSenoidal.h"//9
#include "FonteDePulsos.h" //10
#include "FonteDeCorrenteSenoidal.h" //11
#include "Indutor.h" //12
#include "Capacitor.h" //13
#include "Transformador.h" //14
#include "Diodo.h"// DIODO 15
#include "Chave.h"// CHAVE 16
#include "FonteDePulsosDeCorrente.h"// 17
#define TOLG2 1e-10

#define MAX_ELEMENTOS 100
#define MAX_TENTATIVA 10000

using namespace std;


class Circuito{
    private:
      double matriz[MAX_NOS + 1][MAX_NOS + 2]; //matriz que modela o circuito

      vector<Elemento*> vectorElementos; //vector contendo todos os resistores, capacitores etc presentes no circuito
      float resultado[MAX_NOS]; // resultado da analise
      int nVariaveis; //numero de variaveis
      int nEquacoes;
      int nNos;
      double passo;
      int instante;

      void contarNos();
      void contarVariaveis();
      void zerarMatriz();
      vector< vector<double> > vectorSolucoes;

    public:
      Circuito(vector<Elemento*> e,double p);
      bool inserirElemento(Elemento *e); //inclui novo elemento no circuito
      bool inserirElementos(vector<Elemento*> a);  //inclui varios elementos no circuito
      bool criarMatriz(); //a partir dos elementos cria a matriz a ser resolvida
      bool atualizarMatriz(); //atualiza a matriz, considerando, considerando que ela varia no tempo
      bool resolverSistema(); //resolve a matriz
      void printSolucao();
      void guardarSolucao();
      void newtonRaphson();
      void print();



};


#endif
