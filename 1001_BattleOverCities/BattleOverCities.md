# 1001 Battle Over Cities - Hard Version (35 分)
It is vitally important to have all the cities connected by highways in a war. If a city is conquered by the enemy, all the highways from/toward that city will be closed. **To keep the rest of the cities connected**, we must repair some highways with the minimum cost. On the other hand, if losing a city will cost us too much to rebuild the connection, we must pay more attention to that city.

Given the map of cities which have all the destroyed and remaining highways marked, you are supposed to point out the city to which we must pay the most attention.
## Input Specification:

Each input file contains one test case. Each case starts with a line containing 2 numbers N (≤500), and M, which are the total number of cities, and the number of highways, respectively. Then M lines follow, each describes a highway by 4 integers: City1 City2 Cost Status where City1 and City2 are the numbers of the cities the highway connects (the cities are numbered from 1 to N), Cost is the effort taken to repair that highway if necessary, and Status is either 0, meaning that highway is destroyed, or 1, meaning that highway is in use.

Note: **It is guaranteed that the whole country was connected before the war**.
## Output Specification:

For each test case, just print in a line the city we must protest the most, that is, it will take us the maximum effort to rebuild the connection if that city is conquered by the enemy.

In case there is more than one city to be printed, output them in increasing order of the city numbers, separated by one space, but no extra space at the end of the line. In case there is no need to repair any highway at all, simply output 0.
## Sample Input 1:
```
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 1 0
```
## Sample Output 1:
```
1 2
```
## Sample Input 2:
```
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 2 1
```
## Sample Output 2:
```
0
```
***
目标是保证未被占领城市的连通                            
由于只要保证城市的连通，不需要考虑连通的方式，可以把连通的城市看作集合，所以用并查集的方式                                           

自己写的[Submit.cpp](./Submit.cpp)因为看上去是个图论的题目，所以把所有的边都用邻接矩阵来存放，导致后面遍历很麻烦最后测试点3答案错误，测试点4超时了

> 总体的思路就是从1开始遍历所有的城市，假设该城市被占领，在排除所有和该城市相连的路径之后，检查存在多少个集合，只有一个表示剩下的城市是连通的，花费是0；否则遍历集合中的城市找到需要修复且花费最小的边来合并集合

全过的解法[CorrectAnswer.cpp](./CorrectAnswer.cpp)也是用并查集，但是他没用邻接矩阵，而是定义一个结构体，把边存起来，让边的遍历方便很多，减少了大量时间复杂度，同时把未破环的边放在前面，在合并集合的时候优先使用未被破环的边
