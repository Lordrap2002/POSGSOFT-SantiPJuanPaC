#include <iostream>
#include "Criterio.h"

Criterio::Criterio(){

}

float Criterio::calcularNotaCriterio(){
    return this->notaPromedio * getInfoCriterio().getPesoPorcentual();
}

float Criterio::calcularNotaPromedio(){
    return (this->notaJurado1 + this->notaJurado2) / 2;
}

void Criterio::mostrarCriterio(){

}

void Criterio::llenarCriterio(){
    cout << "Por favor escriba el comentario del jurado 1: ";
    cin >> this->comentario1;
    cout << "Por favor escriba la nota del jurado 1: ";
    cin >> this->notaJurado1;
    cout << "Por favor escriba el comentario del jurado 2: ";
    cin >> this->comentario2;
    cout << "Por favor escriba la nota del jurado 2: ";
    cin >> this->notaJurado2;
    cout << "Por favor escriba el comentario general del criterio: ";
    cin >> this->comentarioGeneral;
    calcularNotaPromedio();
    calcularNotaCriterio();
}

float Criterio::getNotaJurado1(){
    return this->notaJurado1;
}

void Criterio::setNotaJurado1(float notaJurado1){
    this->notaJurado1 = notaJurado1;
}

float Criterio::getNotaJurado2(){
    return this->notaJurado2;
}

void Criterio::setNotaJurado2(float notaJurado2){
    this->notaJurado2 = notaJurado2;
}

float Criterio::getNotaPromedio(){
    return this->notaPromedio;
}

void Criterio::setNotaPromedio(float notaPromedio){
    this->notaPromedio = notaPromedio;
}

float Criterio::getNotaCriterio(){
    return this->notaCriterio;
}

void Criterio::setNotaCriterio(float notaCriterio){
    this->notaCriterio = notaCriterio;
}

string Criterio::getComentario1(){
    return this->comentario1;
}

void Criterio::setComentario1(string comentario1){
    this->comentario1 = comentario1;
}

string Criterio::getComentario2(){
    return this->comentario2;
}

void Criterio::setComentario2(string comentario2){
    this->comentario2 = comentario2;
}

string Criterio::getComentarioGeneral(){
    return this->comentarioGeneral;
}

void Criterio::setComentarioGeneral(string comentarioGeneral){
    this->comentarioGeneral = comentarioGeneral;
}

InfoCriterio Criterio::getInfoCriterio(){
    return this->infoCriterio;
}

void Criterio::setInfoCriterio(InfoCriterio infoCriterio){
    this->infoCriterio = infoCriterio;

}