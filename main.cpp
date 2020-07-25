#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstring>
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
class cuenta{
    public:
    int numeroDeCuenta;
    protected:
    string tipo;    
    string moneda;
    float saldo =0;
    float sobregiro;

    public:
    cuenta(){
        cout << "Número de cuenta: ";
        cin >> numeroDeCuenta;
        cout << "Tipo(CA/CC): ";
        cin >> tipo;
        
         for (int i = 0; i < tipo.length(); i++)
            {
                tipo[i] = toupper(tipo[i]);    
            }
        if(tipo!= "CA"&& tipo!="CC"){
            cout<<"tipo de cuenta equivocada"<<endl;
            exit(-1);
        }
        
        
        
        if (tipo == "CC")
        {
        sobregiro = 10;
        }else{
        sobregiro = 0;
        } 
        cout << "Moneda($/U$S): ";
        cin >> moneda;
    } 
    void view(){
        cout<< "=============================="<<endl;
        cout<< "Número de cuenta: "<<numeroDeCuenta <<endl;
        cout<< "Tipo de cuenta: "<<tipo <<endl;
        cout<< "Moneda: "<<moneda <<endl;
        cout<< "Saldo: "<<saldo <<endl;
        cout<< "Sobregiro: "<<sobregiro <<endl;
        cout<< "=============================="<<endl;
    }  
    void deposit(float monto){
        saldo = saldo+monto;
        cout<< "Saldo actual: "<< saldo<<endl;
    }     
    void retirement(float monto){
        if(tipo == "CC"){
        if(monto<(saldo+(sobregiro*saldo)/100)){
        saldo = saldo-monto;
        }else{
            cout<< "Saldo insuficiente"<< endl;
        }
    }else{
        if (monto<= saldo){
            saldo = saldo-monto;
            }
        }
    }
};


int main(){
    cuenta cuenta1;
    cuenta1.view();



    return 0;

}