//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Command.h"     // for Expression Command.
#include "Binary_Command.h"   // for Binary Command.
#include "Stack.h"            // for stack definition.

/**
* @class Subtract_Command
*
* Implementation of Subtract_Command.
*/

class Subtract_Command : public Binary_Command
{
public:

	/// Default constructor.
	Subtract_Command (void);

	/// Destructor.
	~Subtract_Command (void);

	/**
	* Perform Subtraction of the two numbers and returns the result.
	* 
	* @param[in]       n1                    Number 1 for Subtraction.
	* @param[in]       n2                    Number 2 for Subtraction.
	* @return          Result of Subtraction.
	*/
	virtual int evaluate (int n1, int n2) const;

	/**
	* Checks and returns the token type string of the Subtraction Command.
	*
	* @retval          "-"                     String of -
	*/
	virtual std::string binary_token_type (void) const;

	/**
	* Returns the stack precedence number of the - operator.
	*
	* @retval          2                       Stack precedence number of -
	*/
	virtual int binary_stack_precedence_number (void) const;

private:

};


#endif // !SUBTRACT_COMMAND_H_