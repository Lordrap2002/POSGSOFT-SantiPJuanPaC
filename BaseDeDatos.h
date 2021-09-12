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
using std::string;
using std::vector;

class BaseDeDatos 
{
private:
	int consecutivoDeActas = 0;
	vector<Acta> actasCalificadas;
	vector<Acta> actasPendientes;
	vector<InfoCriterio> infoCriterios;

public:
	BaseDeDatos();
	void crearActa();
	void llenarActa(int codigo);
	void exportarActa(int codigo);
	void modificarInfoCriterios();
	void verHistorial();
	void verActa(int codigo);
	bool existeActa(int codigo);
	void crearCriteriosAlActa(Acta acta);

	//sets/gets
	vector<Acta> getActasPendientes();
	void setActasPendientes(vector<Acta> acta);
	vector<Acta> getActasCalificadas();
	void setActasCalificadas(vector<Acta> acta);
	vector<InfoCriterio> getInfoCriterios();
	void setInfoCriterios(vector<InfoCriterio> infoCriterio);
};
#endif /* !BASEDEDATOS_H */