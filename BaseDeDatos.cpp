#include <iostream>
#include "BaseDeDatos.h"
#include "Acta.h"

//Constructor vac�o.
BaseDeDatos::BaseDeDatos() 
{

}

/// <summary>
/// M�todo que nos permite crear un acta y llenar la informaci�n b�sica de esta, como la fecha y el autor.
/// </summary>
void BaseDeDatos::crearActa() 
{
    int codigo, valorTipoTrabajo;
    string fecha, autor, nombreTrabajo, director, codirector, jurado1, jurado2;
    Trabajo tipoTrabajo;
    cout << "Digite el codigo: ";
    cin >> codigo;
    cout << "Digite fecha: ";
    //fflush limpia el buffer para que no haya problemas de lectura y escritura de datos.
    fflush(stdin);
    getline(cin, fecha);
    cout << "Digite autor: ";
    fflush(stdin);
    getline(cin, autor);
    cout << "Digite el nombre del trabajo: ";
    fflush(stdin);
    getline(cin, nombreTrabajo);
    cout << "Digite el nombre del director: ";
    fflush(stdin);
    getline(cin, director);
    cout << "Digite el nombre codirector: ";
    fflush(stdin);
    getline(cin, codirector);
    cout << "Digite el nombre del jurado1: ";
    fflush(stdin);
    getline(cin, jurado1);
    cout << "Digite el nombre del jurado2: ";
    fflush(stdin);
    getline(cin, jurado2);
    cout << "Digite el tipo de trabajo(1. Aplicado, 2. Investigacion): ";
    cin >> valorTipoTrabajo;
    tipoTrabajo = valorTipoTrabajo == aplicado ? aplicado : investigacion;
    //Se env�a a actasPendientes la informaci�n del acta reci�n creada, para que
    //cuando se est� invocando el acta ya tenga dicha informaci�n.
    actasPendientes.push_back(Acta(codigo, fecha, autor, nombreTrabajo, 
                                    director, codirector, jurado1, 
                                    jurado2, crearCriterios(), tipoTrabajo));
}


/// <summary>
/// M�todo que primero llama a existeActa() para validar que existe el acta, y en caso True se llama al m�todo llenarActa()
/// de la clase Acta para llenar la informaci�n de ese acta y evaluarla.
/// </summary>
/// <param name="codigo">C�digo del acta que se desea llenar</param>
void BaseDeDatos::llenarActa(int codigo) 
{
    //Se crea una variale temporal para guardar la informacion que se pasara a cada acta
    Acta actaTemp;
    if(existeActaPendiente(codigo)){
        //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
        for(vector<Acta>::iterator pActa = this->actasPendientes.begin();
        pActa != this->actasPendientes.end(); pActa++){
            if(pActa->getCodigo() == codigo){
                actaTemp = *pActa;
                actaTemp.llenarActa();
                actasCalificadas.push_back(actaTemp);
                actasPendientes.erase(pActa);
                pActa = actasPendientes.end() - 1;
            }
        }
    }else{
        cout << "No se encontro el acta.\n";
    }
    this->consecutivoDeActas++;
}

/// <summary>
/// M�todo que primero invoca a existeActaCalificada(), y en caso True recorre el vector de actas calificadas,
/// y manda a exportar la informaci�n del acta deseada llamando al m�todo exportarActa() desde la clase Acta. 
/// </summary>
/// <param name="codigo">C�digo del acta que se desea exportar</param>
void BaseDeDatos::exportarActa(int codigo) 
{
    if (existeActaCalificada(codigo)) {
        //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
            for (vector<Acta>::iterator pActa = this->actasCalificadas.begin();
                pActa != this->actasCalificadas.end(); pActa++) {
                if (pActa->getCodigo() == codigo) {
                    pActa->exportarActa();
                    pActa = actasCalificadas.end() - 1;
                }
            }
        }
        else {
            cout << "No se encontro el acta.\n";
        }
}

