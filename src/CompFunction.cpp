#include "CompFunction.h"

CompFunction::CompFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2)
	: m_func1(func1), m_func2(func2) {
	m_description = "(" + func1->getDescription() + " -> " + func2->getDescription() + ")";
}

//===============================================
SquareMatrix CompFunction::apply(const std::vector<SquareMatrix>& matrices) const {

	std::vector<SquareMatrix> temp1;
	std::vector<SquareMatrix> temp2;

	temp1.push_back(matrices[0]);

	//start from 1 because the first matrix is always go to the comp function
	for (int i = 1; i < matrices.size(); i++) {
		temp2.push_back(matrices[i]);
	}
	
	//put the result of the first function to the front of the vector
	temp2.insert(temp2.begin(), m_func1->apply(temp1));
	return m_func2->apply(temp2);
}

//===============================================
std::string CompFunction::getDescription() const {
	return m_description;
}

//===============================================
int CompFunction::requiredMatrix() const {
	return m_func2->requiredMatrix();
}

