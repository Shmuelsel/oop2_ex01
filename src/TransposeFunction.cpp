#include "TransposeFunction.h"

TransposeFunction::TransposeFunction() {
	m_description = "tran";
}

//===============================================
SquareMatrix TransposeFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0].transpose();
}

//===============================================
std::string TransposeFunction::getDescription() const {
	return m_description;
}

//===============================================
int TransposeFunction::requiredMatrix() const {
	return 1;
}