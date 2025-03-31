#include "SubFunction.h"

SubFunction::SubFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2) : func1(func1), func2(func2) {
	description = "(" + func1->getDescription() + " - " + func2->getDescription() + ")";
}

//===============================================
SquareMatrix SubFunction::apply(const std::vector<SquareMatrix>& matrices) const {

	std::vector<SquareMatrix> temp1;
	std::vector<SquareMatrix> temp2;

	for (int i = 0; i < func1->requiredMatrix(); i++) {
		temp1.push_back(matrices[i]);
	}

	for (int i = func1->requiredMatrix(); i < matrices.size(); i++) {
		temp2.push_back(matrices[i]);
	}

	return func1->apply(temp1) - func2->apply(temp2);
}

//===============================================
std::string SubFunction::getDescription() const {
	return description;
}

//===============================================
int SubFunction::requiredMatrix() const {
	return func1->requiredMatrix() + func2->requiredMatrix();
}
