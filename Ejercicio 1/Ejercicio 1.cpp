// Ejercicio 1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct seat {
	int number;
	char passenger[40];
	char DNI[11];
	bool taken;
	bool smoking;
};

int main() {
	const int AMOUNT = 20;
	bool skip = false;
	struct seat asientos[AMOUNT];
	char trash[1];
	for (int i = 0; i < AMOUNT; i++) {
		if (i >= 10) asientos[i].smoking = true;
		asientos[i].taken = false;
		strcpy_s(asientos[i].passenger, "N/A");
		strcpy_s(asientos[i].DNI, "N/A");
		asientos[i].number = i + 1;
	}
	int choice;
	do {
		if (!skip) {
			cout << "\n1. Sector fumadores\n";
			cout << "2. Sector no fumadores\n";
			cout << "3. Salir\n\n";
			cin >> choice;
			cin.getline(trash, 1);
		}
		else skip = false;
		bool hayAsientoDisp = false;
		int chosenSeat;
		switch (choice) {
		case 1:
			for (int i = 0; i < AMOUNT / 2; i++) {
				if (!asientos[i].taken) {
					hayAsientoDisp = true;
					break;
				}
			}
			if (hayAsientoDisp) {
				bool success = false;
				do {
					cout << "Los asientos disponibles son:\n";
					for (int i = 0; i < AMOUNT / 2; i++)
						if (!asientos[i].taken)
							cout << "- " << asientos[i].number << endl;
					cout << "Elija su asiento:\n>>> ";
					cin >> chosenSeat;
					cin.getline(trash, 1);
					for (int i = 0; i < AMOUNT / 2;i++) {
						if (asientos[i].number == chosenSeat && !asientos[i].taken) {
							cout << "Confirmado el asiento " << chosenSeat << ". Ingrese su nombre:\n>>> ";
							cin.getline(asientos[i].passenger, 40);
							cout << "Ingrese su DNI:\n>>> ";
							cin.getline(asientos[i].DNI, 11);
							asientos[i].taken = true;
							success = true;
							break;
						}
						else if (i == AMOUNT / 2 - 1) {
							cout << "El asiento " << chosenSeat << " o es una opcion valida.\n\n";
						}
					}
				} while (!success);
			}
			else {
				char input;
				cout << "No hay asientos disponibles en la seccion de fumadores.";
				if (!skip) {
					cout << "Desea comprar un pasaje de la seccion de no fumadores ? (s/n)\n >>> ";
					cin >> input;
					if (input == 's' || input == 'S') {
						choice = 2;
						skip = true;
					}
					else {
						cout << "El proximo vuelo es en 3 horas.\n";
						break;
					}
				}
			}
			break;
		case 2:
			for (int i = AMOUNT / 2; i < AMOUNT; i++) {
				if (!asientos[i].taken) {
					hayAsientoDisp = true;
					break;
				}
			}
			if (hayAsientoDisp) {
				bool success = false;
				do
				{
					cout << "Los asientos disponibles son:\n";
					for (int i = AMOUNT / 2; i < AMOUNT; i++)
						if (!asientos[i].taken)
							cout << asientos[i].number << endl;
					cout << "Elija su asiento:\n";
					cin >> chosenSeat;
					cin.getline(trash, 1);
					for (int i = AMOUNT / 2; i < AMOUNT;i++) {
						if (asientos[i].number == chosenSeat && !asientos[i].taken) {
							cout << "Confirmado el asiento " << chosenSeat << ". Ingrese su nombre:\n>>> ";
							cin.getline(asientos[i].passenger, 40);
							cout << "Ingrese su DNI:\n>>> ";
							cin.getline(asientos[i].DNI, 11);
							asientos[i].taken = true;
							success = true;
							break;
						}
						else if (i == AMOUNT - 1) {
							cout << "El asiento " << chosenSeat << " no es una opcion valida.\n\n";
						}
					}
				} while (!success);
			}
			else {
				cout << "No hay asientos disponibles en la seccion de no fumadores.";
				if (!skip) {
					cout << " Desea comprar un pasaje de la seccion de fumadores ? (s / n)\n >>> ";
					char input;
					cin >> input;
					if (input == 's' || input == 'S') {
						choice = 1;
						skip = true;
					}
					else {
						cout << "El proximo vuelo es en tres horas.";
						break;
					}
				}
			}
			break;
		case 3:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opcion no valida\n\n";
		}
	} while (choice != 3);
	return 0;
}