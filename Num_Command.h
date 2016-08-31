//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include <string>
#include <iostream>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Command.h"     // for Expression Command.
#include "Stack.h"            // for stack definition.

/**
* @class Num_Command
*
* Implementation of Num_Command.
*/

class Num_Command : public Expr_Command
{
public:

	/// Default constructor.
	Num_Command (void);

	/**
	* Initializing constructor.
	*
	* @param[in]       n                    Number passed in.
	*/
	Num_Command (int n);

	/// Destructor.
	~Num_Command (void);

	/**
	* Performs Number Command on the stack and returns operation status.
	* It pushes one number onto the stack.
	* 
	* @param[in]       s                     Stack to be used for evaluation.
	* @retval          true                  Operation Succeded.
	*/
	virtual bool execute (Stack <int> & s);

	/**
	* Checks and returns the token type string of the particular Number.
	*
	* @return          String of particular Number.
	*/
	virtual std::string token_type (void) const;

	/**
	* Returns the stack precedence number of the Number.
	*
	* @retval          0                       Stack precedence number of Number.
	*/
	virtual int stack_precedence_number (void) const;

	/**
	* It is used to determine if the command is an operator.
	* 
	* @retval          true                  Command is an operator.
	* @retval          false                 Command is not an operator.
	*/
	virtual bool is_operator (void) const;

private:

	//Number to be pushed onto the stack.
	int n_;
};


#endif // !_NUM_COMMAND_H_
