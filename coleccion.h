/*********************************************************************************
 * Curso de Estructuras de Datos y Algoritmos. Práctica 2.
 * Universidad de Zaragoza.
 * Autores: Francisco Crespo Aznárez (798066) y Jorge Grima Terrén (801324)
 * Ultima revisión: 9 de noviembre de 2020
 * Fichero de implementación coleccion.h
\********************************************************************************/

#include "pila.h"

#ifndef COLECCION_H
#define COLECCION_H

// Interfaz del TAD genérico coleccion. Pre-declaraciones:
//El tipo T requerirá tener definidas las funciones:
// bool iguales (const T& e1, const T& e2);
// bool menor (const T& e1, const T& e2);

template<typename T> struct coleccion;
//{DESCRIPCION  del  TAD:  {Los valores del TAD representan colecciones de elementos, ordenadas de menor a 
// mayor elemento (con respecto a la operación “menor”), en las que puede haber elementos “iguales”.  
// Los elementos iguales se mantendrán ordenados según su orden de incorporación a la colección  
// (primero, el   que el primero de ellos se haya añadido; último, el más recientemente añadido).}
template<typename T> void crear(coleccion<T>& c);
//{Crea una colección vacía, sin elementos.}
template<typename T> void anyadir(coleccion<T>& c, T& p);
//{Devuelve la colección resultante de añadir el elemento e a la colección c. Si en c ya había 
// algún elemento igual a e, entonces e quedará como el último elemento de todos los iguales a él.}
template<typename T> bool esta(const coleccion<T>& c, const T& p);
//{Devuelve verdad si y sólo si en c hay algún elemento igual al elemento e.
template<typename T> bool obtenerUltimo(coleccion<T>& c, T& p);
//{Si en c hay algún elemento igual a e, devuelve el último elemento igual a e que fue añadido a la colección c.
//Parcial: no definida si e no está en c.}  
template<typename T> void borrar(coleccion<T>& c, const T& p);
//{Si en c hay algún elemento igual a e, devuelve la colección resultante de borrar de c todos los 
// elementos iguales a e. En caso contrario, devuelve una colección igual a c.} 
template<typename T> void borrarUltimo (coleccion<T>& c, const T& p);
//{Si en c hay algún elemento igual a e, devuelve la colección resultante de borrar de c el último 
// elemento igual a e que fue añadido a la colección. En caso contrario, devuelve una colección igual a c.}
template<typename T> int tamanyo(const coleccion<T>& c);
//{Devuelve el número total de elementos en la colección.} 
template<typename T> bool esVacia(const coleccion<T>& c);
//{Devuelve verdad si y sólo si c no tiene ningún elemento.} 


//{Las siguientes operaciones constituyen un iterador:} 
template<typename T> void iniciarIterador(coleccion<T>& c);
//{Inicializa el iterador para recorrer los elementos de la colección c, de forma que el siguiente 
// elemento a visitar sea el primero (situación de no haber visitado ningún elemento).} 
template<typename T> bool existeSiguiente(const coleccion<T>& c);
//{Devuelve verdad si queda algún elemento por visitar con el iterador de la colección c, devuelve  
// falso si ya se ha visitado el último elemento.} 
template<typename T> bool siguiente(coleccion<T>& c, T& p, bool& iterador, int& auxAlt);
//{Devuelve el siguiente elemento a visitar con el iterador de la colección c.  
// Parcial: la operación no está definida si no quedan elementos por visitar (no haySiguiente(c).} 




// Funciones recursivas

// Inserta un nodo binario con el elemento e en el árbol l
template<typename T> void anyadirRec(typename coleccion<T>::arbin*& n, T p, int& datos);
// Devuelve cierto si el elemento "p" está en el nodo, sino hace recursividad hasta llegar a las hojas
template<typename T> bool estaRec (typename coleccion<T>::arbin* n, T p);
// Devuelve cierto si el elemento "p" está en el nodo, sino hace recursividad hasta llegar a las hojas 
template<typename T> bool obtenerUltimoRec (typename coleccion<T>::arbin* n, T& p);
// Borra un nodo binario que contiene un elemento igual a "p" en el árbol l
template<typename T> void borrarRec (typename coleccion<T>::arbin*& n, const T& p, bool& quitado, int& datoBorrar);
// Borra el último nodo binario que contiene un elemento igual a "p" en el árbol 
template<typename T> void borrarUltimoRec(typename coleccion<T>::arbin*& n, const T& p, bool& quitado);

template<typename T> void borrarMaximo(typename coleccion<T>::arbin*& n, pila<T>& p);
// Devuelve el máximo elemento en el árbol a partir del nivel "dim"
template<typename T> void maximoRec (typename coleccion<T>::arbin* n, typename coleccion<T>::arbin*& maximo);




