#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char people[3][3]= {'.','O','.','/','|','\\','(','.',')'}; //储存人的姿势
char mp[105][105];
bool vis[105][105];
int n,m;
int judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||vis[x][y])return 0;
    return 1;
}
void search_p(int i,int j)
{
    vis[i][j]=1;
    if(mp[i][j]=='O') //如果访问到了一个没有访问过的头，就根据相对位置访问该人的其他位置。
    {
        if(judge(i+1,j-1)&&mp[i+1][j-1]=='/')vis[i+1][j-1]=1;
        if(judge(i+1,j)&&mp[i+1][j]=='|')vis[i+1][j]=1;
        if(judge(i+1,j+1)&&mp[i+1][j+1]=='\\')vis[i+1][j+1]=1;
        if(judge(i+2,j-1)&&mp[i+2][j-1]=='(')vis[i+2][j-1]=1;
        if(judge(i+2,j+1)&&mp[i+2][j+1]==')')vis[i+2][j+1]=1;
    }
    if(mp[i][j]=='/')
    {
        if(judge(i,j+1)&&mp[i][j+1]=='|')vis[i][j+1]=1;
        if(judge(i,j+2)&&mp[i][j+2]=='\\')vis[i][j+2]=1;
        if(judge(i-1,j+1)&&mp[i-1][j+1]=='O')vis[i-1][j+1]=1;
        if(judge(i+1,j)&&mp[i+1][j]=='(')vis[i+1][j]=1;
        if(judge(i+1,j+2)&&mp[i+1][j+2]==')')vis[i+1][j+2]=1;
    }
    if(mp[i][j]=='|')
    {
        if(judge(i-1,j)&&mp[i-1][j]=='O')vis[i-1][j]=1;
        if(judge(i,j+1)&&mp[i][j+1]=='\\')vis[i][j+1]=1;
        if(judge(i,j-1)&&mp[i][j-1]=='/')vis[i][j-1]=1;
        if(judge(i+1,j-1)&&mp[i+1][j-1]=='(')vis[i+1][j-1]=1;
        if(judge(i+1,j+1)&&mp[i+1][j+1]==')')vis[i+1][j+1]=1;
    }
    if(mp[i][j]=='\\')
    {
        if(judge(i,j-1)&&mp[i][j-1]=='|')vis[i][j-1]=1;
        if(judge(i,j-2)&&mp[i][j-2]=='/')vis[i][j-2]=1;
        if(judge(i-1,j-1)&&mp[i-1][j-1]=='O')vis[i-1][j-1]=1;
        if(judge(i+1,j)&&mp[i+1][j]==')')vis[i+1][j]=1;
        if(judge(i+1,j-2)&&mp[i+1][j-2]=='(')vis[i+1][j-2] =1;
    }
    if(mp[i][j]=='(')
    {
        if(judge(i-1,j+1)&&mp[i-1][j+1]=='|')vis[i-1][j+1]=1;
        if(judge(i,j+2)&&mp[i][j+2]==')')vis[i][j+2]=1;
        if(judge(i-1,j)&&mp[i-1][j]=='/')vis[i-1][j]=1;
        if(judge(i-1,j+2)&&mp[i+1][j]=='\\')vis[i-1][j+2]=1;
        if(judge(i-2,j+1)&&mp[i-2][j+1]==')')vis[i-2][j+1]=1;
    }
    if(mp[i][j]==')')
    {
        if(judge(i-1,j-1)&&mp[i-1][j+1]=='|')vis[i-1][j-1]=1;
        if(judge(i,j-2)&&mp[i][j+2]=='(')vis[i][j-2]=1;
        if(judge(i-1,j)&&mp[i-1][j]=='\\')vis[i-1][j]=1;
        if(judge(i-1,j-2)&&mp[i+1][j]=='/')vis[i-1][j-2]=1;
        if(judge(i-2,j-1)&&mp[i-2][j-1]==')')vis[i-2][j-1]=1;
    }
}
int main()
{
    int cases,i,j,cnt;
    cin>>cases;
    while(cases--)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        cin>>n>>m;
        for(i=0; i<n; i++)
            scanf("%s",mp[i]);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(!vis[i][j]&&mp[i][j]!='.') //如果找到一个没有访问过的人的身体部位，计数器加1
                {
                    cnt++;
                    search_p(i,j);//寻找该人身体其他部位并且标记出来
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

