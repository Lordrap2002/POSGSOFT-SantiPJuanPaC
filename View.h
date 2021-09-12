#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <stdlib.h>
#include "BaseDeDatos.h"
#include "Criterio.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

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