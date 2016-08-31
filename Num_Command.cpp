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
#include "Num_Command.h"      // for Number Command.
#include "Stack.h"            // for stack definition.


//
// Num_Command
//
Num_Command::Num_Command()
{}

//
// Num_Command (int)
//
// store the number passed into n_ variable using base member initialization.
Num_Command::Num_Command (int n)
	:n_ (n)
{}

//
// ~Num_Command
//
Num_Command::~Num_Command (void)
{}

//
// execute
//
bool Num_Command::execute (Stack <int> & s)
{
	// push the number n_ onto the stack.
	s.push(this->n_);
	// return true if successful.
	return true;
}

//
// token_type
//
std::string Num_Command::token_type (void) const
{
	return "n_";
}

//
// stack_precedence_number
//
int Num_Command::stack_precedence_number (void) const
{
	return 0;
}

//
// is_operator
//
bool Num_Command::is_operator (void) const
{
	return false;
}