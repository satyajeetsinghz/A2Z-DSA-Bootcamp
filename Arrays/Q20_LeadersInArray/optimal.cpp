/*
 * Leaders in Array — Optimal Solution
 *
 * Problem: An element is called a "leader" if it is greater than or equal to
 *          all elements to its right. The rightmost element is always a leader.
 *          Example: [12, 14, 16, 7, 6, 2, 5]
 *          Leaders: 16, 7, 6, 5 (because each is >= all elements to its right)
 *
 * Key Insight: 
 * - If we traverse from RIGHT to LEFT, we can track the maximum element seen so far.
 * - Any element >= current maximum is a leader (no element to its right is greater).
 * - This eliminates the need to check every right element for each position.
 *
 * Algorithm Steps:
 * 1. Traverse array from right to left while maintaining running maximum
 * 2. If current element >= maximum, it's a leader (store it and update max)
 * 3. Reverse the leaders array to restore left-to-right order
 * 4. Print all leaders
 *
 * Why this works:
 * - Right-to-left scan means we've already seen all elements to the right
 * - Comparing with max tells us if current element is >= ALL right elements
 * - We collect leaders in reverse order, so we reverse at the end
 *
 * Time Complexity: O(N) — single pass + reversal
 * Space Complexity: O(N) — for storing leaders (worst case: all elements are leaders)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Sample input array to find all leader elements
    int arr[] = {12, 14, 16, 7, 6, 2, 5};
    
    // Calculate total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Array to store leaders as we find them
    // WHY: We need to collect leaders and print them in left-to-right order later
    int leader[n];
    
    // Counter to track how many leaders we've found
    // WHY: Leaders array doesn't automatically know its filled size
    int count = 0;
    
    // Variable to track the maximum element seen so far from the right
    // WHY: A leader must be >= all elements to its right, so we track the max
    // Initialize to smallest possible value so first element will always be >= it
    int maxLeader = INT8_MIN;

    // STEP 1: Traverse array from RIGHT to LEFT
    // WHY: By scanning right-to-left, we know the maximum of all elements
    //      to the right at each position, allowing O(1) leader check
    for (int i = n - 1; i >= 0; i--)
    {
        // Check if current element is >= maximum element seen so far (from right)
        // WHY: If arr[i] >= maxLeader, then arr[i] is >= ALL elements to its right
        //      This is the definition of a leader!
        if (arr[i] >= maxLeader)
        {
            // Store this leader in our result array
            leader[count] = arr[i];
            count++;
            
            // Update the running maximum
            // WHY: This element is now the largest we've seen from the right,
            //      so future elements must be >= this to be leaders
            maxLeader = arr[i];
        }
    }

    // STEP 2: Reverse the leaders array to restore left-to-right order
    // WHY: We collected leaders from right to left, but output should be left to right
    // We only swap the first half with the second half (standard reversal logic)
    for (int i = 0; i < count / 2; i++)
    {
        // Swap elements from both ends moving toward center
        int temp = leader[i];
        leader[i] = leader[count - 1 - i];
        leader[count - 1 - i] = temp;
    }

    // STEP 3: Print all leaders in left-to-right order
    for (int i = 0; i < count; i++)
    {
        cout << leader[i] << " ";
    }

    return 0;
}