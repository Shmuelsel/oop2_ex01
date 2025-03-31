#include "TransposeFunction.h"

SquareMatrix TransposeFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0].transpose();
}

//===============================================
std::string TransposeFunction::getDescription() const {
	return "Tran";
}

//===============================================
int TransposeFunction::requiredMatrix() const {
	return 1;
}