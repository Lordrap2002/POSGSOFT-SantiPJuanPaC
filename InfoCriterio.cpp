#include <iostream>
#include "InfoCriterio.h"

InfoCriterio::InfoCriterio(){

}

InfoCriterio::InfoCriterio(int id, string descripcion, float pesoPorcentual) {
    setId(id);
    setDescripcion(descripcion);
    setPesoPorcentual(pesoPorcentual);
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
