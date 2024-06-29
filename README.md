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


