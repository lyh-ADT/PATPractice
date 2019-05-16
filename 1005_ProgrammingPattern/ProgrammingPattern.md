# 1005 Programming Pattern (35 分)

Programmers often have a preference among program constructs. For example, some may prefer if(0==a), while others may prefer if(!a). Analyzing such patterns can help to narrow down a programmer's identity, which is useful for detecting plagiarism.

Now given some text sampled from someone's program, can you find the person's most commonly used pattern of a specific length?
## Input Specification:

Each input file contains one test case. For each case, there is one line consisting of the pattern length N (1≤N≤1048576), followed by one line no less than N and no more than 1048576 characters in length, terminated by a carriage return \n. The entire input is case sensitive.
## Output Specification:

For each test case, print in one line the length-N substring that occurs most frequently in the input, followed by a space and the number of times it has occurred in the input. If there are multiple such substrings, print the lexicographically smallest one.

Whitespace characters in the input should be printed as they are. Also note that there may be multiple occurrences of the same substring overlapping each other.
## Sample Input 1:
```
4
//A can can can a can.
```
## Sample Output 1:
```
 can 4
```
## Sample Input 2:
```
3
int a=~~~~~~~~~~~~~~~~~~~~~0;
```
## Sample Output 2:
```
~~~ 19
```
