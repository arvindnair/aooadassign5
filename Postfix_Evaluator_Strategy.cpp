// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

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
#include "Stack_Expr_Command_Factory.h"     // for Stack Expression Command Factory.
#include "Stack.h"                          // for Stack definition.
#include "Array.h"                          // for Array definition.
#include "Add_Command.h"                    // for Add Command.
#include "Divide_Command.h"                 // for Divide Command.
#include "Multiply_Command.h"               // for Multiply Command.
#include "Subtract_Command.h"               // for Subtract Command.
#include "Modulus_Command.h"                // for Modulus Command.
#include "Binary_Command.h"                 // for Binary Command.
#include "Postfix_Evaluator_Strategy.h"     // for Expression Evaluator.

#define DEFAULT_SIZE 10                     // A Default size so that the array need not be resized.
// everytime an element is added.

//
// Postfix_Evaluator_Strategy
//
Postfix_Evaluator_Strategy::Postfix_Evaluator_Strategy (void)
	:postfix(0),
	iter(postfix),
	factory()
{}

//
// ~Postfix_Evaluator_Strategy
//
Postfix_Evaluator_Strategy::~Postfix_Evaluator_Strategy (void)
{
	for (size_t i = 0; i < postfix.size(); i++)
	{
		delete postfix[i];
	}
}

//
// calculator (const std::string &)
//
int Postfix_Evaluator_Strategy::calculator (const std::string & infix)
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
// infix_to_postfix
//
bool Postfix_Evaluator_Strategy::parse_expr (const std::string & infix)
{
	// check if expression has proper spaces and parenthesis.
	if (!(is_expression(infix)))
	{
		throw std::runtime_error("Invalid Expression");
	}
	// creating a stream of strings.
	std::istringstream input(infix);
	std::string token;
	std::string token_previous;
	Expr_Command * cmd=0;
	// declaring a temporary stack of expression commands.
	Stack <Expr_Command* > temp;
	// declaring a variable to increment the postfix array.
	size_t i=0;
	// declaring variable count to count the commands leaving out the parenthesis commands.
	size_t count=0;
	bool operator_flag=false;
	// initially resize the postfix array to default size of 10.
	postfix.resize(DEFAULT_SIZE);
	while(!input.eof())
	{
		count++;
		// if postfix array size is lesser than count the resize to the sum of postfix size plus
		// the default size.
		if (postfix.size()<=count)
		{
			postfix.resize((postfix.size()+DEFAULT_SIZE));
		}
		// taken a string from the input stream.
		input >> token;
		cmd=0;

		// Arvind, many of the checkss below can be made as methods on the command.
		// Right now, the logic for your checks is tightly coupled to the supported
		// operators. You, in essense, implemented the same problem we are were trying
		// to avoid when evaluator each operator.

		// Dr.Hill, I have removed the check_stack_status and check_precedence from the
		// Expression Evaluator and placed the operator precedence in the commands. The
		// method stack_precedence_number will give the stack precedence of the operators
		// as per the descending order i.e., Numbers highest, /, * and % next, then + and -
		// and finally ( and ). This precedence number has been allocated w.r.t the stack 
		// operations in infix to postfix conversion. So, if we add a new operator then 
		// we just need to specify the precedence in that command's class. Also, I have
		// created a new method called token_type which will return the string value of
		// that particular command type is returned. So, I have eliminated the second
		// stack used to store the operators as strings. Now, my design is loosely
		// coupled.

		// Arvind, you have a LOT of duplicate code below for each operator. Please
		// improve this design and promote better reuse in your code below.

		// Dr.Hill, I have used functions called is_operator, is_number and is_expression
		// to avoid duplication of code. This makes the infix_to_postfix function much 
		// smaller and readable. Hence, I have done better reuse in my code. Also, I have
		// used Iterator pattern.

			// if token is +, create add command.
			if (token=="+")
			{
				cmd=factory.create_add_command();
				operator_flag=true;
			}
			// if token is -, create subtract command.
			else if (token=="-")
			{
				cmd=factory.create_subtract_command();
				operator_flag=true;
			}
			// if token is *, create multiply command.
			else if (token=="*")
			{
				cmd=factory.create_multiply_command();
				operator_flag=true;
			}
			// if token is /, create divide command.
			else if (token=="/")
			{
				cmd=factory.create_divide_command();
				operator_flag=true;
			}
			// if token is %, create modulus command.
			else if (token=="%")
			{
				cmd=factory.create_modulus_command();
				operator_flag=true;
			}
		
		// if token is equal to left parenthesis
		else if (token=="(")
		{
			// store command object to cmd.
			cmd=factory.create_left_parenthesis_command();
			temp.push(cmd);
			cmd=0;
			// decrement the count as the left parenthesis will not be added to the postfix array.
			count--;
		}
		// if token is equal to right parenthesis
		else if (token==")")
		{
			// while the stack is not empty and the a left parenthesis is not encountered.
			while ((!(temp.is_empty())) && ("("!=temp.top()->token_type()))
			{
				// keep adding the contents of the stack to the postfix array of commands.
				postfix[i]=temp.top();
				temp.pop();
				i++;
			}
			// decrement the count variable as right parenthesis is encountered.
			count--;
			// store the left parenthesis into cmdtemp.
			Expr_Command* cmdtemp=temp.top();
			temp.pop();
			delete cmdtemp;
		}
		// check if the token is a number or an invalid expression.
		else
		{
			// create value variable to store the integer.
			int value=0;
			// if the token is a number then create number command.  
			if(is_number(token,count,token_previous,value))
			{
				// after check is done store the command object to cmd.
				cmd=factory.create_num_command(value);
				// add the command object to the postfix array.
				postfix[i]=cmd;
				i++;
				cmd=0;
			}
			else
			{
				// resize the postfix array to i.
				postfix.resize(i);
				// temp stack is not empty delete the contents.
				while (!(temp.is_empty()))
				{
					Expr_Command * cmdtemp1=temp.top();
					temp.pop();
					delete cmdtemp1;
				}
				// now throw the exception.
				throw std::runtime_error("Invalid Expression");
			}
		}
		if (operator_flag)
		{
			// check if the command can be pushed onto the stack.
			while ((!(temp.is_empty())) && (cmd->is_operator()) && (temp.top()->stack_precedence_number()<=cmd->stack_precedence_number()))
			{
				postfix[i]=temp.top();
				i++;
				temp.pop();
			}
			// after check the particular command is pushed onto the stack.
			temp.push(cmd);
			// setting cmd to zero.
			cmd=0;
			operator_flag=false;
		}

		// set this token to previous token.
		token_previous=token;
	}
	// finally pop the command stack and update the postfix array accordingly.
	while ((!(temp.is_empty())) && "("!=temp.top()->token_type())
	{
		postfix[i]=temp.top();
		temp.pop();
		i++;
	}
	// temp stack is not empty delete the contents.
	while (!(temp.is_empty()))
	{
		Expr_Command * cmdtemp1=temp.top();
		temp.pop();
		delete cmdtemp1;
	}
	// resize the postfix array to i.
	postfix.resize(i);
	return true;
}


