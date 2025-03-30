#pragma once
#include "MatrixFunction.h"

class CompFunction : public MatrixFunction {
private:
	std::shared_ptr<MatrixFunction> func1;
	std::shared_ptr<MatrixFunction> func2;
	std::string description;

public:	
	CompFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2);
	SquareMatrix apply(const SquareMatrix& m) const override;
	std::string getDescription() const override;
};