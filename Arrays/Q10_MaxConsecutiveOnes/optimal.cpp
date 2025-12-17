/*
 * Maximum Consecutive Ones - Optimal Approach
 * 
 * Problem: Given a binary array (contains only 0s and 1s), find the maximum
 * number of consecutive 1s in the array.
 * 
 * Algorithm: Single Pass with Streak Tracking
 * 
 * Strategy:
 * - Use a single traversal through the array (optimal)
 * - Maintain a counter for current consecutive 1s streak
 * - Maintain a variable for maximum streak encountered
 * - When 1 is found: increment streak counter and update max
 * - When 0 is found: reset streak counter (sequence broken)
 * 
 * Why this is optimal:
 * - Single pass: O(N) time - cannot be improved as we must examine each element
 * - Constant space: O(1) - only two variables used
 * - No backtracking or re-scanning needed
 * - Updates maximum in real-time during traversal
 * 
 * Visual Example: [1, 1, 0, 1, 1, 1, 1, 0, 1, 1]
 * Position: 0  1  2  3  4  5  6  7  8  9
 * Count:    1  2  0  1  2  3  4  0  1  2
 * Maximum:  1  2  2  2  2  3  4  4  4  4  <- Final: 4
 * 
 * Time Complexity: O(N) - Single traversal, each element examined once
 * Space Complexity: O(1) - Only two integer variables used
 * 
 * This is the BEST possible approach for this problem.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample binary array containing only 0s and 1s
    // Sequences of 1s: [1,1], [1,1,1,1], [1,1]
    // Expected result: 4 (the sequence [1,1,1,1] at indices 3-6)
    int arr[] = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Variable to store the maximum length of consecutive 1s found
    // Initialize to 0 as we haven't found any sequence yet
    int maximum = 0;
    
    // Variable to track the current streak/length of consecutive 1s
    // Reset to 0 whenever we encounter a 0 (streak breaks)
    int count = 0;

    // Optimal single pass: Traverse array once from left to right
    // This is the minimum number of passes required (cannot do better than O(N))
    for (int i = 0; i < n; i++)
    {
        // CASE 1: Current element is 1
        // Either continuing an existing streak or starting a new one
        if (arr[i] == 1)
        {
            // Increment the consecutive 1s counter
            // This extends the current streak by including this element
            count++;
            
            // Immediately update maximum if current streak exceeds previous best
            // Real-time update ensures we don't miss any peak even if streak breaks later
            // max() function returns the larger of two values
            maximum = max(maximum, count);
        }

        // CASE 2: Current element is 0
        // The consecutive sequence of 1s has been interrupted
        else
        {
            // Reset the streak counter to 0
            // Prepare to start counting a fresh sequence when next 1 is encountered
            // This is crucial: we don't carry forward the previous streak
            count = 0;
        }
    }

    // Display the final result: length of longest consecutive 1s sequence
    // After complete traversal, maximum holds the answer
    cout << "Maximum Consecutive is: " << maximum;
    
    return 0;
}