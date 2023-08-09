int findKMin(vector<int> arr, int n, int k)
{
    // Create a Double Ended Queue, Qi
    // that will store indexes
    // of array elements, queue will
    // store indexes of useful elements
    // in every window
    deque<int> Qi(k);
 
    // Process first k (or first window)
    // elements of array
    int i;
    for (i = 0; i < k; ++i) {
        // For every element,
        // the previous smaller elements
        // are useless so remove them from Qi
        while ((!Qi.empty()) &&
               arr[i] >= arr[Qi.back()])
            Qi.pop_back(); // Remove from rear
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
     
    int minDiff = INT_MAX;
     
    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i) {
        // The element at the front
        // of the queue is the largest
        //  element of previous window
        minDiff = min(minDiff, arr[Qi.front()]);
 
        // Remove the elements
        // which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
 
        // Remove all elements smaller
        // than the currently being
        // added element (remove useless elements)
        while ((!Qi.empty()) &&
                arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
        // Add current element
        // at the rear of Qi
        Qi.push_back(i);
    }
 
    // compare the maximum
    // element of last window
    minDiff = min(minDiff, arr[Qi.front()]);
    return minDiff;
}
 
// Function to find the minimum
// of the maximum difference of the
// adjacent elements after removing
// K elements from the array

int maxAdjDifference(vector<int> a, int k) {
    // Initialising the
    // minimum difference
    int n = a.size();
    vector<int> diff(n-1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }
 
    // find minimum of all maximum
    // of subarray sizes n - k - 1
    int answer = findKMin(diff,
                  n - 1, n - k - 1);
    return answer;
}
// link: https://www.codingninjas.com/studio/problems/minimize-the-maximum-difference-between-adjacent-elements-in-an-array_893177?leftPanelTab=3
