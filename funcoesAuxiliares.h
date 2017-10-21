#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
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
#include "Indutor.h"
#include "Transformador.h"
#include "Diodo.h"
#include "Chave.h"
#include "FonteDePulsosDeCorrente.h"
#include "Capacitor.h"


#define MAX_ARRAY 1000
#define MAX_LINHA     200
#define MAX_

#define MAX_ELEM      200
using namespace std;

void inicializarArquivoSaida(vector<Elemento*> meusElementos, int nNos);

void salvarEstado(vector<double> a,double t,double passo);

vector<Elemento*> lerArquivo(const char *nomeDoArquivo,double *parametros);

vector<double> transferirParaVector(double array[][102], int nVariaveis); //Guarda o estado em um vector
