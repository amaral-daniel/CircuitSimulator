#include "funcoesAuxiliares.h"

void inicializarArquivoSaida(vector<Elemento*> meusElementos, int nNos)
{
    ofstream Arquivo ("output.tab",std::ofstream::out | std::ofstream::trunc);
    Arquivo<<"t"<<" ";
    //char *nomeElemento;
    for(int i = 0; i < nNos;i++)
    {
        Arquivo<<i<<" ";
    }
    for(unsigned int i = 0; i < meusElementos.size() ; i++)
    {
        if(meusElementos[i]->quantasCorrentes() == 1)
        {
            Arquivo<<"j"<<meusElementos[i]->getNome()<<" ";
        }
        else if(meusElementos[i]->quantasCorrentes() == 2)
        {
            Arquivo<<"j"<<meusElementos[i]->getNome()<<"a"<<" "<<"j"<<meusElementos[i]->getNome()<<"b"<<" ";
        }

    }
    Arquivo<<endl;
    Arquivo.close();

}
void salvarEstado(vector<double> tensoesECorrentes,double t,double passo)
{
  ofstream Arquivo ("output.tab",ios::app);
  if (Arquivo.is_open())
  {
      Arquivo << t - passo<<" ";
      for (unsigned int i=0;i<=tensoesECorrentes.size(); i++)
      {
          Arquivo << tensoesECorrentes[i]<<" ";
      }
        Arquivo << "\n";
        Arquivo.close();
  }
  else cout << "Arquivo não abriu"<<endl;;

}


