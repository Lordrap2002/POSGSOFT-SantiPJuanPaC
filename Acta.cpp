#include <iostream>
#include "Acta.h"

Acta::Acta(){

}

void Acta::mostrarActa(){

}

void Acta::llenarActa(){

}

void Acta::exportarActa(){

}

int Acta::getNumero(){
    return this->numero;
}

void Acta::setNumero(int numero){
    this->numero = numero;
}

string Acta::getFecha(){
    return this->fecha;
}

void Acta::setFecha(string fecha){
    this->fecha = fecha;
}

string Acta::getAutor(){
    return this->autor;
}

void Acta::setAutor(string autor){
    this->autor = autor;
}

string Acta::getNombreTrabajo(){
    return this->nombreTrabajo;
}

void Acta::setNombreTrabajo(string nombreTrabajo){
    this->nombreTrabajo = nombreTrabajo;
}

string Acta::getDirector(){
    return this->director;
}

void Acta::setDirector(string director){
    this->director = director;
}

string Acta::getCodirector(){
    return this->codirector;
}

void Acta::setCodirector(string codirector){
    this->codirector = codirector;
}

string Acta::getJurado1(){
    return this->jurado1;
}

void Acta::setJurado1(string jurado1){
    this->jurado1 = jurado1;
}

string Acta::getJurado2(){
    return this->jurado2;
}

void Acta::setJurado2(string jurado2){
    this->jurado2 = jurado2;
}

string Acta::getComentariosGenerales(){
    return this->comentariosGenerales;
}

void Acta::setComentariosGenerales(string comentariosGenerales){
    this->comentariosGenerales = comentariosGenerales;
}

float Acta::getNotaFinal(){
    return this->notaFinal;
}

void Acta::setNotaFinal(float notaFinal){
    this->notaFinal = notaFinal;
}

vector<Criterio> Acta::getCriterios(){
    return this->criterios;
}

void Acta::setCriterios(vector<Criterio> criterios){
    this->criterios = criterios;
}

Trabajo Acta::getTipoTrabajo(){
    return this->tipoTrabajo;
}

void Acta::setTipoTrabajo(Trabajo tipoTrabajo){
    this->tipoTrabajo = tipoTrabajo;
}

Resultado Acta::getResultadoFinal(){
    return this->resultadoFinal;
}

void Acta::setResultadoFinal(Resultado resultadoFinal){
    this->resultadoFinal = resultadoFinal;
}


void adicionaCriterio(Criterio criterio) {

}
