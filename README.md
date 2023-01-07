# Find-And-Replace

## Program Description
This is a program in C that performs find and replace functionality on a given input file. The program produces an output file that duplicates the input file, but with every instance of the _find_ text with the _replacement_ text.

For example, if our input file looks like this:

`This is the first test.`

`This input file contains these three lines.`

`Here is the third line.`

If we replace the word "the" with the word "horse" then, the output should look like this:

`This is horse first test.`

`This input file contains horsese three lines.`

`Here is horse third line.`

## Running the Program
When using a Windows system, the program should be run with the following statement:
> `type fileIn.txt | ./a.exe find replace > fileOut.txt`

When using a Linux/Unix/Mac system, your program should run with the statement:
> `cat fileIn.txt | ./a.out find replace > fileOut.txt`

Here, _fileIn.txt_ is the input file, _fileOut.txt_ is the output file, and the program should produce a _fileOut.txt_ identical to _fileIn.txt_ but every instance of _find_ replaced with _replace_.

## Program Structure
In addition to the main method, the program contains functions for:
* returning the length of a string
* searching for a substring within a bigger string and returning the starting position of the substring
* string concatenation

It is important to note that `stdio.h` was the only library included for this program.
