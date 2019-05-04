# 1003 Universal Travel Sites (35 分)

After finishing her tour around the Earth, CYLL is now planning a universal travel sites development project. After a careful investigation, she has a list of capacities of all the satellite transportation stations in hand. To estimate a budget, she must know the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.
## Input Specification:

Each input file contains one test case. For each case, the first line contains the names of the source and the destination planets, and a positive integer N (≤500). Then N lines follow, each in the format: source[i] destination[i] capacity[i] where source[i] and destination[i] are the names of the satellites and the two involved planets, and capacity[i] > 0 is the maximum number of passengers that can be transported at one pass from source[i] to destination[i]. Each name is a string of 3 uppercase characters chosen from {A-Z}, e.g., ZJU.

Note that the satellite transportation stations have no accommodation facilities for the passengers. Therefore none of the passengers can stay. Such a station will not allow arrivals of space vessels that contain more than its own capacity. It is guaranteed that the list contains neither the routes to the source planet nor that from the destination planet.
## Output Specification:

For each test case, just print in one line the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.

## Sample Input:
```
EAR MAR 11
EAR AAA 300
EAR BBB 400
AAA BBB 100
AAA CCC 400
AAA MAR 300
BBB DDD 400
AAA DDD 400
DDD AAA 100
CCC MAR 400
DDD CCC 200
DDD MAR 300
```
## Sample Output:
```
700
```
***
最大流问题，第一次遇到                                     
用`Edmonds-Karp算法`                                            
#### int main()
主要负责处理输入数据                              
用`map<string, int> namesId`把星球对应在`vector<vector<int>> edges`中的下标存起来                             
`edges`中存的是有向有权的邻接矩阵，也就是行下标代表的是出度的节点，列下标代表的是入度的节点，交换两个下标得到的是反向边

#### int maxFluence(vector<vector<int>>& edges, int const& planets_n, int st, int en)
负责`Edmonds-Karp算法`中找到增广路之后，在把路上每一段的容量减少delta的同时，也把每一段上的反方向的容量增加delta                            
`vector<int> flue`中存放的就是当前找到的增广路经过的节点，没有经过的节点的值为`-1`，走过的节点对应的下标位置上存储的是上一个节点的下标

最后返回答案

#### int fluenceBFS(vector<vector<int>> &edges, int const& planets_n, vector<int>& flue, int st, int en)

负责`Edmonds-Karp算法`的BFS，把路径存到传入的`flue`中                                 
`vector<int> f`存的是当前这个节点能通过的最大流量

最后返回这条路径的流量


