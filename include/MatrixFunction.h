#pragma once
#include "SquareMatrix.h"
#include <string>

class MatrixFunction {
public:
	virtual ~MatrixFunction() = default;
	virtual SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const = 0;
	virtual std::string getDescription() const = 0;
	virtual int requiredMatrix() const = 0;
};