/**
 * Justin Galloway
 * Personal Project
 * - Matrices - Matrix 2 -
 *
 * Initializes the matrices using user input.
 */

#include "pch.h"
#include <iostream>

using namespace std;

// Prints the Matrix.
void printMatrices(int size, double **matrix1, double **matrix2);
// Prints the sum of the matrices.
void add(int size, double **matrix1, double **matrix2);
// Prints the difference of the matrices.
void subtract(int size, double **matrix1, double **matrix2);
// Prints the product of the matrices.
void multiply(int size, double **matrix1, double **matrix2);

int main() {
	// matrix is mxm so only need one dimensions parameter
	int size;
	double **matrix1;
	double **matrix2;

	cout << "Enter the square matrix size for both matrices: ";
	cin >> size;

	matrix1 = new double *[size];
	for (int i = 0; i < size; i++)
		*(matrix1 + i) = new double[size];
	matrix2 = new double *[size];
	for (int i = 0; i < size; i++)
		*(matrix2 + i) = new double[size];

	cout << "Enter the data for matrix 1.\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "m1[" << i << "][" << j << "] = ";
			cin >> *(*(matrix1 + i) + j);
		}
	}
	cout << "Enter the data for matrix 2.\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "m2[" << i << "][" << j << "] = ";
			cin >> *(*(matrix2 + i) + j);
		}
	}

	bool exit = false;
	while (!exit) {
		cout << "\n\n1: Print out the matrices.\n";
		cout << "2: View the sum.\n";
		cout << "3: View the difference.\n";
		cout << "4: View the product.\n";
		cout << "5: Exit program.\n";

		int input;
		cin >> input;
		cout << endl;

		switch (input) {
		case 1:
			printMatrices(size, matrix1, matrix2);
			break;
		case 2:
			add(size, matrix1, matrix2);
			break;
		case 3:
			subtract(size, matrix1, matrix2);
			break;
		case 4:
			multiply(size, matrix1, matrix2);
			break;
		case 5:
			exit = true;
			break;
		default:
			cout << "Invalid input. Please input a proper choice.\n";
			break;
		}
	}

	return 0;
}

void printMatrices(int size, double **matrix1, double **matrix2) {
	cout << "\nMatrix 1:\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << *(*(matrix1 + i) + j) << " ";
		cout << "\n";
	}
	cout << "\nMatrix 2:\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << *(*(matrix2 + i) + j) << " ";
		cout << "\n";
	}
}

void add(int size, double **matrix1, double **matrix2) {
	cout << "\nMatrix 1 + Matrix 2 =\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j) << " ";
		cout << "\n";
	}
}

void subtract(int size, double **matrix1, double **matrix2) {
	cout << "\nMatrix 1 - Matrix 2 =\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << *(*(matrix1 + i) + j) - *(*(matrix2 + i) + j) << " ";
		cout << "\n";
	}
}

void multiply(int size, double **matrix1, double **matrix2) {
	int product = 0;
	cout << "\nMatrix 1 * Matrix 2 =\n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++)
				product = product + *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
			cout << product << " ";
			product = 0;
		}
		cout << endl;
	}
}