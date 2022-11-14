#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Nodo {
private:
	std::string name;
	std::string path;
	std::string context;
	sf::Texture texture;
	sf::Sprite sprite;
	Nodo* next;

public:
	Nodo(std::string);
	void setScene(std::string);
	std::string getName();
	void setContext(std::string);
	std::string getContext();
	std::list<Nodo*> listaAdyacencia;
	sf::Sprite getScene();
};