//Declaración:
template<typename T>
struct coleccion{
    friend void crear<T> (coleccion<T>& c);
    friend void anyadir<T>(coleccion<T>& c, T& p);
    friend bool esta<T> (const coleccion<T>& c, const T& p);
    friend bool obtenerUltimo<T> (coleccion<T>& c, T& p);
    friend void borrar<T> (coleccion<T>& c, const T& p);
    friend void borrarUltimo<T> (coleccion<T>& c, const T& p);
    friend int tamanyo<T> (const coleccion<T>& c);
    friend bool esVacia<T> (const coleccion<T>& c);
    friend void iniciarIterador<T> (coleccion<T>& c);
    friend bool existeSiguiente<T> (const coleccion<T>& c);
    friend bool siguiente<T>(coleccion<T>& c, T& p, bool& iterador, int& auxAlt);
  
  private: 
  		struct arbin {
  			pila<T> valor;
  			arbin* izquierda;
  			arbin* derecha;
  		};
  		int numDatos;
  		pila<arbin*> index;
  		arbin* raiz;			//puntero al nodo raiz

		friend void anyadirRec<T>(arbin*& n, T p, int& datos);
		friend bool estaRec<T>(arbin* n, T p);
		friend bool obtenerUltimoRec<T>(arbin* n, T& p);
 	   	friend void borrarRec<T>(arbin*& n, const T& p, bool& quitado, int& datoBorrar);
		friend void borrarUltimoRec<T>(arbin*& n, const T& p, bool& quitado);
		friend void borrarMaximo<T>(arbin*& n, pila<T>& p);
   		friend void maximoRec<T>(arbin* n, arbin*& maximo);
};

// Implementación de las operaciones:

template<typename T> // hecho
void crear (coleccion<T>& c) {
    c.numDatos = 0;
    c.raiz = nullptr;
	crear(c.index);
}

template<typename T>
void anyadir (coleccion<T>& c, T& p) {
	anyadirRec(c.raiz, p, c.numDatos);
}

template<typename T>
void anyadirRec(typename coleccion<T>::arbin*& n, T p, int& datos){
    if(n == nullptr){          // Caso base 
        n = new typename coleccion<T>::arbin; 
        crear(n->valor);
        apilar(n->valor, p);
        n->izquierda = nullptr;
        n->derecha = nullptr;
        datos++;	
    }
    else{       // Caso recurrente para seguir buscando donde insertarlo
    	T aux;
   	 	if (cima(n->valor, aux)) {
   			if(iguales(aux, p)){  
        		apilar(n->valor, p); 
        		datos++;      
   			}
      	  	else if (menor(p, aux)){
        	    anyadirRec(n->izquierda, p, datos);
     	  	}
      	  	else{
      	      	anyadirRec(n->derecha, p, datos);
      	  	}
      	}
    }
}

template<typename T>
bool esta(const coleccion<T>& c, const T& p) {
  	return estaRec(c.raiz, p);
}

template<typename T>
bool estaRec(typename coleccion<T>::arbin* n, T p) {
	if (n == nullptr) {
		return false;
	}
	else {
		T aux;
		if (!cima(n->valor, aux)) return false;
		if (menor(p, aux)) {	//caso de que p sea menor que aux
			return estaRec(n->izquierda, p);
		}
		else if (iguales(p, aux)) {		//en caso de que sean iguales
			return true;
		}
		else {	//caso en el p es mayor que aux
		    return estaRec(n->derecha, p);
		}
	}
}

template<typename T>
bool obtenerUltimo(coleccion<T>& c, T& p) {
    return obtenerUltimoRec(c.raiz, p);
}

template<typename T>
bool obtenerUltimoRec(typename coleccion<T>::arbin* n, T& p) {
	if (n == nullptr) {
		return false;
	}
	else {
		T aux;
		if (!cima(n->valor, aux)) return false;
		if (menor(p, aux)) {	//caso de que p sea menor que aux
			return obtenerUltimoRec(n->izquierda, p);
		}
		else if (iguales(aux, p)) {	//en caso de que sean iguales
			p = aux;
			return true;
		}
		else{	//caso en el p es mayor que aux
			return obtenerUltimoRec(n->derecha, p);
		}
	}
}

template<typename T>
void borrar(coleccion<T>& c, const T& p) {
	int numBorrar;
	bool quitado = false;
	borrarRec(c.raiz, p, quitado, numBorrar);
	if(quitado){
		c.numDatos -= numBorrar;
		if (c.numDatos == 0)
			c.raiz = nullptr;
	}
}

