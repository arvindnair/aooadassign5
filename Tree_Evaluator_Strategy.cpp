// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
#include "Tree_Evaluator_Strategy.h"

//
// Tree_Evaluator_Strategy
//
Tree_Evaluator_Strategy::Tree_Evaluator_Strategy (void)
	:builder_()
{}

//
// ~Tree_Evaluator_Strategy
//
Tree_Evaluator_Strategy::~Tree_Evaluator_Strategy (void)
{}

//
// calculator (const std::string &)
//
int Tree_Evaluator_Strategy::calculator (const std::string & infix)
{
	try
	{
		int result=0;
		// call to parse expression which will create the tree.
		parse_expr(infix);
		// call to evaluate expression to evaluate the tree.
		evaluate_expr(result);
		return result;
	}
	catch(std::exception& e)
	{
		// rethrow exception for try catch in driver.
		const std::string es=e.what();
		throw std::runtime_error(es);
	}
}

//
// parse_expr (const std::string &, Expr_Builder &)
//
bool Tree_Evaluator_Strategy::parse_expr (const std::string & infix)
{
	// check if expression has proper spaces and parenthesis.
	if (!(is_expression(infix)))
	{
		throw std::runtime_error("Invalid Expression");
	}
	// creating a stream of strings.
	std::istringstream input(infix);
	// declaring token strings to store current and previous tokens.
	std::string token;
	std::string token_previous;
	// declaring variable count to count the nodes leaving out the parenthesis nodes.
	size_t count=0;
	builder_.build_expression();
	while(!input.eof())
	{
		// Arvind, you have not implemented the builder pattern correctly. The
		// client should not have any logic related to the build process, such as
		// keeping track of the stack of operands. Instead, the concrete builder
		// should be responsible maintaining that information. Please fix your
		// design such that the client just class the correct build method on the
		// builder for each token that it extracts from the input. The client
		// (i.e., this method) should not have a stack or any state pertaining to
		// how the build process should work.

		// Dr.Hill, I have moved the stack of operands to the builder. Now, the client 
		// calls the correct build method for the particular token extracted from the 
		// input. The Expression Evaluator does not have any stack or state pertaining 
		// to how the build process should work.

		count++;
		input >> token;

		// if the token is an operator then create the particular nodes.
		// pushes the particular operator string onto string stack.
		if (token=="+")
		{
			builder_.build_add_operand();
		}
		else if (token=="-")
		{
			builder_.build_subtract_operand();
		}
		else if (token=="*")
		{
			builder_.build_multiply_operand();
		}
		else if (token=="/")
		{
			builder_.build_divide_operand();
		}
		else if (token=="%")
		{
			builder_.build_modulus_operand();
		}
		// if token is equal to left parenthesis build left parenthesis
		// for both parenthesis decrement count. 
		else if (token=="(")
		{
			builder_.build_left_parenthesis();
			count--;
		}
		// if token is equal to right parenthesis build right parenthesis
		else if (token==")")
		{
			builder_.build_right_parenthesis();
			count--;
		}
		// check if the token is a number.
		else
		{
			// create value variable to store the integer.
			int value=0;
			// if the token is a number then build number node otherwise it is 
			// an invalid expression.
			if(is_number(token,count,token_previous,value))
			{
				builder_.build_number(value);
			}
			else
			{
				throw std::runtime_error("Invalid Expression");
			}
		}
		token_previous=token;
	}
	// if only one token is passed then it is an invalid expression. 
	if (count<=1)
	{
		throw std::runtime_error("Invalid Expression");
	}
	return true;
}

//
// evaluate_expr (Expr_Builder &, int &)
//
bool Tree_Evaluator_Strategy::evaluate_expr (int & result)
{
	// declare evaluate expression tree class to pass in accept for Visitor Pattern
	// by calling accept after getting expression.
	Eval_Expr_Tree evaluate;
	Expr_Node * expr=builder_.get_expression();
	expr->accept(evaluate);
	result=evaluate.result();
	return true;
}

//
// is_number (const std::string &, size_t &, std::string &, int &)
//
bool Tree_Evaluator_Strategy::is_number (const std::string & token, size_t & count, std::string & token_previous, int & value)
{
	// make num_temp_1 contain token in istringstream format.
	std::istringstream num_temp_1(token);
	// declare a int variable 
	int num=0;
	// if num_temp_1 i.e., the token is a number then check conditions below.
	if(!(num_temp_1 >> num).fail())
	{
		// using stringstream to convert the obtained number into a string.
		std::stringstream ss;
		ss << num;
		std::string str = ss.str();
		// now check if the token and the string are equal e.g. if 5a is token then
		// str will be 5 and it is not a valid expression.
		if(str==token)
		{
			value = atoi(token.c_str());
			// if the count is greater than 1 then check if previous token is an integer.
			if(count>1)
			{
				std::istringstream num_temp_2(token_previous);
				int num_1=0;
				// num_temp_2 is is an integer then two integers simultaneously is an invalid expression.
				if(!(num_temp_2 >> num_1).fail())
				{
					return false;
				}
			}
			return true;
		}
		// if the token is not a number but alphanumeric character.
		else
		{
			return false;
		}
	}
	// else the token is not an integer.
	else
	{
		return false;
	}
}
