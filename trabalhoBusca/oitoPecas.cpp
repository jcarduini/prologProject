/** INFORMAÇÕES DO PROGRAMA:
 ** valor '9' no tabuleiro indica espaço em branco

**/
#include<stdlib.h> //atoi	
#include <iostream>
#include<vector> //push_back

#define TAM 4

class No
{
	public:
	int estado [TAM][TAM];
	int custo;
};


static int estadoObjetivo[TAM][TAM];
static int estadoInicial[TAM][TAM];
int i,j,k;
/* cria o estado meta */

void criaObjetivo(){
	k = 1;
	for (i = 0; i <TAM; i++)
		for(j = 0; j < TAM; j++){
			estadoObjetivo[i][j] = k;
			k++;
		}
	} 
/*
	int estadoCorrente[TAM][tamanho];


*/
/*cria matriz com valores passados como argumento*/
/*
void criaEstadoInicial(char **argv){
	k = 1;
	for (i = 0; i < TAM; i++)
		for (j = 0; j < TAM; j++){
			estadoInicial[i][j] = atoi(argv[k]);
			k++;
			}

}


void imprimeEstado(int estado[TAM][TAM]){
   for(i=0;i<TAM;i++)  // loop tamanho times for three lines
    {
        for(int j=0;j<TAM;j++)  // loop for the three elements on the line
        	if (estado[i][j] != 9)
		 	std::cout<<estado[i][j];  // display the current element out of the arra
		else
			std::cout<<" ";
     	std::cout<<std::endl;  // when the inner loop is done, go to a new line
    }
   std::cout<<std::endl;
}	

*/
/*Verifica se a matriz passada é igual à matriz meta*/
/*
bool testeObjetivo(int estadoCorrente[TAM][TAM]){
	for(i=0;i<TAM;i++)  // loop tamanho times for three lines
		for(int j=0;j<TAM;j++)  // loop for the three elements on the line
			if (estadoCorrente[i][j] != estadoObjetivo[i][j])
				return false;
	return true;
}	
*/
int main(int argc, char**argv){

	criaObjetivo();//cria meta
	criaEstadoInicial(argv);//cria primeiro estado corrente
//	std::vector<std::shared_ptr<int[TAM][TAM]>> borda;
//	borda.resize(1);
//	borda.[0] = (estadoInicial[TAM][tamanho]);

//	(int) *borda[0] = new int [tadmanho] [TAM];
//	borda[0] = &estadoInicial[TAM][tamanho];	
//	imprimeEstado(estadoObjetivo);
//	imprimeEstado(estadoInicial);
//	imprimeEstado(estadoCorrente);
//	if(testeObjetivo(estadoInicial))
//	{
		std::cout<< "Meta atingida"<<std::endl; 
		return true;
		
//	}

	std::cout<< "Meta não encontrada";
	std::cout<<std::endl;
//	return false;
}
