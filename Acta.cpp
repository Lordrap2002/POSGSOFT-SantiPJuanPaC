#include <iostream>
#include "Acta.h"

Acta::Acta(){

}

Acta::Acta(int codigo, string fecha, string autor, string nombreTrabajo, string director,
            string codirector, string jurado1, string jurado2, vector<Criterio> criterios,
            Trabajo tipoTrabajo){
    setCodigo(codigo);
    setFecha(fecha);
    setAutor(autor);
    setNombreTrabajo(nombreTrabajo);
    setDirector(director);
    setCodirector(codirector);
    setJurado1(jurado1);
    setJurado2(jurado2);
    setCriterios(criterios);
    setTipoTrabajo(tipoTrabajo);
    setNotaFinal(0);
}

Acta::Acta(int codigo, string fecha, string autor, string nombreTrabajo, string director,
            string codirector, string jurado1, string jurado2, string comentariosGenerales, 
            Trabajo tipoTrabajo, Resultado resultadoFinal, float notaFinal){
    setCodigo(codigo);
    setFecha(fecha);
    setAutor(autor);
    setNombreTrabajo(nombreTrabajo);
    setDirector(director);
    setCodirector(codirector);
    setJurado1(jurado1);
    setJurado2(jurado2);
    setComentariosGenerales(comentariosGenerales);
    setTipoTrabajo(tipoTrabajo);
    setResultadoFinal(resultadoFinal);
    setNotaFinal(notaFinal);
}

void Acta::mostrarActa(){
    cout << "Acta #" << getCodigo() << endl
        << "Fecha: " << getFecha() << endl
        << "Autor: " << getAutor() << endl
        << "Nombre del trabajo: " << getNombreTrabajo() << endl
        << "Director: " << getDirector() << endl
        << "Codirector: " << getCodirector() << endl
        << "Jurado 1: " << getJurado1() << endl
        << "Jurado 2: " << getJurado2() << endl
        << "Tipo de trabajo: ";
        mostrarTipoTrabajo();
        cout << "Criterios:" << endl;
        for(vector<Criterio>::iterator pCriterio = this->criterios.begin();
            pCriterio != this->criterios.end(); pCriterio++){
            pCriterio->mostrarCriterio();
        }
        cout << "Comentarios generales: " << getComentariosGenerales() << endl
        << "Nota final: " << getNotaFinal() << endl
        << "Resultado final: ";
        mostrarResultadoFinal();
}

void Acta::llenarActa(){
    for(vector<Criterio>::iterator pCriterio = this->criterios.begin();
        pCriterio != this->criterios.end(); pCriterio++){
            pCriterio->getInfoCriterio().mostrarInfoCriterio();
            pCriterio->llenarCriterio();
            
    }
    cout << "Por favor escriba los comentarios generales: ";
    fflush(stdin);
    getline(cin, this->comentariosGenerales);
    calcularNotaFinal();
    if(this->notaFinal < 3.0){
        this->resultadoFinal = reprobado;
    }else{
        this->resultadoFinal = aprobado;
    }
}

void Acta::exportarActa(){
    ofstream archivoTemp;
    string nombreArchivo = this->nombreTrabajo + ".txt";
    archivoTemp.open(nombreArchivo);
    archivoTemp << "Acta #" << getCodigo() << endl
        << "Fecha: " << getFecha() << endl
        << "Autor: " << getAutor() << endl
        << "Nombre del trabajo: " << getNombreTrabajo() << endl
        << "Director: " << getDirector() << endl
        << "Codirector: " << getCodirector() << endl
        << "Jurado 1: " << getJurado1() << endl
        << "Jurado 2: " << getJurado2() << endl;
        exportarTipoTrabajo(nombreArchivo);
        cout << "Criterios:" << endl;
    archivoTemp.close();
    for(vector<Criterio>::iterator pCriterio = this->criterios.begin();
        pCriterio != this->criterios.end(); pCriterio++){
        pCriterio->exportarCriterio(nombreArchivo);
    }
    archivoTemp.open( nombreArchivo, ios::app);
    archivoTemp << "Comentarios generales: " << getComentariosGenerales() << endl
    << "Nota final: " << getNotaFinal() << endl;
    exportarResultadoFinal(nombreArchivo);
    archivoTemp.close();
}

void Acta::calcularNotaFinal(){
    for(vector<Criterio>::iterator pCriterio = this->criterios.begin();
        pCriterio != this->criterios.end(); pCriterio++){
            this->notaFinal += pCriterio->getNotaCriterio();
    }
}

void Acta::mostrarTipoTrabajo(){
    if(this->tipoTrabajo == aplicado){
        cout << "Aplicado" << endl;
    }else{
        cout << "Investigacion" << endl;
    }
}

void Acta::exportarTipoTrabajo(string nombreArchivo){
    ofstream archivoTemp;
    archivoTemp.open(nombreArchivo);
    if(this->tipoTrabajo == aplicado){
        archivoTemp << "Aplicado" << endl;
    }else{
        archivoTemp << "Investigacion" << endl;
    }
    archivoTemp.close();
}

void Acta::mostrarResultadoFinal(){
    if(this->resultadoFinal == aprobado){
        cout << "Aprobado" << endl;
    }else{
        cout << "Reprobado" << endl;
    }
}

void Acta::exportarResultadoFinal(string nombreArchivo){
    ofstream archivoTemp;
    archivoTemp.open(nombreArchivo);
    if(this->resultadoFinal == aprobado){
        archivoTemp << "Aprobado" << endl;
    }else{
        archivoTemp << "Reprobado" << endl;
    }
    archivoTemp.close();
}

int Acta::getCodigo(){
    return this->codigo;
}

void Acta::setCodigo(int codigo){
    this->codigo = codigo;
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

