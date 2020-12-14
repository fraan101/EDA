/*********************************************************************************
 * Curso de Estructuras de Datos y Algoritmos. Práctica 2.
 * Universidad de Zaragoza.
 * Autores: Francisco Crespo Aznárez (798066) y Jorge Grima Terrén (801324)
 * Ultima revisión: 9 de noviembre de 2020
 * Fichero de implementación puntos2D.h
\********************************************************************************/

#ifndef PUNTOS2D_H
#define PUNTOS2D_H
using namespace std;

// Interfaz del TAD punto2D. Pre-declaraciones:

struct punto2D;
// {{DESCRIPCION  del  TAD: Los valores del TAD representan puntos del plano de dos dimensiones comentados 
// con una descripción. Cada punto tiene sus coordenadas x e y (números reales) y una descripción 
// (cadena). Para comparar y ordenar puntos2D se utilizan únicamente los valores de sus coordenadas: 
// primero el de la x, y luego el de la y.}
void crear(double a, double b, string d, punto2D& p);
// {Crea un punto2D con descripción d, con a como coordenada x, y con b como coordenada y.}
double suX(const punto2D p);
// {Devuelve el valor de la coordenada x del punto p.} 
double suY(const punto2D p);
// {Devuelve el valor de la coordenada y del punto p.} 
string suDescripcion(const punto2D p);
// {Devuelve la descripción del punto p.} 
bool iguales(const punto2D p1, const punto2D p2);
// {Devuelve verdad si y solo si las coordenadas x de los puntos p1 y p2 tienen el mismo valor, y 
// además también coincide el valor de sus coordenadas y. Devuelve falso en cualquier otro caso.}
bool menor(const punto2D p1, const punto2D p2);
// {Devuelve verdad si y solo si la coordenada x del punto p1 es menor que la coordenada x del 
// punto p2, o si las coordenadas x de ambos puntos son iguales pero la coordenada y del punto p1
// es menor que la coordenada y del punto p2. Devuelve falso en cualquier otro caso.}
string generarCadena(double r, double r2, string desc);
// {Devuelve una cadena con la representación alfanumérica de la información del punto p con el  
// formato: primero el valor de la coordenada x, luego una cadena “ ; ”, luego el valor de la  
// coordenada y, luego una    cadena “ ; ”, y por último la descripción del punto p
bool operator==(const punto2D p1, const punto2D p2);
// {Dados dos datos de tipo punto2D p1 y p2, devuelve verdad si y sólo si son iguales,
// devuelve falso en caso contrario}
bool operator<(const punto2D p1, const punto2D p2);
// {Dados dos datos de tipo punto2D p1 y p2, devuelve verdad si y sólo si p1 es menor que p2,
// devuelve falso en caso contrario}

//Declaración:
struct punto2D{
	friend void crear(double a, double b, string d, punto2D& p);
	friend double suX(const punto2D p);
	friend double suY(const punto2D p);
	friend string suDescripcion(const punto2D p);
	friend bool iguales(const punto2D p1, const punto2D p2);
	friend bool menor(const punto2D p1, const punto2D p2);
	friend string generarCadena(double r, double r2, string desc);
	friend bool operator==(const punto2D p1, const punto2D p2);
	friend bool operator<(const punto2D p1, const punto2D p2);

	private: 
  		double x;
		double y;
		string descripcion;
};

#endif // fin de puntos2D.h
