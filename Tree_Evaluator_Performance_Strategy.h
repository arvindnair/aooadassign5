//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _TREE_EVALUATOR_PERFORMANCE_STRATEGY_H_
#define _TREE_EVALUATOR_PERFORMANCE_STRATEGY_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include <sstream>
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Expr_Node.h"
#include "Stack.h"
#include "Expr_Evaluator_Strategy.h"

/**
* @class Tree_Evaluator_Performance_Strategy
*
* Basic implementation of Tree_Evaluator_Performance_Strategy.
*/
class Tree_Evaluator_Performance_Strategy : public Expr_Evaluator_Strategy
{
public:

	/// Default constructor.
	Tree_Evaluator_Performance_Strategy (void);

	/// Destructor.
	virtual ~Tree_Evaluator_Performance_Strategy (void);

	/**
	* It take the given infix expression as string and then calculates the result
	* and returns the result to the driver.
	* 
	* @param[in]       infix                 Infix string.
	* @return          Result of the operation.
	*/
	virtual int calculator (const std::string & infix);



private:
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// DEFINE ANY HELPER METHODS HERE

	/**
	* Parses the given infix expression and calls on the build nodes as per
	* the particular tokens encountered. If expression is not valid then 
	* std::runtime_error is thrown.
	* 
	* @param[in]       infix                 Infix string.
	* @retval          true                  Operation Succeeded.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual bool parse_expr (const std::string & infix);

	/**
	* It evaluates the expression and stores the result. It uses the builder's 
	* get_result method to obtain result.
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
	* @param[in]       count                 Counts the number of tokens.
	* @param[in]       token_previous        The previous token.
	* @param[in]       value                 The integer value of the number.
	* @retval          true                  Passed token is a number.
	* @retval          false                 Passed token is not a number.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual bool is_number (const std::string & token, size_t & count, std::string & token_previous, int & value);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Copy Constructor.
	Tree_Evaluator_Performance_Strategy (const Tree_Evaluator_Performance_Strategy &);

	/// Assignment Operator.
	const Tree_Evaluator_Performance_Strategy & operator = (const Tree_Evaluator_Performance_Strategy &);

	// Stack to store operators in string format.
	Stack<std::string> op_stack_;

	// use expression tree builder class to build the tree.
	Expr_Tree_Builder builder_;
};

#endif // !_TREE_EVALUATOR_PERFORMANCE_STRATEGY_H_
