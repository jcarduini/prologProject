resolve(P):-
	inicio(S),
	limite(L),
	busca(S,[S],Q,L),
	reverse(Q,P).

busca(S,P,P,_):-
	meta(S),!. /*FIM*/

busca(S,Visitados,P,L):-
	L>0,
	proximoEstado(S,N), /*gera próximo estado*/
	estadoPermitido(N), /*verifica se o estado é permitido*/
	\+member(N,Visitados), /*negação de n pertence a visitados*/
	L1 is L-1, /*decrementa limite*/
	busca(N,[N|Visitados],P,L1). /*continua busca*/


proximoEstado(Tab,[X|Tab]):-
	member(X,[1,2,3,4,5,6,7,8]).

estadoPermitido([]).

estadoPermitido([X|Y]):-
	naoAtaca(X,Y,1).

naoAtaca(_,[],_).
naoAtaca(X,[Y|Z],D):-
	X \= Y,
	D1 is abs(X-Y),
	D1 \= D,
	D2 is D+1,
	naoAtaca(X,Z,D2). 

/* base de dados */

inicio([]).
limite(0).
meta(S):-
	length(S,8).
