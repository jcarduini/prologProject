#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v){
	out <<"[";
	size_t last = v.size() - 1;
	for(size_t i = 0; i < v.size(); ++i){
		out<< v[i];
		if (i != last)
			", ";
	}
	out<< "]";
	return out;
}
	
bool attacks(std::vector<int> branch){

	std::cout<< "Entrando na função attacks com size = " <<branch.size()<< '\n';	
	if (branch.size() < 2){	
		std::cout<<"Nao ataca pelo tamanho\n";
		return false;
				}		
	int i = 0;//column
	//se ataca o vizinho direto
	while (i< branch.size()){
		std::cout<<" valor de i: "<< i;
		//se ataca as outras damas diagonal, ou mesma linha
		if( std::abs(branch[i] - branch.back()) == std::abs((branch.size()) - i) ){
			std::cout<<"ataca diagonal\n";
			return true;
			}
		if(branch[i] == branch.back()){		
			std::cout<<" valor de i +: "<< i;
			std::cout<<"Ataca porque eh igual! i = "<<i << " branch[i] = "<<branch[i]<< " queen ="<< branch.back()<<"\n";
			return true;
		}
		++i;
	}	
	//não tem conflito com nenhuma rainha do tabuleiro
	return false;	
}


void nextState(std::vector< std::vector<int> > & branchs, int queens)
{
	std::cout<< "Entrando na função nextState\n";	
	int i=0;
	while(i<queens){
		std::vector<int> sheet = branchs.front();
		std::cout<<"State: "<< sheet<< '\n';
		sheet.push_back(i);
		std::cout<<"State + : "<< sheet<< '\n';
		if (!attacks(sheet)){
			branchs.push_back(sheet);
			std::cout<<"In: "<< branchs.back()<< '\n';}
		i++;	
	}				//fim do nível
	
	branchs.erase(branchs.begin());	//apaga primeiro elemento da lista
}
	
int main(int argc, char** argv){

	std::cout<<"Quantas rainhas deseja usar? \n";
	int queens, i = 0;
	std::cin >> queens; 
	std::vector< std::vector<int> > board(1,std::vector<int>());
//	board[0][0] = {};
//	board[0].push_back([]);
	do{
		nextState(board, queens);
	}while (board[0].size() < queens - 1);	
	while (!board.empty())
			std::cout<< "Solução "<< ++i << ": " << board.front() <<'\n';  
	return 0;
}
