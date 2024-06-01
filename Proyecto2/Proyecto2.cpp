#include <iostream>
#include "Database.h"
#include "Usuario.h"
#include "Articulo.h"
#include "Acreedor.h"
#include "Deudor.h"
#include "FormaPago.h"
#include "Personal.h"
#include "Penalizacion.h"
#include "Notificacion.h"
#include "Finiquito.h"

using namespace std;

void mostrarMenu();
void manejarOpcion(int opcion, Database& db);

int main() {
    try {
        Database db("localhost:3308", "root", "1q2w3e4r", "ventacredito");

        int opcion = 0;
        do {
            mostrarMenu();
            cout << "Selecciona una opcion: ";
            cin >> opcion;
            manejarOpcion(opcion, db);
        } while (opcion != 0);

    }
    catch (sql::SQLException& e) {
        cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

void mostrarMenu() {
    cout << "\n--- Menu Principal ---\n";
    cout << "1. Consultar todos los usuarios\n";
    cout << "2. Agregar un nuevo usuario\n";
    cout << "3. Consultar todos los articulos\n";
    cout << "4. Agregar un nuevo articulo\n";
    cout << "5. Consultar todos los pagos\n";
    cout << "6. Consultar todos los acreedores\n";
    cout << "7. Agregar un nuevo acreedor\n";
    cout << "8. Consultar todos los deudores\n";
    cout << "9. Agregar un nuevo deudor\n";
    cout << "10. Consultar todas las formas de pago\n";
    cout << "11. Agregar una nueva forma de pago\n";
    cout << "12. Consultar todo el personal\n";
    cout << "13. Agregar nuevo personal\n";
    cout << "14. Consultar todas las penalizaciones\n";
    cout << "15. Agregar una nueva penalizacion\n";
    cout << "16. Consultar todas las notificaciones\n";
    cout << "17. Agregar una nueva notificacion\n";
    cout << "18. Consultar todos los finiquitos\n";
    cout << "19. Agregar un nuevo finiquito\n";
    cout << "0. Salir\n";
}

void manejarOpcion(int opcion, Database& db) {
    switch (opcion) {
    case 1:
        Usuario::consultarTodos(db);
        break;
    case 2: {
        string nombre, perfil;
        cout << "Introduce el nombre del usuario: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Introduce el perfil del usuario (consulta, pagos, administrador): ";
        getline(cin, perfil);
        if (Usuario::esPerfilValido(perfil)) {
            Usuario usuario(nombre, perfil);
            usuario.guardar(db);
        }
        else {
            cerr << "Perfil no valido. Perfiles permitidos: consulta, pagos, administrador.\n";
        }
        break;
    }
    case 3:
        Articulo::consultarTodos(db);
        break;
    case 4: {
        string nombre;
        double precio;
        cout << "Introduce el nombre del articulo: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Introduce el precio del articulo: ";
        cin >> precio;
        Articulo articulo(nombre, precio);
        articulo.guardar(db);
        break;
    }
    case 5:
   
    case 6:
        Acreedor::consultarTodos(db);
        break;
    case 7: {
        string nombre;
        cout << "Introduce el nombre del acreedor: ";
        cin.ignore();
        getline(cin, nombre);
        Acreedor acreedor(nombre);
        acreedor.guardar(db);
        break;
    }
    case 8:
        Deudor::consultarTodos(db);
        break;
    case 9: {
        string nombre, email;
        cout << "Introduce el nombre del deudor: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Introduce el email del deudor: ";
        getline(cin, email);
        Deudor deudor(nombre, email);
        deudor.guardar(db);
        break;
    }
    case 10:
        FormaPago::consultarTodos(db);
        break;
    case 11: {
        string tipo;
        cout << "Introduce el tipo de forma de pago (efectivo, tarjeta, Paypal, cheque, otro): ";
        cin.ignore();
        getline(cin, tipo);
        FormaPago formaPago(tipo);
        formaPago.guardar(db);
        break;
    }
    case 12:
        Personal::consultarTodos(db);
        break;
    case 13: {
        string nombre, puesto;
        cout << "Introduce el nombre del personal: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Introduce el puesto del personal: ";
        getline(cin, puesto);
        Personal personal(nombre, puesto);
        personal.guardar(db);
        break;
    }
    case 14:
        Penalizacion::consultarTodos(db);
        break;
    case 15: {
        int deudor_id;
        double monto;
        string fecha;
        cout << "Introduce el ID del deudor: ";
        cin >> deudor_id;
        cout << "Introduce el monto de la penalización: ";
        cin >> monto;
        cout << "Introduce la fecha de la penalización (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, fecha);
        Penalizacion penalizacion(deudor_id, monto, fecha);
        penalizacion.guardar(db);
        break;
    }
    case 16:
        Notificacion::consultarTodos(db);
        break;
    case 17: {
        int deudor_id;
        string mensaje, fecha;
        cout << "Introduce el ID del deudor: ";
        cin >> deudor_id;
        cout << "Introduce el mensaje de la notificación: ";
        cin.ignore();
        getline(cin, mensaje);
        cout << "Introduce la fecha de la notificación (YYYY-MM-DD): ";
        getline(cin, fecha);
        Notificacion notificacion(deudor_id, mensaje, fecha);
        notificacion.guardar(db);
        break;
    }
    case 18:
        Finiquito::consultarTodos(db);
        break;
    case 19: {
        int deudor_id;
        double monto;
        string fecha;
        cout << "Introduce el ID del deudor: ";
        cin >> deudor_id;
        cout << "Introduce el monto del finiquito: ";
        cin >> monto;
        cout << "Introduce la fecha del finiquito (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, fecha);
        Finiquito finiquito(deudor_id, monto, fecha);
        finiquito.guardar(db);
        break;
    }
    case 0:
        cout << "Saliendo del programa...\n";
        break;
    default:
        cerr << "Opcion no valida. Por favor, selecciona una opcion valida.\n";
    }
}