/*
 * Maximum Consecutive Ones - Single Pass Approach
 * 
 * Problem: Given a binary array (contains only 0s and 1s), find the maximum
 * number of consecutive 1s in the array.
 * 
 * Algorithm: Linear Scan with Running Counter
 * 
 * Strategy:
 * - Traverse the array from left to right
 * - Maintain a running count of consecutive 1s
 * - When we encounter a 1: increment count and update maximum
 * - When we encounter a 0: reset count to 0 (streak broken)
 * - Track the maximum count seen throughout the traversal
 * 
 * Key Insight:
 * - We only need one pass through the array
 * - No need to generate all subarrays (hence not truly "brute force")
 * - Reset counter when sequence breaks (encounter 0)
 * 
 * Example: [1, 1, 0, 1, 1, 1, 1, 0, 1, 1]
 * - Sequence 1: two 1s (count = 2)
 * - Sequence 2: four 1s (count = 4) <- maximum
 * - Sequence 3: two 1s (count = 2)
 * 
 * Note: This is actually an optimal solution, not brute force.
 * The file name might be misleading.
 * 
 * Time Complexity: O(N) - Single traversal through the array
 * Space Complexity: O(1) - Only using constant extra space
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample binary array containing only 0s and 1s
    // Expected result: Maximum consecutive 1s is 4 (at indices 3-6)
    int arr[] = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Variable to track the maximum consecutive 1s found so far
    // Initialize to 0 (minimum possible value)
    int maximum = 0;
    
    // Variable to track the current streak of consecutive 1s
    // Reset to 0 whenever we encounter a 0
    int count = 0;

    // Single pass: Traverse through each element in the array
    for (int i = 0; i < n; i++)
    {
        // CASE 1: Current element is 1
        // Continue or start a new consecutive sequence
        if (arr[i] == 1)
        {
            // Increment the count of consecutive 1s
            // This extends the current streak by one
            count++;
            
            // Update maximum if current streak is longer than previous best
            // This ensures we always track the longest consecutive sequence
            maximum = max(maximum, count);
        }

        // CASE 2: Current element is 0
        // The consecutive sequence of 1s is broken
        else
        {
            // Reset count to 0 to start counting a new sequence
            // The current streak has ended, so we prepare for the next one
            count = 0;
        }
    }

    // Display the maximum number of consecutive 1s found in the array
    cout << "Maximum Consecutive is: " << maximum;
    
    return 0;
}