#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <stdlib.h>
#include "Criterio.h"
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

enum Trabajo{aplicado, investigacion};

enum Resultado{aprobado, reprobado};

class Acta{
    //Atributos
    private:
        int numero;
        string fecha, autor, nombreTrabajo, director,
            codirector, jurado1, jurado2, comentariosGenerales;
        float notaFinal;
        vector<Criterio> criterios;
        Trabajo tipoTrabajo;
        Resultado resultadoFinal;
    //Metodos
    public:
        Acta();
        void mostrarActa();
        void llenarActa();
        void exportarActa();

        //gets/sets
        int getNumero();
        void setNumero(int numero);
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

        void adicionaCriterio(Criterio criterio);
};

#endif