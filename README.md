# Expression-Evaluator-for-Rational-Numbers-Using-Trees

# Introduction : 
An expression evaluator is a software component or program that interprets and computes the result of
mathematical, logical, or symbolic expressions provided as input. It takes an expression as input, processes
it according to predefined rules or algorithms, and returns the result of the evaluation. Your task in this
assignment is to create an expression evaluator for programs written in the language E++, for a special
kind of input data which is described below.

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



