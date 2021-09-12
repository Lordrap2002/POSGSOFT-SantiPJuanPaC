#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <stdlib.h>
#include "InfoCriterio.h"

using std::cin;
using std::cout;
using std::string;

class Criterio{
    private:
        float notaJurado1, notaJurado2, notaPromedio, notaFinal;
        string comentario1, comentario2, comentarioGeneral;
        InfoCriterio infoCriterio;
    public:
        Criterio();
        float calcularNotaFinal();
        float calcularNotaPromedio();
        
        //gets/sets
        float getNotaJurado1();
        void setNotaJurado1(float notaJurado1);
        float getNotaJurado2();
        void setNotaJurado2(float notaJurado2);
        float getNotaPromedio();
        void setNotaPromedio(float notaPromedio);
        float getNotaFinal();
        void setNotaFinal(float notaFinal);
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