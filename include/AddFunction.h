#pragma once
#include "MatrixFunction.h"

class AddFunction : public MatrixFunction {
private:
	std::shared_ptr<MatrixFunction> func1;
	std::shared_ptr<MatrixFunction> func2;
	std::string description;

public:
	AddFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2);
	SquareMatrix apply(const SquareMatrix& m) const override;
	std::string getDescription() const override;
};