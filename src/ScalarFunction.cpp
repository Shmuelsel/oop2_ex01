#include "ScalarFunction.h"

ScalarFunction::ScalarFunction(int scalar) : m_scalar(scalar) {
	m_description = "scal " + std::to_string(m_scalar);
}

SquareMatrix ScalarFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0] * m_scalar;
}

//===============================================
std::string ScalarFunction::getDescription() const {
	return m_description;
}

//===============================================
int ScalarFunction::requiredMatrix() const {
	return 1;
}