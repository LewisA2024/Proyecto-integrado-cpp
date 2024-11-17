// P_integrador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Janerys M. Ortiz Aviles 
//Lewis Diaz Acevedo

#include <iostream>
#include <string>
#include <map>
#include<set>
#include <fstream>
using namespace std;

const int max_cant_id = 5; // Tamano maximo de los IDs

bool solo_numeros(const string& str) { // Para asegurar que el ID solo contenga números y no se vaya en un loop infinito 
    for (char const& c : str) {
        if (isalpha(c)) return true;
        
         
    }
    return false;
}

int main() {
    string id_unico1, nombre, apellido, lectorlinea; // Variables para guardar datos de tipo texto
    int menu, categoria_1, categoria_2, categoria_3; // Variables para guardar opción del menú y la votación en las categorias 
    int id_unico;
    set<int> ids;  // Usamos un set para almacenar los IDs únicos
    map<string, int> votos_categoria_1, votos_categoria_2, votos_categoria_3;  // Mapas para almacenar los votos

    // Definir las series por categoría / los numeros representan las series, similar a pow.
    map<int, string> series_categoria_1 = {
        {1, "Supernatural"},
        {2, "How I Met Your Mother"},
        {3, "Stranger Things"},
        {4, "El Chavo del 8"}
    };
    cout << endl << endl; 
    map<int, string> series_categoria_2 = {
        {1, "Dragon Ball"},
        {2, "Dororo"},
        {3, "One Piece"},
        {4, "Bleach"}
    };
    cout << endl << endl; 
    map<int, string> series_categoria_3 = {
        {1, "Rick and Morty"},
        {2, "Regular Show"},
        {3, "Looney Tunes"},
        {4, "Futurama"}
    };
    cout << endl << endl; 

    // Crear y abrir el archivo de texto para escribir
    ofstream Myfile("Conteo_votaciones.txt");

    // Lee los votos desde el archivo 
    ifstream MyFile("Conteo_votaciones.txt");
    while (getline(MyFile, lectorlinea)) {
        cout << lectorlinea << endl;
    }
    MyFile.close();
    do{
    
    // Menu de opciones
    
        cout << "Bienvenidos a las votaciones de series!" << endl;
        cout << "1. Deseo participar de las votaciones" << endl;
        cout << "2. Deseo salir de la app" << endl;
        cin >> menu;
        cout << endl;

        if (menu == 1) {
            
            
            //Login
            cout << "Ingrese su nombre: ";
            cin >> nombre;
            cout << "Ingrese su apellido: ";
            cin >> apellido;
            cout << "Ingrese su ID: ";
            cin >> id_unico1;

            //Verifica que el ID solo tenga numeros
            while (solo_numeros(id_unico1)) {
                cout << "El ID solo puede tener digitos: ";
                cin >> id_unico1;
            
            
            }
            //La funcion stoi hace un cambio de string a entero
                id_unico = stoi(id_unico1);
                // Verificar si el ID ya está registrado.
                while (ids.count(id_unico) > 0) {
                    cout << "Este ID ya ha votado." << endl;
                    cout << "Ingrese un ID diferente: ";
                    cin >> id_unico;

                }
            // Inserta el ID en el set
            ids.insert(id_unico);

            
            
            
            
            // Votacion de la categoria 1: Series Live Action
            cout << "\n\n\nCategoria #1: Series Live Action" << endl;
            for (const auto& serie : series_categoria_1) {
                cout << serie.first << ". " << serie.second << endl;
            }
             
            do {
                cout << "Por cual desea votar?:  \n";
                cin >> categoria_1;

                if ( categoria_1 < 1 || categoria_1 > 4) {
                    cout << "ERROR: Opcion no valida. Por favor, elija un numero entre 1 y 4." << endl;
                }
            } while (categoria_1 < 1 || categoria_1 > 4);
            cout << endl << endl << endl;


            // Votacion de la categoria 2: Series de Anime
            cout << "Categoria #2: Series de Anime" << endl;
            for (const auto& serie : series_categoria_2) {
                cout << serie.first << ". " << serie.second << endl;
            }
            /
            do {

                cout << "\n\nPor cual desea votar?:  \n";
                cin >> categoria_2;

                if (categoria_2 < 1 || categoria_2 > 4) {
                    cout << "\n\nERROR: Opcion no valida. Por favor, elija un numero entre 1 y 4." << endl;
                }
            } while (categoria_2 < 1 || categoria_2 > 4);
            cout << endl << endl << endl;

            // Votacion de la categoría 3: Series Animadas
            cout << "Categoria #3: Series Animadas" << endl;
            for (const auto& serie : series_categoria_3) {
                cout << serie.first << ". " << serie.second << endl;
            }
           
            do {

                cout << "\n\nPor cual desea votar?:  \n";
                cin >> categoria_3;

                if (categoria_3 < 1 || categoria_3 > 4) {
                    cout << "ERROR: Opcion no valida. Por favor, elija un numero entre 1 y 4." << endl;
                }
            } while (categoria_3 < 1 || categoria_3 > 4);
            cout << endl << endl << endl;

            // Registrar los votos en los mapas
            votos_categoria_1[series_categoria_1[categoria_1]]++;
            votos_categoria_2[series_categoria_2[categoria_2]]++;
            votos_categoria_3[series_categoria_3[categoria_3]]++;
           
            cout << "Desea continuar votando o salir?" << endl;
            cout << "1. Volver al menu principal" << endl;
            cout << "2. Salir" << endl;
            cin >> menu;
        }
        else if ( menu == 2) {
            cout << "\n\nUsted ha salido de la app" << endl;
        }
        else {
            cout << "\n\nERROR: El valor ingresado no es válido." << endl;
        }
    } while ( menu != 2);

    // Escribe los resultados finales
    cout << "\n\nResultados de las votaciones:\n\n" << endl;
    cout << "Categoria #1: Series Live Action\n" << endl;
    for (const auto& serie : votos_categoria_1) {
        cout << serie.first << ": " << serie.second << " votos" << endl;
    }

    cout << "\n\n\nCategoria #2: Series de Anime\n" << endl;
    for (const auto& serie : votos_categoria_2) {
        cout << serie.first << ": " << serie.second << " votos" << endl;
    }

    cout << "\n\n\nCategoria #3: Series Animadas\n" << endl;
    for (const auto& serie : votos_categoria_3) {
        cout << serie.first << ": " << serie.second << " votos" << endl;
    }

    // Imprime los resultados en el archivo. Esto es lo que sale en pantalla
    Myfile << "Resultados de las votaciones:\n\n" << endl;
    cout << endl; // El \n es para espacio y que se vea mas organizado 
    Myfile << "Categoria #1: Series Live Action: \n" << endl;
    for (const auto& serie : votos_categoria_1) {
        Myfile << serie.first << ": " << serie.second << " votos" << endl;
    }

    Myfile << "\n\n\nCategoria #2: Series de Anime: \n" << endl;
    cout << endl;  
    for (const auto& serie : votos_categoria_2) {
        Myfile << serie.first << ": " << serie.second << " votos" << endl;
    }

    Myfile << "\n\n\nCategoria #3: Series Animadas: \n" << endl;
    cout << endl; 
    for (const auto& serie : votos_categoria_3) {
        Myfile << serie.first << ": " << serie.second << " votos" << endl;
    }

    Myfile.close();  // Cierra el archivo

    return 0;
}

