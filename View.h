#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <stdlib.h>
#include "BaseDeDatos.h"
#include "Criterio.h"

using namespace std;

class View
{
private:
	BaseDeDatos sistema;
	Criterio criterios;

public:
	View();
	void mostrarMenu();
	void mostrarMenuEvaluador();
	void mostrarMenuDirectora();
	void mostrarMenuAsistente();
};
#endif /* !VIEW_H */