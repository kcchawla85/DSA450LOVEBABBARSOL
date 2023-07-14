#include <bits/stdc++.h> 

void heapify(vector<int>& arr, int size, int ind){

    int largest=ind;

    int left=2*ind+1;

    int right=2*ind+2;

    if(left<size and arr[largest]<arr[left]){

        largest=left;

    }

    if(right<size and arr[largest]<arr[right]){

        largest=right;

    }

    if(largest!=ind){

        swap(arr[largest], arr[ind]);

        heapify(arr, size, largest);

    }

}

void heapsort(vector<int>& arr, int n){

    for(int i=n/2-1; i>=0; i--){

       heapify(arr, n, i);

   }

    for(int i=n-1; i>0; i--){

        swap(arr[i], arr[0]);

        

        heapify(arr, i, 0);

    }

}

vector<int> heapSort(vector<int>& arr, int n) {

    for(int i=n/2-1; i>=0; i--){

       heapify(arr, n, i);

   }

   heapsort(arr, n);

   return arr;

}
//link : https://www.youtube.com/watch?v=NKJnHewiGdc
