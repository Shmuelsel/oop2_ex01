#pragma once
#include "MatrixFunction.h"

class ScalarFunction : public MatrixFunction {
private:
	int scalar;

public:
	ScalarFunction(int scalar);
	SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
	std::string getDescription() const override;
	int requiredMatrix() const override;
};