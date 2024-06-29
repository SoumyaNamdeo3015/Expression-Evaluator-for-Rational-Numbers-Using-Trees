# Expression Evaluator for Rational Numbers Using Trees

## Introduction

An expression evaluator is a software component or program that interprets and computes the result of mathematical, logical, or symbolic expressions provided as input. The task in this assignment is to create an expression evaluator for programs written in the language E++, which supports integer or rational numbers and allows very large values. Part of this project includes implementing `unlimitedInt` and `unlimitedRational` classes.

## Description of E++

### Expression

Expressions in E++ are fully parenthesized, well-formed arithmetic infix expressions using the operators `+`, `-`, `*`, `/`. Operands can be numerical values or variables (e.g., `x`).

### Examples

#### Examples of Valid E++ Expressions

- `(a + b)`
- `((x * y) - z)`
- `((5 + x) / (a + b))`
- `((a + 2) * 3)`
- `(((x + y) * (a - b)) - (c / d))`
- `(((2 * a) / 3) + (b - (c - d)))`

#### Examples of Invalid E++ Expressions

- `a + b` (missing enclosing brackets)
- `(ab)` (missing operator)
- `((x + y) * (a + b) + c)` (missing operators between sub-expressions)
- `()` (empty expression)
- `&` (invalid operator)
- `(*ab)` (not an infix expression)
- `((a/))` (operator at the end)
- `((x + y)(a - b))` (missing operator between sub-expressions)
- `(a + b))` (unbalanced parentheses)

### Syntax

The syntax of E++ includes two types of statements:

- **Variable Assignment**: `v := E` where `v` is a variable and `E` is a well-formed expression.
- **Returning a Value**: `return E` where `E` is a well-formed expression.

### Rules

- **Declaration Before Use**: A variable `x` can only appear on the RHS of an expression if there exists a statement `x := E` before it.
- **Immutability**: Each variable `x` can only be assigned once. Multiple assignments like `x := E1` and `x := E2` are not allowed.

# UnlimitedInt

The `UnlimitedInt` class is a custom integer data type designed to handle integers of arbitrary size without
any limitations on their magnitude. Unlike standard integer types in programming languages, such as int or
long, which have fixed ranges, `UnlimitedInt` can represent extremely large or precise integer values. This
class is a fundamental building block for working with integers in situations where traditional integer types
fall short due to their size limitations.


## UnlimitedInt Class Description

The `UnlimitedInt` class has the following attributes and methods:

### Attributes
- **`size`**: An integer that represents the size of the `UnlimitedInt` object.
- **`capacity`**: An integer that represents the capacity of the `UnlimitedInt` object.
- **`sign`**: An integer that indicates the sign of the `UnlimitedInt` object. It is set to `1` for positive numbers and `-1` for negative numbers. For the `UnlimitedInt` representing `0`, you can set this to either `0`, `1`, or `-1`.
- **`unlimited_int`**: An integer pointer that points to an array storing the unlimited integer.

### Methods
- **`get_capacity()`**: Returns the capacity of the `UnlimitedInt` object.
- **`get_size()`**: Returns the size of the `UnlimitedInt` object.
- **`get_array()`**: Returns a pointer to the array storing the `UnlimitedInt` digits.
- **`get_sign()`**: Returns the sign of the `UnlimitedInt` object (`1` for positive, `-1` for negative).
- **`to_string()`**: Converts a `UnlimitedInt` object to its string representation. For example, `"5"` for `5` and `"-5"` for `-5`.

### Arithmetic Operations
The `UnlimitedInt` class supports the following arithmetic operations:
- **Addition**
- **Subtraction**
- **Multiplication**
- **Division**
- **Modulus**

# UnlimitedRational 

In a related context, we introduce a class named `UnlimitedRational`, which will be used for evaluating expressions in one of the subparts of the assignment. A rational number is typically represented in the form `p/q`, where `p` and `q` are integers (Z), `p` and `q` are coprime (meaning they have no common divisors other than 1), and `q ≠ 0`.

The `UnlimitedRational` class extends the concept of rational numbers by using the previously introduced `UnlimitedInt` class for its numerator and denominator. This allows you to accommodate even the most extensive calculations in scenarios where standard floating-point representations might suffer from precision loss.

## UnlimitedRational Class

The `UnlimitedRational` class extends the concept of rational numbers by using the `UnlimitedInt` class for its numerator and denominator. This allows for precise calculations even in scenarios where standard floating-point representations might suffer from precision loss. The `UnlimitedRational` class includes the following attributes and methods:

### Attributes

- `p`: A pointer to an `UnlimitedInt` object representing the numerator. 
- `q`: A pointer to an `UnlimitedInt` object representing the denominator. Note that `p` and `q` must be coprime, or the implementation will not pass tests. If `p` is 0, any non-zero value of `q` will be acceptable for the denominator.

### Methods

