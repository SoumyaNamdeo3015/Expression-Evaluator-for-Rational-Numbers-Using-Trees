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

