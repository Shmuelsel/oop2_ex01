#include "SquareMatrix.h"
#include <sstream>

SquareMatrix::SquareMatrix(int size) : size(size) {
	data.resize(size);
	for (int i = 0; i < size; i++) {
		data[i].resize(size);
	}
}
//===============================================
SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) {
	SquareMatrix result(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return result;
}
//===============================================
SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) {
	SquareMatrix result(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return result;
}
//===============================================
SquareMatrix SquareMatrix::operator*(const int scalar) const{
	SquareMatrix result(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result.data[i][j] = data[i][j] * scalar;
		}
	}
	return result;
}
//===============================================
std::ostream& operator<<(std::ostream& os, const SquareMatrix& m) {
	for (int i = 0; i < m.size; i++) {
		for (int j = 0; j < m.size; j++) {
			os << m.data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

//===============================================
SquareMatrix SquareMatrix::transpose() const {
	SquareMatrix result(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result.data[i][j] = data[j][i];
		}
	}
	return result;
}

//===============================================
int SquareMatrix::getData(int i, int j) const {
	return data[i][j];
}

//===============================================
void SquareMatrix::inputValues() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> data[i][j];
		}
	}
}
