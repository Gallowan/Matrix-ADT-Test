/**
 * Justin Galloway
 * Personal Project
 * - Matrices - Matrix 3 -
 *
 * Utilizes Abstract Data Types and operatior overrides.
 */

#include "pch.h"
#include <iostream>

using namespace std;

class Matrix {
private:
    int size;
    // Pointer to matrix values.
    double **matrix;
public:
    Matrix();

	// Prints the Matrix.
	void printMatrix();
    // Addition override.
    Matrix operator+(Matrix &m);
    // Subtraction override.
    Matrix operator-(Matrix &m);
    // Multiplication override.
    Matrix operator*(Matrix &m);

    // Sets matrix dimensions.
    void setSize(int);
    int getSize();
    void setMatrix(int);

    // Set matrix to 0 values
    void setBlankMatrix(int);
};

Matrix::Matrix() {}

void Matrix::setSize(int size) {
	this->size = size;
}
int Matrix::getSize() {
	return size;
}

void Matrix::printMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << *(*(matrix + i) + j) << " ";
        cout << "\n";
    }
}

// Addition function override.
Matrix Matrix::operator+(Matrix &m) {
    Matrix mSum;
    mSum.setSize(m.getSize());
    mSum.setBlankMatrix(mSum.getSize());

    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            double sumValue = *(*(matrix + i) + j) + *(*(m.matrix + i) + j);
            *(*(mSum.matrix + i) + j) = sumValue;
        }
    }
    return mSum;
}

// Subtraction function override.
Matrix Matrix::operator-(Matrix &m) {
    Matrix difference;
    difference.setSize(m.getSize());
    difference.setBlankMatrix(difference.getSize());

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double differenceValue = *(*(matrix + i) + j) - *(*(m.matrix + i) + j);
            *(*(difference.matrix + i) + j) = differenceValue;
        }
    }

    return difference;
}

// Multiplication function override.
Matrix Matrix::operator*(Matrix &m) {
    Matrix product;
    product.setSize(m.getSize());
    product.setBlankMatrix(product.getSize());

    int productValue = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++)
                productValue += *(*(matrix + i) + k) * *(*(m.matrix + k) + j);
            *(*(product.matrix + i) + j) = productValue;
            productValue = 0;
        }
    }

    return product;
}

void Matrix::setMatrix(int size) {
    this->size = size;
    matrix = new double *[size];
    for (int i = 0; i < size; i++)
        *(matrix + i) = new double[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "m[" << i << "][" << j << "] = ";
            cin >> *(*(matrix + i) + j);
        }
    }
}

void Matrix::setBlankMatrix(int size) {
    this->size = size;
    matrix = new double *[size];
    for (int i = 0; i < size; i++)
        *(matrix + i) = new double[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(matrix + i) + j) = 0;
        }
    }
}

int main() {
    int size;
	bool exit = false;
    Matrix matrix1;
    Matrix matrix2;

	cout << "Enter the square matrix size for both matrices: ";
	cin >> size;

	cout << "Enter the data for matrix 1.\n" << endl;
	matrix1.setMatrix(size);

	cout << "Enter the data for matrix 2.\n" << endl;
	matrix2.setMatrix(size);

    while (!exit) {
		cout << "\n\n1: Print out the matrices.\n";
		cout << "2: View the sum.\n";
		cout << "3: View the difference.\n";
		cout << "4: View the product.\n";
		cout << "5: Exit program.\n";

        int input;
        cin >> input;
        cout << endl;

        Matrix temp;
        switch (input) {
            case 1:
				cout << "\nMatrix 1:\n" << endl;
				matrix1.printMatrix();
				cout << "\nMatrix 2:\n" << endl;
				matrix2.printMatrix();
                break;
            case 2:
                temp = matrix1 + matrix2;
				cout << "\nMatrix 1 + Matrix 2 =\n" << endl;
				temp.printMatrix();
                temp.~Matrix();
                break;
            case 3:
                temp = matrix1 - matrix2;
				cout << "\nMatrix 1 - Matrix 2 =\n" << endl;
				temp.printMatrix();
                temp.~Matrix();
                break;
            case 4:
                temp = matrix1 * matrix2;
				cout << "\nMatrix 1 * Matrix 2 =\n" << endl;
				temp.printMatrix();
                temp.~Matrix();
                break;
            case 5:
                exit = true;
				// Empty the trash!
                matrix1.~Matrix();
                matrix2.~Matrix();
                break;
            default:
				cout << "Invalid input. Please input a proper choice.\n";
				break;
        }
    }

    return 0;
}