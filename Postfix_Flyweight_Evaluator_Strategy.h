//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _POSTFIX_FLYWEIGHT_EVALUATOR_STRATEGY_H_
#define _POSTFIX_FLYWEIGHT_EVALUATOR_STRATEGY_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include <sstream>
#include "Array_Iterator.h"                 // for Array Iterator.
#include "Expr_Command_Factory.h"           // for Expression Command Factory.
#include "Expr_Command.h"                   // for Expression Command.
#include "Stack.h"                          // for Stack definition.
#include "Array.h"                          // for Array definition.
#include "Add_Command.h"                    // for Add Command.
#include "Divide_Command.h"                 // for Divide Command.
#include "Multiply_Command.h"               // for Multiply Command.
#include "Subtract_Command.h"               // for Subtract Command.
#include "Modulus_Command.h"                // for Modulus Command.
#include "Binary_Command.h"                 // for Binary Command.
#include "Flyweight_Expr_Command_Factory.h"
#include "Expr_Evaluator_Strategy.h"

/**
* @class Postfix_Flyweight_Evaluator_Strategy 
*
* Implementation of Infix to Postfix evaluation and result of Postfix.
*/
class Postfix_Flyweight_Evaluator_Strategy : public Expr_Evaluator_Strategy
{
public:

	/// Default constructor.
	Postfix_Flyweight_Evaluator_Strategy (void);

	/// Destructor.
	virtual ~Postfix_Flyweight_Evaluator_Strategy (void);

	virtual int calculator (const std::string & infix);

private:
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// DEFINE ANY HELPER METHODS HERE

	/**
	* Converts the given infix expression to postfix format. It takes infix string and
	* a postfix array of commands and using the factory creates objects of
	* various command requests and converts into a postfix array of commands, storing
	* it in postfix. If expression is not valid then std::runtime_error is thrown.
	* 
	* @param[in]       infix                 Infix string.
	* @retval          true                  Operation Succeded.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual bool parse_expr (const std::string & infix);

	/**
	* Evaluates the expresion in postfix format by iterating over the contents of 
	* the postfix array of commands and executing them. The result is stored in result 
	* after the iteration and popping the stack.If expression is not valid then 
	* std::runtime_error is thrown.
	* 
	* @param[in]       result                Result of the Expression.
	* @retval          true                  Operation Succeeded.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual bool evaluate_expr (int & result);

	/**
	* Checks if the token is a token is an number and returns true if it is an
	* number and returns false if it is not an number.If expression is not valid then 
	* std::runtime_error is thrown.
	* 
	* @param[in]       token                 Particular token to be checked.
	* @param[in]       count                 Counts the number of commands in postfix array.
	* @param[in]       token_previous        The previous token.
	* @param[in]       value                 The integer value of the number.
	* @retval          true                  Passed token is a number.
	* @retval          false                 Passed token is not a number.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual bool is_number (const std::string & token, size_t & count, std::string & token_previous, int & value);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// creating an array of commands.
		Array<Expr_Command* > postfix;
		Array_Iterator<Expr_Command* > iter;
		// creating a stack command factory object.
		Flyweight_Expr_Command_Factory factory;
};

#endif // !_POSTFIX_FLYWEIGHT_EVALUATOR_STRATEGY_H_
