#include "Diodo.h"

Diodo::Diodo(int A, int B)
{

    a = A;
    b = B;

    tipo = DIODOTYPE;
    aberto = false;

}

bool Diodo::estampar(double matrizCircuito[][MAX_NOS + 2],int nVariaveis, vector<double> estadoAnterior, bool primeiro)
{

  bool mudou;
  bool curto = !aberto;
  if(primeiro)
  {
  //    cout<<"primeira vez que tenta o diodo"<<endl;
            int k = rand()%2;
            if(k == 1)
            {

        	matrizCircuito[a][nVariaveis + 1]-=0;
        	matrizCircuito[b][nVariaveis + 1]+=0;
        	matrizCircuito[indiceCorrente][indiceCorrente]+=1;
        	matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
        	aberto = true;

            }
            else
            {

	        matrizCircuito[a][indiceCorrente]+=1;
        	matrizCircuito[b][indiceCorrente]-=1;
	        matrizCircuito[indiceCorrente][a]-=1;
 	        matrizCircuito[indiceCorrente][b]+=1;
 		matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
		aberto = false;

            }

            return true;
  }
  else
  {

            if(aberto)
            {
                      if((estadoAnterior[a] - estadoAnterior[b] <= 0) )//estava certo
                      {
                                  mudou = false;
                                aberto = true;
     
                        	matrizCircuito[a][nVariaveis + 1]-=0;
        			matrizCircuito[b][nVariaveis + 1]+=0;
        			matrizCircuito[indiceCorrente][indiceCorrente]+=1;
        			matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
        		

                        }
                          else if((estadoAnterior[a] - estadoAnterior[b]) >= 0)//estava erradissimo
                        {
   					mudou = true;
                              		aberto = false;
					matrizCircuito[a][indiceCorrente]+=1;
			        	matrizCircuito[b][indiceCorrente]-=1;
				        matrizCircuito[indiceCorrente][a]-=1;
			  	        matrizCircuito[indiceCorrente][b]+=1;
 			 		matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
						
						
			}


                        else
                        {
                            cout<<"ERRO!!!!!!!algo de errado nao esta certo no diodo"<<endl;

                        }
            }
            else if(curto)
            {
                      if( estadoAnterior[indiceCorrente]>=0 )//estava certo
                      {
                          //    cout<<"tava em curto e a corrente tava positiva OK"<<endl;
                              mudou = false;
                              aberto = false;
	                       matrizCircuito[a][indiceCorrente]+=1;
		        	matrizCircuito[b][indiceCorrente]-=1;
			        matrizCircuito[indiceCorrente][a]-=1;
 			        matrizCircuito[indiceCorrente][b]+=1;
 				matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
		      }

                      else if(estadoAnterior[indiceCorrente] < 0 ) //tava errado
                      {
                      //    cout<<"tava em curto e a corrente tava negativa, mudando"<<endl;
				        mudou = true;
			                aberto = true;

			           	matrizCircuito[a][nVariaveis + 1]-=0;
 					matrizCircuito[b][nVariaveis + 1]+=0;
        				matrizCircuito[indiceCorrente][indiceCorrente]+=1;
        				matrizCircuito[indiceCorrente][nVariaveis + 1]+=0;
        		

                      }
                      else
                      {
                          cout<<"ERRO!!!!!!!algo de errado nao esta certo no diodo"<<endl;

                      }
            }
            else
            {
                cout<<"ERRO!!!!!!!algo de errado nao esta certo no diodo"<<endl;

            }


    }

    return mudou;
}

void Diodo::print(){
    cout<<"Diodo com terminais "<<a<<" , "<<b<<endl;


}


int Diodo::aumentoVariaveis(int n)
{
    indiceCorrente = n + 1;
    return 1;


}

int Diodo::quantasCorrentes()
{
    return 1;

}
