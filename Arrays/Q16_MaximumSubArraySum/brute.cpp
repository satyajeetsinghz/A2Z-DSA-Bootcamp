/*
 * Maximum Subarray Sum - Brute Force Approach
 * 
 * Problem: Given an array of integers (positive and negative), find the
 * contiguous subarray with the largest sum.
 * 
 * Algorithm: Generate all possible subarrays and find maximum sum
 * - Use nested loops to generate all subarrays
 * - Outer loop fixes the starting point
 * - Inner loop extends from start to end, calculating sum on the fly
 * - Track the maximum sum encountered
 * 
 * Subarray: A contiguous part of the array
 * Example: For [1, 2, 3], subarrays are: [1], [1,2], [1,2,3], [2], [2,3], [3]
 * 
 * Time Complexity: O(N²) - Two nested loops generating all subarrays
 * Space Complexity: O(1) - Only using constant extra space
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array with both positive and negative numbers
    // In this example: subarrays like [5, -3, 7] will give sum = 9
    int arr[] = {-2 , -1, 5, -3, 7};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize maxSum with the first element
    // This handles edge cases like arrays with all negative numbers
    // (we must select at least one element as per standard problem definition)
    int maxSum = arr[0];

    // Outer loop: Fix the starting index of the subarray
    // Each iteration considers subarrays starting from index i
    for(int i = 0; i < n; i++)
    {
        // Initialize sum for subarrays starting at index i
        // Reset to 0 for each new starting position
        int sum = 0;
        
        // Inner loop: Extend the subarray from index i to j
        // This generates all subarrays: arr[i], arr[i..i+1], arr[i..i+2], etc.
        for(int j = i; j < n; j++)
        {
            // Add the current element to extend the subarray
            // This incrementally builds sum for subarray arr[i...j]
            sum += arr[j];
            
            // Update maxSum if current subarray sum is larger
            // This ensures we track the maximum sum across all possible subarrays
            maxSum = max(maxSum, sum);
        }
    }

    // Output the maximum sum found among all contiguous subarrays
    cout << "Maximum Subarry Sum: " << maxSum;

    return 0;
}