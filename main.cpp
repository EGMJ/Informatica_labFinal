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
        string telefono;
    public:
    
    void set(){
        cout << "Nombre: ";
        cin >> nombre;
        // paso a mayusculas nombre
        for (unsigned int i = 0; i < nombre.length(); i++)
        {
            nombre[i] = toupper(nombre[i]);    
        }
        
        // ingreso apellido
        cout << "Apellido: ";
        cin >> apellido;
        // paso a mayusuculas apellido
        for (unsigned int i = 0; i < apellido.length(); i++)
        {
            apellido[i] = toupper(apellido[i]);    
        }
    }


};

class clientes: public persona{
    public:
    int codigoCliente;
    


    public:
    void setCodigo(int cod){
        codigoCliente=cod;}
    void setCedula(int ced){
    cedula=ced;}
    void set(){
        
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
        int codigoEmpleado=0;
        string tipoEmpleado;
    
    public:
        void setCodigo(int cod){
        codigoEmpleado=cod;}
        void setCedula(int ced){
        cedula=ced;}
        void setTipo(int tipo){
        tipoEmpleado=tipo;}

        
        void setEmpleado(){
        
        cout << "Nombre empleado: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "Telefono: ";
        cin >> telefono;
        cout << "Tipo empleado: ";
        cin >> tipoEmpleado; 
        }
        void view(){
            cout<< "Nombre: "<<nombre<<endl;
            cout<< "Apellido: "<<apellido<<endl;
            cout<< "Direccion: "<<direccion<<endl;
            cout<< "Telefono: "<<telefono<<endl;
            cout<< "Codigo empleado: "<<codigoEmpleado<<endl;
            cout<< "Tipo empleado: "<<tipoEmpleado<<endl;

        }
};
class cuenta{
    public:
    int numeroDeCuenta=0;
    protected:
    string tipo;    
    string moneda;
    float saldo =0;
    float sobregiro=0;