//
// evaluate_postfix
//
bool Postfix_Evaluator_Strategy::evaluate_expr (int & result)
{
	// specify a stack for pushing results of evaluation/execution.
	Stack <int> s;
	// a counter to count iteration.
	size_t count_iter=0;
	// iterate over the postfix array and execute each command.
	for (; !iter.is_done() ; iter.advance())
	{
		(*iter)->execute(s);
		count_iter++;
	}
	// if the counter of iteration is 1 then the expression is invalid. So, throw exception.
	if(count_iter<=1)
	{
		throw std::runtime_error("Invalid Expression");
	}
	// if stack size is not equal to 1 then the expression is invalid.
	if (s.size()!=1)
	{
		throw std::runtime_error("Invalid Expression");
	}
	// store the result in result.
	result=s.top();
	return true;
}

//
// is_number
//
bool Postfix_Evaluator_Strategy::is_number (const std::string & token, size_t & count, std::string & token_previous, int & value)
{
	// make num_temp_1 contain token in istringstream format.
	std::istringstream num_temp_1(token);
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
			// convert the string to an integer value.
			value = atoi(token.c_str());
			// if the count is greater than 1 then check if previous token is an integer.
			if(count>1)
			{
				// create istringstream of previous token in num_temp_2
				std::istringstream num_temp_2(token_previous);
				int num_1=0;
				// num_temp_2 is is an integer then the expression is invalid expression.
				if(!(num_temp_2 >> num_1).fail())
				{
					return false;
				}
			}
			return true;
		}
		// if the token is not a valid expression then throw exception.
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
