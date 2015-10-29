/** INFORMAÇÕES DO PROGRAMA:
 ** valor '9' no tabuleiro indica espaço em branco

**/
#include<stdlib.h> //atoi	
#include <iostream>
#include<vector> //push_back
#define TAM 3

struct No
{
    int estado[TAM][TAM];
    int custo;
};

std::vector<No*> borda;

static int estadoObjetivo[TAM][TAM];

No noCorrente;
No noInicial;
No* ptrInicial = &noInicial;



int i,j,k;

/*cria matriz com valores passados como argumento*/
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

/* cria o estado meta */
void criaObjetivo(){
	k = 1;
	for (i = 0; i <TAM; i++)
		for(j = 0; j < TAM; j++){
                    estadoObjetivo[i][j] = k;
                    k++;
		}
	} 
void criaEstadoInicial(char** argv){    
    ptrInicial->custo=0;
	k = 1;
	for (i = 0; i < TAM; i++)
		for (j = 0; j < TAM; j++){
			ptrInicial->estado[i][j] = atoi(argv[k]);
                        k++;
			}
        //return ptrInicial;
}


/*Verifica se a matriz passada é igual à matriz meta*/

bool testeObjetivo(int estadoCorrente[TAM][TAM]){
	for(i=0;i<TAM;i++)  // loop tamanho times for three lines
		for(int j=0;j<TAM;j++)  // loop for the three elements on the line
			if (estadoCorrente[i][j] != estadoObjetivo[i][j])
				return false;
	return true;
}




void insereFilhos(No no)
{
    
}

bool buscaArvore()
{
    borda.push_back(ptrInicial);
    do{
        noCorrente = *(borda.back());       // Toma o nó da última posição, como uma pilha
        borda.pop_back();                   //Retira último nó da borda
        if(testeObjetivo(noCorrente.estado))// Estado meta encontrado!
            return true;
        /*else*/                            // Ainda não foi encontrado...
        insereFilhos(noCorrente);
    }while(!borda.empty()); /*retorna falha */        
    std::cout<< "Meta não encontrada!";
    std::cout<<std::endl;
    return false;
}

int main(int argc, char **argv){

    criaObjetivo();//cria meta
    imprimeEstado(estadoObjetivo);
    criaEstadoInicial(argv);//cria primeiro estado corrente
    imprimeEstado(ptrInicial->estado);
    buscaArvore();

}