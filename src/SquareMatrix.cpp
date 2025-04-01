#include "SquareMatrix.h"
#include <sstream>

SquareMatrix::SquareMatrix(int size) : m_size(size) {
	m_data.resize(size);
	for (int i = 0; i < size; i++) {
		m_data[i].resize(size);
	}
}
//===============================================
SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) {
	SquareMatrix result(m_size);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
		}
	}
	return result;
}
//===============================================
SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) {
	SquareMatrix result(m_size);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			result.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
		}
	}
	return result;
}
//===============================================
SquareMatrix SquareMatrix::operator*(const int scalar) const{
	SquareMatrix result(m_size);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			result.m_data[i][j] = m_data[i][j] * scalar;
		}
	}
	return result;
}
//===============================================
std::ostream& operator<<(std::ostream& os, const SquareMatrix& m) {
	for (int i = 0; i < m.m_size; i++) {
		for (int j = 0; j < m.m_size; j++) {
			os << m.m_data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

//===============================================
SquareMatrix SquareMatrix::transpose() const {
	SquareMatrix result(m_size);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			result.m_data[i][j] = m_data[j][i];
		}
	}
	return result;
}

//===============================================
int SquareMatrix::getData(int i, int j) const {
	return m_data[i][j];
}

//===============================================
void SquareMatrix::inputValues() {
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			std::cin >> m_data[i][j];
		}
	}
}
