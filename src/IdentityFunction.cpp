#include "IdentityFunction.h"

SquareMatrix IdentityFunction::apply(const SquareMatrix& m) const {
	return m;
}

//===============================================
std::string IdentityFunction::getDescription() const {
	return "Id";
}
