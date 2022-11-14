#include <iostream>
#include "Nodo.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Secuestro");

    Nodo* A = new Nodo("A");
    Nodo* B = new Nodo("B"); 
    Nodo* C = new Nodo("C");
    Nodo* D = new Nodo("D");
    Nodo* E = new Nodo("E");
    Nodo* F = new Nodo("F");
    Nodo* G = new Nodo("G");
    Nodo* NodoActual = new Nodo("aux");
    
    A->setScene("messi.jpg");
    B->setScene("jaken.png");
    C->setScene("messi.jpg");
    D->setScene("jaken.png");
    E->setScene("messi.jpg");
    F->setScene("jaken.png");
    G->setScene("messi.jpg");

    A->listaAdyacencia = { B, C };
    B->listaAdyacencia = { D, E};
    C->listaAdyacencia = { G };
    D->listaAdyacencia = { C, F};
    E->listaAdyacencia = { B, C };
    F->listaAdyacencia = { };
    G->listaAdyacencia = { F };
    
    NodoActual = A;
   
    list<Nodo*> MatrizNodos = {A, B, C, D, E, F, G};
    std::list<Nodo*>::iterator element;
       

    while (window.isOpen()) {
 
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(NodoActual->getScene());
        window.display();

        if (NodoActual->listaAdyacencia.empty()) {
            cout << "GAME OVER" << endl;
            system("pause");
            cout << "Quieres volver a empezar? [Y] Si\n[N] No" << endl;
            std::string _empezar;
            cin >> _empezar;
            if (_empezar == "y" || _empezar == "Y") {
                NodoActual = A;
            }
            else {
                window.close();

            }
        }
        else {
            cout << "A donde quieres ir?" << endl;
            for (auto x : NodoActual->listaAdyacencia)
            {
                cout << x->getName() << " ";
            }
            cout << endl;
            std::string opcion;
            cin >> opcion;

            element = find_if(NodoActual->listaAdyacencia.begin(), NodoActual->listaAdyacencia.end(), [&NodoActual, opcion](Nodo* n1) {
                if (n1->getName() == opcion) {
                    return NodoActual = n1;
                }
                else
                {
                    cout << "Elije una opcion valida" << endl;
                    system("pause");
                    system("cls");
                }
                });
        }
    }


    delete A, B, C, D, E, F, G;
    delete NodoActual;
}
