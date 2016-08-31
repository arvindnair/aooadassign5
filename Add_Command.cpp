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
#include "Add_Command.h"      // for Add Command.
#include "Stack.h"            // for stack definition.

//
// Add_Command
//
Add_Command::Add_Command (void)
{}

//
// ~Add_Command
//
Add_Command::~Add_Command (void)
{}

//
// evaluate
//
int Add_Command::evaluate (int n1, int n2) const
{
	// Arvind, please use the template method pattern here to reduce duplicate
	// code across each of the binary commands.
	
	// Dr.Hill, I have used the template method pattern by using a class Binary
	// Command which has reduced the duplicate code across each of the Binary
	// Commands (Addition, Subtraction, Multiplication, Division and Modulus).

	// return the addition of n1 and n2.
	return n1+n2;
}

//
// binary_token_type
//
std::string Add_Command::binary_token_type (void) const
{
	return "+";
}

//
// binary_stack_precedence_number
//
int Add_Command::binary_stack_precedence_number (void) const
{
	return 2;
}