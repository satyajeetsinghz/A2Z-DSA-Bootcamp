/*
 * Longest Subarray with Sum K - Optimal Approach using Sliding Window
 * 
 * Problem: Given an array of POSITIVE integers and a target sum K,
 * find the length of the longest contiguous subarray whose elements sum to K.
 * 
 * IMPORTANT: This approach ONLY works for arrays with POSITIVE numbers.
 * For arrays with negative numbers, use hash map approach (better.cpp).
 * 
 * Algorithm: Sliding Window (Two Pointers Technique)
 * 
 * Concept:
 * - Maintain a dynamic window [left, right] representing current subarray
 * - Expand window by moving right pointer (add elements)
 * - Shrink window by moving left pointer (remove elements)
 * 
 * Strategy:
 * 1. Start with both pointers at beginning (left=0, right=0)
 * 2. Expand window: Add arr[right] to sum and move right
 * 3. If sum > K: Shrink from left until sum <= K
 * 4. If sum == K: Calculate length and update maximum
 * 5. Repeat until right pointer reaches end
 * 
 * Why this works for positive numbers:
 * - Adding elements ALWAYS increases sum
 * - Removing elements ALWAYS decreases sum
 * - This monotonic property allows greedy shrinking/expanding
 * - We never need to backtrack or reconsider
 * 
 * Why this FAILS for negative numbers:
 * - Negative numbers can decrease sum when added
 * - We might need to expand past K and come back to K
 * - The monotonic property is broken
 * 
 * Time Complexity: O(2N) ≈ O(N) - Each element visited at most twice (once by right, once by left)
 * Space Complexity: O(1) - Only using constant extra space
 * 
 * This is the BEST approach for positive-only arrays.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array (ONLY positive integers)
    // Subarray [3, 1, 1, 1] has sum = 6 and length = 4
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Target sum K we're looking for in contiguous subarrays
    int k = 6;

    // TWO POINTERS for Sliding Window:
    
    // 'left' pointer: Marks the start of the current window/subarray
    int left = 0;
    
    // 'right' pointer: Marks the end of the current window/subarray
    // Also acts as the scanning pointer that moves through the array
    int right = 0;
    
    // Variable to track sum of current window [left, right]
    int sum = 0;
    
    // Variable to track the maximum length found so far
    int maxLen = 0;

    // Main loop: Expand the window by moving right pointer
    // Continue until right pointer scans through entire array
    while (right < n)
    {
        // STEP 1: Expand window - Add current element to the window
        // Include arr[right] in our current subarray and update sum
        sum += arr[right];

        // STEP 2: Shrink window if sum exceeds target
        // Keep removing elements from left while sum is too large
        // This brings us closer to the target sum K
        while (sum > k)
        {
            // Remove the leftmost element from window
            // Subtract arr[left] from sum to shrink the window
            sum -= arr[left];
            
            // Move left pointer right to reduce window size
            // The window [left, right] is now smaller
            left++;
        }

        // STEP 3: Check if current window sum equals target K
        // After expansion and potential shrinking, check if we have a valid subarray
        if (sum == k)
        {
            // Calculate length of current window
            // Length = right - left + 1
            // Example: window from left=2 to right=5 has length = 5-2+1 = 4
            maxLen = max(maxLen, right - left + 1);
        }

        // STEP 4: Move right pointer to explore next element
        // Expand the window for next iteration
        right++;
    }

    // Display the length of the longest subarray with sum K
    // If no subarray found, maxLen will be 0
    cout << "Longest subarray length is: " << maxLen;

    return 0;
}