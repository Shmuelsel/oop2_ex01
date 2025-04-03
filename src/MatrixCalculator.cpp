#include "MatrixCalculator.h"
#include "IdentityFunction.h"
#include "TransposeFunction.h"
#include "ScalarFunction.h"
#include "AddFunction.h"
#include "SubFunction.h"
#include "CompFunction.h"
#include <iostream>
#include <sstream>

MatrixCalculator::MatrixCalculator() {
	functions.push_back(std::make_shared<IdentityFunction>());
	functions.push_back(std::make_shared<TransposeFunction>());
}

//===============================================
void MatrixCalculator::printFunctions() const {
	std::cout << "List of available matrix operations:\n";
	for (int i = 0; i < functions.size(); i++) {
		std::cout << i << ". " << functions[i]->getDescription() << std::endl;
	}
	std::cout << std::endl;
}

//===============================================
SquareMatrix MatrixCalculator::inputMatrix(int size) const {
	SquareMatrix m(size);
	m.inputValues();
	return m;
}

//===============================================
void MatrixCalculator::printHelp() const {
    std::cout << "\nThe available commands are:\n";
    std::cout << "- eval(num)        : Compute the result of operation #num on a given nªn matrix\n";
    std::cout << "- scal(ar)(val)    : Create an operation that multiplies the matrix by scalar val\n";
    std::cout << "- add(num1)(num2)  : Create an operation that is the sum of operations #num1 and #num2\n";
    std::cout << "- sub(num1)(num2)  : Create an operation that is the difference of operations #num1 and #num2\n";
    std::cout << "- comp(osite)(num1)(num2) : Create an operation that is the composition of operations #num1 and #num2\n";
    std::cout << "- del(ete)(num)    : Delete operation #num from the list\n";
    std::cout << "- help             : Print this command list\n";
    std::cout << "- exit             : Exit the program\n\n";
}

//===============================================
MatrixCalculator::Command MatrixCalculator::parseCommand(const std::string& command) const {
	if (command == "eval") {
		return Command::EVAL;
	}
	else if (command == "scal") {
		return Command::SCAL;
	}
	else if (command == "add") {
		return Command::ADD;
	}
	else if (command == "sub") {
		return Command::SUB;
	}
	else if (command == "comp") {
		return Command::COMP;
	}
	else if (command == "del") {
		return Command::DEL;
	}
	else if (command == "help") {
		return Command::HELP;
	}
	else if (command == "exit") {
		return Command::EXIT;
	}
	else {
		return Command::HELP;
	}
}

//===============================================
void MatrixCalculator::handleEval(std::istream& is) {
	int num;
	is >> num;
	if (num < 0 || num >= functions.size()) {
		std::cout << "Invalid function number\n";
		return;
	}

	int size;
	is >> size;

	int requiredMatrix = functions[num]->requiredMatrix();
	std::vector<SquareMatrix> matrices;

	std::cout << std::endl;

	if (requiredMatrix > 1) {
		std::cout << "Please enter " << requiredMatrix << " matrix:\n\n";
		for (int i = 0; i < requiredMatrix; i++) {
			std::cout << "Enter a " << size << "x" << size << " matrix:\n";
			matrices.push_back(inputMatrix(size));
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "Enter a " << size << "x" << size << " matrix:\n";
		matrices.push_back(inputMatrix(size));
	}

	SquareMatrix result = functions[num]->apply(matrices);
	std::cout << std::endl << functions[num]->getDescription();

	for (int i = 0; i < requiredMatrix; i++) {
		std::cout << "(" << std::endl << matrices[i] << ")";
	}

	std::cout << " =\n" << result << std::endl;
}

//===============================================
void MatrixCalculator::handleScal(std::istream& is) {
	int scalar;
	is >> scalar;
	functions.push_back(std::make_shared<ScalarFunction>(scalar));
	std::cout << std::endl;
}

//===============================================
void MatrixCalculator::handleAdd(std::istream& is) {
	int num1, num2;
	is >> num1 >> num2;
	if (num1 < 0 || num1 >= functions.size() || num2 < 0 || num2 >= functions.size()) {
		std::cout << "Invalid function number\n";
		return;
	}
	functions.push_back(std::make_shared<AddFunction>(functions[num1], functions[num2]));
}

//===============================================
void MatrixCalculator::handleSub(std::istream& is) {
	int num1, num2;
	is >> num1 >> num2;
	if (num1 < 0 || num1 >= functions.size() || num2 < 0 || num2 >= functions.size()) {
		std::cout << "Invalid function number\n";
		return;
	}
	functions.push_back(std::make_shared<SubFunction>(functions[num1], functions[num2]));
}

//===============================================
void MatrixCalculator::handleComp(std::istream& is) {
	int num1, num2;
	is >> num1 >> num2;
	if (num1 < 0 || num1 >= functions.size() || num2 < 0 || num2 >= functions.size()) {
		std::cout << "Invalid function number\n";
		return;
	}
	functions.push_back(std::make_shared<CompFunction>(functions[num1], functions[num2]));
}

//===============================================
void MatrixCalculator::handleDel(std::istream& is) {
	int num;
	is >> num;
	if (num < 0 || num >= functions.size()) {
		std::cout << "Invalid function number\n";
		return;
	}
	functions.erase(functions.begin() + num);
}

//===============================================
void MatrixCalculator::run() {
	while (true) {
		printFunctions();
		std::cout << "Enter command ('help' for the list of available commands): ";

		std::string line;
		std::getline(std::cin >> std::ws, line);
		std::istringstream iss(line);
		std::string commandStr;
		iss >> commandStr;

		Command command = parseCommand(commandStr);

		switch (command) {
		case Command::HELP:
			printHelp();
			break;
		case Command::EXIT:
			std::cout << "Goodbye!\n";
			return;
		case Command::EVAL:
			handleEval(iss);
			break;
		case Command::SCAL:
			handleScal(iss);
			break;
		case Command::ADD:
			handleAdd(iss);
			break;
		case Command::SUB:
			handleSub(iss);
			break;
		case Command::COMP:
			handleComp(iss);
			break;
		case Command::DEL:
			handleDel(iss);
			break;
		}
	}
}