    public:
    void setNumero(int num){
        numeroDeCuenta=num;}
    void set(){
        
        cout << "Tipo(CA/CC): ";
        cin >> tipo;
        
         for (unsigned int i = 0; i < tipo.length(); i++)
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
    void deposit(){
        float monto =0;
        cout<<"Ingrese el monto a depositar: ";
        cin>>monto;
        if (monto>0)
        {
        saldo = saldo+monto;
        cout<< "Saldo actual: "<< saldo<<endl;  /* code */
        }else
        {
            cout<<"Monto incorrecto"<<endl;
        }
        
        
        
    }     
    void retirement(){
        float monto =0;
        cout<<"Ingrese el monto a retirar: ";
        cin>>monto;
        if (monto>0 && saldo>0)
        {
            /* code */ 
        if(tipo == "CC"){
        if(monto<=(saldo+(sobregiro*saldo)/100)){
        saldo = saldo-monto;
        }else{
            cout<< "Saldo insuficiente"<< endl;
        }
        }else{
        if (monto<= saldo){
            saldo = saldo-monto;
            }
        }
        }else{
            cout<<"Monto incorrecto o saldo insuficiente"<<endl;
        }
    }
    float _saldo()
    {return saldo;}
    string _moneda(){
        return moneda;
    }
};


class registros {
    public:
    int status=-1;
    cuenta cuentaCliente;
    clientes cliente;

};


class historial{
    public:
    int empleado=-1;
    int cuenta =-1;
    string transaccion;
   
    
    void set(int emp,int cuen,string trans){
        empleado = emp;
        cuenta = cuen;
        transaccion = trans;
        
    }
    void view(){
        cout<<"Empleado: "<<empleado<<", Cuenta: "<<cuenta<<", transacción: "<<transaccion<<endl;
    }
  
};

int main(){
    int opcion =-1;
    clientes clientesLista[20];
    empleados empleadosLista[20];
    
    historial transacciones[50];
    registros registroLista[20];
  

     while (opcion != 0)
    {
        cout << "Ingrese la opción deseada. " << endl;
        cout << "\t1-Ingresar empleado " << endl;
        cout << "\t2-Ingresar cliente " << endl;
        cout << "\t3-Listar empleados. " << endl;
        cout << "\t4-Listar clientes. " << endl;
        cout << "\t5-Crear cuenta. " << endl;
        cout << "\t6-Listar cuenta. " << endl;
        cout << "\t7-Depositar saldo. " << endl;
        cout << "\t8-Retirar. " << endl;
        cout << "\t9-Saldo total bancario. " << endl;
        cout << "\t10-Historial de transacciones. " << endl;
        
        cout << "\t0-Salir " << endl;
        cin>> opcion;
        switch (opcion)
        {
            // Crea usuario
        case 1:{
        
            cout<<""<<endl;
            int posicion=0;
            int codigo =1;
            int cedula =0;
            int duplicado =0;
            cout << "Cedula empleado: ";
            cin >> cedula;
            while(empleadosLista[posicion].codigoEmpleado!=0){
                if (empleadosLista[posicion].cedula ==cedula)
                {   cout<<"Usario ya registrado"<<endl;
                    duplicado = -1;
                    break;
                }else{
                posicion++;
                codigo++;
                }
                
                
            }if (duplicado !=-1)
            {
            empleadosLista[posicion].setCedula(cedula);
            empleadosLista[posicion].setCodigo(codigo);
            empleadosLista[posicion].setEmpleado();
            
            cout<<"================================"<<endl;  /* code */
            }
            
           
            break;
            }

        case 2:{

            cout<<""<<endl;
            int posicion=0;
            int codigo =1;
            int cedula =0;
            int duplicado =0;
            cout << "Cedula cliente: ";
            cin >> cedula;
            while(clientesLista[posicion].codigoCliente!=0){
                if (clientesLista[posicion].cedula ==cedula)
                {   cout<<"Usario ya registrado"<<endl;
                    duplicado = -1;
                    break;
                }else{
                posicion++;
                codigo++;
                }
                
                
            }if (duplicado !=-1)
            {
            clientesLista[posicion].setCedula(cedula);
            clientesLista[posicion].setCodigo(codigo);
            clientesLista[posicion].set();
            cout<<"================================"<<endl;  /* code */
            }
            
           
            break;
        }


            // Lista usuarios
        case 3:{
            cout<<""<<endl;
            int posicion = 0;
            cout<<"Empleado ||  Apellido"<<endl;
            while(empleadosLista[posicion].codigoEmpleado!=0){
                cout<<empleadosLista[posicion].codigoEmpleado;
                cout<< "        ||    ";
                cout<< empleadosLista[posicion].apellido<<endl;
                posicion++;
            }
            
            cout<<"================================"<<endl;  
            break;
        }
         case 4:{
            cout<<""<<endl;
            int posicion = 0;
            cout<<"Cliente ||  Apellido"<<endl;
            while(clientesLista[posicion].codigoCliente!=0){
                cout<<clientesLista[posicion].codigoCliente;
                cout<< "       ||    ";
                cout<< clientesLista[posicion].apellido<<endl;
                posicion++;
            }
            
            cout<<"================================"<<endl;  
            break;
        }
            // Crea cuenta
        case 5:{
            int cliente = -1;
            // int lista[20];
            cout<<""<<endl;

            if (clientesLista[0].codigoCliente==0)
            {
                cout<< "No existen clientes registrados"<<endl;
                break;
            }
            cout<<"Seleccione un cliente de la lista:"<<endl;

            int posicion = 0;
            cout<<"Cliente ||  Apellido"<<endl;
            while(clientesLista[posicion].codigoCliente!=0){
                cout<<clientesLista[posicion].codigoCliente;
                cout<< "    ||    ";
                cout<< clientesLista[posicion].apellido<<endl;
                posicion++;
            }
            
            
            cuenta ingresar;
            int numeroCuenta=100;
            cin>>cliente;
            posicion=0;
            int registroPos=0;
             while(clientesLista[posicion].codigoCliente!=0){
                 if(clientesLista[posicion].codigoCliente==cliente){
                     
                    registroPos=0;
                     while (registroLista[registroPos].status!=-1)
                     {
                         registroPos++;
                         numeroCuenta++;
                     }

                     registroLista[registroPos].cliente.codigoCliente=cliente;\
                     ingresar.setNumero(numeroCuenta);
                     ingresar.set();
                     registroLista[registroPos].cuentaCliente=ingresar;
                     registroLista[registroPos].status=1;
                     cout<<"Cuenta creada con exito"<<endl;
                     registroLista[registroPos].cuentaCliente.view();
                     cout<<"================================"<<endl;
                     break;
                 }else{
            
                 }
                 posicion++;
            
            } 
            if (registroLista[registroPos].status!=1)
            {
                cout<<"Cliente ingresado incorrecto"<<endl;
                cout<<"================================"<<endl;
            }
            
            
            
            break;
            }
            // Lista cuentas
        case 6:{
            int cuentaPos=0;
            while(registroLista[cuentaPos].status!=-1){
                cout<<"Cuenta: "<<registroLista[cuentaPos].cuentaCliente.numeroDeCuenta<<endl;
                cuentaPos++;
              }
            break;
        }
            // Deposita
        case 7:{
            if ((registroLista[0].status==-1 ))
            {
                cout<<"No existe cuenta registrada"<<endl;
                break;
            }else if( empleadosLista[0].codigoEmpleado==0){
                cout<<"No existe empleado registrado"<<endl;
                break;
            }
            int empleado =0;
            int cuentaPos=0;
            int cuenta=-1;
            int empleadoPos = 0;
            cout<< "Seleccione un empleado:"<<endl;
            while(empleadosLista[empleadoPos].codigoEmpleado!=0){
                cout<<"Codigo de empleado: "<<empleadosLista[empleadoPos].codigoEmpleado<<" - Apellido - "<<empleadosLista[empleadoPos].apellido<<"Tipo -"<<empleadosLista[empleadoPos].tipoEmpleado<<endl;
                empleadoPos++;
              }
              
              cin>>empleado;
              if(empleado<1||empleado>empleadoPos){
                  cout<<"empleado incorrecto"<<endl;
                  break;
              }


            cout<< "Seleccione una cuenta:"<<endl;
            while(registroLista[cuentaPos].status!=-1){
                cout<<"Cuenta: "<<registroLista[cuentaPos].cuentaCliente.numeroDeCuenta<<endl;
                cuentaPos++;
              }
            cin>>cuenta;
            
            if(cuenta<100||cuenta>registroLista[cuentaPos-1].cuentaCliente.numeroDeCuenta){
                  cout<<"cuenta incorrecta"<<endl;
                  break;
              }
            cuentaPos=0;
            while(registroLista[cuentaPos].cuentaCliente.numeroDeCuenta!=cuenta){
                 cuentaPos++;
            }
            
            // cout<<cuentaPos<<endl;
            registroLista[cuentaPos].cuentaCliente.deposit();
            registroLista[cuentaPos].cuentaCliente.view();
            int transIndex=0;
            while (transacciones[transIndex].cuenta!=-1)
            {
              transIndex++;
              
            }
            historial reg;
            reg.set(empleado,cuenta,"Deposito");
            
            transacciones[transIndex]=reg;
            
            break;
        }
            // Retirar
        case 8:{
            // Retirar
            int cuentaPos=0;
            int cuenta=-1;
            int empleado=0;
            int empleadoPos = 0;
            cout<< "Seleccione un empleado:"<<endl;
            while(empleadosLista[empleadoPos].codigoEmpleado!=0){
                cout<<"Codigo de empleado: "<<empleadosLista[empleadoPos].codigoEmpleado<<" - Apellido - "<<empleadosLista[empleadoPos].apellido<<"Tipo -"<<empleadosLista[empleadoPos].tipoEmpleado<<endl;
                empleadoPos++;
              }
              
              cin>>empleado;
              if(empleado<1||empleado>empleadoPos){
                  cout<<"empleado incorrecto"<<endl;
                  break;
              }

            cout<< "Seleccione una cuenta de la lista:"<<endl;
            while(registroLista[cuentaPos].status!=-1){
                cout<<"Cuenta: "<<registroLista[cuentaPos].cuentaCliente.numeroDeCuenta<<endl;
                cuentaPos++;
              }
            cin>>cuenta;
            if(cuenta<100||cuenta>registroLista[cuentaPos-1].cuentaCliente.numeroDeCuenta){
                  cout<<"cuenta incorrecta"<<endl;
                  break;
              }
            cuentaPos=0;

            while(registroLista[cuentaPos].cuentaCliente.numeroDeCuenta!=cuenta){
                 cuentaPos++;
            }
            registroLista[cuentaPos].cuentaCliente.retirement();
            registroLista[cuentaPos].cuentaCliente.view();
            int transIndex=0;
            while (transacciones[transIndex].cuenta!=-1)
            {
              transIndex++;
              
            }
            historial reg;
            reg.set(empleado,cuenta,"Retiro");
            
            transacciones[transIndex]=reg;
            
            
            break;
        }
            // Saldo total bancario
        case 9:{
            int cuentaPos=0;
            float saldoBancarioPeso= 0;
            float saldoBancarioDolares= 0;

            
            while(registroLista[cuentaPos].status!=-1){
                
                string moneda = registroLista[cuentaPos].cuentaCliente._moneda();
                float saldo = registroLista[cuentaPos].cuentaCliente._saldo();
            
                if (moneda=="$" && saldo>0 )
                    {
                    saldoBancarioPeso = saldoBancarioPeso + saldo;
                    cuentaPos++;
                    }else if  (moneda=="U$S"&& saldo>0)
                    {
                    saldoBancarioDolares = saldoBancarioPeso + saldo;
                    cuentaPos++;
                    }else{
                        cuentaPos++;
                    }
                
                
                }
            cout<<"================================"<<endl;
            cout<< "Saldo en Pesos: "<<saldoBancarioPeso<<endl;
            cout<<"Saldo en Dolares: "<<saldoBancarioDolares<<endl;
            cout<<"================================"<<endl;

            break;


       
            }
            // Historial de transacciones
        case 10:{
          
            int transIndex = 0;
            while (transacciones[transIndex].cuenta!=-1)
            {
                transacciones[transIndex].view();
                transIndex++;
              
            }
            
            }
        }   
    }
    return 0;

    
}