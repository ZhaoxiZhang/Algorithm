#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef __int64 LL;
struct Node
{
    LL cnt,val;
    bool flag;
    Node():cnt(0),val(0),flag(false) {}
};
bool cmp(Node x,Node y)
{
    return x.val > y.val;
}


int main()
{
    LL N,tmp,maxx = 0,sum = 0;
    bool Isz = false;
    Node num[15];
    scanf("%I64d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%I64d",&tmp);
        sum += tmp;
        num[tmp].val = tmp;
        num[tmp].cnt++;
        num[tmp].flag = true;
        if (tmp > maxx)
        {
            maxx = tmp;
        }
        if (tmp == 0)
        {
            Isz = true;
        }
    }
    if (!Isz)
    {
        printf("-1\n");
    }
    else
    {
        if (sum % 3 == 0)
        {
            if (num[maxx].val == 0)
            {
                printf("0\n");
            }
            else
            {
                for (int i = maxx; i >= 0; i--)
                {
                    if(num[i].flag)
                    {
                        while (num[i].cnt--)
                        {
                            printf("%I64d",num[i].val);
                        }
                    }
                }
                printf("\n");
            }
        }
        else
        {
            LL r = sum % 3;
            bool Can = false;
            LL cnt = 0;
            if (r == 1)
            {
                for (int i = 1; i <= maxx ; i+=3)
                {
                    if (num[i].flag && num[i].cnt)
                    {
                        Can = true;
                        num[i].cnt--;
                        if (num[i].cnt == 0)
                        {
                            num[i].flag = false;
                            num[i].val = 0;
                        }
                        break;
                    }
                }
                if(!Can)
				{
					for (int i = 2;i <= maxx;i+=3)
					{
						if (num[i].flag && num[i].cnt)
						{
							while (num[i].cnt--)
							{
								cnt++;
								if (num[i].cnt == 0)
								{
									num[i].flag = false;
								}
								if (cnt == 2 || num[i].cnt == 0)
								{
									if (cnt == 2)
									{
										Can = true; 
									}
									break;
								}
							}
							if (cnt == 2)
							{
								Can = true;
								break;
							}
						}
					}
				} 
            }
            else if (r == 2)
            {
                for (int i = 2; i <= maxx; i+=3)
                {
                    if (num[i].flag && num[i].cnt)
                    {
                        Can = true;
                        num[i].cnt--;
                        if(num[i].cnt == 0)
                        {
                            num[i].flag = false;
                            num[i].val = 0;
                        }
                        break;
                    }
                }
                if (!Can)
                {
                    for (int i = 1; i <= maxx; i+=3)
                    {
                        if (num[i].flag && num[i].cnt)
                        {
                            while (num[i].cnt--)
                            {
                                cnt++;
                                if (num[i].cnt == 0)
                                {
                                    num[i].flag = false;
                                }
                                if (cnt == 2 || num[i].cnt == 0)
                                {
                                    if (cnt == 2)
                                    {
                                        Can = true;
                                    }
                                    break;
                                }
                            }
                        }
                        if (cnt == 2)
                        {
                            Can = true;
                            break;
                        }
                    }
                }
            }
            if (!Can)
            {
                printf("-1\n");
            }
            else
            {
                bool Noz = false;
				for (int i = 0;i <= maxx;i++)
                {
                	if (num[i].flag && num[i].val)
                	{
						Noz = true;
                		break;
                	}
                }
				
				if (Noz)
				{
					for (int i = maxx;i >= 0;i--)
					{
						if (num[i].flag && num[i].cnt)
						{
							while (num[i].cnt--)
							{
								printf("%I64d",num[i].val);
							}
						}
					}
					printf("\n");
				}
				else
				{
					printf("0\n");
				}
            }
        }
    }
    return 0;
}
