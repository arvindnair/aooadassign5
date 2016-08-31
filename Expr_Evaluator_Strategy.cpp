#include "Expr_Evaluator_Strategy.h"

Expr_Evaluator_Strategy::Expr_Evaluator_Strategy()
{
}

Expr_Evaluator_Strategy::~Expr_Evaluator_Strategy()
{
}

//
// is_expression
//
bool Expr_Evaluator_Strategy::is_expression (const std::string & infix) const
{
	// if input is blank expression is invalid.
	if (infix[0]=='\0')
	{
		return false;
	}
	// if the expression starts or ends with a space or if there are two
	// spaces between valid terms it is not a valid expression. Using NOR
	// i.e., expression should have no spaces at beginning or ending or both.
	if (!((infix[0]==' ') || (infix[infix.size()-1]==' ')))
	{
		// check for two spaces together.
		for (size_t i = 0; i < (infix.size()-1); i++)
		{
			// if two consecutive terms are spaces then it is not a valid expression.
			if (infix[i]==' ' && infix[i+1]==' ')
			{
				return false;
			}
		}
	}
	// expression has spaces at beginning or ending or both.
	else
	{
		return false;
	}
	// counter to count left parenthesis.
	size_t left_count=0;
	// counter to count right parenthesis.
	size_t right_count=0;
	// check the count of left and right parenthesis over infix string.
	for (size_t i = 0; i < infix.size(); i++)
	{
		// if infix string contains left parenthesis then increment left_count.
		if (infix[i]=='(')
		{
			left_count++;
		}
		// if infix string contains right parenthesis then increment right_count.
		if (infix[i]==')')
		{
			right_count++;
			if (left_count<right_count || (i>=2 && infix[i-2]=='('))
			{
				return false;
			}
		}
	}
	// if the left and right parenthesis count are not equal then return false,
	// expression is invalid.
	if (left_count!=right_count)
	{
		return false;
	}
	// if all checks above are successful then return true.
	return true;
}