/*
 * Search Insert Position in a Sorted Array - Optimal Approach (Binary Search)
 *
 * Problem: Given a sorted array and a target value, find the index where the target
 * should be inserted to maintain sorted order. If target already exists, return its index.
 *
 * Also known as: Search Insert Position / First Position of Target
 *
 * Key Observation:
 * - This is essentially finding the LOWER BOUND of the target
 * - Lower Bound = smallest index where arr[i] >= target
 * - This is both the answer for: "where to insert" and "if found, its position"
 *
 * Algorithm: Binary Search with Lower Bound Logic
 *
 * Three scenarios:
 * 1) Target found in array: Return the first (leftmost) occurrence index
 * 2) Target not found: Return the position where it should be inserted to maintain order
 * 3) Target greater than all elements: Return array size (n)
 *
 * Search Logic:
 * 1) If arr[mid] >= target: This could be our answer, store it and search left
 *    -> Store mid in ans, move high to mid - 1 (continue left to find leftmost)
 * 2) If arr[mid] < target: Target is to the right
 *    -> Move low to mid + 1 (continue right)
 *
 * Why this approach is optimal:
 * - Identical to Lower Bound algorithm
 * - O(log N) time complexity
 * - O(1) space complexity
 * - Handles both "element exists" and "element doesn't exist" cases uniformly
 *
 * Examples:
 * arr = [1, 2, 4, 4, 5], target = 4 -> returns 2 (first position of 4)
 * arr = [1, 2, 4, 4, 5], target = 3 -> returns 2 (where 3 should be inserted)
 * arr = [1, 2, 4, 4, 5], target = 6 -> returns 5 (after all elements)
 *
 * Time Complexity: O(log N) - Binary search halving the search space
 * Space Complexity: O(1) - Only a few integer variables
 *
 * This is the BEST approach for this problem.
 */

#include <iostream>
using namespace std;

// Search Insert Position function: returns index to insert/find target
int searchInsert(int arr[], int n, int target)
{
    // Inclusive search boundaries
    int low = 0;
    int high = n - 1;

    // Store answer as array size initially
    // This handles case when target > all elements (insert at end)
    // This will be updated whenever we find an element >= target
    int ans = n;

    // Binary search loop
    while (low <= high)
    {
        // Safe mid calculation to prevent overflow
        int mid = low + (high - low) / 2;

        // CASE 1: arr[mid] >= target (valid candidate)
        // This position can either be the target itself or where it should be inserted
        if (arr[mid] >= target)
        {
            // Store this position as a potential answer
            // Continue searching left to find the LEFTMOST position
            ans = mid;
            high = mid - 1;
        }

        // CASE 2: arr[mid] < target (element too small)
        else
        {
            // Target must be to the right if elements here are smaller
            low = mid + 1;
        }
    }

    // Return the insertion position or the position of target if it exists
    return ans;
}

int main()
{
    // Sample sorted array with potential duplicates
    int arr[] = {1, 2, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element to search for or insert
    int target = 4;

    // Find the search insert position
    // For this case, returns 2 (first occurrence of 4)
    cout << "Insert Position = " << searchInsert(arr, n, target);

    return 0;
}