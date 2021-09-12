all: compilar
compilar: Criterio BaseDeDatos Acta InfoCriterio view main
		g++ -o Salida BaseDeDatos.o Criterio.o Acta.o InfoCriterio.o View.o Main.o
Criterio: Criterio.cpp Criterio.h InfoCriterio.h
		g++ -c Criterio.cpp
BaseDeDatos: BaseDeDatos.cpp BaseDeDatos.h Acta.h
	g++ -c BaseDeDatos.cpp
Acta: Acta.cpp Acta.h Criterio.h
	g++ -c Acta.cpp
InfoCriterio: InfoCriterio.cpp InfoCriterio.h
	g++ -c InfoCriterio.cpp
view: View.cpp View.h BaseDeDatos.h Criterio.h
		g++ -c View.cpp
main: Main.cpp View.h 
	  g++ -c Main.cpp
clean: #comando para borrar los .o
	@echo "Cleaning compilation..."
	del *.o