/*
 * Maximum Sum Circular Subarray (LeetCode Q918)
 *
 * Problem: Given a circular integer array, find the maximum possible sum of a non-empty subarray.
 * A circular array means the end of the array connects back to the beginning.
 *
 * Approach (Kadane's Algorithm Variation):
 * - There are two possible cases for maximum circular subarray:
 *   Case 1: Maximum subarray is in the middle (non-circular) → Use standard Kadane's algorithm
 *   Case 2: Maximum subarray wraps around (circular) → Elements at both ends of array
 *
 * - For Case 2 (circular), instead of finding max sum directly, we can:
 *   Find minimum subarray sum in the middle, then subtract it from total sum
 *   Circular max sum = Total sum - Minimum subarray sum
 *
 * - Run Kadane's algorithm twice simultaneously:
 *   1. Find maximum subarray sum (standard Kadane)
 *   2. Find minimum subarray sum (inverted Kadane)
 *
 * - Answer = max(maxSum, totalSum - minSum)
 * - Edge case: If all elements are negative, maxSum will be negative
 *   In this case, totalSum - minSum would give 0 (empty array), which is invalid
 *   So we return maxSum when all elements are negative
 *
 * Key Insight:
 * - Circular maximum = Total sum - Minimum subarray (elements not included in circular max)
 * - This transforms the circular problem into a linear one
 * - We avoid explicitly handling wrap-around logic
 *
 * Example:
 * - Input: [5, -3, 5]
 * - maxSum = 7 (5 + (-3) + 5, entire array)
 * - minSum = -3 (middle element)
 * - totalSum = 7
 * - Circular max = 7 - (-3) = 10 (wraps: last 5 + first 5)
 * - Answer = max(7, 10) = 10
 *
 * Complexity:
 * - Time: O(n) single pass through the array
 * - Space: O(1) only using constant extra space
 */

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find maximum sum of a subarray in a circular array
// Parameters: arr[] - input array, n - size of array
// Returns: maximum possible sum of any subarray (considering circular nature)
int maxSubarraySumCircular(int arr[], int n)
{
    int totalSum = arr[0];  // Sum of all elements in the array

    // Variables for standard Kadane's algorithm (finding maximum subarray)
    int currentMax = arr[0];  // Current maximum sum ending at current position
    int maxSum = arr[0];      // Overall maximum subarray sum found so far

    // Variables for inverted Kadane's algorithm (finding minimum subarray)
    int currentMin = arr[0];  // Current minimum sum ending at current position
    int minSum = arr[0];      // Overall minimum subarray sum found so far

    // Traverse array starting from index 1
    for (int i = 1; i < n; i++)
    {
        int num = arr[i];  // Current element

        // Kadane for maximum subarray sum (Case 1: non-circular)
        currentMax = max(num, currentMax + num);  // Either start fresh or extend current
        maxSum = max(maxSum, currentMax);         // Update global maximum

        // Kadane for minimum subarray sum (needed for Case 2: circular)
        currentMin = min(num, currentMin + num);  // Either start fresh or extend current
        minSum = min(minSum, currentMin);         // Update global minimum

        totalSum += num;  // Accumulate total sum
    }

    // Edge case: All elements are negative
    // If maxSum < 0, then all elements are negative
    // In this case, totalSum - minSum would give 0 (empty subarray), which is invalid
    // So we return maxSum (the least negative element)
    if (maxSum < 0)
        return maxSum;

    // Return the maximum of:
    // 1. maxSum: standard maximum subarray (non-circular)
    // 2. totalSum - minSum: circular maximum (wrap-around case)
    return max(maxSum, totalSum - minSum);
}

int main()
{
    // Test case: array where circular sum is greater than linear sum
    int arr[] = {2, -3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate number of elements

    // Display the result
    cout << maxSubarraySumCircular(arr, n);

    return 0;  // Exit program successfully
}
