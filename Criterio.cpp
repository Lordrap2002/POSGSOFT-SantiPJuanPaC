#include <iostream>
#include "Criterio.h"

Criterio::Criterio(){

}

float Criterio::calcularNotaFinal(){
    return this->notaPromedio * getInfoCriterio().getPesoPorcentual();
}

float Criterio::calcularNotaPromedio(){
    return (this->notaJurado1 + this->notaJurado2) / 2;
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

float Criterio::getNotaFinal(){
    return this->notaFinal;
}

void Criterio::setNotaFinal(float notaFinal){
    this->notaFinal = notaFinal;
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