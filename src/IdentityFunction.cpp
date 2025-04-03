#include "IdentityFunction.h"

IdentityFunction::IdentityFunction() {
	m_description = "id";
}

//===============================================
SquareMatrix IdentityFunction::apply(const std::vector<SquareMatrix>& matrices) const {
	return matrices[0];
}

//===============================================
std::string IdentityFunction::getDescription() const {
	return m_description;
}

//===============================================
int IdentityFunction::requiredMatrix() const {
	return 1;
}
