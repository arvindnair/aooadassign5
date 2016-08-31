//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _FLYWEIGHT_EXPR_COMMAND_FACTORY_H_
#define _FLYWEIGHT_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/**
* @class Flyweight_Expr_Command_Factory
*
* Implementation of Flyweight_Expr_Command_Factory.
*/
class Flyweight_Expr_Command_Factory : public Expr_Command_Factory
{
public:

	/// Default constructor.
	Flyweight_Expr_Command_Factory (void);

	/// Destructor.
	virtual ~Flyweight_Expr_Command_Factory (void);

	/**
	* Creates and returns a new Number Command object.  
	*
	* @return         New Number Command object.
	*/
	virtual Num_Command * create_num_command (int num);

	/**
	* Creates a new Addition Command object and stores in Add variable
	* if called for the first time.It returns a reference to add variable.  
	*
	* @return         Reference to Add Variable.
	*/
	virtual Add_Command * create_add_command (void);

	/**
	* Creates a new Subtraction Command object and stores in Subtract variable
	* if called for the first time.It returns a reference to subtract variable.  
	*
	* @return         Reference to Subtract Variable.
	*/
	virtual Subtract_Command * create_subtract_command (void);

	/**
	* Creates a new Multiplication Command object and stores in Multiply variable
	* if called for the first time.It returns a reference to multiply variable.  
	*
	* @return         Reference to Subtract Variable.
	*/
	virtual Multiply_Command * create_multiply_command (void);

	/**
	* Creates a new Division Command object and stores in Divide variable
	* if called for the first time.It returns a reference to Divide variable.  
	*
	* @return         Reference to Divide Variable.
	*/
	virtual Divide_Command * create_divide_command (void);

	/**
	* Creates a new Modulus Command object and stores in Modulus variable
	* if called for the first time.It returns a reference to modulus variable.  
	*
	* @return         Reference to modulus Variable.
	*/
	virtual Modulus_Command * create_modulus_command (void);

	/**
	* Creates a new Left Parenthesis Command object and stores in Left Parenthesis variable
	* if called for the first time.It returns a reference to Left Parenthesis variable.  
	*
	* @return         Reference to Left Parenthesis Variable.
	*/
	virtual Left_Parenthesis_Command * create_left_parenthesis_command (void);

	/**
	* Creates a new Right Parenthesis Command object and stores in Right Parenthesis variable
	* if called for the first time.It returns a reference to Right Parenthesis variable.  
	*
	* @return         Reference to Right Parenthesis Variable.
	*/
	virtual Right_Parenthesis_Command * create_right_parenthesis_command (void);
	

private:

	//Add Command Variable
	Add_Command * add_;

	//Subtract Command Variable
	Subtract_Command * subtract_;

	//Multiply Command Variable
	Multiply_Command * multiply_;

	//Divide Command Variable
	Divide_Command * divide_;

	//Modulus Command Variable
	Modulus_Command * modulus_;

	//Left Parenthesis (Open Parenthesis) Variable
	Left_Parenthesis_Command * left_par_;

	//Right Parenthesis (Right Parenthesis) Variable
	Right_Parenthesis_Command * right_par_;
};

#endif // !_FLYWEIGHT_EXPR_COMMAND_FACTORY_H_