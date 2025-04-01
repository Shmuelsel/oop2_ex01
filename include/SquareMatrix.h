#pragma once
#include <iostream>
#include <vector>

class SquareMatrix {
private:
	std::vector<std::vector<int>> m_data;
	int m_size;

public:
	SquareMatrix(int size);
	SquareMatrix transpose() const;
	SquareMatrix operator+(const SquareMatrix& other);
	SquareMatrix operator-(const SquareMatrix& other);
	SquareMatrix operator*(const int scalar)const;
	int getData(int i, int j) const;
	void inputValues();

	friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& m);
};