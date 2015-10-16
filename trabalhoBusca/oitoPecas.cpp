/** INFORMAÇÕES DO PROGRAMA:
 ** valor '9' no tabuleiro indica espaço em branco

**/
#include<stdlib.h> //atoi	
#include <iostream>

static int estadoObjetivo[3][3];
static int estadoInicial[3][3];

int estadoCorrente[3][3];
int i,j,k;

void criaEstadoInicial(char **argv){
	k = 2;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			estadoCorrente[i][j] = atoi(argv[k]);
			k++;
	}

}
void criaObjetivo(){
	k = 1;
	for (i = 0; i <3; i++)
		for(j = 0; j < 3; j++){
			estadoObjetivo[i][j] = k;
			k++;
		}
	} 

void imprimeEstado(int estado[3][3]){
   for(i=0;i<3;i++)  // loop 3 times for three lines
    {
        for(int j=0;j<3;j++)  // loop for the three elements on the line
        	if (estado[i][j] != 9)
		 	std::cout<<estado[i][j];  // display the current element out of the array
     	std::cout<<std::endl;  // when the inner loop is done, go to a new line
    }
   std::cout<<std::endl;
}	

bool testeObjetivo(int estadoCorrente[3][3]){
	for(i=0;i<3;i++)  // loop 3 times for three lines
		for(int j=0;j<3;j++)  // loop for the three elements on the line
			if (estadoCorrente[i][j] != estadoObjetivo[i][j])
				return false;
	return true;
}	

int main(int argc, char**argv){

	criaObjetivo();
	criaEstadoInicial(argv);
	int **borda = (int **) malloc(sizeof (int *));
	imprimeEstado(estadoObjetivo);
	imprimeEstado(estadoCorrente);
	while(!testeObjetivo(estadoCorrente))
	{
		std::cout<< "Meta atingida"<<std::endl; 
		return true;
		
	}

	std::cout<< "false";
	std::cout<<std::endl;
	return false;
}
