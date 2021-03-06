// Ejercicio 2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

void showHangman(int parts, char show[]) {
	cout << ".____\n";
	cout << "|   |\n";
	if (parts > 0) {
		cout << "|   O\n";
		if (parts > 1) {
			cout << "|   |\n";
			if (parts > 2) {
				cout << "|  /|";
				if (parts > 3) {
					cout << "\\\n";
					if (parts > 4) {
						cout << "|   |\n";
						if (parts > 5) {
							cout << "|  / ";
							if (parts > 6) {
								cout << "\\\n";
							}
						}
					}
				}
			}
		}
	}
	cout << "\n\n";
	for (int i = 0; show[i] != '\0'; i++) {
		cout << show[i] << " ";
	}
	cout << endl;
}

bool isInWord(char l, char w[], char g[], bool *cont) {
	bool itIs = false;
	for (int i = 0; w[i] != '\0'; i++) {
		if (l == w[i]) {
			g[i] = l;
			itIs = true;
		}
	}
	if (strcmp(w, g) == 0) cont = false;
	return itIs;
}

int main() {
	char palabras[10][15] = { "RARO", "DEBILIDAD", "LEYENDA", "INFLACION", "AMENAZA", "COCINERO", "UNIVERSAL", "ENDURECER", "DIRECTIVA", "IZQUIERDA" };
	char choice;
	do {
		int turns = 0;
		bool keep = true;
		char chosen[15];
		char guessed[15] = "______________";
		srand(time(NULL));
		strcpy_s(chosen, palabras[rand() % 10]);
		guessed[strlen(chosen)] = '\0';
		char letter;
		showHangman(turns, guessed);
		while (keep && turns < 7) {
			cout << "Ingrese una letra(mayusculas):\n>>> ";
			cin >> letter;
			if (isInWord(letter, chosen, guessed, &keep)) {
				cout << "correcto!\n";
			}
			else {
				cout << "incorrecto!\n";
				turns++;
			}
			showHangman(turns, guessed);
		}
		if (turns == 7) {
			cout << "Has perdido! Reintentar?(S / N)\n>>> ";
			cin >> choice;
		}
		else {
			cout << "Ha ganado! Reintentar? (S / N)\n>>> ";
			cin >> choice;
		}
	} while (choice == 's' || choice == 'S');
	return 0;
}