// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Random_Generator.h"

//
// Random_Generator
//
// using srand to remove bias.
Random_Generator::Random_Generator (void)
{
	srand((unsigned int)time(0));
}

//
// ~Random_Generator
//
Random_Generator::~Random_Generator (void)
{
}

//
// expr_type_1(std::ofstream &, int &)
//
void Random_Generator::expr_type_1 (std::ofstream & output_file, int & count)
{

	for (int i = 0; i < count; i++)
	{
		// loop for num op (5 times)
		for (int i = 0; i < 5; i++)
		{
			write_number(output_file);
			write_space(output_file);
			write_operator(output_file);
			write_space(output_file);
		}
		write_number(output_file);
		write_new_line(output_file);
	}

}

//
// expr_type_2(std::ofstream &, int &)
//
void Random_Generator::expr_type_2 (std::ofstream & output_file, int & count)
{
	for (int i = 0; i < count; i++)
	{
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_number(output_file);
		write_new_line(output_file);
	}
}

//
// expr_type_3(std::ofstream &, int &)
//
void Random_Generator::expr_type_3 (std::ofstream & output_file, int & count)
{
	for (int i = 0; i < count; i++)
	{
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_left_parenthesis(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_operator(output_file);
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_new_line(output_file);
	}
}

//
// expr_type_5(std::ofstream &, int &)
//
void Random_Generator::expr_type_4 (std::ofstream & output_file, int & count)
{
	for (int i = 0; i < count; i++)
	{
		write_number(output_file);
		write_space(output_file);
		write_operator(output_file);
		// loop for o_par num op (3 times)
		for (int i = 0; i < 3; i++)
		{
			write_space(output_file);
			write_left_parenthesis(output_file);
			write_space(output_file);
			write_number(output_file);
			write_space(output_file);
			write_operator(output_file);
		}
		write_space(output_file);
		write_number(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_space(output_file);
		write_right_parenthesis(output_file);
		write_new_line(output_file);
	}
}

//
// expr_type_5(std::ofstream &, int &)
//
void Random_Generator::expr_type_5 (std::ofstream & output_file, int & count)
{
	// loop for horizontal num op (count times) format.
	for (int i = 0; i < (count-1)/2; i++)
	{
		write_number(output_file);
		write_space(output_file);
		write_add_sub_operator(output_file);
		write_space(output_file);
	}
	write_number(output_file);
	write_new_line(output_file);
}

//
// random_number
//
int Random_Generator::random_number (void)
{
	// modulus of 10 + 1 for numbers from 1 to 10.
	int s=rand()%10+1;
	return s;
}

//
// left_parenthesis
//
char Random_Generator::left_parenthesis (void)
{
	return '(';
}

//
// right_parenthesis
//
char Random_Generator::right_parenthesis (void)
{
	return ')';
}

//
// space
//
char Random_Generator::space (void)
{
	return ' ';
}

//
// random_operator
//
char Random_Generator::random_operator (void)
{
	// select a random number from 1 to 5.
	int s=rand()%5;
	// as per the number return an operator.
	if (s==0)
	{
		return '+';
	}
	else if (s==1)
	{
		return '-';
	}
	else if (s==2)
	{
		return '*';
	}
	else if (s==3)
	{
		return '/';
	}
	else
	{
		return '%';
	}
}

//
// random_add_sub_operator
//
char Random_Generator::random_add_sub_operator (void)
{
	// select a number randomly between 1 and 2.
	int s=rand()%2+1;
	// As per the number select the operator.
	if (s==1)
	{
		return '+';
	}
	else
	{
		return '-';
	}
}

//
// write_number(std::ofstream &)
//
void Random_Generator::write_number (std::ofstream & output_file)
{
	int i=random_number();
	output_file<<i;
}

//
// write_space(std::ofstream &)
//
void Random_Generator::write_space (std::ofstream & output_file)
{
	char c=space();
	output_file<<c;
}

//
// write_operator(std::ofstream &)
//
void Random_Generator::write_operator (std::ofstream & output_file)
{
	char c=random_operator();
	output_file<<c;
}

//
// write_add_sub_operator(std::ofstream &)
//
void Random_Generator::write_add_sub_operator (std::ofstream & output_file)
{
	char c=random_add_sub_operator();
	output_file<<c;
}

//
// write_left_parenthesis(std::ofstream &)
//
void Random_Generator::write_left_parenthesis (std::ofstream & output_file)
{
	char c=left_parenthesis();
	output_file<<c;
}

//
// write_right_parenthesis(std::ofstream &)
//
void Random_Generator::write_right_parenthesis (std::ofstream & output_file)
{
	char c=right_parenthesis();
	output_file<<c;
}

//
// write_new_line(std::ofstream &)
//
void Random_Generator::write_new_line (std::ofstream & output_file)
{
	output_file<<std::endl;
}