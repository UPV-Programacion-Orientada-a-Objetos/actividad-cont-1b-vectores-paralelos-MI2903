#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>
using namespace std;

// Constante para el tamaño máximo del inventario
const int MAX_PRODUCTOS = 100;
// Umbral para considerar bajo stock
const int UMBRAL_BAJO_STOCK = 10;
// Nombre del archivo de inventario
const string ARCHIVO_INVENTARIO = "inventario.txt";

// Arreglos paralelos para almacenar la información de los productos
int codigos[MAX_PRODUCTOS];           // Códigos únicos de los productos
string nombres[MAX_PRODUCTOS];        // Nombres de los productos
int cantidades[MAX_PRODUCTOS];        // Cantidades en stock de los productos
float precios[MAX_PRODUCTOS];         // Precios unitarios de los productos
string ubicaciones[MAX_PRODUCTOS];    // Ubicaciones en almacén de los productos

int numProductos = 0; // Contador de productos actuales en el inventario

//==Funciones de manejo de archivos 

//funcion para caragar el inventario desde el archivo inventario.txt
//lee la linea por linea y extrae los datos separados por comas 

bool cargarInventario() {
    ifstream archivo(ARCHIVO_INVENTARIO);
    
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << ARCHIVO_INVENTARIO << endl;
        cout << "Se iniciará con inventario vacío." << endl;
        return false;
    }
    
    string linea;
    // Saltamos la primera línea que contiene los encabezados
    if (getline(archivo, linea)) {
        cout << "Cargando inventario desde '" << ARCHIVO_INVENTARIO << "'..." << endl;
    }
    numProductos = 0;
    //leemos liena por linea del archivo 
    while (getline(archivo, linea) && numProductos < MAX_PRODUCTOS) {
        stringstream ss(linea);
        string dato;
// extraemos el codigo 
if (getline(ss, dato, ',')) {
            codigos[numProductos] = stoi(dato);
        } else continue;
        //extraemos el nombre 
if (getline(ss, dato, ',')) {
            nombres[numProductos] = dato;
        } else continue;
        //extraemos la cantidad 
if (getline(ss, dato, ',')) {
            cantidades[numProductos] = stoi(dato);
        } else continue;
        //extraemos el precio
         if (getline(ss, dato, ',')) {
            precios[numProductos] = stof(dato);
        } else continue;
        //extraemos la ubicacion (ultimo campo)
        if (getline(ss, dato)) {
            ubicaciones[numProductos] = dato;
        } else continue;
        
        numProductos++;


  

}
}