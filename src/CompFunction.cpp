#include "CompFunction.h"

CompFunction::CompFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2) : func1(func1), func2(func2) {
	description = "(" + func1->getDescription() + " -> " + func2->getDescription() + ")";
}

//===============================================
SquareMatrix CompFunction::apply(const std::vector<SquareMatrix>& matrices) const {

	std::vector<SquareMatrix> temp1;
	std::vector<SquareMatrix> temp2;

	temp1.push_back(matrices[0]);

	//i starts from 1 
	for (int i = 1; i < matrices.size(); i++) {
		temp2.push_back(matrices[i]);
	}
	
	temp2.push_back(func1->apply(temp1));
	return func2->apply(temp2);
}

//===============================================
std::string CompFunction::getDescription() const {
	return description;
}

//===============================================
int CompFunction::requiredMatrix() const {
	return func2->requiredMatrix();
}

