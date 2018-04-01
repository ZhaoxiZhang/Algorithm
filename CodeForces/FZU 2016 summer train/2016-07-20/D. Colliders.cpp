#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100005
bool is_prime[maxn]; //判断素数标记
bool visit[maxn];    //筛选访问标记
int prime[maxn];     //素数数组
bool active[maxn];   //激活标记
int tool[maxn][20];  //记录一个数的素因子数组
int count[maxn];     //将素数与对应的激活号关联

void select_prime () //筛选素数
{
	is_prime[0] = 0;
    is_prime[1] = 0;
    int cnt = 0;
    /*int x = sqrt(maxn);
    for (int i = 2;i <= x;i++)
    {
    	if (is_prime[i])
    	{
    		prime[cnt++] = i;
    		for (int j = i*i;j<=maxn;j+=i)
    		{
    			is_prime[j] = 0;
    		}
    	}
    }*/
    
    for ( int i = 2 ; i < maxn ; i ++ )
        if ( !visit[i] )
        {
            visit[i] = 1;
            if ( is_prime[i] )
            {
                prime[cnt++] = i;
                for ( int j = 2 * i ; j < maxn ; j += i )
                {
                    visit[j] = 1;
                    is_prime[j] = 0;
                }
            }
        }
}

void div_prime ( int n )  //拆分素因子
{
    int ths = 1; //其中0号下标存素因子个数
    for ( int i = 0 ; prime[i] <= n / 2 ; i ++ )
    {
		if ( n % prime[i] == 0 ) //每找到一个素数就存起来
            tool[n][ths++] = prime[i];
    }
    if ( is_prime[n] ) tool[n][ths++] = n;
    tool[n][0] = ths - 1;  //其中0号下标存素因子个数
}

void Active ( int num )  //激活操作
{
    if ( active[num] ) printf ( "Already on\n" );
    else
    {
        for ( int i = 1 ; i <= tool[num][0] ; i ++ ) //寻找冲突即自己的素因子出现在已经激活的
        {                       		     //合数或者素数中
			if ( count[tool[num][i]] != 0 ) 
            {
                printf ( "Conflict with %d\n" , count[tool[num][i]] );
                return ;
            }
        }
        active[num] = 1;
        for ( int i = 1 ; i <= tool[num][0] ; i ++ )
        {
        	count[tool[num][i]] = num;
        	//cout << tool[num][i] << " " << count[tool[num][i]] << endl;
        }
            
        printf ( "Success\n" );
    }
}

void Deactive ( int num )  //关闭激活操作
{
    if ( !active[num] ) printf ( "Already off\n" );
    else
    {
        active[num] = 0;
        for ( int i = 1 ; i <= tool[num][0] ; i ++ )
        {
        	count[tool[num][i]] = 0;
			//cout << tool[num][i] << " " << count[tool[num][i]] << endl;
        }
        printf ( "Success\n" );
    }
}

int main()
{
    int n,m,pos;
    char tmp;
    memset ( active , 0 , sizeof ( active ) );
    memset ( is_prime , 1 , sizeof ( is_prime )) ;  
    memset ( visit , 0 , sizeof ( visit ) );
    memset ( prime , 0 , sizeof ( prime ) );
    memset ( count , 0 , sizeof ( count ) );
    select_prime();
    scanf ( "%d %d" , &n , &m );
        for ( int i = 1 ; i <= n ; i ++ )
            div_prime ( i );
        /*for ( int i = 1 ; i <= n ; i ++ )
        {
            cout << i <<"的素因子有" << tool[i][0] << "个: ";
            for ( int j = 1 ; j <= tool[i][0] ; j ++ ) 
                cout << tool[i][j] <<  ' ';
            cout << endl;
        }*/
        while ( m-- )
        {
            getchar();
			scanf("%c %d",&tmp,&pos);
			if (tmp == '+')
			{
				Active(pos);
			}
			else if (tmp == '-')
			{
				Deactive(pos);
			}
        }
    return 0;
}
