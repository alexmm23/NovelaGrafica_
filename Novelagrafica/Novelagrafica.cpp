#include <iostream>
#include "Nodo.h"
#include "Arista.h"
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
    
    A->setScene("jaken.png");
    A->listaAdyacencia = { B, C };
    B->listaAdyacencia = { D, E};
    C->listaAdyacencia = { G };
    D->listaAdyacencia = { C, F};
    E->listaAdyacencia = { B, C };
    F->listaAdyacencia = {  NULL };
    G->listaAdyacencia = { F };
    
    NodoActual = A;
    

    list<Nodo*> MatrizNodos = {A, B, C, D, E, F, G};
   

    

    while (window.isOpen()) {
 
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(NodoActual->getScene());
        window.display();


        cout << "A donde quieres ir?" << endl;
        for (auto x : NodoActual->listaAdyacencia)
        {
            cout << x->getName() << " ";
        }
        cout << endl;
        std::string opcion;
        cin >> opcion;

        std::list<Nodo*>::iterator element;
        element = find_if(MatrizNodos.begin(), MatrizNodos.end(), [opcion](Nodo* n) {
            std::list<Nodo*>::iterator it = n->listaAdyacencia.begin();
            Nodo* temp = *it;
            for (it; it != n->listaAdyacencia.end(); ++it) {
                if (temp->getName() == opcion) {
                    return temp;
                }
                else {
                    cout << "No existe esa opcion" << endl;
                }
            }
            });
        NodoActual = *element;
        /*while(element != NodoActual->listaAdyacencia.end())*/
        
        /*std::list<string>::iterator element;
        element = find_if(NodoActual->listaAdyacencia.begin(), NodoActual->listaAdyacencia.end(), [opcion](string name) {
            if (name == opcion)
                return "hello"; });
        
        if(element != NodoActual->listaAdyacencia.end()){
            NodoActual = 
        }*/
        //auto element = for_each(MatrizAdyacente.begin(), MatrizAdyacente.end(), [opcion](list<Nodo*> plist)
        //    {
        //        list<Nodo*>::iterator i = plist.begin();
        //        Nodo* aux = new Nodo("aux");
        //        for (i; i != plist.end(); i++) {
        //            
        //            aux = *i;
        //            if (aux->getName() == opcion) {
        //                cout << aux->getName();
        //                return aux;
        //            }
        //            else {
        //                cout << "falla al encontrar el nombre del nodo";
        //                return aux;
        //            }
        //        }
        //    });
        //auxiliar = element;
    }



}