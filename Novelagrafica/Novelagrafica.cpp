#include <iostream>
#include "Nodo.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(750,800), "Novela grafica");
    sf::Music music1;
    music1.openFromFile("music/TheBiggestDiscovery.ogg");
    music1.setVolume(10);
    Nodo* A = new Nodo("A"); 
    Nodo* B = new Nodo("B"); 
    Nodo* C = new Nodo("C"); 
    Nodo* D = new Nodo("D"); 
    Nodo* E = new Nodo("E"); E->setMusic("music/persecusion.ogg");//persecusion
    Nodo* F = new Nodo("F"); F->setMusic("music/Assassin.ogg");
    Nodo* G = new Nodo("G"); G->setMusic("music/TheBiggestDiscovery.ogg");
    Nodo* H = new Nodo("H"); H->setMusic("music/Anguish.ogg");
    Nodo* I = new Nodo("I"); 
    Nodo* J = new Nodo("J"); J->setMusic("music/Battleship.ogg");//musica de combate
    Nodo* K = new Nodo("K"); K->setMusic("music/Assassin.ogg");
    Nodo* NodoActual = new Nodo("aux");
    
    A->setScene("escenaA.png");         
    B->setScene("escenaB.png");         
    C->setScene("escenaC.png");
    D->setScene("escenaD.png");
    E->setScene("escenaE.png");
    F->setScene("escenaF.png");
    G->setScene("escenaG.png");
    H->setScene("escenaH.png");
    I->setScene("escenaI.png");
    J->setScene("escenaJ.png");
    K->setScene("escenaK.png");

    A->listaAdyacencia = { B, C };
    B->listaAdyacencia = { D, E};
    C->listaAdyacencia = { F };
    D->listaAdyacencia = { G, E};
    E->listaAdyacencia = { H };
    F->listaAdyacencia = { B, E};
    G->listaAdyacencia = { I, J };
    H->listaAdyacencia = { K };
    I->listaAdyacencia = { H };
    J->listaAdyacencia = { H };
    K->listaAdyacencia = {  };
    
    NodoActual = A;
    music1.play();
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
            system("cls");
            if (_empezar == "y" || _empezar == "Y") {
                NodoActual = A;
            }
            else {
                window.close();

            }
        }
        else {
            sf::Music musicaActual;
            musicaActual.getLoop();
            musicaActual.setVolume(100);
            if (NodoActual->getMusic() != ""){
                musicaActual.openFromFile(NodoActual->getMusic());
                musicaActual.play();
            }

            cout << "Estas en: " << NodoActual->getName() << endl;
            cout << NodoActual->getContext() << endl;
            cout << "A donde quieres ir?" << endl;
            for (auto x : NodoActual->listaAdyacencia)
            {
                cout <<"|" << x->getName() << "|" << " ";
            }
            cout << endl;
            std::string opcion;
            cin >> opcion;
            system("cls");
            for_each(NodoActual->listaAdyacencia.begin(), NodoActual->listaAdyacencia.end(), [&NodoActual, opcion](Nodo* n1) {
                
                if (n1->getName() == opcion) {
                    return NodoActual = n1;
                }
                });
         
        }
    }


    delete A, B, C, D, E, F, G, H, J , K;
    delete NodoActual;
}
