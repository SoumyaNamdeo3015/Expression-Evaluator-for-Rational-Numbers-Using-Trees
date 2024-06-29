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

# UnlimitedRational 

## UnlimitedRational Class

In a related context, we introduce a class named `UnlimitedRational`, which will be used for evaluating expressions in one of the subparts of the assignment. A rational number is typically represented in the form `p/q`, where `p` and `q` are integers (Z), `p` and `q` are coprime (meaning they have no common divisors other than 1), and `q ≠ 0`.

The `UnlimitedRational` class extends the concept of rational numbers by using the previously introduced `UnlimitedInt` class for its numerator and denominator. This allows you to accommodate even the most extensive calculations in scenarios where standard floating-point representations might suffer from precision loss.

# UnlimitedRational Class

The `UnlimitedRational` class extends the concept of rational numbers by using the `UnlimitedInt` class for its numerator and denominator. This allows for precise calculations even in scenarios where standard floating-point representations might suffer from precision loss. The `UnlimitedRational` class includes the following attributes and methods:

## Attributes

- `p`: A pointer to an `UnlimitedInt` object representing the numerator. 
- `q`: A pointer to an `UnlimitedInt` object representing the denominator. Note that `p` and `q` must be coprime, or the implementation will not pass tests. If `p` is 0, any non-zero value of `q` will be acceptable for the denominator.

## Methods

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


