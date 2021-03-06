/**
 * Justin Galloway
 * Personal Project
 * - Matrices - Matrix 1 -
 */

#include "pch.h"
#include <iostream>

using namespace std;

// Initialize matrix size.
const int SIZE = 5;

// Prints the Matrix.
void printMatrices(double m1[SIZE][SIZE], double m2[SIZE][SIZE]);
// Prints the sum of the matrices.
void add(double m1[SIZE][SIZE], double m2[SIZE][SIZE]);
// Prints the difference of the matrices.
void subtract(double m1[SIZE][SIZE], double m2[SIZE][SIZE]);
// Prints the product of the matrices.
void multiply(double m1[SIZE][SIZE], double m2[SIZE][SIZE]);

int main() {
	double matrix1[SIZE][SIZE] =
	{
			{1.0, 2.0, 3.0, 4.0, 5.0},
			{2.0, 3.0, 4.0, 5.0, 6.0},
			{3.0, 4.0, 5.0, 6.0, 7.0},
			{4.0, 5.0, 6.0, 7.0, 8.0},
			{5.0, 6.0, 7.0, 8.0, 9.0}
	};
	double matrix2[SIZE][SIZE] =
	{
			{1.0, 3.0, 5.0,  7.0, 9.0},
			{3.0, 2.0, 1.0,  2.0, 1.0},
			{5.0, 0.0, 1.0,  0.0, 0.0},
			{7.0, 1.0, 1.0,  2.0, 1.0},
			{9.0, 2.0, -2.0, 2.0, 1.0}
	};

	bool exit = false;
	while (!exit) {
		cout << "\n1: Print out the matrices.\n";
		cout << "2: View the sum.\n";
		cout << "3: View the difference.\n";
		cout << "4: View the product.\n";
		cout << "5: Exit program.\n";

		int input;
		cin >> input;
		cout << endl;

		switch (input) {
		case 1:
			printMatrices(matrix1, matrix2);
			break;
		case 2:
			add(matrix1, matrix2);
			break;
		case 3:
			subtract(matrix1, matrix2);
			break;
		case 4:
			multiply(matrix1, matrix2);
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

void printMatrices(double matrix1[SIZE][SIZE], double matrix2[SIZE][SIZE]) {
	cout << "\nMatrix 1:\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << matrix1[i][j] << " ";
		cout << "\n";
	}
	cout << "\nMatrix 2:\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << matrix2[i][j] << " ";
		cout << "\n";
	}
}

void add(double matrix1[SIZE][SIZE], double matrix2[SIZE][SIZE]) {
	cout << "\nMatrix 1 + Matrix 2 =\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << matrix1[i][j] + matrix2[i][j] << " ";
		cout << "\n";
	}
}

void subtract(double matrix1[SIZE][SIZE], double matrix2[SIZE][SIZE]) {
	cout << "\nMatrix 1 - Matrix 2 =\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << matrix1[i][j] - matrix2[i][j] << " ";
		cout << "\n";
	}
}

void multiply(double matrix1[SIZE][SIZE], double matrix2[SIZE][SIZE]) {
	int product = 0;
	cout << "\nMatrix 1 * Matrix 2 =\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++)
				product = product + matrix1[i][k] * matrix2[k][j];
			cout << product << " ";
			product = 0;
		}
		cout << endl;
	}
}