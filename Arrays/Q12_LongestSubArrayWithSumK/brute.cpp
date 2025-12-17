/*
 * Longest Subarray with Sum K - Brute Force Approach
 * 
 * Problem: Given an array of integers and a target sum K, find the length
 * of the longest contiguous subarray whose elements sum to K.
 * 
 * Algorithm: Generate All Subarrays and Check Sum
 * - Use nested loops to generate all possible subarrays
 * - Outer loop fixes the starting point
 * - Inner loop extends from start to end, calculating sum on the fly
 * - Check if sum equals K and track the maximum length
 * 
 * Approach:
 * - For each starting index i, explore all subarrays starting from i
 * - Calculate sum incrementally as we extend the subarray
 * - When sum equals K, calculate length and update maximum
 * 
 * Subarray: A contiguous portion of the array
 * Example: In [1, 2, 3], subarrays are: [1], [1,2], [1,2,3], [2], [2,3], [3]
 * 
 * Drawbacks:
 * - Inefficient for large arrays due to nested loops
 * - Checks every possible subarray even when unnecessary
 * - Multiple subarrays might have sum K, but we only need the longest
 * 
 * Time Complexity: O(N²) - Nested loops generating all subarrays
 * Space Complexity: O(1) - Only using constant extra space
 * 
 * Note: Better approaches exist using hash maps or sliding windows
 * depending on whether array has negative numbers or not.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array to find longest subarray with sum K
    // Multiple subarrays sum to 3: [3], [1,1,1], [2,1]
    // Longest is [1,1,1] with length 3
    int arr[] = {1, 2, 3, 1, 1, 1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Target sum K we're looking for in contiguous subarrays
    int k = 3;

    // Variable to track the maximum length found so far
    // Initialize to 0 (if no subarray with sum K exists, return 0)
    int maxLen = 0;

    // Outer loop: Fix the starting index of the subarray
    // Each iteration considers subarrays starting from index i
    for (int i = 0; i < n; i++)
    {
        // Initialize sum for subarrays starting at index i
        // Reset to 0 for each new starting position
        int sum = 0;

        // Inner loop: Extend the subarray from index i to j
        // This generates all subarrays: arr[i], arr[i..i+1], arr[i..i+2], etc.
        for (int j = i; j < n; j++)
        {
            // Add current element to extend the subarray
            // sum now represents sum of subarray arr[i...j]
            sum += arr[j];

            // Check if current subarray sum equals the target K
            if (sum == k)
            {
                // Calculate the length of this subarray
                // Length = ending index - starting index + 1
                // Example: subarray from i=2 to j=4 has length = 4-2+1 = 3
                int length = j - i + 1;
                
                // Update maximum length if current subarray is longer
                // This ensures we track the longest subarray with sum K
                maxLen = max(maxLen, length);
            }
        }
    }

    // Display the length of the longest subarray with sum K
    // If no subarray found, maxLen will be 0
    cout << "Longest subarray length: " << maxLen;

    return 0;
}