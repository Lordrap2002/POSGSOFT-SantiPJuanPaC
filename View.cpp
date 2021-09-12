#include "View.h"

View::View()
{
}

void View::mostrarMenuEvaluador() 
{
    int opcion = -1, codigo;
    do
    {

        cout << "Menu Evaluador\n";
        cout << "1. Evalua trabajo de grado \n";
        cout << "2. Exporta trabajo de grado \n";
        std::cout << "Digite la opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {

        case 1:
            criterios.llenarCriterio();
            break;
        case 2:
            sistema.exportarActa(codigo);
            break;
        }

    } while (opcion != 0);
}

void View::mostrarMenuDirectora()
{
    int opcion = -1;
    do
    {

        cout << "Menu director/a\n";
        cout << "1. Modificar criterios \n";
        cout << "2. ver historial de actas \n";
        std::cout << "Digite la opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {

        case 1:
            sistema.modificarInfoCriterios();
            break;
        case 2:
            sistema.verHistorial();
            break;
        }

    } while (opcion != 0);
}

void View::mostrarMenuAsistente()
{
    int opcion = -1;
    do
    {

        cout << "Menu asistente\n";
        cout << "1. crear acta \n";
        cout << "2. ver historial \n";
        std::cout << "Digite la opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {

        case 1:
            sistema.crearActa();
            break;
        case 2:
            sistema.verHistorial();
            break;
        }

    } while (opcion != 0);
}

void View::mostrarMenu()
{
    int opcion = -1;
    do
    {

        cout << "Menu Sistema\n";
        cout << "1. Entra como evaluador/a \n";
        cout << "2. Entra como director/a \n";
        cout << "3. Entra como asistente \n";
        cout << "0. Salir \n";
        std::cout << "Digite la opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {

        case 1:
            View::mostrarMenuEvaluador();
            break;
        case 2:
            View::mostrarMenuDirectora();
            break;

        case 3:
            View::mostrarMenuAsistente();
            break;
        }

    } while (opcion != 0);
}