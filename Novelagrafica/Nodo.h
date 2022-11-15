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
	std::string nmusic;


public:
	Nodo(std::string);
	void setScene(std::string);
	sf::Sprite getScene();
	std::string getName();
	void setContext(std::string);
	std::string getContext();
	std::list<Nodo*> listaAdyacencia = {};
	void setMusic(std::string);
	std::string getMusic();
	
	
};

