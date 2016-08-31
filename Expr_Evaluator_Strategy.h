#ifndef _EXPR_EVALUATOR_STRATEGY_H_
#define _EXPR_EVALUATOR_STRATEGY_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>

/**
* @class Expr_Evaluator_Strategy
*
* Implementation of Expression Evaluator Strategy.
*/
class Expr_Evaluator_Strategy
{
public:

	/// Default constructor.
	Expr_Evaluator_Strategy();

	/// Destructor.
	virtual ~Expr_Evaluator_Strategy();

	/**
	* It take the given infix expression as string and then calculates the result
	* and returns the result to the driver.It is a pure virtual function.
	* 
	* @param[in]       infix                 Infix string.
	* @return          Result of the operation.
	*/
	virtual int calculator (const std::string & infix) = 0;

protected:

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
	virtual bool parse_expr (const std::string & infix) = 0;

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
	virtual bool evaluate_expr (int & result) = 0;

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
	virtual bool is_number (const std::string & token, size_t & count, std::string & token_previous, int & value) = 0;

	/**
	* Checks if the token is a token is an expression and returns true if it is an
	* expression and returns false if it is not an expression.If expression is not 
	* valid then std::runtime_error is thrown.
	* 
	* @param[in]       infix                 Infix expression to be checked.
	* @retval          true                  Passed string is an expression.
	* @retval          false                 Passed string is not an expression.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual bool is_expression (const std::string & infix) const;

};

#endif // !_EXPR_EVALUATOR_STRATEGY_H_
