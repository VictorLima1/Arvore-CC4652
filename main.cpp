#include "Arvore.hpp"

int main(){
	Arvore<int> a;
	a.insere(5);
    a.insere(2);
    a.insere(7);
    a.insere(1);
    a.insere(3);
    a.insere(6);
    a.insere(5);
    
	a.erd();
	
	return 0;
}
