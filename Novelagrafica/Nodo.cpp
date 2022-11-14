#include "Nodo.h"
using namespace std;

Nodo::Nodo(std::string _name) {
	name = _name;

}

void Nodo::setScene(std::string _path) {
	texture.loadFromFile(_path);
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