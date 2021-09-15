#include <iostream>
#include "InfoCriterio.h"

//Constructor vacío.
InfoCriterio::InfoCriterio(){

}

//Constructor con parámetros.
InfoCriterio::InfoCriterio(int id, string descripcion, float pesoPorcentual) {
    setId(id);
    setDescripcion(descripcion);
    setPesoPorcentual(pesoPorcentual);
}

/// <summary>
/// Método que es invocado desde BaseDeDatos para poder imprimir en pantalla la información de cada criterio.
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
