#include <iostream>

long long conquer(long long *arr, int si, int mid, int ei) {
    int *merge = new int[ei - si + 1];
    
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    long long inv = 0; // Initialize the inversion count

    while (idx1 <= mid && idx2 <= ei) {
        if (arr[idx1] <= arr[idx2]) { // Note the use of <= instead of <
            merge[x++] = arr[idx1++];
        } else {
            merge[x++] = arr[idx2++];
            inv += mid - idx1 + 1; // Count inversions when the element from the right subarray is smaller
        }
    }

    while (idx1 <= mid) {
        merge[x++] = arr[idx1++];
    }

    while (idx2 <= ei) {
        merge[x++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < x; i++, j++) {
        arr[j] = merge[i];
    }
    
    delete[] merge; // Free the dynamically allocated memory
    return inv; // Return the inversion count
}

long long countInversions(long long *arr, int si, int ei) {
    if (si >= ei) {
        return 0;
    }
    
    int mid = si + (ei - si) / 2;
    long long inv = 0;
    inv += countInversions(arr, si, mid);
    inv += countInversions(arr, mid + 1, ei);
    inv += conquer(arr, si, mid, ei);
    return inv; // Return the calculated inversion count
}

long long getInversions(long long *arr, int n) {
    return countInversions(arr, 0, n - 1);
}
//link: https://www.codingninjas.com/studio/problems/count-inversions_615?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
