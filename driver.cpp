//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "Postfix_Flyweight_Evaluator_Strategy.h"
#include "Tree_Evaluator_Strategy.h"
#include "Expr_Evaluator_Strategy.h"
#include "Postfix_Flyweight_Evaluator_Performance_Strategy.h"
#include "Tree_Evaluator_Performance_Strategy.h"
#include "Postfix_Evaluator_Strategy.h"

/**
* Chooses and returns a strategy as per user choice.
* 
* @param[in]       choice                 Choice of strategy.
* @return          Particular strategy chosen.
*/
Expr_Evaluator_Strategy * choose (int & choice);

/**
* Used to extract and assign the strategy, input file and timing file from command line arguments.
* 
* @param[in]       argc                    Command line arguments count.
* @param[in]       argv                    Command line arguments array.
* @param[in]       strategy                Strategy number stored after conversion
* @param[in]       input_file              Input file name/path stored.
* @param[in]       timing_file             Timing file name/path stored.
* @retval          true                    Passed string is a number.
* @retval          false                   Passed string is not a number.
*/
bool cmd_args (int & argc, char * argv[], int & strategy, std::string & input_file, std::string & timing_file);

/**
* Checks if the strategy is a number.
* 
* @param[in]       string_strategy         Strategy in string format from command line arguments. 
* @param[in]       strategy                Strategy number stored after conversion
* @retval          true                    Passed string is a number.
* @retval          false                   Passed string is not a number.
*/
bool is_number (const std::string & string_strategy, int & strategy);

/**
* Used to display help menu.
* 
*/
void help();

int main (int argc, char* argv [])
{
	// when --help or -h is entered display help menu.
	if (argc==2)
	{
		std::string help_str=argv[1];
		if (help_str=="--help" || help_str=="--h")
		{
			help();
		}
		else
		{
			std::cout<<"Run with --help or --h for help menu."<<std::endl;
		}
	}
	// proceed further if command line arguments match.
	else if (argc==4)
	{
		std::string quit_msg="QUIT";
		// variable for strategy to be used.
		int strategy;
		// variable for input file.
		std::string input_file;
		// variable for timing file.
		std::string timing_file;
		// base class pointer for strategy pattern.
		Expr_Evaluator_Strategy * impltemp=0;
		if (cmd_args(argc,argv,strategy,input_file,timing_file))
		{
			std::ofstream output_file(timing_file);
			std::ifstream input_file_read(input_file);
			if (input_file_read.is_open())
			{
				std::string exp;
				clock_t start = clock();
				while (std::getline(input_file_read,exp))
				{
					// assign a strategy as per user choice.
					Expr_Evaluator_Strategy * impl=choose(strategy);
					// using try catch
					try
					{
						// if expression entered is QUIT then exit the program.
						if (exp==quit_msg)
						{
							impltemp=impl;
							break;
						}
						// calculate and output the result using the particular strategy.
						int result=impl->calculator(exp);
						std::cout<<result<<std::endl;
					}
					catch(std::exception& e)
					{
						std::cout<<e.what()<<std::endl;
					}
					delete impl;
				}
				// when quit is encountered.
				delete impltemp;
				clock_t end = clock();
				// timing calculation.
				double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				output_file<<"Total Execution Time is: "<<time<<std::endl;
				// closing both files after use.
				input_file_read.close();
				output_file.close();
			}
			// if file cannot be opened indicate the same.
			else
			{
				std::cout<<"Cannot Open File specified"<<std::endl;
				std::cout<<"Run with --help or --h for help menu."<<std::endl;
			}
		}
	}
	// for handling invalid command line arguments.
	else
	{
		std::cout<<"Run with --help or --h for help menu."<<std::endl;
	}
	return 0;
}

//
// choose (int &)
//
// choose and return a strategy as per the given choice.
Expr_Evaluator_Strategy * choose (int & choice)
{
	if (choice==1)
	{
		return new Postfix_Evaluator_Strategy();
	}
	else if (choice==2)
	{
		return new Postfix_Flyweight_Evaluator_Strategy();
	}
	else if (choice==3)
	{
		return new Postfix_Flyweight_Evaluator_Performance_Strategy();
	}
	else if (choice==4)
	{
		return new Tree_Evaluator_Strategy();
	}
	// choice 5
	else
	{
		return new Tree_Evaluator_Performance_Strategy();
	}
}

