#include <bits/stdc++.h> 
int middleOfThree(int x, int y, int z)
{
      int arr[3]={x,y,z};
      sort(arr,arr+3);
      return arr[1];

}
