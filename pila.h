/*********************************************************************************
 * Curso de Estructuras de Datos y Algoritmos. Práctica 2.
 * Universidad de Zaragoza.
 * Autores: Francisco Crespo Aznárez (798066) y Jorge Grima Terrén (801324)
 * Ultima revisión: 9 de noviembre de 2020
 * Fichero de implementación pila.h
\********************************************************************************/
#ifndef PILA_H
#define PILA_H

template<typename T> struct pila;
// Funciones de la pila 
template<typename T> void crear(pila<T>& p); 
// Apila un nuevo T a la pila del árbol c
template<typename T> void apilar (pila<T>& p, T e);
// Desapila el último T apilado en la pila del árbol c  
template<typename T> void desapilar (pila<T>& p);
// Devuelve el último T apilado en la pila del árbol c 
template<typename T> bool cima (const pila<T>& p, T& e);
template<typename T> int altura(const pila<T>& p);
template<typename T> bool esVacia(const pila<T>& p);
/* Funciones del iterador */
template<typename T> void inicializarIterador(pila<T>& p);
template<typename T> bool existeSiguiente(const pila<T>& p);
template<typename T> bool siguiente(pila<T>& p, T& e);
template<typename T> void liberar(pila<T>& p);

template<typename T>
struct pila{
	friend void crear<T>(pila<T>& p); 
	friend void apilar<T>(pila<T>& p, T e);
	friend void desapilar<T>(pila<T>& p);
	friend bool cima<T>(const pila<T>& p, T& e);
	friend int altura<T>(const pila<T>& p);
	friend bool esVacia<T>(const pila<T>& p);
	friend void inicializarIterador<T>(pila<T>& p);
	friend bool existeSiguiente<T>(const pila<T>& p);
	friend bool siguiente<T>(pila<T>& p, T& e);
	friend void liberar<T>(pila<T>& p);

   private:
		struct stack {
  			T dato;
  			stack* anteriorElemento;	//puntero a anterior cima
		};
  		stack* elementoCima;	
  		stack* iter;
		int alt;		
};

template<typename T>
void crear(pila<T>& p) {
	p.elementoCima = nullptr;
	p.iter = nullptr;
	p.alt = 0;
}

template<typename T>
void apilar (pila<T>& p, T e) {
	typename pila<T>::stack* auxPila = p.elementoCima;
	p.elementoCima = new typename pila<T>::stack;
	p.elementoCima->dato = e;
	p.elementoCima->anteriorElemento = auxPila;
	p.alt++;
}

template<typename T>
void desapilar (pila<T>& p) {
	if (!esVacia(p)) {
		typename pila<T>::stack* auxPila = p.elementoCima;
		p.elementoCima = p.elementoCima->anteriorElemento;
		p.alt--;
		delete auxPila;
	}
}

template<typename T>
bool cima (const pila<T>& p, T& e) { 
	if (p.elementoCima == nullptr) {
		return false;
	}
	 else {
		e = p.elementoCima->dato;
		return true;
	}
}

template<typename T>
int altura (const pila<T>& p){
	return p.alt;
}

template<typename T>
bool esVacia (const pila<T>& p) {
	return p.elementoCima == nullptr;
}

template<typename T>
void inicializarIterador (pila<T>& p) {
	p.iter = p.elementoCima;
}

template<typename T>
bool existeSiguiente (const pila<T>& p) {
	return p.iter != nullptr;                
}

template<typename T>
bool siguiente (pila<T>& p, T& e) {
	if(existeSiguiente(p)) {
		e = p.iter->dato;
		p.iter = p.iter->anteriorElemento;
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
void liberar (pila<T>& p){
	typename pila<T>::stack* auxPila;
	while(p.elementoCima != nullptr){
		auxPila = p.elementoCima;
		p.elementoCima = p.elementoCima->anteriorElemento;
		delete auxPila;
	}
}

#endif // fin de pila.h
