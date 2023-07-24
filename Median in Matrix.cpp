#include <vector>
#include <algorithm>
#include <limits> // Include the <limits> header for INT_MAX and INT_MIN

int findMedian(std::vector<std::vector<int>>& arr, int n, int m) {
    int minVal = std::numeric_limits<int>::max(); // Use std::numeric_limits<int>::max() for INT_MAX
    int maxVal = std::numeric_limits<int>::min(); // Use std::numeric_limits<int>::min() for INT_MIN

    // Finding the minimum and maximum elements in the matrix
    for (int i = 0; i < n; i++) {
        minVal = std::min(minVal, arr[i][0]);
        maxVal = std::max(maxVal, arr[i][m - 1]);
    }

    int desired = (n * m + 1) / 2;
    while (minVal < maxVal) {
        int midVal = minVal + (maxVal - minVal) / 2;
        int place = 0;

        // Find count of elements smaller than or equal to midVal
        for (int i = 0; i < n; ++i)
            place += std::upper_bound(arr[i].begin(), arr[i].end(), midVal) - arr[i].begin();

        if (place < desired)
            minVal = midVal + 1;
        else
            maxVal = midVal;
    }
    return minVal;
}
/*
Sure! Let's go through the algorithm of the provided code step by step:

1. Define a function `findMedian` that takes a 2D vector `arr`, representing the row-wise sorted matrix, and the integers `n` and `m` as input.

2. Find the minimum (`minVal`) and maximum (`maxVal`) elements in the matrix. To do this, initialize `minVal` to the maximum possible integer value and `maxVal` to the minimum possible integer value.

3. Iterate through each row of the matrix to find the actual `minVal` and `maxVal` elements.

4. Calculate the desired position of the median element using the formula `desired = (n * m + 1) / 2`.

5. Use binary search to find the median value. Start a loop while `minVal` is less than `maxVal`.

6. Calculate the `midVal` as the average of `minVal` and `maxVal`.

7. Initialize `place` to 0. This variable will keep track of how many elements in the matrix are less than or equal to `midVal`.

8. Iterate through each row of the matrix again and count the number of elements that are less than or equal to `midVal`. To do this, use the `std::upper_bound` function to find the position of the first element greater than `midVal` in each row. The number of elements less than or equal to `midVal` in that row will be given by the difference between the beginning of the row and the `upper_bound` position.

9. If the count `place` is less than `desired`, update `minVal` to `midVal + 1` to search in the upper half of the range.

10. If the count `place` is greater than or equal to `desired`, update `maxVal` to `midVal` to search in the lower half of the range.

11. Repeat steps 6 to 10 until `minVal` becomes equal to `maxVal`, i.e., the binary search finds the median value.

12. Return the `minVal` as the median of the matrix.

The binary search approach efficiently finds the median of the row-wise sorted matrix without explicitly traversing all elements, making it a more efficient solution for large matrices.
*/
