#pragma once
#include "MatrixFunction.h"

class IdentityFunction : public MatrixFunction {
public:
	SquareMatrix apply(const SquareMatrix& m) const override;
	std::string getDescription() const override;
};