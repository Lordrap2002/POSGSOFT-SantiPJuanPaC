#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <stdlib.h>
#include "BaseDeDatos.h"

using namespace std;

class View
{
private:
	BaseDeDatos sistema;

public:
	View();
	void mostrarMenu();
	void mostrarMenuEvaluador();
	void mostrarMenuDirectora();
	void mostrarMenuAsistente();
};
#endif /* !VIEW_H */