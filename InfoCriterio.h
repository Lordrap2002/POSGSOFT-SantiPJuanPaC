#ifndef INFOCRITERIO_H
#define INFOCRITERIO_H

#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::string;

class InfoCriterio{
    private:
        string descripcion;
        float pesoPorcentual;
        int id;
    public:
        InfoCriterio();
        string getDescripcion();
        void setDescripcion(string descripcion);
        float getPesoPorcentual();
        void setPesoPorcentual(float pesoPorcentual);
        int getId();
        void setId(int id);
};

#endif