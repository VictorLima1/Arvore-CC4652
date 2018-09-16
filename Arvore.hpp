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
		
		void destrutor(No<T>* s){
        if(s){
            destrutor(s->esq);
            destrutor(s->dir);
            delete(s);
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
		
		No<T>* busca(T valor){
        	No<T>* atual = raiz;
        	while(atual){
            	if(valor==atual->valor)
                	return atual;

            	if(valor <= atual->valor){
                	atual = atual->esq;
            	}else{
                	atual = atual->dir;
            	}
        	}
			return 0;
    	}

    	
    	int contaFilhos(No<T>* x){
    		return (x->esq!=NULL)+(x->dir!=NULL);
    	}
    	
    	No<T>** ponteiroDoPai(No<T>* p){
    		if(p->pai->esq == p){
    			return &(p->pai->esq);
    		}else{
    			return &(p->pai->dir);
    		}
    	}
    	
    	No<T>* antes(No<T>* x){
    		No<T>* a = x->esq;
    		while(a->dir){
    			a = a->dir;
    		}
    		
    		return a;
    	}
    	
    	void remove(No<T>* x){
    		int filhos = contaFilhos(x);
    		
    		if(filhos == 0){
    			*ponteirosDoPai(x) = nullptr;
    			delete x;
    		}else if(filhos == 1){
    			No<T> *f = x->esq;
    			if(!f)
    				f = x->dir;
    		    		
    			*ponteirosDoPai(x) = f;
    			f->pai = x->pai;
    			delete x;
    		}
    		else{
    			No<T> *ant = antes(x);
    			x->valor=ant->valor;
    			remove(ant);
    		}
    	}
    	
    	~Arvore(){
        	destrutor(raiz);
    	}
		
};

#endif
