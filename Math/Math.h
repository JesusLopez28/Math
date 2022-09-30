#pragma once
#include <iostream>
using namespace std;

class Math{
private:
	short int** matrix1;
	short int** matrix2;
	short int** matrix3;
	short int filas, columnas;
	double angle;
	const double PI = 3.14159;
	const double EPSILON = 0.00001;

public:
	void sumarMatrix();
	void productoMatrix();
	double angulos_a_radianes(double angulo);
	double potencia(double base, int exp);
	long int factorial(int factor);
	double positivo(double numero);
	double seno(double x);
	double coseno(double x);
	double tangente(double x);
};

void Math::sumarMatrix() {
	int i, j;
	system("cls");
	cout << "Digite el numero de filas: ";
	cin >> filas;
	cout << "Digite el numero de columnas: ";
	cin >> columnas;
	system("cls");
	matrix1 = new short int* [filas];
	for (i = 0; i < filas; i++) {
		matrix1[i] = new short int[columnas];
	}
	cout << "Digite los elementos de la primera matriz:" << endl;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			cout << "Digite el valor [" << i << "][" << j << "]:";
			cin >> *(*(matrix1 + i) + j);
		}

	}
	system("cls");
	matrix2 = new short int* [filas];
	for (i = 0; i < filas; i++) {
		matrix2[i] = new short int[columnas];
	}
	cout << "Digite los elementos de la segunda matriz:" << endl;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			cout << "Digite el valor [" << i << "][" << j << "]:";
			cin >> *(*(matrix2 + i) + j);
		}

	}
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			*(*(matrix1 + i) + j) += *(*(matrix2 + i) + j);
		}
	}
	system("cls");
	cout << "La suma de las matrices es:" << endl;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			cout << *(*(matrix1 + i) + j) << " ";
		}
		cout << endl;
	}

 
 	for (i = 0; i < filas; i++) {
		delete[] matrix2[i];
	}delete[]matrix2;

	for (i = 0; i < filas; i++) {
		delete[] matrix1[i];
	}delete[]matrix1;
}

void Math::productoMatrix() {
	int i, j, k;
	short int filas_a, filas_b, columnas_a, columnas_b;
	system("cls");
	cout << "Digite el numero de filas de la matriz A: ";
	cin >> filas_a;
	cout << "Digite el numero de columnas de la matriz A: ";
	cin >> columnas_a;
	system("cls");
	cout << "Digite el numero de filas de la matriz B: ";
	cin >> filas_b;
	cout << "Digite el numero de columnas de la matriz B: ";
	cin >> columnas_b;
	system("cls");

	if (columnas_a == filas_b) {
		matrix1 = new short int* [filas_a];
		for (i = 0; i < filas_a; i++) {
			matrix1[i] = new short int[columnas_a];
		}
		cout << "Digite los elementos de la matriz A:" << endl;
		for (i = 0; i < filas_a; i++) {
			for (j = 0; j < columnas_a; j++) {
				cout << "Digite el valor [" << i << "][" << j << "]:";
				cin >> *(*(matrix1 + i) + j);
			}

		}
		system("cls");
		matrix2 = new short int* [filas_b];
		for (i = 0; i < filas_b; i++) {
			matrix2[i] = new short int[columnas_b];
		}
		cout << "Digite los elementos de la matriz B:" << endl;
		for (i = 0; i < filas_b; i++) {
			for (j = 0; j < columnas_b; j++) {
				cout << "Digite el valor [" << i << "][" << j << "]:";
				cin >> *(*(matrix2 + i) + j);
			}

		}


		matrix3 = new short int* [filas_a];
		for (i = 0; i < filas_a; i++) {
			matrix3[i] = new short int[columnas_b];
		}
		for (i = 0; i < filas_a; i++) {
			for (j = 0; j < columnas_b; j++) {
				*(*(matrix3 + i) + j) = 0;
				for (k = 0; k < columnas_a; k++) {
					*(*(matrix3 + i) + j) += ( (*(*(matrix1 + i) + k)) * (*(*(matrix2 + k) + j)));
				}
			}
		}
		system("cls");
		cout << "El producto de las matrices es:" << endl;
		for (i = 0; i < filas_a; i++) {
			for (j = 0; j < columnas_b; j++) {
				cout << *(*(matrix3 + i) + j) << " ";
			}
			cout << endl;
		}
	}
	else cout << "No se puede hacer la operacion" << endl;

	for (i = 0; i < filas_b; i++) {
		delete[] matrix2[i];
	}delete[]matrix2;

	for (i = 0; i < filas_a; i++) {
		delete[] matrix1[i];
	}delete[]matrix1;

	for (i = 0; i < filas_a; i++) {
		delete[] matrix3[i];
	}delete[]matrix3;
}

double Math::angulos_a_radianes(double angulo) {
	return (angulo * PI) / 180;
}

double Math::potencia(double base, int exp) {
	if (exp == 0 || base == 1) { return 1; }
	if (base == -1) { return 1 - (exp % 2) * 2; }
	double resultado = base;
	while (exp-- > 1) {
		resultado *= base;
	}
	return resultado;
}

long int Math::factorial(int factor) {
	if (factor == 0) return 1;
	long int resultado = 1;
	do {
		resultado *= factor;
	} while (factor-- > 1);
	return resultado;
}

double Math::positivo(double numero) {
	if (numero < 0) return -1 * numero;
	return numero;
}

double Math::seno(double x) {
	double resultado = 0;
	double resultado_anterior = 0;
	int sumador = 0; 
	do {
		resultado_anterior = resultado;
		resultado += potencia(-1, sumador) * potencia(x, 2 * sumador + 1) / factorial(2 * sumador + 1);
		sumador++;

	} while (positivo(resultado - resultado_anterior) >= EPSILON);

	return resultado;
}

double Math::coseno(double x) {
	double resultado = 0;
	double resultado_anterior = 0;
	int sumador = 0;
	do {
		resultado_anterior = resultado;
		resultado += potencia(-1, sumador) * potencia(x, 2 * sumador) / factorial(2 * sumador);
		sumador++;

	} while (positivo(resultado - resultado_anterior) >= EPSILON);

	return resultado;
}

double Math::tangente(double x) {

	if (x / (PI / 2) == (int)(x / (PI / 2))) {
		cout << "Error: el angulo no debe ser multiplo de 90" << endl;
		return 0;
	}
	return seno(x) / coseno(x);
}