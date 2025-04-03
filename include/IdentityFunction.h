#pragma once
#include "MatrixFunction.h"

class IdentityFunction : public MatrixFunction {
public:
	IdentityFunction();
	SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
	std::string getDescription() const override;
	int requiredMatrix() const override;
};