#include <iostream>
#include "BaseDeDatos.h"
#include "Acta.h"

BaseDeDatos::BaseDeDatos() 
{

}

void BaseDeDatos::crearActa() 
{
    /*
    * 1. creamos un nuevo objeto de tipo acta
    * 2. pedimos al usuario los valores de los atributos y se los asignamos en el objeto
    * 3. asignamos el consecutivo al acta
    * 4. Insertarmos los criterios actuales en el acta llamando crearCriteriosAlActa()
    * 4. adicionamos el acta al contenedor de actas
    * 5. incrementamos el consecutivo de actas
    */
    int codigo, valorTipoTrabajo;
    string fecha, autor, nombreTrabajo, director, codirector, jurado1, jurado2;
    Trabajo tipoTrabajo;
    cout << "Digite el codigo: ";
    cin >> codigo;
    cout << "Digite fecha: ";
    cin >> fecha;
    cout << "Digite autor: ";
    cin >> autor;
    cout << "Digite el nombre del trabajo: ";
    cin >> nombreTrabajo;
    cout << "Digite el nombre del director: ";
    cin >> director;
    cout << "Digite el nombre codirector: ";
    cin >> codirector;
    cout << "Digite el nombre del jurado1: ";
    cin >> jurado1;
    cout << "Digite el nombre del jurado2: ";
    cin >> jurado2;
    cout << "Digite el tipo de trabajo(1. Aplicado, 2. Investigacion): ";
    cin >> valorTipoTrabajo;
    tipoTrabajo = valorTipoTrabajo;
    Acta(codigo, fecha, autor, nombreTrabajo, director, codirector, jurado1, 
         jurado2, crearCriterios(), tipoTrabajo);
    this->consecutivoDeActas++;
}

void BaseDeDatos::llenarActa(int codigo) 
{
    if(existeActa(codigo)){
        for(vector<Acta>::iterator pActa = this->actasPendientes.begin();
        pActa != this->actasPendientes.end(); pActa++){
            if(pActa->getCodigo() == codigo){
                pActa->llenarActa();
                actasCalificadas.push_back(*pActa);
                actasPendientes.erase(pActa);
                pActa = actasPendientes.end();
            }
        }
    }else{
        cout << "No se encontro el acta.\n";
    }
    
}

void BaseDeDatos::exportarActa(int codigo) 
{
    if (existeActa(codigo)) {
            for (vector<Acta>::iterator pActa = this->actasCalificadas.begin();
                pActa != this->actasCalificadas.end(); pActa++) {
                if (pActa->getCodigo() == codigo) {
                    pActa->exportarActa();
                    pActa = actasCalificadas.end();
                }
            }
        }
        else {
            cout << "No se encontro el acta.\n";
        }
}

void BaseDeDatos::modificarInfoCriterios() 
{
    int opcion;
    do{
        cout << "Que desea hacer?:\n"
        << "1. Modificar toda la informacion de los criterios.\n"
        << "2. Modificar la informacion de un solo criterio.\n"
        << "3. Agregar un nuevo criterio.\n"
        << "0. Salir.\n"
        << "Opcion: ";
        switch(opcion){
        case 1:
            int i, cantCriterios;
            cout << "Porfavor escriba la cantidad de criterios que van a existir: ";
            cin >> cantCriterios;
            for(i = 0; i < cantCriterios; i++){
                infoCriterios.push_back(crearInfoCriterio());
            }
            break;
        case 2:
            int id;
            cout << "Porfavor escriba el ID del criterio que va a modificar: ";
            cin >> id;
            vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
            while(pInfoCriterio->getId() - id){
                pInfoCriterio++;
            }
            *pInfoCriterio = crearInfoCriterio();
            break;
        case 3:
            infoCriterios.push_back(crearInfoCriterio());
            break;
        }
    }while(opcion);
    
}

void BaseDeDatos::verHistorial() 
{
    
}

void BaseDeDatos::verActa(int codigo) {
    if (existeActa(codigo)) {
        for (vector<Acta>::iterator pActa = this->actasCalificadas.begin();
            pActa != this->actasCalificadas.end(); pActa++) {
            if (pActa->getCodigo() == codigo) {
                pActa->mostrarActa();
                pActa = actasCalificadas.end();
            }
        }
    }
    else {
        cout << "No se encontro el acta.\n";
    }
}

bool BaseDeDatos::existeActa(int codigo) {
    for(vector<Acta>::iterator pActa = this->actasPendientes.begin();
        pActa != this->actasPendientes.end(); pActa++){
        if(pActa->getCodigo() == codigo){
            return true;
        }    
    }
    return false;
    
}

vector<Criterio> BaseDeDatos::crearCriterios()
{
    /*
    * 1. Para cada uno de los INFOCRITERIOS definidos en base de datos creamos un Criterio
    * 2. Adicionamos cada criterio en el vector de criterios
    */

    //Recorriendo el VECTOR de Infocriterios de la base de datos vamos a ir creando los criterios en el acta.
    Criterio criterioTemp;
    vector<Criterio> criterios;
    for(vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
        pInfoCriterio != this->infoCriterios.end(); pInfoCriterio++){
        criterioTemp.setInfoCriterio(*pInfoCriterio);
        criterios.push_back(criterioTemp);
    }
    return criterios;
}

InfoCriterio BaseDeDatos::crearInfoCriterio(){
    int id;
    string descripcion;
    float pesoPorcentual;
    cout << "Por favor escriba el ID del criterio: ";
    cin >> id;
    cout << "Por favor escriba la descripcion del criterio: ";
    cin >> descripcion;
    cout << "Por favor escriba el peso porcentual del criterio en decimal: ";
    cin >> pesoPorcentual;
    return InfoCriterio(id, descripcion, pesoPorcentual);
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