- `get_p()`: Returns the numerator as an `UnlimitedInt` object.
- `get_q()`: Returns the denominator as an `UnlimitedInt` object.
- `get_p_str()`: Returns the numerator as a string representation.
- `get_q_str()`: Returns the denominator as a string representation.
- `get_frac_str()`: Returns the rational number as a string in the form "p/q". If `p/q` is positive, then both "p/q" and "-p/-q" are acceptable answers. Similarly, if `p/q` is negative, the "-" sign can be either in the numerator or the denominator.
- 
### Arithmetic Operations
The `UnlimitedRational` class supports the following arithmetic operations:
- **Addition**
- **Subtraction**
- **Multiplication**
- **Division**
- **Modulus**

# Parser for E++ 

A parser converts each statement of the program into a tree structure (called a Parse Tree) which is expressive of all the components of that statement. It allows us to capture the structure of the program, as well as perform syntactic checks. 

Parse tree for the statement `x2 := (2 + (7 ∗ x0))` is given below.

In this assignment, the parse tree for a given statement will always be unique. We do this by imposing the following conditions on the parse tree:

- For a statement `v := E`, the node associated with the variable `v` will be in the left subtree of the node associated with the `:=` assignment operator, and all of the nodes in the tree of expression `E` will be in the right subtree of the node associated with the `:=` assignment operator.
- Within an expression, all of the variables and constants needed to evaluate the left operand of the expression must be in the left subtree of the operator node, and all of the variables and constants needed to evaluate the right operand of the expression must be in the right subtree of the operator node.

Hence the parse tree below for the statement `x2 := (2 + (7 ∗ x0))` would be incorrect since for the `+` operand, we require `2` to be in the left subtree of the operator node and `7` and `x0` to be in the right subtree of the operator node.

# Expression Evaluator 

Each well-formed expression evaluates to a value. Therefore, each node in the parse tree will have a value associated with it, which can be calculated explicitly by recursively evaluating the subtree rooted at that node. 

**Note:** For an assignment `v := E`, we will not check the evaluated values at the nodes corresponding to `v` and `:=`. Feel free to assign a garbage value. Some more details are present in the following sections, particularly Section 5.2.

# Symbol Table in Parsing and Expression Evaluation 

In this assignment, you will also be implementing a Symbol Table using an (unbalanced) Binary Search Tree (BST) to manage variables in the E++ expression evaluator. This task is essential for both parsing and expression evaluation. Let’s explore the concept and its relevance:

## Understanding Symbol Tables

A symbol table is a critical data structure used in our evaluator to store information about variables, functions, or other identifiers within an E++ program. It serves as a mapping, associating unique identifiers (in this case, variable names) with their corresponding values or attributes.

## Relevance to Parsing

Symbol tables play a crucial role in syntax checking. They ensure that variables are declared before they are used, preventing undefined variable errors and other syntax-related issues. However, in this assignment, this would not be relevant since the test cases ensure syntax and semantics are followed correctly.

## Relevance to Expression Evaluation

For expression evaluation:
- **Variable Resolution:** In E++, expressions often include variables. To evaluate these expressions, you must resolve the variables to their actual values. The symbol table provides a mechanism to map variable names to their corresponding values.
- **Efficient Evaluation:** A symbol table enhances the efficiency of expression evaluation. Without a symbol table, you would need to traverse the entire code repeatedly to find variable values, leading to performance issues.

# Implementation of Symbol Table, Parser, and Expression Evaluator

In this section, we describe the implementation for the Symbol Table, Parser, and Expression Evaluator for the programming language E++. We outline the expected functionality and relationships between these components.

## Symbol Table

This needs to be implemented using a BST, not necessarily balanced. You should use the `<` operator (lexicographic ordering) for comparison amongst keys (strings).

### Functions to Implement

You are required to implement the following functions in the `SymbolTable` class defined in `symtable.h`:

- `insert(string k, UnlimitedRational* v)`: This function should insert a key-value pair (variable name and its value) into the Symbol Table.
- `remove(string k)`: Implement a function to remove a key-value pair based on the variable name.
- `search(string k)`: Write a function to retrieve the value associated with a variable name from the Symbol Table.
- `get_size()`: Implement a function to get the size (number of entries) in the Symbol Table.
- `get_root()`: Provide a function to get the root node of the Symbol Table (useful for internal implementation).

## Evaluator

This is the top-level class which will read individual instructions, parse them, and evaluate them.

### Functions to Implement

You are required to implement the following functions in the `Evaluator` class defined in `evaluator.h`:

- `void parse(vector<string> code)`: This function should read an input vector of tokens (strings), parse it, and convert it to a parse tree. The root of the tree should be pushed into the `expr_trees` vector. Ensure that the `type` and `val` properties are correctly set during parsing. An example is:
  - **Statement:**
    ```
    v := (13 + (2 / 51))
    ```
  - **Tokens (Vector of strings):**
    ```
    ["v", ":=", "(", "13", "+", "(", "2", "+", "(", "2", "/", "51", ")", ")"]
    ```
  Note that the tokens corresponding to numerical values given as input to this function will always be integral (not rational). Only the intermediate and final values during calculations have to be rationals.

- `void eval()`: This function should evaluate the last element of the `expr_trees` vector. It will be called immediately after a call to `parse`, and it should also populate the symbol tables. Ensure that the `evaluated_value` property is correctly set during evaluation.




