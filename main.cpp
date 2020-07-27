#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstring>
using namespace std;


class persona{
    
    public:
        int cedula;
        string nombre;
        string apellido;
        // defino variables de persona
        string direccion;
        int telefono;
    public:
    
    void set(){
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

class clientes: public persona{
    public:
    int codigoCliente;
    


    public:
    // clientes(int _cedula,string _nombre,string _apellido, string _direccion,int _telefono){}
    void set(){
        cout << "Codigo cliente: ";
        cin >> codigoCliente;
        cout << "Cedula cliente: ";
        cin >> cedula;
        cout << "Nombre cliente: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "Telefono: ";
        cin >> telefono;
        
    }
};

class empleados: public persona{

    public:
        int codigoEmpleado;
        string tipoEmpleado;
    
    public:
        void set(){
        cout << "Cedula cliente: ";
        cin >> cedula;
        cout << "Nombre cliente: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "Telefono: ";
        cin >> telefono;
        cout << "Codigo empleado: ";
        cin >> codigoEmpleado;
        cout << "Tipo empleado: ";
        cin >> tipoEmpleado; 
        }
};
class cuenta{
    public:
    int numeroDeCuenta=0;
    protected:
    string tipo;    
    string moneda;
    float saldo =0;
    float sobregiro;

    public:
    void set(){
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
         if(moneda!= "$"&& moneda!="U$S"){
            cout<<"moneda de cuenta equivocada"<<endl;
            exit(-1);
        }
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


class registros {
    public:
    int status=-1;
    cuenta cuentaCliente;
    clientes cliente;

};

int main(){
    int opcion =-1;
    clientes clientesLista[20];
    empleados empleadosLista[20];
    cuenta cuentaLista[20];
    // cuenta1.set();
    // cuenta1.view();

    registros registroLista[20];
  

     while (opcion != 0)
    {
        cout << "Ingrese la opción deseada. " << endl;
        cout << "\t1-Ingresar cliente " << endl;
        cout << "\t2-Listar clientes. " << endl;
        cout << "\t3-Crear cuenta. " << endl;
        cout << "\t4-Listar cuenta. " << endl;
        cout << "\t5-Depositar saldo. " << endl;
        cout << "\t6-Retirar. " << endl;
        cout << "\t7-Salto total bancario. " << endl;
        cout << "\t8-Retirar. " << endl;
        
        cout << "\t0-Salir " << endl;
        cin>> opcion;
        switch (opcion)
        {
            // Modifica cantidad de dias
        case 1:{
            cout<<""<<endl;
            int posicion=0;
            while(clientesLista[posicion].codigoCliente!=0){
                posicion++;
            }
            
            clientesLista[posicion].set();
            cout<<"================================"<<endl;
            break;
            }
            // Modificar sala/cama/cargos diarios
        case 2:{
            cout<<""<<endl;
            int posicion = 0;
            cout<<"Cliente ||  Apellido"<<endl;
            while(clientesLista[posicion].codigoCliente!=0){
                cout<<clientesLista[posicion].codigoCliente;
                cout<< "    ||    ";
                cout<< clientesLista[posicion].apellido<<endl;
                posicion++;
            }
            
            cout<<"================================"<<endl;  
            break;
        }
            // lista todos los pacientes
        case 3:{
            int cliente = -1;
            // int lista[20];
            cout<<""<<endl;
            cout<<"Seleccione un cliente de la lista:"<<endl;

            int posicion = 0;
            cout<<"Cliente ||  Apellido"<<endl;
            while(clientesLista[posicion].codigoCliente!=0){
                cout<<clientesLista[posicion].codigoCliente;
                cout<< "    ||    ";
                cout<< clientesLista[posicion].apellido<<endl;
                posicion++;
            }
            
            cin>>cliente;
            posicion=0;
            int registroPos=0;
             while(clientesLista[posicion].codigoCliente!=0){
                 if(clientesLista[posicion].codigoCliente==cliente){
                     cout<<"entró"<<endl;
                    registroPos=0;
                     while (registroLista[registroPos].status!=-1)
                     {
                         registroPos++;
                     }
                     registroLista[registroPos].cliente.codigoCliente=cliente;
                     registroLista[registroPos].cuentaCliente.set();
                     registroLista[registroPos].status=1;
                     cout<<"Cuenta creada con exito"<<endl;
                     cout<<"================================"<<endl;
                     break;
                 }else{
            
                 }
                 posicion++;
            
            }
            cout<<"Cliente ingresado incorrecto"<<endl;
            
            break;
            }
        
        case 4:{
            int cuentaPos=0;
            while(registroLista[cuentaPos].status!=-1){
                cout<<"Cuenta: "<<registroLista[cuentaPos].cuentaCliente.numeroDeCuenta<<endl;
                cuentaPos++;
              }
        }
        case 5:{
            int cuentaPos=0;
            while(registroLista[cuentaPos].status!=-1){
                cout<<"Cuenta: "<<registroLista[cuentaPos].cuentaCliente.numeroDeCuenta<<endl;
                cuentaPos++;
              }
        }
        case 6:{}
        case 7:{}
        case 8:{}
        }
    }

    return 0;

}