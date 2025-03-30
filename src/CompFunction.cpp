#include "CompFunction.h"

CompFunction::CompFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2) : func1(func1), func2(func2) {
	description = func1->getDescription() + " -> " + func2->getDescription();
}

//===============================================
SquareMatrix CompFunction::apply(const SquareMatrix& m) const {
	return func2->apply(func1->apply(m));
}

//===============================================
std::string CompFunction::getDescription() const {
	return description;
}