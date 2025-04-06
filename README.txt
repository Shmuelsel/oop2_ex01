##OOP2 Exercise 01

##Students Details:
1.
Name: Shmuel Selzer
ID: 207861535
2.
Name: Zeev Morgenstern
ID: 322986472

##General Explanation of the Exercise:
This exercise is part of the Object-Oriented Programming 2 (OOP2) course. The goal is to implement a Matrix Calculator that can perform various matrix operations such as addition, subtraction, scalar multiplication, and composition of operations.

##List of Created Files:
1. "MatrixCalculator.cpp" - Implementation of the MatrixCalculator class. It defines the methods for handling matrix operations and executing commands.
2. "IdentityFunction.cpp" - Implementation of the `IdentityFunction` class, which represents an identity matrix operation.
3. "TransposeFunction.cpp" - Implementation of the `TransposeFunction` class, which represents a transpose matrix operation.
4. "ScalarFunction.cpp" - Implementation of the `ScalarFunction` class, which represents a scalar multiplication matrix operation.
5. "AddFunction.cpp" - Implementation of the `AddFunction` class, which represents an addition matrix operation.
6. "SubFunction.cpp" - Implementation of the `SubFunction` class, which represents a subtraction matrix operation.
7. "CompFunction.cpp" - 
8. "SquareMatrix.ccp" - Implementation of the `SquareMatrix` class, defining methods for matrix operations and input/output.
9. "MatrixFunction.h" - Header file declaring the `MatrixFunction` class, which is an abstract base class for different matrix operations.
10. "main.cpp" - The main entry point of the application. It initializes the program and handles user input.

##Main Data Structures and Their Roles
1. ""MatrixCalculator"": Manages matrix operations, parses commands, and handles user interactions.
2. ""SquareMatrix"": Represents a square matrix and provides methods for input, output, and matrix operations like addition, subtraction, and scalar multiplication.
3. ""MatrixFunction"": Abstract base class for different matrix operations. Derived classes implement specific matrix operations.

## Notable Algorithms
1. ""handleEval"": Evaluates a chosen matrix operation on input matrices.
2. ""handleAdd"": Creates an operation that sums two existing operations.
3. ""handleSub"": Creates an operation that subtracts one operation from another.
4. ""handleComp"": Creates an operation that composes two existing operations.

## Design
### Objects and Their Responsibilities
- ""MatrixCalculator"" Handles all matrix operations and user interactions. Contains a list of different matrix functions and handles all commands.
- ""SquareMatrix"" Manages matrix data and operations related to matrix values.
- ""MatrixFunction"" and its derived classes (`IdentityFunction`, `TransposeFunction`, `ScalarFunction`, etc.): Implement specific matrix operations.

### Interaction Between Objects
The `MatrixCalculator` object interacts with multiple `MatrixFunction` objects to perform matrix operations. `SquareMatrix` objects are used as inputs and outputs for these operations.

## Known Bugs
No known bugs