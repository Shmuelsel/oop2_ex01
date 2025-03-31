#include "IdentityFunction.h"

SquareMatrix IdentityFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0];
}

//===============================================
std::string IdentityFunction::getDescription() const {
	return "Id";
}

//===============================================
int IdentityFunction::requiredMatrix() const {
	return 1;
}
