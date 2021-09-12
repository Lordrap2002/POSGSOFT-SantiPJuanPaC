#include <iostream>
#include "BaseDeDatos.h"
#include "Acta.h"

BaseDeDatos::BaseDeDatos() 
{

}

void BaseDeDatos::crearActa() 
{

}

void BaseDeDatos::llenarActa(int codigo) 
{
    /*
    * 1. creamos un nuevo objeto de tipo acta
    * 2. pedimos al usuario los valores de los atributos y se los asignamos en el objeto
    * 3. asignamos el consecutivo al acta
    * 4. Insertarmos los criterios actuales en el acta llamando crearCriteriosAlActa()
    * 4. adicionamos el acta al contenedor de actas
    * 5. incrementamos el consecutivo de actas
    */
    string valorString;
    Acta actaActual;

    //pedimos al usuario la fecha y la asignamos al atributo respectivo
    std::cout << "Digite fecha: ";
    getline(cin, valorString);
    actaActual.setFecha(valorString);
    //pedimos al usuario el autor y la asignamos al atributo respectivo
    std::cout << "Digite autor: ";
    getline(cin, valorString);
    actaActual.setAutor(valorString);
    //pedimos al usuario el nombre del trabajo y la asignamos al atributo respectivo
    std::cout << "Digite el nombre del trabajo: ";
    getline(cin, valorString);
    actaActual.setNombreTrabajo(valorString);

    //asignamos el consecutivo al acta
    actaActual.setNumero(this->consecutivoDeActas);
    //Insertarmos los criterios actuales en el acta llamando crearCriteriosAlActa()
    crearCriteriosAlActa(actaActual);
    //adicionamos el acta al contenedor de actas
    actasCalificadas[actaActual.getNumero()] = actaActual;




}


void crearCriteriosAlActa(Acta acta)
{
    /*
    * 1. Para cada uno de los INFOCRITERIOS definidos en base de datos creamos un Criterio
    * 2. Adicionamos cada criterio en el vector de criterios
    */

    //Recorriendo el VECTOR de Infocriterios de la base de datos vamos a ir creando los criterios en el acta.
    Criterio criterioActual;


    for (vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
        pInfoCriterio != this->infoCriterios.end(); pInfoCriterio++)
    {
        criterioActual.setInfoCriterio(pInfoCriterio);
        acta.adicionaCriterio(criterioActual);
    }
    


}


void BaseDeDatos::exportarActa(int codigo) 
{

}

void BaseDeDatos::modificarInfoCriterios() 
{
   
}

void BaseDeDatos::verHistorial() 
{
    
}

void BaseDeDatos::verActa(int codigo) {
    
}

vector<Acta> BaseDeDatos::getActasPendientes() {
    return actasPendientes;
}

void BaseDeDatos::setActasPendientes(vector<Acta> actasPendientes) {
    this->actasPendientes = actasPendientes;
}

vector<Acta> BaseDeDatos::getActasCalificadas() {
    return actasCalificadas;
}

void BaseDeDatos::setActasCalificadas(vector<Acta> actasCalificadas) {
    this->actasCalificadas = actasCalificadas;
}

vector<InfoCriterio> BaseDeDatos::getInfoCriterios() {
    return infoCriterios;
}

void BaseDeDatos::setInfoCriterios(vector<InfoCriterio> infoCriterio) {
    this->infoCriterios = infoCriterios;
}