template<typename T>
void borrarRec(typename coleccion<T>::arbin*& n, const T& p, bool& quitado, int& datoBorrar) {
	if (n != nullptr) {
		T auxPila;
		if (cima(n->valor, auxPila)) {
			if (menor(p, auxPila)) {
				borrarRec(n->izquierda, p, quitado, datoBorrar);
			}
			else if (menor(auxPila, p)) {
				borrarRec(n->derecha, p, quitado, datoBorrar);															
			}
			else if (iguales(p, auxPila)) {
				typename coleccion<T>::arbin* aux;
				if (n->izquierda == nullptr && n->derecha == nullptr) {
					datoBorrar = altura(n->valor);
					delete n;
					n = nullptr;
				}
				else if (n->izquierda == nullptr) {
					aux = n;
					n = n->derecha;
					datoBorrar = altura(aux->valor);
					liberar(aux->valor);
					delete aux;
				}
				else if (n->derecha == nullptr) {
					aux = n;
					n = n->izquierda;
					datoBorrar = altura(aux->valor);
					liberar(aux->valor);
					delete aux;
				}
				else {
					datoBorrar = altura(n->valor);
					borrarMaximo(n->izquierda, n->valor);	
				}
				quitado = true;
			}
		}
	}
}

template<typename T>
void borrarUltimo(coleccion<T>& c, const T& p) {
	bool quitado = false;
	borrarUltimoRec(c.raiz, p, quitado);
	if(quitado) {
		c.numDatos--;	//si se ha borrado
		if(!c.numDatos) {	//en caso de que se hayan borrado todos los nodos
			c.raiz = nullptr;
		}
	}
}

template<typename T> 
void borrarUltimoRec(typename coleccion<T>::arbin*& n, const T& p, bool& quitado){
	if (n != nullptr) {
		T auxPila;
		if (cima(n->valor, auxPila)) {
			if (menor(p, auxPila)) {
				borrarUltimoRec(n->izquierda, p, quitado);
			}
			else if (menor(auxPila, p)) {
				borrarUltimoRec(n->derecha, p, quitado);
			}
			else if (iguales(p,auxPila)) {
				desapilar(n->valor);
				if (!altura(n->valor)) {		//en caso de que solo quede un elemento en la pila
					typename coleccion<T>::arbin* aux;
					if (n->izquierda == nullptr && n->derecha == nullptr) {
						delete n;
						n = nullptr;
					}
					else if (n->izquierda == nullptr) {
						aux = n;
						n = n->derecha;
						liberar(aux->valor);
						delete aux;
					}
					else if (n->derecha == nullptr) {
						aux = n;
						n = n->izquierda;
						liberar(aux->valor);
						delete aux;
					}
					else {
						borrarMaximo(n->izquierda, n->valor);
					
					}
				}
				quitado = true;
			}
		}
	}
}

template<typename T>
void borrarMaximo(typename coleccion<T>::arbin*& n, pila<T>& p) {
	typename coleccion<T>::arbin* aux;
	if (n->derecha == nullptr) {
		p = n->valor;
		aux = n;
		n = n->izquierda;
		delete aux;
	}
	else {
		borrarMaximo(n->derecha, p);
	}
}

template<typename T>
int tamanyo(const coleccion<T>& c) {
    return c.numDatos;
}

template<typename T>
bool esVacia(const coleccion<T>& c) {
    return c.raiz == nullptr;
}

template<typename T>
void maximoRec(typename coleccion<T>::arbin* n, typename coleccion<T>::arbin*& maximo) { /////////// Preguntar si es necesario o no
	if (n != nullptr) {
		if (n->derecha == nullptr) {
			maximo = n;
		}
		else {
			maximoRec(n->derecha, maximo);
		}
	}
}

template<typename T>
void iniciarIterador(coleccion<T>& c) {
  	typename coleccion<T>::arbin* aux = c.raiz; 
	liberar(c.index);
   	while(aux != nullptr){    // Mientras no lleguemos al final
        apilar(c.index, aux);     // Apilamos
        aux = aux->izquierda;     // Vamos avanzando
    }																																						
}

template<typename T>
bool existeSiguiente(const coleccion<T>& c) {
   return !esVacia(c.index);
}

template<typename T>
bool siguiente(coleccion<T>& c, T& p, bool& iterador, int& auxAlt) {
	if(existeSiguiente(c)){
		typename coleccion<T>::arbin* aux;
		
		if (!cima(c.index, aux)) return false;
		if (iterador && (altura(aux->valor) > 1)) {
			auxAlt = altura(aux->valor);
			inicializarIterador(aux->valor);
			iterador = false;
		}
		if (auxAlt > 1) {
			if (existeSiguiente(aux->valor)) {
				if (siguiente(aux->valor, p)) {
					auxAlt--;
				}
				else {
					return false;
				}
			}
		}
		else {
			if (!iterador) {
				if (!siguiente(aux->valor, p)) return false;
			}
			else {
				if (!cima(aux->valor, p)) return false;
			}
			desapilar(c.index);
			aux = aux->derecha;
			while(aux != nullptr){
				apilar(c.index, aux);
				aux = aux->izquierda;
			}
			iterador = true;
		}
		return true;	
	}
	else{
		return false;
	}
}
				
#endif // fin de coleccion.h
