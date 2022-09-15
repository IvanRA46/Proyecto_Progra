#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>


using namespace std;

class  Figuras {
private:
    int x, y;
    char character;
public:
    Figuras (char character, int x, int y) {
        this->character = character;
        this->x = x;
        this->y = y;
    };
    int getX();
    int getY();
    char getCharacter();
    virtual void draw() = 0;
};

class Cuadro : public Figuras {
private:
    int side, fill;
public:
    Cuadro(char character, int x, int y, int side, int fill) : Figuras(character, x, y) {
        this->side = side;
        this->fill = fill;
    };
    int getSide();
    int getFill();
    void draw();
};

class Triangulo : public Figuras {
private:
    int height;
public:
    Triangulo(char character, int x, int y, int height) : Figuras (character, x, y) {
        this->height = height;
    };
    int getHeight();
    void draw();
};

class Circulo : public Figuras {
private:
    int radius;
public:
    Circulo(char character, int x, int y, int radius) : Figuras(character, x, y) {
        this->radius = radius;
    };
    int getRadius();
    void draw();
};


char Figuras::getCharacter() {
	return character;
}

int Figuras::getX() {
	return x;
}

int Figuras::getY() {
	return y;
}


int Cuadro::getSide() {
	return side;
}

int Cuadro::getFill() {
	return fill;
}

void Cuadro::draw() {
	char cha, matrix[100][100];
	int x, y, s, f;
	int i = 0, j = 0;
	cha = getCharacter();
	s = getSide();
	f = getFill();
	x = getX();
	y = getY();
	char opcion = _getch();

	while (opcion != 'q') {
		system("cls");
		cout << "Opciones para mover la figura:" << endl;
		cout << "(W) Arriba\t";
		cout << "(S) Abajo\t";
		cout << "(A) Izquierda\t";
		cout << "(D) Derecha\t";
		cout << "(Q) Salir\t";

		for (i; i < s; i++) {
			for (j = 0; j < s; j++) {
				if (f == 0) {
					if (i == 0 || j == 0 || i == s - 1 || j == s - 1) {
						matrix[i][j] = cha;
					}
					else {
						matrix[i][j] = ' ';
					}
				}
				else {
					matrix[i][j] = cha;
				}
			}
		}

		for (i = 1; i < y; i++) cout << " " << endl;
		for (i = 0; i < s; i++) {
			cout << setw(x);
			for (j = 0; j < s; j++) {
				cout << matrix[i][j];
			}
			cout << "   " << endl;
		}

		opcion = _getch();
		switch (opcion) {
		case 'w': y--; break;
		case 's': y++; break;
		case 'a': x--; break;
		case 'd': x++; break;
		}
	}
}


int Triangulo::getHeight() {
	return height;
}

void Triangulo::draw() {
	char cha;
	int x, y, h;
	int i = 0, j = 0;
	cha = getCharacter();
	h = getHeight();
	x = getX();
	y = getY();
	char opcion = _getch();

	while (opcion != 'q') {
		system("cls");
		cout << "Opciones para mover la figura:" << endl;
		cout << "(W) Arriba\t";
		cout << "(S) Abajo\t";
		cout << "(A) Izquierda\t";
		cout << "(D) Derecha\t";
		cout << "(Q) Salir\t";

		for (i = 1; i < y; i++) cout << " " << endl;
		for (i = 1; i <= h; i++) {
			cout << setw(x);
			for (j = 1; j <= h - i; j++) cout << " ";
			for (j = 1; j <= 2 * i - 1; j++) cout << cha;
			cout << endl;
		}

		opcion = _getch();
		switch (opcion) {
		case 'w': y--; break;
		case 's': y++; break;
		case 'a': x--; break;
		case 'd': x++; break;
		}
	}
}



int Circulo::getRadius() {
	return radius;
}

void Circulo::draw() {
	char cha;
	int x, y, r;
	int i = 0, j = 0;
	cha = getCharacter();
	r = getRadius();
	x = getX();
	y = getY();
	char opcion = _getch();

	while (opcion != 'q') {
		system("cls");
		cout << "Opciones para mover la figura:" << endl;
		cout << "(W) Arriba\t";
		cout << "(S) Abajo\t";
		cout << "(A) Izquierda\t";
		cout << "(D) Derecha\t";
		cout << "(S) Salir\t";

		for (i = 1; i < y; i++) cout << " " << endl;
		for (j = 0; j <= r * 2; j++) {
			cout << setw(x);
			for (i = 0; i <= r * 2; i++) {
				if (pow(i - r, 2) + pow(j - r, 2) <= pow(r, 2)) cout << cha;
				else cout << " ";
			}
			cout << endl;
		}

		opcion = _getch();
		switch (opcion) {
		case 'w': y--; break;
		case 's': y++; break;
		case 'a': x--; break;
		case 'd': x++; break;
		}
	}
}