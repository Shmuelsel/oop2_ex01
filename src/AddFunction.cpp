#include "AddFunction.h"

AddFunction::AddFunction(std::shared_ptr<MatrixFunction> func1, std::shared_ptr<MatrixFunction> func2) : func1(func1), func2(func2) {
	description = func1->getDescription() + " + " + func2->getDescription();
}

//===============================================
SquareMatrix AddFunction::apply(const SquareMatrix& m) const {
	return func1->apply(m) + func2->apply(m);
}

//===============================================
std::string AddFunction::getDescription() const {
	return description;
}