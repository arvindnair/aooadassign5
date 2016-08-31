//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Flyweight_Expr_Command_Factory.h"

//
// Flyweight_Expr_Command_Factory
//
// setting all the references of particular commands to zero.
Flyweight_Expr_Command_Factory::Flyweight_Expr_Command_Factory (void)
	:add_(0),
	subtract_(0),
	multiply_(0),
	divide_(0),
	modulus_(0),
	left_par_(0),
	right_par_(0)
{}

//
// ~Flyweight_Expr_Command_Factory
//
// If the references are created using new i.e., they are not zero then delete them.
Flyweight_Expr_Command_Factory::~Flyweight_Expr_Command_Factory (void)
{
	if (this->add_!=0)
	{
		delete this->add_;
	}
	if (this->subtract_!=0)
	{
		delete this->subtract_;
	}
	if (this->multiply_!=0)
	{
		delete this->multiply_;
	}
	if (this->divide_!=0)
	{
		delete this->divide_;
	}
	if (this->modulus_!=0)
	{
		delete this->modulus_;
	}
	if (this->left_par_!=0)
	{
		delete this->left_par_;
	}
	if (this->right_par_!=0)
	{
		delete this->right_par_;
	}
}

//
// create_num_command (int)
//
// returns new Num command as it is not shareable.
Num_Command * Flyweight_Expr_Command_Factory::create_num_command (int num)
{
	return new Num_Command(num);
}

//
// create_add_command
//
// If add reference is empty, stores a new add command and returns the reference.
Add_Command * Flyweight_Expr_Command_Factory::create_add_command (void)
{
	if (this->add_==0)
	{
		this->add_=new Add_Command();
	}
	return this->add_;	
}

//
// create_subtract_command
//
// If subtract reference is empty, stores a new subtract command and returns the reference.
Subtract_Command * Flyweight_Expr_Command_Factory::create_subtract_command (void)
{
	if (this->subtract_==0)
	{
		this->subtract_=new Subtract_Command();
	}
	return this->subtract_;
	
}

//
// create_multiply_command
//
// If multiply reference is empty, stores a new multiply command and returns the reference.
Multiply_Command * Flyweight_Expr_Command_Factory::create_multiply_command (void)
{
	if (this->multiply_==0)
	{
		this->multiply_=new Multiply_Command();
	}
	return this->multiply_;
}

//
// create_divide_command 
//
// If divide reference is empty, stores a new divide command and returns the reference.
Divide_Command * Flyweight_Expr_Command_Factory::create_divide_command (void)
{
	if (this->divide_==0)
	{
		this->divide_=new Divide_Command();
	}
	return this->divide_;
}

//
// create_modulus_command
//
// If modulus reference is empty, stores a new modulus command and returns the reference.
Modulus_Command * Flyweight_Expr_Command_Factory::create_modulus_command (void)
{
	if (this->modulus_==0)
	{
		this->modulus_=new Modulus_Command();
	}
	return this->modulus_;
}

//
// create_left_parenthesis_command 
//
// If left parenthesis reference is empty, stores a new left parenthesis command and returns the reference.
Left_Parenthesis_Command * Flyweight_Expr_Command_Factory::create_left_parenthesis_command (void)
{
	if (this->left_par_==0)
	{
		this->left_par_=new Left_Parenthesis_Command();
	}
	return this->left_par_;
}

//
// create_right_parenthesis_command
//
// If right parenthesis reference is empty, stores a new right parenthesis command and returns the reference.
Right_Parenthesis_Command * Flyweight_Expr_Command_Factory::create_right_parenthesis_command (void)
{
	if (this->right_par_==0)
	{
		this->right_par_=new Right_Parenthesis_Command();
	}
	return this->right_par_;
}