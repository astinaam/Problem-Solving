# Problem-Solving
Problem solving in different online judges. Testing scripts are written in bash.
### Testing means compiling and running a code with test cases given automatically.
### Language : C++
# Contest Creating and Testing
* `Keep contest.sh, test.sh, cr.sh, compile.sh, run.sh, template.cpp and genp.sh scripts in same directory.`
* `Create contest by running contest.sh with two arguments. First argument is the contest name without space and second argument is the number of problems (max = 12) you want to create. Then problems will be created automatically like A,B,C,D... with the template.cpp file's content in them and five input and output files will be created for each problem.`  
`Example of the command : ./contest.sh contest_name numberof_problems`
* `Then go to contest directory and you can test a individual problem by test.sh script, run it by run.sh, compile and run using cr.sh, compile using compile.sh.`  
`Example of commands: `  
`./test.sh problem_name number_of_testcases like ./test.sh A 2`  
`./compile.sh problem_name`  
`./run.sh problem_name`  
`./cr.sh problem_name`  
* `You need to put test cases in the files for corresponding problems.`
* `Make sure all the scripts are executable.`

# Problem Creating and Testing
* `Keep test.sh, cr.sh, compile.sh, run.sh, template.cpp and genp.sh scripts in same directory.`
* `Create a problem using command ./genp.sh P X`  
-- `Here, P is the problem name without space and X is the number of test cases.`
* `You can now test, compile and run the code from the directory as described above.`


## Thank You.
