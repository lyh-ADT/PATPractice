# 1002 Business (35 ?)

As the manager of your company, you have to carefully consider, for each project, the time taken to finish it, the deadline, and the profit you can gain, in order to decide if your group should take this project. For example, given 3 projects as the following:

- Project[1] takes 3 days, it must be finished in 3 days in order to gain 6 units of profit.
- Project[2] takes 2 days, it must be finished in 2 days in order to gain 3 units of profit.
- Project[3] takes 1 day only, it must be finished in 3 days in order to gain 4 units of profit.

You may take Project[1] to gain 6 units of profit. But if you take Project[2] first, then you will have 1 day left to complete Project[3] just in time, and hence gain 7 units of profit in total. Notice that once you decide to work on a project, you have to do it from beginning to the end without any interruption.
## Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤50), and then followed by N lines of projects, each contains three numbers P, L, and D where P is the profit, L the lasting days of the project, and D the deadline. It is guaranteed that L is never more than D, and all the numbers are non-negative integers.
## Output Specification:

For each test case, output in a line the maximum profit you can gain.
## Sample Input:
```
4
7 1 3
10 2 3
6 1 2
5 1 1
```
## Sample Output:
```
18
```
***
?????????                     
?[??1001](../1001_BattleOverCities/CorrectAnswer.cpp)?????????????????????                  
#### ??
i??????????j???????????(?)
```C++
if (j <= projects[i].deadline) {
    if (j - projects[i].lasting >= 0 &&
        dp[i - 1][j] < projects[i].profit + dp[i - 1][j - projects[i].lasting]) {
        dp[i][j] = projects[i].profit + dp[i - 1][j - projects[i].lasting];
    } else {
        dp[i][j] = dp[i - 1][j];
    }
}
```
?????????`dp[N][maxDeadline]`???????????????????`maxProfit`??????????