#include "ScalarFunction.h"

ScalarFunction::ScalarFunction(int scalar) : scalar(scalar) {}

SquareMatrix ScalarFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0] * scalar;
}

//===============================================
std::string ScalarFunction::getDescription() const {
	return "Scal " + std::to_string(scalar);
}

//===============================================
int ScalarFunction::requiredMatrix() const {
	return 1;
}