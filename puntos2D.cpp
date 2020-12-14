/*********************************************************************************
 * Curso de Estructuras de Datos y Algoritmos. Práctica 2.
 * Universidad de Zaragoza.
 * Autores: Francisco Crespo Aznárez (798066) y Jorge Grima Terrén (801324)
 * Ultima revisión: 9 de noviembre de 2020
 * Fichero puntos2D.cpp
\********************************************************************************/

#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "puntos2D.h"
using namespace std;

void crear(double a, double b, string d, punto2D& p) {
	p.x = a;
	p.y = b;
	p.descripcion = d;
}

double suX(const punto2D p) {
	return p.x;
}

double suY(const punto2D p) {
	return p.y;
}

string suDescripcion(const punto2D p) {
	return p.descripcion;
}

bool iguales(const punto2D p1, const punto2D p2) {
	return ((p1.x == p2.x) && (p1.y == p2.y));
}

bool menor(const punto2D p1, const punto2D p2) {
	return (p1.x < p2.x)||(p1.x == p2.x && p1.y < p2.y);
}

string generarCadena(double r, double r2, string desc) {
     stringstream ss;
     ss << fixed << setprecision(2) << r << " ; " << fixed << setprecision(2) << r2 << " ; " << desc;
     return ss.str(); 
}  


