/*
 * Maximum Subarray Sum - Kadane's Algorithm (Optimal Approach)
 * 
 * Problem: Given an array of integers (positive and negative), find the
 * contiguous subarray with the largest sum and return both the sum and indices.
 * 
 * Algorithm: Kadane's Algorithm - Dynamic Programming Approach
 * - Maintain a running sum of the current subarray
 * - If running sum becomes negative, discard it and start fresh
 * - Key Insight: A negative sum will only decrease future sums, so reset
 * - Track maximum sum and the start/end indices of the best subarray
 * 
 * Why Kadane's works:
 * - At each position, we decide: extend current subarray OR start new one
 * - If current sum < 0, starting fresh from next element is always better
 * - This greedy choice leads to optimal solution
 * 
 * Time Complexity: O(N) - Single pass through the array
 * Space Complexity: O(1) - Only using constant extra space
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array with positive and negative integers
    // Expected result: subarray [1, 5, -3, 7] gives maximum sum = 10
    int arr[] = {-2, -3, 1, 5, -3, 7, -1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize maxSum with first element
    // Handles edge case where all elements are negative (must select at least one)
    int maxSum = arr[0];
    
    // Track the sum of current subarray being considered
    // Starts at 0 because we haven't begun processing elements yet
    int currentSum = 0;

    // Track the potential starting index for the current subarray window
    // Set to -1 initially; will be updated to i+1 when we start fresh
    int start = -1;
    
    // Store the actual starting index of the maximum sum subarray found
    // Will be updated whenever we find a new maximum
    int ansStart = -1;
    
    // Store the ending index of the maximum sum subarray found
    // Will be updated whenever we find a new maximum
    int ansEnd = -1;

    // Main loop: Apply Kadane's algorithm by processing each element
    for (int i = 0; i < n; i++)
    {
        // Check if we're starting a new subarray window
        // This happens when currentSum was reset to 0 in previous iteration
        if (currentSum == 0)
        {
            // Mark current index as the start of new potential subarray
            start = i;
        }
        
        // Extend current subarray by including current element
        // Add arr[i] to the running sum of current subarray window
        currentSum += arr[i];

        // Check if current subarray sum is better than best found so far
        if (currentSum > maxSum)
        {
            // Update the maximum sum to current sum (new record found)
            maxSum = currentSum;
            
            // Record where this best subarray starts
            ansStart = start;
            
            // Record where this best subarray ends (current position)
            ansEnd = i;
        }

        // Kadane's core logic: Should we continue or start fresh?
        // If current sum becomes negative, it will drag down future sums
        if (currentSum < 0)
        {
            // Reset current sum to 0 (discard negative sum)
            // Starting fresh from next element gives better results than carrying negative sum
            currentSum = 0;
            
            // Note: start will be set to i+1 in next iteration when currentSum == 0
        }
    }

    // Display the maximum sum achieved by any contiguous subarray
    cout << "Maximum Subarray Sum is: " << maxSum << endl;
    
    // Display the range of indices that form the maximum sum subarray
    cout << "Subarray indices [" << ansStart << ", " << ansEnd << "]" << endl;
    
    // Begin displaying the actual elements of the maximum subarray
    cout << "Subarray element is: [ ";

    // Iterate through the range from ansStart to ansEnd (inclusive)
    for (int i = ansStart; i <= ansEnd; i++)
    {
        // Print each element of the maximum sum subarray
        cout << arr[i] << " ";
    }
    
    // Close the array display
    cout << "]";

    return 0;
}