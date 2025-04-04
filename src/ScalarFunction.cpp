#include "ScalarFunction.h"

ScalarFunction::ScalarFunction(int scalar) : m_scalar(scalar) {}

SquareMatrix ScalarFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0] * m_scalar;
}

//===============================================
std::string ScalarFunction::getDescription() const {
	return "Scal " + std::to_string(m_scalar);
}

//===============================================
int ScalarFunction::requiredMatrix() const {
	return 1;
}