/// <summary>
/// M�todo que permite acceder al vector de infoCriterios y modificar la informaci�n de cada criterio,
/// de todos los criterios, agregar un nuevo criterio o eliminar un criterio.
/// </summary>
void BaseDeDatos::modificarInfoCriterios() 
{
    int opcion, id;
    do{
        cout << "Que desea hacer?:\n"
        << "1. Agregar un nuevo criterio.\n"
        << "2. Agregar varios criterios.\n"
        << "3. Modificar la informacion de un solo criterio.\n"
        << "4. Eliminar un criterio.\n"
        << "0. Salir.\n"
        << "Opcion: ";
        cin >> opcion;
        //system es un comando de la librer�a windows.h que permite ir limpiando la pantalla de donde se est� imprimiendo
        system("cls");
        switch (opcion) {
        case 1:
            //Se llama al m�todo crearInfocriterio() para crear un nuevo criterio con sus respectivos datos.
            infoCriterios.push_back(crearInfoCriterio());
            this->cantCriterios++;
            break;

        case 2:
            int i, cantCriterios;
            cout << "Porfavor escriba la cantidad de criterios que van a existir: ";
            cin >> cantCriterios;
            //Por cada criterio que se haya mandado a crear, se llamar� al m�todo crearInfoCriterio() para
            // crear la informaci�n respectiva al criterio reci�n creado.
            for (i = 0; i < cantCriterios; i++) {
                infoCriterios.push_back(crearInfoCriterio());
            }
            this->cantCriterios = cantCriterios;
            break;
        case 3:
            
            cout << "Porfavor escriba el ID del criterio que va a modificar: ";
            cin >> id;
            //Se llama al m�todo existeCriterio() para verificar la existencia del criterio, y en caso True
            //llama al m�todo crearInfoCriterio() para volver a llenar toda la informaci�n del criterio seleccionado.
            if (existeCriterio(id))
            {
                //pInfoCriterio apunta al vector InfoCriterio para poder invocar m�todos y datos de esa misma clase.
                for (vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
                    pInfoCriterio != this->infoCriterios.end(); pInfoCriterio++) {
                    if (pInfoCriterio->getId() == id) {
                        *pInfoCriterio = crearInfoCriterio();
                        pInfoCriterio = this->infoCriterios.end();
                    }
                }
            }
            else
            {
                cout << "No existe el criterio # \n" << id;
            }

        case 4:
            cout << "Porfavor escriba el ID del criterio que va a eliminar: ";
            cin >> id;
            //Se llama al m�todo existeCriterio() para verificar la existencia del criterio, y en caso True
            //utiliza el comando .erase() para eliminar el criterio seleccionado.
            if (existeCriterio(id))
            {
                
                //pInfoCriterio apunta al vector InfoCriterio para poder invocar m�todos y datos de esa misma clase.
                for (vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
                    pInfoCriterio != this->infoCriterios.end(); pInfoCriterio++) {
                    if (pInfoCriterio->getId() == id) {
                        infoCriterios.erase(pInfoCriterio);
                        this->cantCriterios--;
                        break;
                    }
                }
                
            }
            else
            {
                cout << "No existe el criterio # \n" << id;
            }

            break;
        }
    }while(opcion);
}

/// <summary>
/// M�todo que se encarga de recorrer el vector de actas desde el inicio hasta el final
///  y va imprimiendo en pantalla cada acta invocando el m�todo mostrarActa()
/// </summary>
void BaseDeDatos::verHistorial() 
{
    //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
    for (vector<Acta>::iterator pActa = this->actasCalificadas.begin();
        pActa != this->actasCalificadas.end(); pActa++) {
            pActa->mostrarActa();
    }
}

/// <summary>
/// M�todo que permite invoca el m�todo mostrarActa() para ver los datos de un acta espec�fica dentro del vector de actas calificadas.
/// </summary>
/// <param name="codigo">C�digo del acta que se desea visualizar</param>
void BaseDeDatos::verActa(int codigo) {
    if (existeActaCalificada(codigo)) {
        //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
        for (vector<Acta>::iterator pActa = this->actasCalificadas.begin();
            pActa != this->actasCalificadas.end(); pActa++) {
            if (pActa->getCodigo() == codigo) {
                pActa->mostrarActa();
                pActa = actasCalificadas.end() - 1;
            }
        }
    }
    else {
        cout << "No se encontro el acta.\n";
    }
}

/// <summary>
/// M�todo que recorre el vector de actas pendientes y verifica si existe el acta deseada.
/// </summary>
/// <param name="codigo">C�digo del acta que se desea visualizar</param>
/// <returns>True en case de que exista, y false en caso contrario</returns>
bool BaseDeDatos::existeActaPendiente(int codigo) {
    //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
    for(vector<Acta>::iterator pActa = this->actasPendientes.begin();
        pActa != this->actasPendientes.end(); pActa++){
        if(pActa->getCodigo() == codigo){
            return true;
        }    
    }
    return false;
    
}

