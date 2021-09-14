#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <stdlib.h>
#include "InfoCriterio.h"
#include <fstream>

using namespace std;

class Criterio{
    private:
        float notaJurado1, notaJurado2, notaPromedio, notaCriterio;
        string comentario1, comentario2, comentarioGeneral;
        InfoCriterio infoCriterio;
    public:
        Criterio();
        void calcularNotaCriterio();
        void calcularNotaPromedio();
        void llenarCriterio();       
        //void mostrarCriterio();
        void exportarCriterio(string nombreArchivo);

        //gets/sets
        float getNotaJurado1();
        void setNotaJurado1(float notaJurado1);
        float getNotaJurado2();
        void setNotaJurado2(float notaJurado2);
        float getNotaPromedio();
        void setNotaPromedio(float notaPromedio);
        float getNotaCriterio();
        void setNotaCriterio(float notaCriterio);
        string getComentario1();
        void setComentario1(string comentario1);
        string getComentario2();
        void setComentario2(string comentario2);
        string getComentarioGeneral();
        void setComentarioGeneral(string comentarioGeneral);
        InfoCriterio getInfoCriterio();
        void setInfoCriterio(InfoCriterio infoCriterio);
};

#endif