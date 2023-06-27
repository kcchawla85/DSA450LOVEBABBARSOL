#include <bits/stdc++.h> 
bool isPowerOfTwo(int n)
{
    int i=0;
    if(n==0)
    {
        return false;
    }
    if(n<0)
    {
        return false;
    }
    while(n!=0)
    {
        if(n==pow(2,i))
        {
            return true;
        }
        else if(n<pow(2,i))
        {
            return false;
        }
        i++;
        
        
    }
    return false;
}
