#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <stdlib.h>
#include "Criterio.h"
#include <vector>
#include <fstream>

using namespace std;

enum Trabajo{aplicado = 1, investigacion = 2};

enum Resultado{aprobado, reprobado};

class Acta{
    //Atributos
    private:
        int codigo;
        string fecha, autor, nombreTrabajo, director,
            codirector, jurado1, jurado2, comentariosGenerales;
        float notaFinal;
        vector<Criterio> criterios;
        Trabajo tipoTrabajo;
        Resultado resultadoFinal;
    //Metodos
    public:
        Acta();
        Acta(int codigo, string fecha, string autor, string nombreTrabajo, string director,
            string codirector, string jurado1, string jurado2, vector<Criterio> criterios,
            Trabajo tipoTrabajo);
        Acta(int codigo, string fecha, string autor, string nombreTrabajo, string director,
            string codirector, string jurado1, string jurado2, string comentariosGenerales, 
            Trabajo tipoTrabajo, Resultado resultadoFinal, float notaFinal);
        void mostrarActa();
        void llenarActa();
        void exportarActa();
        void calcularNotaFinal();
        void mostrarTipoTrabajo();
        void importarTipoTrabajo(int valor);
        void mostrarResultadoFinal();
        void importarResultadoFinal(int valor);

        //gets/sets
        int getCodigo();
        void setCodigo(int codigo);
        string getFecha();
        void setFecha(string fecha);
        string getAutor();
        void setAutor(string autor);
        string getNombreTrabajo();
        void setNombreTrabajo(string nombreTrabajo);
        string getDirector();
        void setDirector(string director);
        string getCodirector();
        void setCodirector(string codirector);
        string getJurado1();
        void setJurado1(string jurado1);
        string getJurado2();
        void setJurado2(string jurado2);
        string getComentariosGenerales();
        void setComentariosGenerales(string comentariosGenerales);
        float getNotaFinal();
        void setNotaFinal(float notaFinal);
        vector<Criterio> getCriterios();
        void setCriterios(vector<Criterio> criterios);
        Trabajo getTipoTrabajo();
        void setTipoTrabajo(Trabajo tipoTrabajo);
        Resultado getResultadoFinal();
        void setResultadoFinal(Resultado resultadoFinal);
};

#endif