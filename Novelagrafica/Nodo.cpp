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
//void operator << (ostream os, std::string s);

//ostream& operator <<(ostream& os, std::list<std::string> listad) {
//	std::list<std::string>::iterator it = listad.begin();
//	for (it; it != listad.end(); ++it) {
//		cout << *it;
//	}
//
//
//}