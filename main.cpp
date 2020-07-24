#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class persona{
    
    public:
        int cedula;
    protected:
        // defino variables de persona
        
        string nombre;
        string apellido;
        string direccion;
        int telefono;
    public:
    persona(){
        cout << "Nombre: ";
        cin >> nombre;
        // paso a mayusculas nombre
        for (int i = 0; i < nombre.length(); i++)
        {
            nombre[i] = toupper(nombre[i]);    
        }
        
        // ingreso apellido
        cout << "Apellido: ";
        cin >> apellido;
        // paso a mayusuculas apellido
        for (int i = 0; i < apellido.length(); i++)
        {
            apellido[i] = toupper(apellido[i]);    
        }
    }


};

class clientes{
    public:
    int codigoCliente;
    protected:
    persona cliente;


    public:
    clientes(){
        cout << "Codigo cliente: ";
        cin >> codigoCliente;
    }
};

class empleados{

    public:
        int codigoEmpleado;
        string tipoEmpleado;
    protected:
        persona empleado;
    public:
        empleados(){
        cout << "Codigo empleado: ";
        cin >> codigoEmpleado;
        cout << "Tipo empleado: ";
        cin >> tipoEmpleado; 
        }
};


int main(){
    return 0;
}