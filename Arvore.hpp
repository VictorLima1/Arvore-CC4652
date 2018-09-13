#ifndef ARV_HPP
#define ARV_HPP
#include "No.hpp"
#include <iostream>

using namespace std;

template <typename T>
class Arvore{
	private:
		No<T>* raiz;
		int n;
		
		void erd(No<T>* r){
			if(r){
				erd(r->esq);
				cout << **r << endl;
				erd(r->dir);
			}
		}
		
	public:
		Arvore(): raiz(NULL), n(0){
		
		}
		
		void erd(){
			erd(raiz);
		}
		
		
		void edr(){
			edr(raiz);
		}
		
		
		bool insere(T valor){
			No<T>* novo = new No<T>(valor);
			if(!novo)
				return false;
				
			No<T>* atual = raiz;
			No<T>* anterior = NULL;
			while(atual){
				anterior = atual;
				if(valor <= atual->valor){
					atual = atual->esq;	
				}else{
					atual = atual->dir;
				}
			}
			
			novo->pai = anterior;
			
			if(anterior){
				if(valor <= anterior->valor)
					anterior->esq = novo;
				else
					anterior->dir = novo;
			}else{
				raiz = novo;
			}
			
			n++;
			return true;
		}	
		
};

#endif
