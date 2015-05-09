#include <iostream>
#include <vector>
#include <cmath>

bool attacks(std::vector<int> board, int newQ){

	int i;
	int size = board.size();
	for (i=0; i< size; i++){
		//se ataca diagonal, ou mesma linha
		if((std::abs(size-i)==1 & std::abs(board[i]-newQ)<2) | (board[i] == newQ))
			return true;
		}
	//não tem conflito com nenhuma rainha do tabuleiro
	return false;	
}

void nextState(std::vector< std::vector<int> > & branchs, int queens)
{	
	int i=0;
	while(i<queens){
		std::vector<int> sheet = branchs[0];
		sheet.push_back(i);
//		if permitido(sheet)
			branchs.push_back(sheet);
		i++;	
	}				//fim do nível
	branchs.erase(branchs.begin());	//apaga primeiro elemento da lista
}
	
int main(int argc, char** argv){

	std::vector<int> board;
	if (!attacks(board,1))
		board.push_back(1);
	return 0;
}
