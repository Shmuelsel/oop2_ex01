#pragma once
#include "MatrixFunction.h"

class SubFunction : public MatrixFunction {
private:
	std::shared_ptr<MatrixFunction> func1;
	std::shared_ptr<MatrixFunction> func2;
	std::string description;

public:
	SubFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2);
	SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
	std::string getDescription() const override;
	int requiredMatrix() const override;
};