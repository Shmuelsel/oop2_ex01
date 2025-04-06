#pragma once
#include "MatrixFunction.h"

class TransposeFunction : public MatrixFunction {
public:
	TransposeFunction();
	SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
	std::string getDescription() const override;
	int requiredMatrix() const override;
};