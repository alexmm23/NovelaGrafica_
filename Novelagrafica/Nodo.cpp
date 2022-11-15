#include "Nodo.h"
using namespace std;

Nodo::Nodo(std::string _name) {
	name = _name;
	

}

void Nodo::setScene(std::string _path) {
	path = _path;
	texture.loadFromFile("images/" + path);
	sprite.setTexture(texture);
	
}
sf::Sprite Nodo::getScene() {
	return sprite;
}

std::string Nodo::getName() {
	return name;
}
void Nodo::setContext(std::string _context) {
	context = _context;

}
std::string Nodo::getContext() {
	return context;
}

void Nodo::setMusic(std::string _path) {
	nmusic = _path;
}
std::string Nodo::getMusic() {
	return nmusic;
}
