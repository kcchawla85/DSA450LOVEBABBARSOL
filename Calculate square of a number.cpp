#include <bits/stdc++.h> 
int calculateSquare(int num)
{
    num=abs(num);
    int temp=num;
    int res=0;
    int pos=0;
    while(temp)
    {
        if(temp&1)
        {
            res+=(num<<pos);
        }
        pos++;
        temp=temp>>1;
    }
    return res;
}
