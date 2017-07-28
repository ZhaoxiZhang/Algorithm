#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

__int64 abx(__int64 x)
{
	if (x < 0)
		return -x;
	else
		return x;
}


int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        __int64 w,h,r,x,y,vx,vy,t,w1,h1,lw,lh,px,py;
        __int64 mulit;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&w,&h,&r,&x,&y,&vx,&vy,&t);
        w1 = w - 2*r;
        h1 = h - 2*r;
        lw = x -  r + vx*t;
        lh = y - r + vy*t;
        if (vx == 0 || 2*r == w || t == 0)
        {
            px = x;
        }
        else
        {
			mulit = lw/w1;
            if (mulit&1)
            {
                px = abx(lw - mulit*w1);
				px = w1 - px + r;
            }
            else
            {
                px = abx(lw - mulit*w1) + r;
            }
        }
        
        if (vy == 0 || 2*r == h || t == 0)
        {
            py = y;
        }
        else
        {
            mulit = lh/h1;
            if (mulit&1)
            {
                py = abx(lh - mulit*h1);
                py = h1 - py + r;
            }
            else
            {
                py = abx(lh - mulit*h1) + r;
            }
        }
        printf("%I64d.00 %I64d.00\n",px,py);
    }
    return 0;
}

