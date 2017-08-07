#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    int c[1005];
    char ch;
    int len_a,len_b;
    int idx_c,len_c;
    int sum;
    int i,j;
    len_a = 0;
    len_b = 0;
    scanf("%d",&sum);
    //读取数据
    for(j=0 ; j<sum ;j++)
    {
        //读取缓存区数据
        memset(c,0,sizeof(int)*1005);
        scanf("%s",a);
        scanf("%s",b);
        len_a = strlen(a)-1; //这里是下标而不是长度。
        len_b = strlen(b)-1;
        //确定结果的长度
        if(len_a >= len_b)
        {
            idx_c = len_a+1;
            len_c = idx_c;
        }
        else
        {
            idx_c = len_b+1;
            len_c = idx_c;
        }
        //进行相加的操作
        do
        {
            c[idx_c] = c[idx_c]+a[len_a]-'0'+b[len_b]-'0';
            if(c[idx_c] >= 10)
            {
                c[idx_c] %= 10;
                c[idx_c-1] += 1;
            }
            idx_c--;
            len_a--;
            len_b--;
        }while(len_a!=-1 && len_b!=-1 );

        while(len_a != -1)
        {
            c[idx_c] = c[idx_c]+a[len_a]-'0';
            if(c[idx_c] >= 10)//这里要进行进位判断
            {
                c[idx_c] %= 10;
                c[idx_c-1] += 1;
            }
            idx_c--;
            len_a--;
        }
        while(len_b != -1)
        {
            c[idx_c] = c[idx_c]+b[len_b]-'0';
            if(c[idx_c] >= 10)
            {
                c[idx_c] %= 10;
                c[idx_c-1] += 1;
            }
            idx_c--;
            len_b--;
        }

        printf("Case %d:\n%s + %s = ",j+1,a,b);
        if(c[idx_c] != 0)    //看这个位是否有"值"
            printf("%d", c[idx_c]);
        for(i = idx_c + 1; i <= len_c ; i++)
        {
            printf("%d", c[i]);
        }

        if(j == sum-1)
            printf("\n");
        else
            printf("\n\n");
    }
    return 0;

}
