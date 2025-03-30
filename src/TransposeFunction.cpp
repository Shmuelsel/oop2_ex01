#include "TransposeFunction.h"

SquareMatrix TransposeFunction::apply(const SquareMatrix& m) const {
	return m.transpose();
}

//===============================================
std::string TransposeFunction::getDescription() const {
	return "Tran";
}