/*
 * Two Sum Problem - Optimal Approach using Two Pointers
 * 
 * Problem: Given an array of integers and a target sum, find if there exist
 * two numbers in the array that add up to the target.
 * Return the pair if found, otherwise indicate no pair exists.
 * 
 * Algorithm: Two Pointers Technique (requires sorted array)
 * 
 * Strategy:
 * 1. Sort the array first
 * 2. Use two pointers: one at start (left), one at end (right)
 * 3. Calculate sum of elements at both pointers
 * 4. If sum == target: Found the pair
 * 5. If sum < target: Move left pointer right (increase sum)
 * 6. If sum > target: Move right pointer left (decrease sum)
 * 
 * Why this works:
 * - In sorted array, smaller elements are at left, larger at right
 * - If sum is too small, we need a larger number (move left pointer right)
 * - If sum is too large, we need a smaller number (move right pointer left)
 * - This systematically explores all possibilities without checking every pair
 * 
 * Trade-off:
 * - Requires O(N log N) time for sorting
 * - After sorting, finding pair is O(N)
 * - Total: O(N log N)
 * - If array is already sorted, this is better than hash set approach
 * 
 * Note: This is "optimal" for sorted arrays or when we can't use extra space.
 * For unsorted arrays with space available, hash set O(N) is better.
 * 
 * Time Complexity: O(N log N) - Sorting dominates, then O(N) for two pointers
 * Space Complexity: O(1) or O(log N) - Depends on sorting algorithm used
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Sample input array to search for two sum
    // In this example: 3 + 5 = 8 (target)
    int arr[] = {1, 2, 3, 5};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Target sum we're trying to achieve with two numbers from the array
    int target = 8;

    // Initialize two pointers:
    // 'start' pointer begins at the leftmost position (smallest element after sorting)
    int start = 0;
    
    // 'end' pointer begins at the rightmost position (largest element after sorting)
    int end = n - 1;

    // STEP 1: Sort the array in ascending order
    // Sorting is essential for two-pointer technique to work correctly
    // After sorting: smallest elements at left, largest at right
    // sort() uses Introsort algorithm with O(N log N) complexity
    sort(arr, arr + n);

    // STEP 2: Use two-pointer technique to find the pair
    // Continue while pointers haven't crossed each other
    // When start >= end, we've checked all possible pairs
    while (start < end)
    {
        // Calculate sum of elements at current pointer positions
        int sum = arr[start] + arr[end];

        // CASE 1: Sum equals target - Found the pair!
        if (sum == target)
        {
            // Display the target and the pair that sums to it
            cout << "Target is: " << target << endl;
            cout << "Pair sum is: " << arr[start] << " and " << arr[end];
            
            // Exit immediately as we found a valid pair
            return 0;
        }

        // CASE 2: Sum is less than target
        // We need a larger sum, so move the left pointer right
        // This picks the next larger element (array is sorted)
        else if (sum < target)
        {
            // Increment start pointer to increase the sum
            start++;
        }

        // CASE 3: Sum is greater than target
        // We need a smaller sum, so move the right pointer left
        // This picks the next smaller element (array is sorted)
        else
        {
            // Decrement end pointer to decrease the sum
            end--;
        }
    }

    // Pointers crossed without finding a match
    // No two elements in the array sum up to the target
    cout << "No pair found.";
    
    return 0;
}