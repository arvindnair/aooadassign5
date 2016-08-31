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
#include "Expr_Command.h"                 // for Expression Command.
#include "Right_Parenthesis_Command.h"    // for Right Parenthesis Command.
#include "Stack.h"                        // for stack definition.

//
// Right_Parenthesis_Command
//
Right_Parenthesis_Command::Right_Parenthesis_Command (void)
{}

//
// ~Right_Parenthesis_Command
//
Right_Parenthesis_Command::~Right_Parenthesis_Command (void)
{}

//
// evaluate
//
bool Right_Parenthesis_Command::execute (Stack <int> & s)
{
	// just return true if successful.
	return true;
}

//
// token_type
//
std::string Right_Parenthesis_Command::token_type (void) const
{
	return ")";
}

//
// stack_precedence_number
//
int Right_Parenthesis_Command::stack_precedence_number (void) const
{
	return 3;
}

//
// is_operator
//
bool Right_Parenthesis_Command::is_operator (void) const
{
	return false;
}