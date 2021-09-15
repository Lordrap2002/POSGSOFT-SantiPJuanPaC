#include <iostream>
#include "InfoCriterio.h"

//Constructor vac�o.
InfoCriterio::InfoCriterio(){

}

//Constructor con par�metros.
InfoCriterio::InfoCriterio(int id, string descripcion, float pesoPorcentual) {
    setId(id);
    setDescripcion(descripcion);
    setPesoPorcentual(pesoPorcentual);
}

/// <summary>
/// M�todo que es invocado desde BaseDeDatos para poder imprimir en pantalla la informaci�n de cada criterio.
/// </summary>
void InfoCriterio::mostrarInfoCriterio(){
    cout << "Criterio #" << this->id << endl
        << "Descripcion: " << this->descripcion << endl
        << "Peso porcentual: " << this->pesoPorcentual << endl;
}

string InfoCriterio::getDescripcion(){
    return this->descripcion;
}

void InfoCriterio::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

float InfoCriterio::getPesoPorcentual(){
    return this->pesoPorcentual;
}

void InfoCriterio::setPesoPorcentual(float pesoPorcentual){
    this->pesoPorcentual =pesoPorcentual;
}

int InfoCriterio::getId(){
    return this->id;
}

void InfoCriterio::setId(int id){
    this->id = id;
}
