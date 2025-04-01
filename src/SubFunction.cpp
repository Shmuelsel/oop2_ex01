#include "SubFunction.h"

SubFunction::SubFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2) : m_func1(func1), m_func2(func2) {
	m_description = "(" + func1->getDescription() + " - " + func2->getDescription() + ")";
}

//===============================================
SquareMatrix SubFunction::apply(const std::vector<SquareMatrix>& matrices) const {

	std::vector<SquareMatrix> temp1;
	std::vector<SquareMatrix> temp2;

	for (int i = 0; i < m_func1->requiredMatrix(); i++) {
		temp1.push_back(matrices[i]);
	}

	for (int i = m_func1->requiredMatrix(); i < matrices.size(); i++) {
		temp2.push_back(matrices[i]);
	}

	return m_func1->apply(temp1) - m_func2->apply(temp2);
}

//===============================================
std::string SubFunction::getDescription() const {
	return m_description;
}

//===============================================
int SubFunction::requiredMatrix() const {
	return m_func1->requiredMatrix() + m_func2->requiredMatrix();
}
