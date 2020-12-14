/*********************************************************************************
 * Curso de Estructuras de Datos y Algoritmos. Práctica 2.
 * Universidad de Zaragoza.
 * Autores: Francisco Crespo Aznárez (798066) y Jorge Grima Terrén (801324)
 * Ultima revisión: 9 de noviembre de 2020
 * Fichero practica1.cpp
\********************************************************************************/

#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "puntos2D.h"
#include "coleccion.h"
using namespace std;

void leer(istream& f, ostream& fSalida, punto2D datos, coleccion<punto2D>& puntos){

	string instruccion;
	double x, y;
	string desc;
	
	while(f >> instruccion){
		if(instruccion == "A"){ 		//Introducir nuevos datos
			
			f >> x >> y;
			getline(f >> std::ws, desc);
			crear(x, y, desc, datos);
			anyadir(puntos, datos);
			fSalida << "INTRODUCIDO: " << generarCadena(suX(datos), suY(datos), suDescripcion(datos)) << endl; 
		}
		else if(instruccion == "E"){	//Busqueda de datos
			f >> x >> y;
			crear(x, y, desc, datos);
			if (esta(puntos, datos)) {
				fSalida << "BUSQUEDA CON EXITO: ";
			}
			else {
				fSalida << "BUSQUEDA SIN EXITO: ";
			}
			fSalida << fixed << setprecision(2) << suX(datos) << " ; " << fixed << setprecision(2) << suY(datos) << endl;
		}
		else if(instruccion == "OU"){	//Localización de datos
			f >> x >> y;
			crear(x, y, desc, datos);
			if (obtenerUltimo(puntos, datos)) {
				fSalida << "LOCALIZADO CON EXITO: " << generarCadena(suX(datos), suY(datos), suDescripcion(datos)) << endl;
				}
			else {
				fSalida << "NO LOCALIZADO: " << fixed << setprecision(2) << suX(datos) << " ; " << fixed << setprecision(2) << suY(datos) << " ; " << endl;
			}
		}
		else if(instruccion == "B"){	//Eliminado con éxito
			f >> x >> y;
			crear(x, y, desc, datos);
			int numero = tamanyo(puntos);
			borrar(puntos, datos);
			if (tamanyo(puntos) < numero) {
				fSalida << "ELIMINADO CON EXITO: ";
			}
			else {
				fSalida << "NINGUNO PARA ELIMINAR: ";
			}
			fSalida << fixed << setprecision(2) << suX(datos) << " ; " << fixed << setprecision(2) << suY(datos) << endl;
		}
		else if(instruccion == "BU"){	//Borrado último
			f >> x >> y;
			crear(x, y, desc, datos);
			int numero = tamanyo(puntos);
			borrarUltimo(puntos, datos);
			if (tamanyo(puntos) < numero) {	
				fSalida << "BORRADO ULTIMO DE: ";
			}
			else {
				fSalida << "NO BORRABLE: ";
			}
			fSalida << fixed << setprecision(2) << suX(datos) << " ; " << fixed << setprecision(2) << suY(datos) << endl;
		}
		else if(instruccion == "LT"){	//Total de datos
			bool iter = true;
			fSalida << "----- TOTAL: " << tamanyo(puntos) << endl; 
			iniciarIterador(puntos);
			int auxAlt = 0;
			while (existeSiguiente(puntos)) {
				if (siguiente(puntos, datos, iter, auxAlt)) {
					fSalida << generarCadena(suX(datos), suY(datos), suDescripcion(datos)) << endl;
				}
			}
			fSalida << "-----" << endl;	
		}
		else if(instruccion == "LI"){	//Total n iguales
			bool iter = true;
			f >> x >> y;
			punto2D aux;
			crear(x, y, desc, aux);
			int repeticiones = 0;
			int auxAlt = 0;
			iniciarIterador(puntos);
			fSalida << "-----" << endl;
			while (existeSiguiente(puntos)) {
				if (siguiente(puntos, datos, iter, auxAlt)) {	
					if (iguales(datos, aux)) {
						repeticiones++;
						fSalida << generarCadena(suX(datos), suY(datos), suDescripcion(datos)) << endl;
					}
				}
			}	
			fSalida << "----- TOTAL: " << repeticiones << " IGUALES A: " << fixed << setprecision(2) << suX(aux) << " ; " << fixed << setprecision(2) << suY(aux) << endl;
		}
	}
}

void fichero(const char ficheroEntrada[],const char ficheroSalida[], punto2D datos, coleccion<punto2D>& puntos) {
	ofstream fSalida(ficheroSalida);
	if(fSalida.is_open()) {
		ifstream f(ficheroEntrada);
		if(f.is_open()) {
			leer(f, fSalida, datos, puntos);
			f.close();
		}
		else{
			cerr << "No ha podido abrirse el fichero\"" << ficheroEntrada << "\"." << endl;
		}
		fSalida.close();
	}
	else{
		cerr << "No ha podido abrirse el fichero\"" << ficheroSalida<< "\"." << endl;
	}
}

int main() {
	punto2D datos;
	const char ficheroEntrada[] = "entrada1.txt";
	const char ficheroSalida[] = "salida.txt";
	coleccion<punto2D> puntos;
	crear(puntos);
	fichero(ficheroEntrada, ficheroSalida, datos, puntos);
	return 0;
}
