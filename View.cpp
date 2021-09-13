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
        cout << "Digite la opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            cout << "Por favor escriba el codigo del acta: ";
            cin >> codigo;
            sistema.llenarActa(codigo);
            break;
        case 2:
            cout << "Por favor escriba el codigo del acta: ";
            cin >> codigo;
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
        cout << "4. Exportar datos \n";
        cout << "5. Importar datos \n";
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
        case 4:
            sistema.exportarDatos();
            break;
        case 5:
            sistema.importarDatos();
            break;
        }

    } while (opcion != 0);
}