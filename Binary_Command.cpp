// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Command.h"     // for Expression Command.
#include "Binary_Command.h"   // for Binary Command.
#include "Stack.h"            // for stack definition.

//
// Binary_Command
//
Binary_Command::Binary_Command (void)
{}

//
// ~Binary_Command
//
Binary_Command::~Binary_Command (void)
{}

//
// execute
//
bool Binary_Command::execute (Stack <int> & s)
{
	// if the stack is empty then the expression is invalid.
	if(s.is_empty())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// after check store stack top in n2
	int n2 = s.top();
	s.pop();
	// if the stack is empty then the expression is invalid.
	if(s.is_empty())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// after check store stack top in n1.
	int n1 = s.top();
	s.pop();
	// evaluate as per the particular command and store in result.
	int result = this->evaluate(n1,n2);
	// push the result in stack.
	s.push(result);
	return true;
}

//
// token_type
//
std::string Binary_Command::token_type (void) const
{
	// call the particular command for that string.
	std::string s = this->binary_token_type();
	return s;
}

//
// stack_precedence_number
//
int Binary_Command::stack_precedence_number (void) const
{
	// call the particular command for the precedence number.
	int i = this->binary_stack_precedence_number();
	return i;
}

//
// is_operator
//
bool Binary_Command::is_operator (void) const
{
	return true;
}