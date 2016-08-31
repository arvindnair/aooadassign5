//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include "Random_Generator.h"

int main()
{
	// using srand to use system time for bias.
	srand((unsigned int)time(0));
	// Taking the file name/path as input from user.
	std::cout<<"Enter the file name: "<<std::endl;
	std::string file_name;
	std::getline(std::cin,file_name);
	std::string file_path=file_name;
	std::ofstream output_file(file_path);
	// Asking for expression type to be entered.
	std::cout<<"Enter the type of Expression to be generated: "<<std::endl;
	int choice;
	std::cin>>choice;
	int vertical_count;
	int horizontal_count;
	// There are 5 choices of expressions.
	if (choice>0 && choice<6)
	{
		// If choices are between 1 to 4 then the expressions are vertical.
		if (choice<5)
		{
			std::cout<<"Enter the number of expressions to be generated vertically: "<<std::endl;
			std::cin>>vertical_count;
		}
		// If choice is 5 then expression is horizontal.
		else
		{
			std::cout<<"Enter the number of operands and operators to be generated horizontally: "<<std::endl;
			std::cin>>horizontal_count;
		}
		// Variable for random generator.
		Random_Generator t;
		// Using switch case for appropriate choices.
		switch (choice)
		{
		case 1:
			t.expr_type_1(output_file,vertical_count);
			break;
		case 2:
			t.expr_type_2(output_file,vertical_count);
			break;
		case 3:
			t.expr_type_3(output_file,vertical_count);
			break;
		case 4:
			t.expr_type_4(output_file,vertical_count);
			break;
		case 5:
			t.expr_type_5(output_file,horizontal_count);
			break;
		default:
			break;
		}
		// write a line QUIT to exit expression.
		output_file<<"QUIT";
		output_file.close();
	}
	// If choice is not between 1 to 5 then it its an invalid choice.
	else
	{
		std::cout<<"Invalid Choice!"<<std::endl;
	}
	return 0;
}
