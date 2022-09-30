#include <iostream>
#include "Math.h"
using namespace std;

int main(){
	int repeat = 1, opc = NULL, opc2 = NULL;
	double a, calculo;
	cout << "----------Libreria matematica----------" << endl;
	cout << "Jesus Alejandro Lopez Rosales-22110104-2|O\n\n" << endl;
	system("pause");
	system("cls");

	while (repeat == 1){
		system("cls");
		cout << "-----MENU-----" << endl;
		cout << "Que desea calcular?" << endl;
		cout << "1.- Suma o Producto de matrices" << endl;
		cout << "2.- Seno, Coseno o Tangente de un angulo" << endl;
		cout << "Elije una opcion: ";
		cin >> opc;
		Math* m = new Math();

		switch (opc){

		case 1:
			system("cls");
			cout << "-----MENU-----" << endl;
			cout << "Que desea calcular?" << endl;
			cout << "1.- Suma matrices" << endl;
			cout << "2.- Producto de matrices" << endl;
			cout << "Elije una opcion: ";
			cin >> opc2;
			if (opc2 == 1) {
				m->sumarMatrix();
				system("pause");
			}
			else if (opc2 == 2) {
				m->productoMatrix();
				system("pause");
			}
			else {
				system("cls");
				cout << "OPCION INVALIDA" << endl;
				system("pause");
			}
			break;	

		case 2:
			system("cls");
			cout << "-----MENU-----" << endl;
			cout << "Que desea calcular?" << endl;
			cout << "1.- Seno de un angulo" << endl;
			cout << "2.- Coseno de un angulo" << endl;
			cout << "3.- Tangente de un angulo" << endl;
			cout << "Elije una opcion: ";
			cin >> opc2;
			if (opc2 == 1) {
				system("cls");
				cout << "-----Seno-----" << endl;
				cout << "Digite el angulo: ";
				cin >> a;
				calculo = m->angulos_a_radianes(a);
				calculo = m->seno(calculo);
				system("cls");
				cout << "Resultado: " << calculo << endl;
				system("pause");
			}
			else if (opc2 == 2) {
				cout << "-----Coseno-----" << endl;
				cout << "Digite el angulo: ";
				cin >> a;
				calculo = m->angulos_a_radianes(a);
				calculo = m->coseno(calculo);
				system("cls");
				cout << "Resultado: " << calculo << endl;
				system("pause");
			}
			else if (opc2 == 3) {
				cout << "-----Tangente-----" << endl;
				cout << "Digite el angulo: ";
				cin >> a;
				calculo = m->angulos_a_radianes(a);
				calculo = m->tangente(calculo);
				system("cls");
				cout << "Resultado: " << calculo << endl;
				system("pause");
			}
			else {
				cout << "OPCION INVALIDA" << endl;
			}
			break;

		default:
			cout << "OPCION INVALIDA" << endl;
			break;

		}
		
		system("cls");
		cout << "Desea hacer calcular otra cosa? " << endl;
		cout << "0.-No" << endl;
		cout << "1.-Si" << endl;
		cout << "Elija una opcion: ";
		cin >> repeat;
		system("cls");
	}
	cout << "-----------------\nFin del programa.\nGRACIAS\n-----------------\n\n" << endl;
}
