#pragma once
#include "SquareMatrix.h"
#include <string>

class MatrixFunction {
public:
	virtual ~MatrixFunction() = default;
	virtual SquareMatrix apply(const SquareMatrix& m) const = 0;
	virtual std::string getDescription() const = 0;
};