#include "Circuito.h"

Circuito::Circuito(vector<Elemento*> novosElementos,double p){

  passo = p;
  instante = 0;
  if(novosElementos.size() <= MAX_ELEMENTOS)
  {
      vectorElementos.insert( vectorElementos.end(), novosElementos.begin(), novosElementos.end() );
      cout<<"Circuito inicializado com sucesso contendo "<<novosElementos.size()<<" elementos."<<endl;
  }
  else
  {
        cout<<"ERRO!!!! Numero de elementos excede o maximo permitido de "<<MAX_ELEMENTOS<<". Vector de elementos não inserido"<<endl;
  }
  this->print();

}


bool Circuito::inserirElemento(Elemento *novoElemento){
    if(vectorElementos.size() < MAX_ELEMENTOS)
    {

        vectorElementos.push_back(novoElemento);
        return true;
    }
    cout<<"ERRO!!!! Numero de elementos excede o maximo permitido de "<<MAX_ELEMENTOS<<" Elemento não inserido"<<endl;
    return false;
}

bool Circuito::inserirElementos(vector<Elemento*> novosElementos)
{
    if(vectorElementos.size() + novosElementos.size() <= MAX_ELEMENTOS)
    {
        vectorElementos.insert( vectorElementos.end(), novosElementos.begin(), novosElementos.end() );
        return true;
    }
    cout<<"ERRO!!!! Numero de elementos excede o maximo permitido de "<<MAX_ELEMENTOS<<" Vector de elementos não inserido"<<endl;
    return false;


}

bool Circuito::criarMatriz()
{
  //cout<<"criarMatriz chamada"<<endl;
    vector<double> vectorVazio;
    //cout<<"declarou vectorVazio"<<endl;
    ofstream ofs;
    //cout<<"declarou ofs"<<endl;
    ofs.open("output.tab", ofstream::out | ofstream::trunc);
    //cout<<"abriu"<<endl;
    ofs.close();
    //cout<<"fechou"<<endl;
    contarNos();
    //cout<<"contou nos"<<endl;
    contarVariaveis();
    //cout<<"contou variaveis"<<endl;
    zerarMatriz();

  //  cout<<"antes de inicializarArquivoSaida"<<endl;
    inicializarArquivoSaida(vectorElementos,nNos);
    //cout<<"criando matriz...."<<endl;
    if(vectorElementos.size() == 0)
    {
        return false;
    }
    for(unsigned int i = 0; i < vectorElementos.size(); i++)
    {
        vectorElementos[i]->setPasso(passo);
    //    vectorElementos[i]->print();
      //  cout<<"estampa n"<<i<<endl;
//        if(!(vectorElementos[i]->estampar(matriz,nVariaveis,vectorVazio)))
  //      {
      //      return false;
  //      }
    //    cout<<"estampou n"<<i<<endl;
  //      vectorElementos[i]->print();
  //     printSolucao();
    //    cout<<endl;

    }

    //cout<<"matriz criada com sucesso"<<endl;

    return true;

}

bool Circuito::atualizarMatriz()
{
      instante++;
    //  zerarMatriz();
      for(unsigned int i = 0; i < vectorElementos.size(); i++)
      {
              vectorElementos[i]->aumentarInstante();

      }

  return true;


}

bool Circuito::resolverSistema()
{
    int i,j,l, a;
    double t, p;

    for (i=1; i<=nVariaveis; i++) {
      t=0.0;
      a=i;
      for (l=i; l<=nVariaveis; l++) {
        if (fabs(matriz[l][i])>fabs(t)) {
  	a=l;
  	t=matriz[l][i];
        }
      }
      if (i!=a) {
        for (l=1; l<=nVariaveis+1; l++) {
  	        p=matriz[i][l];
  	        matriz[i][l]=matriz[a][l];
  	        matriz[a][l]=p;
        }
      }
      if (fabs(t)<TOLG2) {
        printf("Sistema singular\n");
        return false;
      }
      for (j=nVariaveis+1; j>0; j--) {  /* Basta j>i em vez de j>0 */
        matriz[i][j] /= t;
        p=matriz[i][j];
        if (p!=0)
          for (l=1; l<=nVariaveis; l++) {
  	  if (l!=i)
  	    matriz[l][j]-=matriz[l][i]*p;
          }
      }
    }

    matriz[0][nVariaveis+1] = 0;


    return true;

}

void Circuito::contarNos()
{
    int maiorNo = 0;

    for(unsigned int i = 0; i < vectorElementos.size(); i++ )
    {
      //    vectorElementos[i]->print();
          if(vectorElementos[i]->getA() > maiorNo )
          {
              maiorNo = vectorElementos[i]->getA();
          }
          if(vectorElementos[i]->getB() > maiorNo )
          {
              maiorNo = vectorElementos[i]->getB();
          }
          if(vectorElementos[i]->getC() > maiorNo )
          {
              maiorNo = vectorElementos[i]->getC();
          }
          if(vectorElementos[i]->getD() > maiorNo )
          {
              maiorNo = vectorElementos[i]->getD();
          }
        //  cout<<"passou pelos ifs todos"<<endl;
    }

    if(maiorNo == 0)
    {
        cout<<"Maior no encontrado foi 0, algo de errado nao esta certo"<<endl;
    }
    maiorNo += 1;
    nNos = maiorNo;

}

void Circuito::contarVariaveis()
{
    nVariaveis = nNos - 1;
    for( unsigned int i = 0; i < vectorElementos.size(); i++ )
    {
          nVariaveis+=vectorElementos[i]->aumentoVariaveis(nVariaveis);
    }



}

