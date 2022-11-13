#pragma once
#include <iostream>

class Nodo;

class Arista
{
private:
	Nodo* origen;
	Nodo* destino;
	int precio;
public:
	Arista();
};

