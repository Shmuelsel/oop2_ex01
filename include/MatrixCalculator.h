#pragma once
#include "MatrixFunction.h"
#include "SquareMatrix.h"
#include <memory>
#include <string>
#include <vector>

class MatrixCalculator {
private:
	enum class Command {
		EVAL,
		ADD,
		SUB,
		COMP,
		SCAL,
		DEL,
		HELP,
		EXIT
	};

	std::vector<std::shared_ptr<MatrixFunction>> functions;

	void printHelp() const;
	void printFunctions() const;
	Command parseCommand(const std::string& command) const;

	void handleEval(std::istream& is);
	void handleAdd(std::istream& is);
	void handleSub(std::istream& is);
	void handleComp(std::istream& is);
	void handleScal(std::istream& is);
	void handleDel(std::istream& is);

public:
	MatrixCalculator();
	void run();
};
