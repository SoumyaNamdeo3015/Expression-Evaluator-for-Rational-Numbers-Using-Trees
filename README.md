# Expression-Evaluator-for-Rational-Numbers-Using-Trees

# Introduction : 
An expression evaluator is a software component or program that interprets and computes the result of
mathematical, logical, or symbolic expressions provided as input. It takes an expression as input, processes
it according to predefined rules or algorithms, and returns the result of the evaluation. Your task in this
assignment is to create an expression evaluator for programs written in the language E++, for a special
kind of input data which is described below. The numbers in E++ can integer or rational and may be very large that's why other part of this projects includes creating unlimitedInt and unlimitedRational classes.

# Description of E++ : 

- ## Expression :

- Expressions in E++ are fully parenthesized, well-formed arithmetic infix expressions, using the following
operators: +, -, *, /. The operands appearing in an expression may be numerical, or variables (such as
x).

- ## Examples :
- ### Examples of valid E++ expressions :
  - (a + b))
  - ((x ∗ y) − z)
  - ((5 + x)/(a + b))
  - ((a + 2) ∗ 3)
  - (((x + y) ∗ (a − b)) − (c/d))
  - (((2 ∗ a)/3) + (b − (c − d)))

- ### Examples of invalid E++ expressions :
  - a + b (missing enclosing brackets)
  - (ab) (missing operator)
  - ((x + y) ∗ (a + b) + c) (missing operators between sub-expressions)
  - () (empty expression)
  - (&) (invalid operator)
  - (∗ab) (not an infix expression)
  - ((a/)) (operator at the end)
  - ((x + y)(a − b)) (missing operator between sub-expressions)
  - (a + b))(unbalanced parentheses)

- ### Syntax :
The syntax of E++ is very simple. There are two types of statements:
- **Variable Assignment** : v := E where the LHS is a variable v and the RHS is a well formed expression
E as defined above.

- **Returning a Value** : return E where E is a well formed expression.

- **Declaration Before Use** : A variable x can appear on the RHS of an expression only if there exists
a statement before it of the form x := E.

- **Immutability** : A variable x can only be assigned to once, i.e. there should not exist two distinct
statements S1 and S2 such that S1 : x := E1 and S2 : x := E2.


# UnlimitedInt :
In this subsection, we will discuss the details of the UnlimitedInt class.
The UnlimitedInt class is a custom integer data type designed to handle integers of arbitrary size without
any limitations on their magnitude. Unlike standard integer types in programming languages, such as int or
long, which have fixed ranges, UnlimitedInt can represent extremely large or precise integer values. This
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


