/*
  Name: HDOJ1002
  Copyright: 
  Author: Tad
  Date: 26-07-07 15:39
  Description: 
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a,b,c;
        cin>>a>>b;
        int la=a.length()-1,lb=b.length()-1,jw=0,ta,tb,tt,f=0;
        char tc;
        while(la>=0||lb>=0)
        {
        
            if(la<0) ta=0;
                else ta=a[la]-'0';
            if(lb<0) tb=0;
                else tb=b[lb]-'0';
            tt=jw+ta+tb;
            jw=tt/10;
            tc=tt%10+'0';            
            if(tc!='0') f=1;
            c+=tc;
            la--;lb--;
        }
        if(jw>0)
        {
            f=1;
            tc=jw+'0';
            c+=tc;
        }

        if(i!=1)cout<<endl;
        cout<<"Case "<<i<<":"<<endl;
        cout<<a<<" + "<<b<<" = ";
        if(f==1)
        {
            for(int i=c.length()-1;i>=0;i--)
                cout<<c[i];
            cout<<endl;
        }
        else cout<<0<<endl;
        
    }
    //system("pause");//return 0;
} 
 
