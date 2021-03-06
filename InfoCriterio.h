#ifndef INFOCRITERIO_H
#define INFOCRITERIO_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class InfoCriterio{
    private:
        string descripcion;
        float pesoPorcentual;
        int id;
    public:
        InfoCriterio();
        InfoCriterio(int id, string descripcion, float pesoPorcentual);
        void mostrarInfoCriterio();
        
        //gets/sets
        string getDescripcion();
        void setDescripcion(string descripcion);
        float getPesoPorcentual();
        void setPesoPorcentual(float pesoPorcentual);
        int getId();
        void setId(int id);
};

#endif