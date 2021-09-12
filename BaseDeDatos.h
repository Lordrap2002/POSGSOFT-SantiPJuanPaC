#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include "Acta.h"
#include "InfoCriterio.h"

using std::cin;
using std::cout;
using std::getline;
using std::iterator;
using std::map;
using std::string;
using std::vector;

class BaseDeDatos 
{
private:
	int consecutivoDeActas = 0;
	map<int, Acta> actasCalificadas;
	map<int, Acta> actasPendientes;
	vector<InfoCriterio> infoCriterios;

public:
	baseDeDatos();
	void crearActa();
	void llenarActa();
	void exportarActa();
	void modificarInfoCriterios();
	void verHistorial();
	void verActa();

	bool existeActa(int numero);
	void crearCriteriosAlActa(Acta acta);
	//sets/gets
	int getActasPendientes();
	void setActasPendientes(Acta acta);
	int getActasCalificadas();
	void setActasCalificadas(Acta acta);
	int getInfoCriterios();
	void setInfoCriterios(InfoCriterio infoCriterio;);




};
#endif /* !BASEDEDATOS_H */