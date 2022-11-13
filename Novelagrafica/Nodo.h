#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Arista;

class Nodo{
private:
	std::string name;
	std::string path;
	sf::Texture texture;
	sf::Sprite sprite;
	Nodo* next;
	Arista* ari;


public:
	Nodo(std::string);
	void setScene(std::string);
	std::string getName();
	std::list<Nodo*> listaAdyacencia;
	sf::Sprite getScene();
	//friend ostream& operator <<(ostream& os, std::list<std::string> listad);
};

