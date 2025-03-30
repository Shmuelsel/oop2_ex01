#include "ScalarFunction.h"

ScalarFunction::ScalarFunction(int scalar) : scalar(scalar) {}

SquareMatrix ScalarFunction::apply(const SquareMatrix& m) const {
	return m * 2;
}

//===============================================
std::string ScalarFunction::getDescription() const {
	return "Scal " + std::to_string(scalar);
}