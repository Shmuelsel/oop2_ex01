#pragma once
#include "MatrixFunction.h"

class ScalarFunction : public MatrixFunction {
private:
	int scalar;

public:
	ScalarFunction(int scalar);
	SquareMatrix apply(const SquareMatrix& m) const override;
	std::string getDescription() const override;
};