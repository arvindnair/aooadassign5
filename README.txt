======================================================================================================================================================================
							********README for ASSIGNMENT 5 (STRATEGY PATTERN)********
======================================================================================================================================================================
***Steps to run Assignment 5:
1. After downloading the folder containing the files, be in the directory where the assignment5.mpc file is present.
2. For Windows, run the command
 mwc.pl -type vc11
in that directory which will generate the Visual Studio solution file (for VS 2012).
3. For Linux, run the following commands,
3.1 mwc.pl -type make -features cpp11=1
3.2 make 
3.3 valgrind --leak-check=full ./assignment5 --strategy="1" --inputfile="/home/arvnair/a5tester/cs507-spring2015assignment5/inputs/Type1/type_1_500.txt" --timingfile="time_type_1_500.txt"
The first command is required for cpp11, the second one does the compiling and the third one will check for memory leaks using Valgrind.
4. The program is run using command line arguments.
./assignment5 will run the program
--strategy="1" specifies the option 1 which uses strategy 1.
--inputfile="/home/arvnair/a5tester/cs507-spring2015-assignment5/inputs/Type1/type_1_500.txt" specifies the file path of the input file.
--timingfile="time_type_1_500.txt" specifies the file name of the timing file for that particular type and number of expressions. You can also specify file path to store timings for particular expressions.
5. I have used 5 strategies. They are specifies to run using a number as follows:
1=Postfix Strategy
2=Postfix Flyweight Strategy
3=Postfix Flyweight Performance Strategy
4=Tree Strategy
5=Tree Performance Strategy
6. For input file specify the path properly. In windows, if the file (type1.txt) is stored on desktop specify path as C:\\Desktop\\type1.txt
on Linux, if stored on your home directory, specify as /home/type1.txt
7. For timing file specify the path properly. In windows, if the file (time1.txt) is stored on desktop specify path as C:\\Desktop\\time1.txt
on Linux, if stored on your home directory, specify as /home/time1.txt
8. Additionally, you can run the program with --help or --h for help menu. For help menu, run as ./assignment5 --help or ./assignment5 --h

======================================================================================================================================================================

***Folder Structure:
1. The folder from git contains 4 sub folders and files.
2. The files are those for the strategy pattern which is the main program of the assignment 5. It contains assignment5.mpc
3. The inputs folder contains sub folders called Type1, Type2,...,Type5. Each of these folders contain text files of expressions as per the types.
type_1_500 i.e., it contains 500 expressions of Type1, type_2_1000 i.e., it contains 1000 expressions of Type2 and so on. The expression types are explained as below:
Type 1: Num Op Num Op Num Op Num Op Num Op Num
Type 2: O_Par O_Par Num Op Num C_Par Op O_Par Num Op Num C_Par C_Par Op Num
Type 3: O_Par Num Op Num C_Par Op O_Par O_Par Num Op Num C_Par Op O_Par Num Op Num C_Par C_Par
Type 4: Num Op O_Par Num Op O_Par Num Op O_Par Num Op Num C_Par C_Par C_Par
Type 5: Num AOp Num AOp …. N times Num
Each of the type of expressions have 500, 1000, 1500, 2000 & 2500 expressions. Expression types 1-4 have vertically 500-2500 expressions and type 5 has Num AOp Num AOp…..500-2500 times horizontally in one line.
Num=number, O_Par=Open/Left Parenthesis, C_Par=Closed/Right Parenthesis, Op=Operator and AOp=Add and Subtract Operators (‘+’ and ‘-‘).
4. The random_expr_generator folder contains the random.mpc file. Steps 2 and 3, 3.1 and 3.2 are to be followed to generate the solution file or the makefile. For running on valgrind use valgrind --leak-check=full ./random and it will ask for the file path where you have to specify the file path described as before. It will also ask for type of expressions to be generated where 1 to 5 will give expression types from 1 to 5. eg: If you enter 1 it will ask how many expressions (of Type 1) and will generate into the file. If suppose you want 1000 expressions of type 3 then run the program and it will ask for file name/path which you will give and then it will ask for type of expression where you have to enter 3 and finally it will ask for number of expressions where you have to enter 1000. The file will be created with the specified expressions.
5. The timings folder contains the timings for each type arranged accordingly as Type1timing, Type2timing,..., Type5timing. Inside each of these folders there are sub folders named as in Type1timing:type_1_s_1_timing, type_1_s_2_timing,...,type_1_s_5_timing,  Type2timing:type_2_s_1_timing, type_2_s_2_timing,... and so on. In each of the folders, there are timings for all numbers of expressions from 500 to 2500. So, if you want type 2 strategy 4 timing for 1500 expressions, go into Type2timing folder and then into type_2_s_4_timing and then select type_2_s_4_1500_timing.txt
6. The valgrind_reports folder contains the valgrind reports for all the input files. They are also arranged similar to the timing files. So, if you want type 3 strategy 2 timing for 2000 expressions, go into Type3_valgrind_report folder and then into Type_3_s _2_valgrind_report and then select type_3_s_2_2000_valgrind-report.out

======================================================================================================================================================================

***Note:
1. I have taken out the timings using assignment5.exe on windows from command line. So, the program was run as 
start /d "C:\Users\Arvind Nair\Desktop\strategy\" assignment5.exe --strategy="1" --inputfile="C:\Users\Arvind Nair\Desktop\strategy\inputs\Type1\type_1_500.txt" --timingfile="C:\Users\Arvind Nair\Desktop\strategy\timings\Type1timing\type_1_s_1_timing\type_1_500_timing.txt"
where assignment5.exe was in strategy folder on my Desktop, the strategy type was Postfix, the input file was taken from inputs folder type1 500 expressions and the timing file generated was stored in timings folder, Type1timing sub folder, inside that type_1_s_1_timing folder as type_1_500_timing.txt
2. Valgrind Reports were taken out on pegasus and named accordingly.
3. All timings are taken in milliseconds (ms).
4. Cpp11 must be installed to run the Expression Evaluator and the Random Generator.
5. My laptop/PC specs are as follows:
Processor: Intel(R) Core(TM) i7-4500U CPU @ 1.80GHz 2.40GHz
Installed memory (RAM): 8.00GB (7.72 GB usable)
System type: 64-bit Operating System,x64-based processor.
