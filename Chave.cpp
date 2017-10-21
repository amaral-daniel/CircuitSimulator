#include "Chave.h"

Chave::Chave(double Vlim,int A, int B,int C,int D)
{

    a = A;
    b = B;
    c = C;
    d = D;

    vlim = Vlim;
    tipo = CHAVETYPE;
    aberto = false;

}

bool Chave::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis, vector<double> estadoAnterior, bool primeiro)
{

  bool mudou;
  bool curto = !aberto;
  if(primeiro)//primeiro)
  {
      int k = rand()%2;

      if(k == 1) //começando com aberto
      {
    //      cout<<"começou chave aberto"<<endl;
          aberto = true;
      //    double condutancia = 0;
        //  matrizCircuito[a][a]+= 1e-9;
        //  matrizCircuito[b][b]+= 1e-9;
        //  matrizCircuito[a][b]-= 1e-9;
         // matrizCircuito[b][a]-= 1e-9;
		                    matrizCircuito[a][nVariaveis + 1]-=0;
        					matrizCircuito[b][nVariaveis + 1]+=0;
        					matrizCircuito[indiceCorrente][indiceCorrente]+=1;
        					matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
      }
      else //começando com curto
      {
    //      cout<<"começou chave curto"<<endl;
          aberto = false;
        //  matrizCircuito[a][a]+=1e+9;
        //  matrizCircuito[a][b]-=1e+9;
        //  matrizCircuito[b][a]-=1e+9;
         // matrizCircuito[b][b]+=1e+9;
						matrizCircuito[a][indiceCorrente]+=1;
			        	matrizCircuito[b][indiceCorrente]-=1;
				        matrizCircuito[indiceCorrente][a]-=1;
			  	        matrizCircuito[indiceCorrente][b]+=1;
 			 			matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
						



      }

      return true;
  }
  else
  {

            if(aberto)
            {
                          if((estadoAnterior[c] - estadoAnterior[d] > vlim))
                          {
                                  mudou = true;
                                  aberto = false;
                                 // matrizCircuito[a][a]+=1e+9;
                                 // matrizCircuito[b][b]+=1e+9;
                                 // matrizCircuito[b][a]-=1e+9;
                                 // matrizCircuito[a][b]-=1e+9;
                        matrizCircuito[a][indiceCorrente]+=1;
			        	matrizCircuito[b][indiceCorrente]-=1;
				        matrizCircuito[indiceCorrente][a]-=1;
			  	        matrizCircuito[indiceCorrente][b]+=1;
 			 			matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
						
	
                            }
                          else if(estadoAnterior[c] - estadoAnterior[d] <= vlim)
                          {
                                  mudou = false;
                                  aberto = true;
                          //        double condutancia = 0;
                                 // matrizCircuito[a][a]+= 1e-9;
                                 // matrizCircuito[b][b]+= 1e-9;
                                 // matrizCircuito[a][b]-= 1e-9;
                                 // matrizCircuito[b][a]-= 1e-9;
                          	matrizCircuito[a][nVariaveis + 1]-=0;
        					matrizCircuito[b][nVariaveis + 1]+=0;
        					matrizCircuito[indiceCorrente][indiceCorrente]+=1;
        					matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
        

                            }
                            else
                            {
                                  cout<<"ERRO!!!!!!!!!!!problema na chave,algo de errado nao esta certo"<<endl;

                            }

              }
              else if(curto)// && (estadoAnterior[c] - estadoAnterior[d] >= vlim)) //estava certo
              {

                            if(estadoAnterior[c] - estadoAnterior[d] >= vlim)
                            {
                          //    cout<<"tava em curto e a corrente tava positiva OK"<<endl;
                                mudou = false;
                                aberto = false;
                             //   matrizCircuito[a][a]+=1e+9;
                              //  matrizCircuito[b][b]-=1e+9;
                              //  matrizCircuito[b][a]-=1e+9;
                              //  matrizCircuito[a][b]+=1e+9;
                    matrizCircuito[a][indiceCorrente]+=1;
		        	matrizCircuito[b][indiceCorrente]-=1;
			        matrizCircuito[indiceCorrente][a]-=1;
 			        matrizCircuito[indiceCorrente][b]+=1;
 					matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;

                          }
                          else if(estadoAnterior[c] - estadoAnterior[d] < vlim) //tava errado
                          {
                          //    cout<<"tava em curto e a corrente tava negativa, mudando"<<endl;
                                mudou = true;
                                aberto = true;

                              //  double condutancia = 0;
                             //   matrizCircuito[a][a]+= 1e-9;
                             //   matrizCircuito[b][b]+= 1e-9;
                              //  matrizCircuito[a][b]-= 1e-9;
                              //  matrizCircuito[b][a]-= 1e-9;
                              //  matrizCircuito[indiceCorrente][indiceCorrente] += 1;
                            matrizCircuito[a][nVariaveis + 1]-=0;
        					matrizCircuito[b][nVariaveis + 1]+=0;
        					matrizCircuito[indiceCorrente][indiceCorrente]+=1;
        					matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;

                          }
                          else
                          {
                              cout<<"ERRO!!!!!!!!!!!problema na chave,algo de errado nao esta certo"<<endl;
                          }


            }
    }


        return mudou;
}

void Chave::print(){
    cout<<"Chave com terminais "<<a<<" , "<<b<<" , "<<c<<" , "<<d<<" e Vlim: "<<vlim<<endl;


}


int Chave::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
    return 1;


}

int Chave::quantasCorrentes()
{
    return 1;

}
