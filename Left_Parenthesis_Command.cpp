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
#include "Expr_Command.h"                // for Expression Command.
#include "Left_Parenthesis_Command.h"    // for Left Parenthesis Command.
#include "Stack.h"                       // for stack definition.

//
// Left_Parenthesis_Command
//
Left_Parenthesis_Command::Left_Parenthesis_Command (void)
{}

//
// ~Left_Parenthesis_Command
//
Left_Parenthesis_Command::~Left_Parenthesis_Command (void)
{}

//
// execute
//
bool Left_Parenthesis_Command::execute (Stack <int> & s)
{
	return true;
}

//
// token_type
//
std::string Left_Parenthesis_Command::token_type (void) const
{
	return "(";
}

//
// stack_precedence_number
//
int Left_Parenthesis_Command::stack_precedence_number (void) const
{
	return 3;
}

//
// is_operator
//
bool Left_Parenthesis_Command::is_operator (void) const
{
	return false;
}