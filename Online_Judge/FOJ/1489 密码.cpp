#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    char name[105],str[30],sec[30];

    while(~scanf("%s",sec))
    {
        for (int i = 0; i < 26; i++)
            str[i] = sec[i];
        getchar();
        gets(name);

        int len = strlen(name);
        for (int i = 0; i < len; i++)
        {
            if (name[i] > 64 && name[i] < 91)
                printf("%c",str[name[i] - 65]);
            else if (name[i] > 95 && name[i] < 123)
                printf("%c",str[name[i] - 97] + 32);
            else
                printf("%c",name[i]);
        }
        printf("\n");
    }
    return 0;
}

