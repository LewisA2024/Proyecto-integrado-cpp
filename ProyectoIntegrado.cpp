// P_integrador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <map>
#include<set>
#include <fstream>
using namespace std;

const int max_cant_id = 5; // Tamaño máximo de los IDs

bool solo_numeros(const string& str) { // Para asegurar que el ID solo contenga números y no se vaya en un loop infinito 
    for (char const& c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    string nombre, apellido, lectorlinea; // Variables para guardar datos de tipo texto
    int menu, categoria_1, categoria_2, categoria_3, opcion_salida = 0; // Variables para guardar opción del menú y la votación
    int id_unico, votacion;
    set<int> ids;  // Usamos un set para almacenar los IDs únicos
    map<string, int> votos_categoria_1, votos_categoria_2, votos_categoria_3;  // Mapas para almacenar los votos

    // Definir las series por categoría
    map<int, string> series_categoria_1 = {
        {1, "Supernatural"},
        {2, "How I Met Your Mother?"},
        {3, "Stranger Things"},
        {4, "El Chavo del 8"}
    };
    map<int, string> series_categoria_2 = {
        {1, "Dragon Ball"},
        {2, "Dororo"},
        {3, "One Piece"},
        {4, "Bleach"}
    };
    map<int, string> series_categoria_3 = {
        {1, "Rick and Morty"},
        {2, "Regular Show"},
        {3, "Looney Tunes"},
        {4, "Futurama"}
    };

    // Crear y abrir el archivo de texto para escribir
    ofstream Myfile("Conteo_votaciones.txt");

    // Leer los votos desde el archivo (si es necesario)
    ifstream MyFile("Conteo_votaciones.txt");
    while (getline(MyFile, lectorlinea)) {
        cout << lectorlinea << endl;
    }
    MyFile.close();
    do{
    // Login del usuario
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    cin >> apellido;
    cout << "Ingrese su ID: ";
    cin >> id_unico;

    // Verificar si el ID ya está registrado
    if (ids.count(id_unico) > 0) {
        cout << "Este ID ya ha votado." << endl;
        return 1;  // Salir si el ID ya existe
    }

    // Registrar el ID en el set
    ids.insert(id_unico);

    // Menú de votaciones
    
        cout << "Bienvenidos a las votaciones de series!" << endl;
        cout << "1. Deseo participar de las votaciones" << endl;
        cout << "2. Deseo salir de la app" << endl;
        cin >> menu;
        cout << endl;

        if (menu == 1) {
            // Votación de la categoría 1: Series Live Action
            cout << "Categoria #1: Series Live Action" << endl;
            for (const auto& serie : series_categoria_1) {
                cout << serie.first << ". " << serie.second << endl;
            }
            cin >> categoria_1;
            //para establecer rango 
            do {
                cout << "Por cual desea votar?:  \n";
                cin >> categoria_1;

                if ( categoria_1 < 1 || categoria_1 > 4) {
                    cout << "ERROR: Opcion no valida. Por favor, elija un numero entre 1 y 4." << endl;
                }
            } while (categoria_1 < 1 || categoria_1 > 4);
            cout << endl << endl << endl;


            // Votación de la categoría 2: Series de Anime
            cout << "Categoria #2: Series de Anime" << endl;
            for (const auto& serie : series_categoria_2) {
                cout << serie.first << ". " << serie.second << endl;
            }
            cin >> categoria_2;
            do {
                cin >> categoria_1;

                if (categoria_1 < 1 || categoria_1 > 4) {
                    cout << "ERROR: Opcion no valida. Por favor, elija un numero entre 1 y 4." << endl;
                }
            } while (categoria_1 < 1 || categoria_1 > 4);
            cout << endl << endl << endl;

            // Votación de la categoría 3: Series Animadas
            cout << "Categoria #3: Series Animadas" << endl;
            for (const auto& serie : series_categoria_3) {
                cout << serie.first << ". " << serie.second << endl;
            }
            cin >> categoria_3;
            do {
                cin >> categoria_1;

                if (categoria_1 < 1 || categoria_1 > 4) {
                    cout << "ERROR: Opcion no valida. Por favor, elija un numero entre 1 y 4." << endl;
                }
            } while (categoria_1 < 1 || categoria_1 > 4);
            cout << endl << endl << endl;

            // Registrar los votos en los mapas
            votos_categoria_1[series_categoria_1[categoria_1]]++;
            votos_categoria_2[series_categoria_2[categoria_2]]++;
            votos_categoria_3[series_categoria_3[categoria_3]]++;

            cout << "Desea continuar votando o salir?" << endl;
            cout << "1. Volver al menu principal" << endl;
            cout << "2. Salir" << endl;
            cin >> opcion_salida;
        }
        else if (opcion_salida == 2) {
            cout << "Usted ha salido de la app" << endl;
        }
        else {
            cout << "ERROR: El valor ingresado no es válido." << endl;
        }
    } while (opcion_salida != 2);

    // Imprimir los resultados finales
    cout << "Resultados de las votaciones:" << endl;
    cout << "Categoria #1: Series Live Action" << endl;
    for (const auto& serie : votos_categoria_1) {
        cout << serie.first << ": " << serie.second << " votos" << endl;
    }

    cout << "Categoria #2: Series de Anime" << endl;
    for (const auto& serie : votos_categoria_2) {
        cout << serie.first << ": " << serie.second << " votos" << endl;
    }

    cout << "Categoria #3: Series Animadas" << endl;
    for (const auto& serie : votos_categoria_3) {
        cout << serie.first << ": " << serie.second << " votos" << endl;
    }

    // Escribir los resultados en el archivo
    Myfile << "Resultados de las votaciones:" << endl;
    cout << endl; //para espacio 
    Myfile << "Categoria #1: Series Live Action" << endl;
    for (const auto& serie : votos_categoria_1) {
        Myfile << serie.first << ": " << serie.second << " votos" << endl;
    }

    Myfile << "Categoria #2: Series de Anime" << endl;
    cout << endl; //para espacio 
    for (const auto& serie : votos_categoria_2) {
        Myfile << serie.first << ": " << serie.second << " votos" << endl;
    }

    Myfile << "Categoria #3: Series Animadas" << endl;
    cout << endl; //para espacio
    for (const auto& serie : votos_categoria_3) {
        Myfile << serie.first << ": " << serie.second << " votos" << endl;
    }

    Myfile.close();  // Cerrar el archivo

    return 0;
}