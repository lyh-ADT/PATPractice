#include<bits/stdc++.h>
using namespace std;
#define MAX 300000
#define INF 0x7fffffff
int root[505],costs[505];
struct route{
    int c1,c2,cost,status;
    void read(){scanf("%d%d%d%d",&c1,&c2,&cost,&status);}
    //重载小于，好的路径在前，cost递增
    bool operator <(const route& r){return r.status==status?cost<r.cost:status>r.status;}
}rou[MAX];
 
int getroot(int n)  //返回集合的根结点,并将路径上节点的父亲节点修改为根节点。
{
    return root[n]==n?n:root[n]=getroot(root[n]);
}
 
int main()
{
    //freopen("test.txt","r",stdin);
    int N,M,i,j,num;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;++i)rou[i].read();
    sort(rou,rou+M);
    int ans=0;
    for(i=1;i<=N;++i){
        for(j=1;j<=N;++j)root[j]=j;
        costs[i]=0;num=N-2;//M-2条路
        for(j=0;j<M;++j){
            if(rou[j].c1==i||rou[j].c2==i)continue;//不计连接该点的所有路径
            int r1=getroot(rou[j].c1),r2=getroot(rou[j].c2);
            if(r1==r2)continue;//已经属于一个集合
            --num;  //集合个数减一
            root[r2]=r1;//合并两个集合
            if(!rou[j].status)costs[i]+=rou[j].cost;
        }
        if(num>0)costs[i]=INF;
        ans=max(ans,costs[i]);
    }
    if(ans){
        bool flag=0;
        for(i=1;i<=N;++i){
            if(costs[i]==ans){
                printf("%s%d",flag?" ":"",i);
                flag=1;
            }
        }
        return 0;
    }
    printf("0");
    return 0;
}