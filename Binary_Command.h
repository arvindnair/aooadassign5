//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _BINARY_COMMAND_H_
#define _BINARY_COMMAND_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Command.h"     // for Expression Command.
#include "Stack.h"            // for stack definition.


/**
* @class Binary_Command
*
* Implementation of Binary Command.
*/
class Binary_Command : public Expr_Command
{
public:
	/// Default constructor.
	Binary_Command (void);

	/// Destructor.
	~Binary_Command (void);

	/**
	* Performs execute on the stack and returns operation status.
	* It is a function which executes commands particular to the command
	* and performs actions if necessary on the stack. If the stack is empty,
	* then the expression is invalid and std::runtime_error is thrown.
	* 
	* @param[in]       s                     Stack to be used for evaluation.
	* @retval          true                  Operation Succeeded.
	* @exception       std::runtime_error    Expression is Invalid.
	*/
	virtual bool execute (Stack <int> & s);

	/**
	* Performs evaluate on the stack and as per the command and returns 
	* the result. It is a pure virtual function.
	* 
	* @param[in]       s                     Stack to be used for evaluation.
	* @return          Result of evaluation.
	*/
	virtual int evaluate (int n1, int n2) const = 0;

	/**
	* Checks and returns the token type string of the particular Command.
	*
	* @return          String of particular Command.
	*/
	virtual std::string token_type (void) const;

	/**
	* Checks and returns the token type string of the Binary Command.
	* It is a pure virtual function.
	*
	* @return          String of particular Binary Command.
	*/
	virtual std::string binary_token_type (void) const = 0;

	/**
	* Returns the stack precedence number of the particular Command.
	*
	* @return          Stack precedence number of particular Command.
	*/
	virtual int stack_precedence_number (void) const;


	/**
	* Returns the stack precedence number of the particular Binary Command.
	* It is a pure virtual function.
	*
	* @return          Stack precedence number of particular Binary Command.
	*/
	virtual int binary_stack_precedence_number (void) const = 0;

	/**
	* It is used to determine if the command is an operator.
	* 
	* @retval          true                  Command is an operator.
	* @retval          false                 Command is not an operator.
	*/
	virtual bool is_operator (void) const;

private:

};


#endif // !_BINARY_COMMAND_H_
