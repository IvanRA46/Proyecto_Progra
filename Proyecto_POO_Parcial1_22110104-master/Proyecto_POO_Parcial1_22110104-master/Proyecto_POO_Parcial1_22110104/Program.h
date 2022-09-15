#include<iostream>
#include "Figuras.h"
#include <iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

class Program {
public:
    void run();
    void menu();
};

void Program::run() {
	menu();
}

void Program::menu() {
	int* pointer_shape;
	int x = 1, y = 1, side, height, radius, fill;
	char q;



	pointer_shape = new int;
	system("cls");
	cout << "Bienvenido\nQue figura desea dibujar?\n1. Cuadrado\n2. Triangulo\n3. Circulo\nIngrese opcion: " << endl;
	cin >> *pointer_shape;
	system("cls");

	cout << "Ingrese el caracter con el que desea dibujar la figura: ";
	cin >> q;
	system("cls");

	if (*pointer_shape == 1) {
		do {
			cout << "Desea que su figura tenga relleno?\n0. NO\n1. SI\nElija una opcion " << endl;
			cin >> fill;
			system("cls");
			cout << "Ingrese la longitud del lado del cuadrado: ";
			cin >> side;
		} while (side <= 0);
		Cuadro* s;
		s = new Cuadro(q, x, y, side, fill);
		s->draw();
		delete s;
	}

	if (*pointer_shape == 2) {
		do {
			cout << "Ingrese la longitud del la altura del triangulo: ";
			cin >> height;
		} while (height <= 0);
		Triangulo* t;
		t = new Triangulo(q, x, y, height);
		t->draw();
		delete t;
	}

	if (*pointer_shape == 3) {
		do {
			cout << "Ingrese la longitud del radio del circulo: ";
			cin >> radius;
		} while (radius <= 0);
		Circulo* c;
		c = new Circulo(q, x, y, radius);
		c->draw();
		delete c;
	}



	cout << "\nHasta luego:)\n" << endl;
}