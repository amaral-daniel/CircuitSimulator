#include <vector>
#include <iostream>
#include "Circuito.h"
#include "funcoesAuxiliares.h"

int main(){
while(true){
    string nomeArquivo;
    cout<<"Digite o nome do arquivo."<<endl;
    cin>>nomeArquivo;
    double parametros[3];
    vector<Elemento*> leitura = lerArquivo(nomeArquivo.c_str(),parametros);
    if(leitura.size() == 0)
    {
        cout<<"ERRO!!Leitura do netlist falhou.Encerrando programa...."<<endl;
        return 0;
    }
    if(parametros[0] <= 0 || parametros[1] <= 0)
    {
        cout<<"ERRO!!Passo e tempo de execucao invalidos.Encerrando programa....."<<endl;
        return 0;
    }
      //  cout<<"a"<<endl;
  //  Elemento *novaFonte, *novoResistor,*novoDiodo, *novoResistor2, *novoIndutor;
  //  novaFonte = new FonteDeTensao(2,1,0);
  //  novaFonte = new FonteDeTensaoSenoidal(0,2.0,1.0,0,0.0,0.0,20,1,0);
  //  novoIndutor = new Indutor(0.5,1,2);
  //  novoResistor = new Resistor(1.0,2,0);
  //  vector<Elemento*> leitura;
  //  leitura.push_back(novaFonte);
  //  leitura.push_back(novoResistor);
  //  leitura.push_back(novoIndutor);

  //  leitura.push_back(novoDiodo);
  //  leitura.push_back(novoResistor2);
    Circuito meuCircuito(leitura, parametros[1]);
    if(!meuCircuito.criarMatriz())
    {
        cout<<"ERRO!!!Falha ao criar matriz"<<endl;
        return -1;
    }

    for(int i = 0; i*parametros[1] <= parametros[0]; i++)//quantos passos ele vai dar
    {
        meuCircuito.newtonRaphson();
        meuCircuito.atualizarMatriz();
      //  cout<<"matriz depois de atualizada e resolvida"<<endl;
        //meuCircuito.printSolucao();
    //    cout<<"atualizou matriz"<<endl;
    }
    cout<<"Solucao final"<<endl;
    meuCircuito.printSolucao();
}


    return 0;
}
