//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Stack.h"            // for stack definition.

/**
* @class Expr_Command 
*
* Implementation of Expression Command.
*/

class Expr_Command
{
public:

	/// Default constructor.
	Expr_Command (void);

	/// Destructor.
	~Expr_Command (void);

	/**
	* Performs execute on the stack and returns operation status.
	* It is a pure virtual function which executes commands and performs
	* actions if necessary on the stack.
	* 
	* @param[in]       s                     Stack to be used for evaluation.
	* @retval          true                  Operation Succeeded.
	*/
	virtual bool execute (Stack <int> & stack) = 0;

	/**
	* Checks and returns the token type string of the particular Command.
	* It is pure virtual function.
	*
	* @return          String of particular Command
	*/
	virtual std::string token_type (void) const = 0;

	/**
	* Returns the stack precedence number of the particular Command.
	* It is pure virtual function.
	*
	* @return          Stack precedence number of particular Command.
	*/
	virtual int stack_precedence_number (void) const = 0;

	/**
	* It is used to determine if the command is an operator.
	* It is a pure virtual function.
	* 
	* @retval          true                  Command is an operator.
	* @retval          false                 Command is not an operator.
	*/
	virtual bool is_operator (void) const = 0;

private:

};




#endif // !EXPR_COMMAND_H_