void Circuito::zerarMatriz()
{
    for(int i = 0; i < MAX_NOS + 1 ; i++)
    {
        for(int j = 0; j < MAX_NOS + 2; j++)
        {
            matriz[i][j] = 0;
        }

    }

}

void Circuito::printSolucao()
{
  for (int i=0; i<=nVariaveis; i++)
  {
      for (int j=0; j<=nVariaveis+1; j++)
          if (matriz[i][j]!=0) printf("%+3.1f ",matriz[i][j]);
          else printf(" ... ");
      printf("\n");
  }

  cout<<endl;


}


void Circuito::guardarSolucao()
{
    vector<double> novaSolucao;
    for(int i = 0; i <= nVariaveis; i++)//mudei indice aqui, converir dps
    {
          novaSolucao.push_back(matriz[i][nVariaveis+1]);
    }
    vectorSolucoes.push_back(novaSolucao); //salva no vetor de estados anteriores do circuito
if(instante > 0)//zero eh ponto de operacao
{
    salvarEstado(novaSolucao,instante*passo,passo); //salva no arquivo out
}





}
void Circuito::newtonRaphson()
{

  //  bool pular = false;
    zerarMatriz();
    vector<double> tentativaAnterior;
    vector<bool> mudou;
    bool primeiro = true;
  //  cout<<"instante:::"<<instante*passo<<endl;
    for(int tentativa = 0; tentativa < MAX_TENTATIVA; tentativa++)
    {
          zerarMatriz();
          mudou.clear();
          if(tentativa != 0)
          {
              primeiro = false;
          }
          else if(remainder(tentativa,(double)(MAX_TENTATIVA/10)  )   == 0)
          {
              primeiro = true;
          }
          else if(tentativa == MAX_TENTATIVA/10 + 1)
          {
              primeiro = false;
          }

          for(unsigned int i = 0; i < vectorElementos.size(); i++)//percorre todos os elementos estampando
          {
    //        cout<<"instante"<<instante<<"tenttiva"<<tentativa<<endl;
              if(vectorElementos[i]->getTipo() == DIODOTYPE || vectorElementos[i]->getTipo() == CHAVETYPE)
              {
      /*              if(instante <= -5)
                    {
                            cout<<"antes"<<instante<<endl;
                            vectorElementos[i]->print();
                            printSolucao();
                    }
        */            mudou.push_back(vectorElementos[i]->estampar(matriz, nVariaveis, tentativaAnterior, primeiro));
          /*          if(instante <= -5)
                    {
                            cout<<"depois"<<endl;
                            vectorElementos[i]->print();
                            printSolucao();
                    }
            */  }
              else
              {
                    if(instante == 0)
                    {
                        //cout<<"primeiro instante, tentativa"<<tentativa<<endl;
                //        if(vectorElementos[i]->getTipo()==CAPACITORTYPE)
                //        {
              /*            if(instante <= -5)
                          {
                                  cout<<"antes"<<instante<<endl;
                                  vectorElementos[i]->print();
                                  printSolucao();
                          }
                */          vectorElementos[i]->estampar(matriz, nVariaveis, tentativaAnterior);//o vector tentativaAnterior esta vazio, eh utilizado apenas para evitar um seg fault

                  /*      if(instante <= -5)
                        {
                                cout<<"depois"<<endl;
                                vectorElementos[i]->print();
                                printSolucao();
                        }
                    */  //  }
                    //    else
                    //    vectorElementos[i]->estampar(matriz, nVariaveis, tentativaAnterior);//o vector tentativaAnterior esta vazio, eh utilizado apenas para evitar um seg fault

                    }
                    else
                    {
                      /*          if(instante <= 0*5)
                                {
                                        cout<<"antes"<<instante<<endl;
                                        vectorElementos[i]->print();
                                        printSolucao();
                                }
                        */        vectorElementos[i]->estampar(matriz, nVariaveis,  vectorSolucoes[instante -1]);//o vector tentativaAnterior esta vazio, eh utilizado apenas para evitar um seg fault
                          /*      if(instante <= -5)
                                {
                                        cout<<"depois"<<endl;
                                        vectorElementos[i]->print();
                                        printSolucao();
                                }*/
                    }
              }

          }
      //    printSolucao();
            resolverSistema();
          tentativaAnterior = transferirParaVector(matriz,nVariaveis); //transfere a solucao encontrada para o vetor tentativaAnterior
          bool mudouAlgo = false;
          for(unsigned int i = 0; i < mudou.size(); i++)//testa se ja convergiu
          {
              if(mudou[i]) //
              {
                  i = mudou.size();
                  mudouAlgo = true;
                  if(tentativa == (MAX_TENTATIVA - 1))
                  {
                      cout<<"Nao conseguiu convergir no instante "<<instante<<" tentativa "<<tentativa<<" ."<<endl;
                  }
              }

          }
          if(!mudouAlgo)//nao encontrou nenhuma mudanca, ja convergiu.
          {
    //            cout<<"convergiu na tentativa"<<tentativa<<endl;;
                tentativa = MAX_TENTATIVA + 10;//soh para sair do loop
          }

    }
  //  cout<<"solucao final instante"<<instante<<endl;
//  if(instante <= 20)
/*if(instante <= 500000){
cout<<"instante:::"<<instante*passo<<"resolvido"<<endl;
    printSolucao();
  }
  */
	
  guardarSolucao();



}

void Circuito::print()
{
    cout<<"****************ELEMENTOS****************"<<endl;
    for(unsigned int i = 0; i < vectorElementos.size() ;i++)
    {
        cout<<">>>";
        vectorElementos[i]->print();

    }
    cout<<"*****************************************"<<endl;

}