//
// cmd_args (int &, char *, int &, std::string &, std::string &)
//
bool cmd_args (int & argc, char * argv[], int & strategy, std::string & input_file, std::string & timing_file)
{
	std::string arg_strategy=argv[1];
	std::string arg_input_file=argv[2];
	std::string arg_timing_file=argv[3];
	// extract the user choices from command line arguments using string functions.
	std::string check_arg_strategy=arg_strategy.substr(0,11);
	std::string check_arg_input_file=arg_input_file.substr(0,12);
	std::string check_arg_timing_file=arg_timing_file.substr(0,13);
	// If invalid command line arguments then display the error and return false.
	if ((check_arg_strategy!="--strategy=" || arg_strategy.length()<12) || (check_arg_input_file!="--inputfile=" || arg_input_file.length()<13) || (check_arg_timing_file!="--timingfile=" || arg_timing_file.length()<14))
	{
		std::cout<<"Invalid Command Line Arguments"<<std::endl;
		std::cout<<"Run with --help or --h for help menu."<<std::endl;
		return false;
	}
	std::string string_strategy=arg_strategy.substr(11,12);
	// if strategy is a number proceed further
	if (is_number(string_strategy,strategy))
	{
		// check if strategy is between 1 to 5.
		if (strategy<1 || strategy>5)
		{
			std::cout<<"Invalid Choice of Strategy"<<std::endl;
			std::cout<<"Run with --help or --h for help menu."<<std::endl;
			return false;
		}
		input_file=arg_input_file.substr(12,arg_input_file.length()-2);
		timing_file=arg_timing_file.substr(13,arg_timing_file.length()-2);
		return true;
	}
	// strategy is not a number.
	else
	{
		std::cout<<"Enter an integer from 1 to 5. Invalid Choice of Strategy."<<std::endl;
		std::cout<<"Run with --help or --h for help menu."<<std::endl;
		return false;
	}
}

//
// is_number (const std::string &, int &)
//
bool is_number (const std::string & string_strategy, int & strategy)
{
	// make num_temp_1 contain token in istringstream format.
	std::istringstream num_temp_1(string_strategy);
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
		if(str==string_strategy)
		{
			// store the number in strategy.
			strategy = atoi(string_strategy.c_str());
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

//
// help
//
// displays help menu
void help()
{
	std::cout<<"----------------------------------------------------------------------------"<<std::endl;
	std::cout<<"----------------------------------------------------------------------------"<<std::endl;
	std::cout<<"     Calculator Program Using Strategy Pattern                              "<<std::endl;
	std::cout<<"     _________________________________________                              "<<std::endl;
	std::cout<<"                                                                            "<<std::endl;
	std::cout<<"                    Help Menu                                               "<<std::endl;
	std::cout<<"                    _________                                               "<<std::endl;
	std::cout<<"                                                                            "<<std::endl;
	std::cout<<"Command       |     Value        |   Description                            "<<std::endl;
	std::cout<<"_______       |     ______       |   ____________                           "<<std::endl;
	std::cout<<"              |                  |                                          "<<std::endl;
	std::cout<<"--strategy=   |     1            |   Postfix Strategy.                      "<<std::endl;
	std::cout<<"--strategy=   |     2            |   Postfix Flyweight Strategy.            "<<std::endl;
	std::cout<<"--strategy=   |     3            |   Postfix Flyweight Performance Strategy."<<std::endl;
	std::cout<<"--strategy=   |     4            |   Tree Strategy.                         "<<std::endl;
	std::cout<<"--strategy=   |     5            |   Tree Performance Strategy.             "<<std::endl;
	std::cout<<"              |                  |                                          "<<std::endl;
	std::cout<<"--inputfile=  |     Name/Path of |   File to be specified for inputs.       "<<std::endl;
	std::cout<<"              |     input file.  |                                          "<<std::endl;
	std::cout<<"              |                  |                                          "<<std::endl;
	std::cout<<"--timingfile= |     Name/Path of |   File to be specified for timing.       "<<std::endl;
	std::cout<<"              |     timing file. |                                          "<<std::endl;
	std::cout<<"              |                  |                                          "<<std::endl;
	std::cout<<"--help or -h  |     Help Menu    |   This menu for help & reference.        "<<std::endl;
	std::cout<<"----------------------------------------------------------------------------"<<std::endl;
	std::cout<<"                                                                            "<<std::endl;
	std::cout<<"                                   Usage                                    "<<std::endl;
	std::cout<<"                                   ______                                   "<<std::endl;
	std::cout<<"                                                                            "<<std::endl;
	std::cout<<"Run the program as: (An Example)                                            "<<std::endl;
	std::cout<<"./assignment5 --strategy=\"1\" --inputfile=\"test.txt\" --timingfile=\"time.txt\""<<std::endl;
	std::cout<<"where assignment5 is the program name,\nstrategy is 1, which is Postfix strategy,";
	std::cout<<"\ninput file containing expressions to be evaluated which is test.txt is in same directory of assignment5";
	std::cout<<"\nand timing file to be created which is time.txt is in same directory as that of assignment5"<<std::endl;
	std::cout<<"                                                                              "<<std::endl;
	std::cout<<"------------------------------------------------------------------------------"<<std::endl;
	std::cout<<"------------------------------------------------------------------------------"<<std::endl;
}