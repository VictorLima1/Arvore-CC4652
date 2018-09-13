#ifndef NO_HPP
#define NO_HPP
#include <cstdlib>

template <typename T>
class Arvore;

template <typename T>
class No{
	private:
		T valor;
		No<T>* pai;
		No<T>* esq;
		No<T>* dir;
		
	public:
		No(T valor):valor(valor), pai(NULL), esq(NULL), dir(NULL){
		
		}
	
		T getValor(){
			return valor;
		}
			
		T operator*(){
			return getValor();
		}
		
		friend class Arvore<T>;
		
};

#endif
