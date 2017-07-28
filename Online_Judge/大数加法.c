void Add(char s1[],char s2[]) //需要两个字符串参数&&无返回值
 {
     int num1[M],nm2[M];
     int i,j;
     len1=strlen(s1);
     len2=strlen(s2);
     for(i=len1-1,j=0;i>=0;i--)//num[0]保存的是低位
             num1[j++]=s1[i]-'0';
     for(i=len2-1,j=0;i>=0;i--)
             num2[j++]=s2[i]-'0';
     for(i=0;i<M;i++)
     {
         num1[i]+=num2[i];
         if(num1[i]>9)
         {
             num1[i]-=10;
             num1[i+1]++;
         }
     }

　　for(i=M;(i>=0)&&(num1[i]==0);i--)//找到第一个不是零的数
    {
        if(i>=0)
            for(;i>=0;i--)
                printf("%d",num1[i]);
        else
            printf("0\n")
    }
