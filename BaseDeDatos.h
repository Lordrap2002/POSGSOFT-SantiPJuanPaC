#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Acta.h"
#include "InfoCriterio.h"
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class BaseDeDatos 
{
private:
	int consecutivoDeActas = 0, cantCriterios = 0;
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
	bool existeActaPendiente(int codigo);
	bool existeActaCalificada(int codigo);
	vector<Criterio> crearCriterios();
	InfoCriterio crearInfoCriterio();
	void importarDatos();
	void exportarDatos();
	//Trabajo identificarTipoTrabajo(int opcion);
	//Resultado identificarResultado(int opcion);
	bool existeCriterio(int id);

	//sets/gets
	int getConsecutivoDeActas();
	void setConsecutivoDeActas(int consecutivoDeActas);
	int getCantCriterios();
	void setCantCriterios(int cantCriterios);
	vector<Acta> getActasPendientes();
	void setActasPendientes(vector<Acta> acta);
	vector<Acta> getActasCalificadas();
	void setActasCalificadas(vector<Acta> acta);
	vector<InfoCriterio> getInfoCriterios();
	void setInfoCriterios(vector<InfoCriterio> infoCriterio);
};
#endif /* !BASEDEDATOS_H */