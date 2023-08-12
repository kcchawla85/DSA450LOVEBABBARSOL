#include <bits/stdc++.h> 

vector<int> nextPermutation(vector<int> &permutation, int n)

{

    //  Write your code here.

    int breakIndex=-1;          // Step 1: Find the break point

    for(int i=n-2;i>=0;i--){

        if(permutation[i]<permutation[i+1]){

            breakIndex= i;      // index i is the break point

            break;

        }

    }

    if(breakIndex==-1){         // What if break point does'nt exist.

        reverse(permutation.begin(),permutation.end());   // reverse the whole array.

        return permutation;                            //for.ex: 3,2,1 next permutation is 1,2,3.

    }

    for(int i=n-1;i>breakIndex;i--){      // Step 2: Find the next greater element.

        if(permutation[i]>permutation[breakIndex]){

            swap(permutation[i],permutation[breakIndex]);  //swap it with arr[breakIndex]

            break;

        }

    }    // Step 3: reverse the right part after breakIndex till last index

    reverse(permutation.begin()+breakIndex+1,permutation.end()); 

    return permutation;

}
//link: https://www.codingninjas.com/studio/problems/next-permutaion_893046?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