/// <summary>
/// M�todo que recorre el vector de actas calificadas y verifica si existe el acta deseada.
/// </summary>
/// <param name="codigo">C�digo del acta que se desea visualizar</param>
/// <returns>True en case de que exista, y false en caso contrario</returns>
bool BaseDeDatos::existeActaCalificada(int codigo) {
    //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
    for(vector<Acta>::iterator pActa = this->actasCalificadas.begin();
        pActa != this->actasCalificadas.end(); pActa++){
        if(pActa->getCodigo() == codigo){
            return true;
        }    
    }
    return false;
    
}

/// <summary>
/// M�todo que crea un criterio con su respectiva informaci�n (infoCriterio()) dentro del vector criterio para que m�s adelante se pueda utilizar.
/// </summary>
/// <returns> Retorna el vector de criterios con el nuevo criterio a�adido</returns>
vector<Criterio> BaseDeDatos::crearCriterios()
{
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

/// <summary>
/// M�todo que primero llama a existeCriterio(), y en caso True le agrega la respectiva informaci�n a dicho criterio en el vector infoCriterios.
/// </summary>
/// <returns>Retorna la informaci�n que se le acaba de agregar a dicho criterio</returns>
InfoCriterio BaseDeDatos::crearInfoCriterio(){
    int id;
    string descripcion;
    float pesoPorcentual;
    cout << "Por favor escriba el ID del criterio: ";
    cin >> id;
    if (!existeCriterio(id))
    {
        cout << "Por favor escriba la descripcion del criterio: ";
        //fflush limpia el buffer para que no haya problemas de lectura y escritura de datos.
        fflush(stdin);
        getline(cin, descripcion);
        cout << "Por favor escriba el peso porcentual del criterio en decimal: ";
        cin >> pesoPorcentual;
        return InfoCriterio(id, descripcion, pesoPorcentual);
    }
    else {
        cout << "Ya existe el criterio # \n" << id;
    }
    
}

/// <summary>
/// M�todo que permite la importaci�n de los datos de las actas que ya han sido creadas y exportadas anteriormente al archivo "datos.csv"
/// </summary>
void BaseDeDatos::importarDatos(){
    int i, j, codigo;
    string linea, palabra;
    float notaFinal;
    vector<string> datos;
    ifstream archivoTemp;
    Trabajo tipoTrabajo;
    Resultado resultadoFinal;
    archivoTemp.open("datos.csv");
    if(archivoTemp.is_open()){
        datos.clear();
        //se lee una linea del archivo .csv, luego es dividida por comas para guardar cada valor en el vector datos
        getline(archivoTemp, linea);
        stringstream s(linea);
        while(getline(s, palabra, ',')){
                datos.push_back(palabra);
        }
        //El comando stoi toma una cadena y la convierte a entero con signo para que se puedan trabajar en variables de tipo entero.
        this->consecutivoDeActas = stoi(datos[0]);
        this->cantCriterios = stoi(datos[1]);
        for(i = 0; i < consecutivoDeActas; i++){
            //se vacia el vector datos para que tenga la informacion de solo una linea
            datos.clear();
            getline(archivoTemp, linea);
            //La clase stringstream nos permite operar cualquier variable de tipo string como si fuera stream
            //y poder operar con ellos.
            stringstream s(linea);
            while(getline(s, palabra, ',')){
                datos.push_back(palabra);
            }
            //Para cada par�metro de Acta, se extrae el valor del archivo y se incorpora a un vector
            //para poder incorporarlos a las respectivas variables.
            // se utilizó un operador ternario para decidir que se va a imprimir dependiendo del tipo de trabajo.
            // datos[valor] corresponde a los diferentes atributos de la clase Acta, para saber que atributo es cada
            // objeto del vector ver Acta.cpp linea 27.
            actasCalificadas.push_back(Acta(stoi(datos[0]), datos[1], datos[2], datos[3], datos[4], 
                                        datos[5], datos[6], datos[7], datos[8], (stoi(datos[9]) == aplicado ? aplicado : investigacion),
                                        (stoi(datos[10]) == aprobado ? aprobado : reprobado), stof(datos[11])));
        }
        //Se toman los datos de la informaci�n de cada uno de los criterios y se incorporan a su respectivo vector
        //para poder incorporarlos en sus respectivas variables.
        for(i = 0; i < cantCriterios; i++){
            datos.clear();
            getline(archivoTemp, linea);
            stringstream s(linea);
            while(getline(s, palabra, ',')){
                datos.push_back(palabra);
            }
            infoCriterios.push_back(InfoCriterio(stoi(datos[0]), datos[1], stof(datos[2])));
        }
        archivoTemp.close();
    }else{
        cout << "No se encontro el archivo .csv con los datos\n";
    }
}

/// <summary>
/// M�todo que permite exportar los datos de las actas calificadas y de los criterios a cualquier archivo, en este caso en un archivo .csv.
/// </summary>
void BaseDeDatos::exportarDatos(){
    int i;
    //Se utiliza la libreria ofstream para poder escribir en archivos aparte como un .txt
    //y se utiliza una variable temporal para pasar los datos desde el codigo al archivo
    ofstream archivoTemp;
    //Trunc se utiliza para que cada vez que se abra el archivo, los datos viejos se eliminen.
    archivoTemp.open("datos.csv", ios::trunc);
    archivoTemp << consecutivoDeActas << "," << cantCriterios << endl;
    //pActa apunta al vector Acta para poder invocar m�todos y datos de esa misma clase.
    for(vector<Acta>::iterator pActa = this->actasCalificadas.begin();
        pActa != this->actasCalificadas.end(); pActa++){
        archivoTemp << pActa->getCodigo() << ","
                    << pActa->getFecha() << ","
                    << pActa->getAutor() << ","
                    << pActa->getNombreTrabajo() << ","
                    << pActa->getDirector() << ","
                    << pActa->getCodirector() << ","
                    << pActa->getJurado1() << ","
                    << pActa->getJurado2() << ","
                    << pActa->getComentariosGenerales() << ","
                    << pActa->getTipoTrabajo() << ","
                    << pActa->getResultadoFinal() << ","
                    << pActa->getNotaFinal() << ","
                    << endl;
    }
    //pInfoCriterio apunta al vector InfoCriterio para poder invocar m�todos y datos de esa misma clase.
    for(vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
        pInfoCriterio != this->infoCriterios.end(); pInfoCriterio++){
        archivoTemp << pInfoCriterio->getId() << ","
                    << pInfoCriterio->getDescripcion() << ","
                    << pInfoCriterio->getPesoPorcentual() << ","
                    << endl;
    }
    archivoTemp.close();
}

/// Se dejo comentariado este metodo por si en algun momento vemos que se puede utilizar.
/// <summary>
/// M�todo que identifica el tipo de trabajo que es el acta del enum Trabajo.
/// </summary>
/// <param name="opcion">Recibe la opci�n del enum de tipo de trabajo (aplicativo o investigaci�n)</param>
/// <returns>Retorna el tipo de trabajo de un acta</returns>
/*Trabajo BaseDeDatos::identificarTipoTrabajo(int opcion){
    Trabajo tipoTrabajo;
    if(opcion == aplicado){
        tipoTrabajo = aplicado;
    }else{
        tipoTrabajo = investigacion;
    }
    return tipoTrabajo;
}*/

/// Se dejo comentariado este metodo por si en algun momento vemos que se puede utilizar.
/// <summary>
/// M�todo que identifica el estado de calificaci�n de cada acta del enum Resultado.
/// </summary>
/// <param name="opcion">Recibe la opci�n del enum del estado de calificaci�n (aprobado o reprobado)</param>
/// <returns>Retorna el estado de calificaci�n de un acta</returns>
/*Resultado BaseDeDatos::identificarResultado(int opcion){
    Resultado resultadoFinal;
    if(opcion == aprobado){
        resultadoFinal = aprobado;
    }else{
        resultadoFinal = reprobado;
    }
    return resultadoFinal;
}*/

/// <summary>
/// M�todo que verifica que un criterio exista antes de crearlo o modificarlo.
/// </summary>
/// <param name="id">Recibe el id del criterio del que se quiera validar si existe o no existe</param>
/// <returns>True en caso de que exista, False en caso de que no exista</returns>
bool BaseDeDatos::existeCriterio(int id) {
    //pInfoCriterio apunta al vector InfoCriterio para poder invocar m�todos y datos de esa misma clase.
    for (vector<InfoCriterio>::iterator pInfoCriterio = this->infoCriterios.begin();
        pInfoCriterio != this->infoCriterios.end(); pInfoCriterio++) {
        if (pInfoCriterio->getId() == id) {
            return true;
        }
    }
    return false;
}

int BaseDeDatos::getConsecutivoDeActas(){
    return this->consecutivoDeActas;
}

void BaseDeDatos::setConsecutivoDeActas(int consecutivoDeActas){
    this->consecutivoDeActas = consecutivoDeActas;
}

int BaseDeDatos::getCantCriterios(){
    return this->cantCriterios;
}

void BaseDeDatos::setCantCriterios(int cantCriterios){
    this-> cantCriterios = cantCriterios;
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