vector<Elemento*> lerArquivo(const char *nomearquivo,double *parametros)
{
  parametros[0] = 0;
  parametros[1] = 0;
  parametros[2] = 0;
  cout<<"Lendo arquivo ...."<<endl;
  vector<Elemento*> vectorElementos;
  char txt[MAX_LINHA+1];
  char tipo;
  double valor;
  char nomeComponente[100];
  char *p;
  char na[100],nb[100],nc[100],nd[100];
  int noA,noB,noC,noD;

  FILE *arquivo;
  /* Leitura do netlist */
  int ne=0;
//  int nv=0;
//   strcpy(lista[0],"0");
  //cout<<"Nome do arquivo com o netlist (ex: mna.net): "<<endl;
  arquivo=fopen(nomearquivo,"r");
  if (arquivo==0) {
    printf("Arquivo %s inexistente\n",nomearquivo);
      return vectorElementos;
  }
  //printf("Lendo netlist:\n");
  fgets(txt,MAX_LINHA,arquivo);
  //printf("Titulo: %s",txt);
  while (fgets(txt,MAX_LINHA,arquivo))
  {
      //  cout<<tipo<<endl;
          ne++; /* Nao usa o netlist[0] */

          if (ne>MAX_ELEM) {
            printf("O programa so aceita ate %d elementos\n",MAX_ELEM);
            exit(1);
          }

      //    char teste = txt[0];
          txt[0]=toupper(txt[0]);
          tipo=txt[0];
        //  cout<<txt<<endl;
          sscanf(txt,"%10s",nomeComponente);
          p=txt+strlen(nomeComponente); /* Inicio dos parametros */
          /* O que e lido depende do tipo */
          if (tipo=='R')
          {

                Elemento *novoResistor;

                sscanf(p,"%10s%10s%lg",na,nb,&valor);
                noA = atoi(na);
                noB = atoi(nb);
                novoResistor = new Resistor(valor,noA,noB);
                novoResistor->setNome(nomeComponente);
                vectorElementos.push_back(novoResistor);


          }
          else if (tipo=='I')
          {

                  Elemento *novaFonteDeCorrente;
                  char tipoFonte[10];
                  sscanf(p,"%10s%10s%10s",na,nb,tipoFonte);
                  if(strcmp(tipoFonte,"DC") ==0)
                  {
                            sscanf(p,"%10s%10s%10s%lg",na,nb,tipoFonte,&valor);
                            noA = atoi(na);
                            noB = atoi(nb);
                            novaFonteDeCorrente = new FonteDeCorrente(valor,noA,noB);
                  }
                  else if(strcmp(tipoFonte,"SIN") == 0)
                  {
                      double nivelContinuo;
                      double amplitude;
                      double frequencia;
                      double atraso;
                      double amortecimento;
                      double defasagem;
                      double numeroDeCiclos;
                      sscanf(p,"%10s%10s%10s%lg%lg%lg%lg%lg%lg%lg",na,nb,tipoFonte,&nivelContinuo,&amplitude,&frequencia,&atraso,&amortecimento,&defasagem,&numeroDeCiclos);
                      noA = atoi(na);
                      noB = atoi(nb);
                      novaFonteDeCorrente = new FonteDeCorrenteSenoidal(nivelContinuo,amplitude,frequencia,atraso,amortecimento,defasagem,numeroDeCiclos,noA,noB);


                  }
                  else if(strcmp(tipoFonte,"PULSE") == 0)
                  {
                      double amplitude1;
                      double amplitude2;
                      double atraso;
                      double tempoDeSubida;
                      double tempoDeDescida;
                      double tempoLigada;
                      double periodo;
                      double numeroDeCiclos;

                      sscanf(p,"%10s%10s%10s%lg%lg%lg%lg%lg%lg%lg%lg",na,nb,tipoFonte,&amplitude1,&amplitude2,&atraso,&tempoDeSubida,&tempoDeDescida, &tempoLigada, &periodo, &numeroDeCiclos);
                      noA = atoi(na);
                      noB = atoi(nb);
                    //  cout<<"tipo fonte encontrada"<<tipoFonte<<endl;
                      novaFonteDeCorrente = new FonteDePulsosDeCorrente(amplitude1,amplitude2,atraso,tempoDeSubida,tempoDeDescida,tempoLigada,periodo,numeroDeCiclos,noA,noB);
                  }
                  else
                  {
                        cout<<"ERRO:Tipo de fonte nao reconhecido:::"<<tipoFonte<<endl;
                  }



                  novaFonteDeCorrente->setNome(nomeComponente);
                  vectorElementos.push_back(novaFonteDeCorrente);
          }
          else if (tipo=='V')
          {

                  Elemento *novaFonteDeTensao;
                  char tipoFonte[10];
                  sscanf(p,"%10s%10s%10s",na,nb,tipoFonte);
                  if(strcmp(tipoFonte,"DC") ==0)
                  {
                            sscanf(p,"%10s%10s%10s%lg",na,nb,tipoFonte,&valor);
                            noA = atoi(na);
                            noB = atoi(nb);
                            novaFonteDeTensao = new FonteDeTensao(valor,noA,noB);
                  //          novaFonteDeTensao->print();

                  }
                  else if(strcmp(tipoFonte,"SIN") == 0)
                  {
                      double nivelContinuo;
                      double amplitude;
                      double frequencia;
                      double atraso;
                      double amortecimento;
                      double defasagem;
                      double numeroDeCiclos;
                      sscanf(p,"%10s%10s%10s%lg%lg%lg%lg%lg%lg%lg",na,nb,tipoFonte,&nivelContinuo,&amplitude,&frequencia,&atraso,&amortecimento,&defasagem,&numeroDeCiclos);
                      noA = atoi(na);
                      noB = atoi(nb);
                      cout<<"tipo fonte encontrada"<<tipoFonte<<endl;
                      novaFonteDeTensao = new FonteDeTensaoSenoidal(nivelContinuo,amplitude,frequencia,atraso,amortecimento,defasagem,numeroDeCiclos,noA,noB);


                  }
                  else if(strcmp(tipoFonte,"PULSE") == 0)
                  {
                      double amplitude1;
                      double amplitude2;
                      double atraso;
                      double tempoDeSubida;
                      double tempoDeDescida;
                      double tempoLigada;
                      double periodo;
                      double numeroDeCiclos;

                      sscanf(p,"%10s%10s%10s%lg%lg%lg%lg%lg%lg%lg%lg",na,nb,tipoFonte,&amplitude1,&amplitude2,&atraso,&tempoDeSubida,&tempoDeDescida, &tempoLigada, &periodo, &numeroDeCiclos);
                      noA = atoi(na);
                      noB = atoi(nb);
                //      cout<<"tipo fonte encontrada"<<tipoFonte<<endl;
                      novaFonteDeTensao = new FonteDePulsos(amplitude1,amplitude2,atraso,tempoDeSubida,tempoDeDescida,tempoLigada,periodo,numeroDeCiclos,noA,noB);
                  //    novaFonteDeTensao->print();
                  }
                  else
                  {
                        cout<<"ERRO:Tipo de fonte nao reconhecido:::"<<tipoFonte<<endl;
                  }


                  novaFonteDeTensao->setNome(nomeComponente);
                  vectorElementos.push_back(novaFonteDeTensao);
          }
          else if (tipo=='G')
          {
                  Elemento *novaFonteDeCorrenteControladaATensao;
                  sscanf(p,"%10s%10s%10s%10s%lg",na,nb,nc,nd,&valor);
                  noA = atoi(na);
                  noB = atoi(nb);
                  noC = atoi(nc);
                  noD = atoi(nd);

                  novaFonteDeCorrenteControladaATensao = new FonteDeCorrenteControladaATensao(valor,noA,noB,noC,noD);
                  novaFonteDeCorrenteControladaATensao->setNome(nomeComponente);
                  vectorElementos.push_back(novaFonteDeCorrenteControladaATensao);

          }
          else if (tipo=='E')
          {
                  sscanf(p,"%10s%10s%10s%10s%lg",na,nb,nc,nd,&valor);

                  Elemento *novaFonteDeTensaoControladaATensao;

                  noA = atoi(na);
                  noB = atoi(nb);
                  noC = atoi(nc);
                  noD = atoi(nd);

                  novaFonteDeTensaoControladaATensao = new FonteDeTensaoControladaATensao(valor,noA,noB,noC,noD);
                  novaFonteDeTensaoControladaATensao->setNome(nomeComponente);
                  vectorElementos.push_back(novaFonteDeTensaoControladaATensao);

          }
          else if (tipo=='F')
          {
                  Elemento *novaFonteDeCorrenteControladaACorrente;
                  sscanf(p,"%10s%10s%10s%10s%lg",na,nb,nc,nd,&valor);

                  noA = atoi(na);
                  noB = atoi(nb);
                  noC = atoi(nc);
                  noD = atoi(nd);

                  novaFonteDeCorrenteControladaACorrente = new FonteDeCorrenteControladaACorrente(valor,noA,noB,noC,noD);
                  novaFonteDeCorrenteControladaACorrente->setNome(nomeComponente);
                  vectorElementos.push_back(novaFonteDeCorrenteControladaACorrente);

          }
          else if (tipo=='H')
         {
              Elemento *novaFonteDeTensaoControladaACorrente;
              sscanf(p,"%10s%10s%10s%10s%lg",na,nb,nc,nd,&valor);

              noA = atoi(na);
              noB = atoi(nb);
              noC = atoi(nc);
              noD = atoi(nd);

              novaFonteDeTensaoControladaACorrente = new FonteDeTensaoControladaACorrente(valor,noA,noB,noC,noD);
              novaFonteDeTensaoControladaACorrente->setNome(nomeComponente);
              vectorElementos.push_back(novaFonteDeTensaoControladaACorrente);
          }
          else if (tipo=='O') {
              Elemento *novoAmpOp;
              sscanf(p,"%10s%10s%10s%10s",na,nb,nc,nd);
              noA = atoi(na);
              noB = atoi(nb);
              noC = atoi(nc);
              noD = atoi(nd);

              novoAmpOp = new AmpOp(noA,noB,noC,noD);
              novoAmpOp->setNome(nomeComponente);
              vectorElementos.push_back(novoAmpOp);
          }
          else if (tipo=='L')
          {

                Elemento *novoIndutor;

                sscanf(p,"%10s%10s%lg",na,nb,&valor);
                noA = atoi(na);
                noB = atoi(nb);
                novoIndutor = new Indutor(valor,noA,noB);
                novoIndutor->setNome(nomeComponente);
                vectorElementos.push_back(novoIndutor);


          }
          else if (tipo=='C')
          {

                Elemento *novoCapacitor;

                sscanf(p,"%10s%10s%lg",na,nb,&valor);
                noA = atoi(na);
                noB = atoi(nb);
                novoCapacitor = new Capacitor(valor,noA,noB);
                novoCapacitor->setNome(nomeComponente);
                vectorElementos.push_back(novoCapacitor);


          }
          else if (tipo=='K') {
              Elemento *novoTransformador;
              sscanf(p,"%10s%10s%10s%10s%lg",na,nb,nc,nd,&valor);

              noA = atoi(na);
              noB = atoi(nb);
              noC = atoi(nc);
              noD = atoi(nd);

              novoTransformador = new Transformador(valor,noA,noB,noC,noD);
              novoTransformador->setNome(nomeComponente);
              vectorElementos.push_back(novoTransformador);
          }
          else if (tipo=='D')
          {

                Elemento *novoDiodo;

                sscanf(p,"%10s%10s",na,nb);
                noA = atoi(na);
                noB = atoi(nb);
                novoDiodo = new Diodo(noA,noB);
                novoDiodo->setNome(nomeComponente);
                vectorElementos.push_back(novoDiodo);


          }
          else if (tipo=='$')
          {

                Elemento *novaChave;

                sscanf(p,"%10s%10s%10s%10s%lg",na,nb,nc,nd,&valor);
                noA = atoi(na);
                noB = atoi(nb);
                noC = atoi(nc);
                noD = atoi(nd);
                novaChave = new Chave(valor,noA,noB,noC,noD);
                novaChave->setNome(nomeComponente);
                vectorElementos.push_back(novaChave);


          }
          else if (tipo=='.')
          {

        //        Elemento *novaChave;
        //        char aux1[10];
                char aux2[10];

                sscanf(p,"%lg%lg%10s%lg",&parametros[0],&parametros[1],aux2,&parametros[2]);
            //    cout<<"aux"<<aux1<<endl;
        //        cout<<parametros[0]<<endl;
        //        cout<<parametros[1]<<endl;
        //        cout<<aux2<<endl;
        //        cout<<parametros[2]<<endl;

            /*    noA = atoi(na);
                noB = atoi(nb);
                noC = atoi(nc);
                noD = atoi(nd);
                novaChave = new Chave(noA,noB,noC,noD,valor);
                novaChave->setNome(nomeComponente);
                vectorElementos.push_back(novaChave);
*/

          }

      //    else if()
          else if (tipo=='*') { /* Comentario comeca com "*" */
            printf("Comentario: %s",txt);
            ne--;
          }
          else {
        //    if(txt[0] != ' ' || txt[0] != '\n')
              printf("Elemento desconhecido: %s\n",txt);
          //  cout<<"b";
          //    cout<<"a"<<teste<<'2'<<endl;
      //      cout<<"abortando leitura do netlist"<<endl;
        //    getch();
      //      vector<Elemento*> vectorVazio;
      //      return vectorVazio;;
          }
  }
  fclose(arquivo);
  return vectorElementos;
}




vector<double> transferirParaVector(double array[102][102], int nVariaveis)
{
    vector<double> saida;
    for(int i = 0; i <= nVariaveis; i++)
    {
    //    cout<<"guardando a variavel i:"<<array[i][nVariaveis+1]<<endl;
        saida.push_back(array[i][nVariaveis+1]);

    }

    return saida;



}
