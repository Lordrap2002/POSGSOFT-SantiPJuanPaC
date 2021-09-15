#include <iostream>
#include "Acta.h"

//Constructor vac�o.
Acta::Acta(){

}

//Constructor con par�metros utilizado al crear una acta nueva.
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

//Constructor con par�metros utilizado al crear una acta a partir de un archivo .csv.
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

//M�todo que es invocado desde BaseDeDatos para imprimir en pantalla los datos
//de cada acta, como el c�digo, la fecha o el autor.
void Acta::mostrarActa(){
    cout << "Acta #" << getCodigo() << endl
        << "Fecha: " << getFecha() << endl
        << "Autor: " << getAutor() << endl
        << "Nombre del trabajo: " << getNombreTrabajo() << endl
        << "Director: " << getDirector() << endl
        << "Codirector: " << getCodirector() << endl
        << "Jurado 1: " << getJurado1() << endl
        << "Jurado 2: " << getJurado2() << endl
        // se utilizó un operador ternario para decidir que se va a imprimir dependiendo del tipo de trabajo.
        << "Tipo de trabajo: " << (tipoTrabajo == aplicado ? "Aplicado" : "Investigacion") << endl 
        << "Comentarios generales: " << getComentariosGenerales() << endl
        << "Nota final: " << getNotaFinal() << endl
        // se utilizó un operador ternario para decidir que se va a imprimir dependiendo del resultado final.
        << "Resultado final: " << (resultadoFinal == aprobado ? "Aprobado" : "Reprobado") << endl;
        
}

/// <summary>
/// M�todo que es invocado desde BaseDeDatos para llenar (evaluar) la informaci�n restante de un acta,
/// como las notas y comentarios de los criterios, la nota final y el resultado final del acta.
/// </summary>
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
    // se utilizó un operador ternario para decidir el valor del resultado final dependiendo de la nota final.
    this-> resultadoFinal = this->notaFinal < 3.5 ? reprobado : aprobado;
}

/// <summary>
/// M�todo que es invocado desde BaseDeDatos para exportar la informaci�n de cada acta a cualquier tipo de archivo. 
/// </summary>
void Acta::exportarActa(){
    //Se utiliza la libreria ofstream para poder escribir en archivos aparte como un .txt
    //y se utiliza una variable temporal para pasar los datos desde el codigo al archivo
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
        << "Jurado 2: " << getJurado2() << endl
        // se utilizó un operador ternario para decidir que se va a imprimir dependiendo del tipo de trabajo.
        << "Tipo de trabajo: " << (tipoTrabajo == aplicado ? "Aplicado" : "Investigacion") << endl
        << "Criterios:" << endl;
    archivoTemp.close();
    //pCriterio apunta al vector InfoCriterio para poder invocar m�todos y datos de esa misma clase.
    for(vector<Criterio>::iterator pCriterio = this->criterios.begin();
        pCriterio != this->criterios.end(); pCriterio++){
        pCriterio->exportarCriterio(nombreArchivo);
    }
    //App es usado para que en vez de que los datos que est�n en el documento sean eliminados o reescritos,
    //se escriban los datos nuevos en lo �ltimo.
    archivoTemp.open( nombreArchivo, ios::app);
    archivoTemp << "Comentarios generales: " << getComentariosGenerales() << endl
    << "Nota final: " << getNotaFinal() << endl
    // se utilizó un operador ternario para decidir que se va a imprimir dependiendo del resultado final.
    << "Resultado final: " << (resultadoFinal == aprobado ? "Aprobado" : "Reprobado") << endl;
    archivoTemp.close();
}

/// <summary>
/// M�todo que recorre el vector Criterio y calcula la nota final teniendo en cuenta la nota de cada uno de los criterios.
/// </summary>
void Acta::calcularNotaFinal(){
    for(vector<Criterio>::iterator pCriterio = this->criterios.begin();
        pCriterio != this->criterios.end(); pCriterio++){
            this->notaFinal += pCriterio->getNotaCriterio();
    }
}

/// Se dejaron comentariados estos metodos por si en algun momento vemos que se pueden utilizar.
/// <summary>
/// M�todo que es llamado desde BaseDeDatos para que imprima en pantalla el tipo de trabajo de cada una de las actas.
/// </summary>
/*void Acta::mostrarTipoTrabajo(){
    if(this->tipoTrabajo == aplicado){
        cout << "Aplicado" << endl;
    }else{
        cout << "Investigacion" << endl;
    }
}*/

/// <summary>
/// M�todo que exporta el tipo de trabajo de cada una de las actas a un archivo aparte para su pr�xima importaci�n y uso.
/// </summary>
/// <param name="nombreArchivo">Recibe el nombre del archivo el cual est� guardado en la variable nombreArchivo,
///  al cual se va a exportar la informaci�n</param>
/*void Acta::exportarTipoTrabajo(string nombreArchivo){
    ofstream archivoTemp;
    archivoTemp.open(nombreArchivo);
    if(this->tipoTrabajo == aplicado){
        archivoTemp << "Aplicado" << endl;
    }else{
        archivoTemp << "Investigacion" << endl;
    }
    archivoTemp.close();
}*/

/// <summary>
/// M�todo que imprime en pantalla el estado de calificaci�n actual de un acta, el cual se encuentra en el enum Resultado.
/// </summary>
/*void Acta::mostrarResultadoFinal(){
    if(this->resultadoFinal == aprobado){
        cout << "Aprobado" << endl;
    }else{
        cout << "Reprobado" << endl;
    }
}*/

/// <summary>
/// M�todo que exporta el estado de calificaci�n de cada una de las actas, en este caso el enum Resultado(aprobado o reprobado).
/// </summary>
/// <param name="nombreArchivo">Recibe el nombre del archivo el cual est� guardado en la variable nombreArchivo,
///  al cual se va a exportar la informaci�n</param>
/*void Acta::exportarResultadoFinal(string nombreArchivo){
    ofstream archivoTemp;
    archivoTemp.open(nombreArchivo);
    if(this->resultadoFinal == aprobado){
        archivoTemp << "Aprobado" << endl;
    }else{
        archivoTemp << "Reprobado" << endl;
    }
    archivoTemp.close();
}*/

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

