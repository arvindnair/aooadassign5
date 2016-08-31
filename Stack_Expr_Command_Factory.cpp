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
#include "Expr_Command_Factory.h"          // for Expression Command Factory.
#include "Stack_Expr_Command_Factory.h"    // for Stack Expression Command Factory.

//
// Stack_Expr_Command_Factory
//
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (void)
{}

//
// ~Stack_Expr_Command_Factory
//
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{}

//
// create num command
//
// returns a Num Command object
Num_Command *  Stack_Expr_Command_Factory::create_num_command (int num)
{
	return new Num_Command(num);
}

//
// create add command
//
// returns a Add Command object
Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
	return new Add_Command();
}

//
// create subtract command
//
// returns a Subtract Command object
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
	return new Subtract_Command();
}

//
// create multiply command
//
// returns a Multiply Command object
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
	return new Multiply_Command();
}

//
// create divide command
//
// returns a Divide Command object
Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
	return new Divide_Command();
}

//
// create modulus command
//
// returns a Modulus Command object
Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
	return new Modulus_Command();
}

//
// create left parenthesis command
//
// returns a Left Parenthesis Command object
Left_Parenthesis_Command * Stack_Expr_Command_Factory::create_left_parenthesis_command (void)
{
	return new Left_Parenthesis_Command();
}

//
// create right parenthesis command
//
// returns a Right Parenthesis Command object
Right_Parenthesis_Command * Stack_Expr_Command_Factory::create_right_parenthesis_command (void)
{
	return new Right_Parenthesis_Command();
}

