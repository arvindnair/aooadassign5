//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _RANDOM_GENERATOR_H_
#define _RANDOM_GENERATOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

/**
* @class Random_Generator
*
* Implementation of Random Generator.
*/
class Random_Generator
{
public:

	/// Default constructor.
	Random_Generator (void);

	/// Destructor.
	~Random_Generator (void);

	/**
	* It take the given output_file and generates the Type 1 expression as per
	* count vertically. Type 1: num op num op... (5 times) num
	* eg: 1 % 2 / 4 - 6 - 5 % 10
	* 
	* @param[in]       output_file                 Output file containing expressions.
	* @param[in]       count                       Number of expressions.
	*/
	void expr_type_1 (std::ofstream & output_file, int & count);

	/**
	* It take the given output_file and generates the Type 2 expression as per
	* count vertically. Type 1: o_par o_par num op num c_par op o_par num op num c_par c_par op num
	* eg: ( ( 8 * 1 ) - ( 7 + 3 ) ) * 9
	* 
	* @param[in]       output_file                 Output file containing expressions.
	* @param[in]       count                       Number of expressions.
	*/
	void expr_type_2 (std::ofstream & output_file, int & count);

	/**
	* It take the given output_file and generates the Type 3 expression as per
	* count vertically. Type 1: o_par num op num c_par op o_par o_par num op num c_par op o_par num op num c_par c_par
	* eg: ( 9 % 3 ) % ( ( 7 - 5 ) / ( 3 - 1 ) )
	* 
	* @param[in]       output_file                 Output file containing expressions.
	* @param[in]       count                       Number of expressions.
	*/
	void expr_type_3 (std::ofstream & output_file, int & count);

	/**
	* It take the given output_file and generates the Type 3 expression as per
	* count vertically. Type 1: num op o_par num op o_par num op o_par num op num c_par c_par c_par
	* eg: 5 % ( 1 - ( 3 / ( 2 / 1 ) ) )
	* 
	* @param[in]       output_file                 Output file containing expressions.
	* @param[in]       count                       Number of expressions.
	*/
	void expr_type_4 (std::ofstream & output_file, int & count);

	/**
	* It take the given output_file and generates the Type 1 expression as per
	* count vertically. Type 1: num aop num aop... (count times) num
	* eg: 1 + 8 - 2 - ... (count times) 7
	* 
	* @param[in]       output_file                 Output file containing expressions.
	* @param[in]       count                       Number of expressions.
	*/
	void expr_type_5 (std::ofstream & output_file, int & count);

	/**
	* Generates and returns a random number between 1 to 10.
	* 
	*/
	int random_number (void);

	/**
	* Generates and returns a left parenthesis character i.e., '('.
	* 
	*/
	char left_parenthesis (void);

	/**
	* Generates and returns a right parenthesis character i.e., ')'.
	* 
	*/
	char right_parenthesis (void);

	/**
	* Generates and returns a random operator from +,-,*,/ and %.
	* 
	*/
	char random_operator (void);

	/**
	* Generates and returns a random operator from + and -.
	* 
	*/
	char random_add_sub_operator (void);

	/**
	* Generates and returns a keyboard space character i.e., ' '.
	* 
	*/
	char space (void);

	/**
	* Writes a number randomly generated to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_number (std::ofstream & output_file);

	/**
	* Writes a space to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_space (std::ofstream & output_file);

	/**
	* Writes an operator randomly generated to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_operator (std::ofstream & output_file);

	/**
	* Writes an add or subtract operator randomly generated to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_add_sub_operator (std::ofstream & output_file);

	/**
	* Writes a left/open parenthesis to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_left_parenthesis (std::ofstream & output_file);

	/**
	* Writes a right/closed parenthesis to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_right_parenthesis (std::ofstream & output_file);

	/**
	* Writes a new line to output file.
	* 
	* @param[in]       output_file                 Output file containing expressions.
	*/
	void write_new_line (std::ofstream & output_file);

private:

};


#endif // !_RANDOM_GENERATOR_H_
