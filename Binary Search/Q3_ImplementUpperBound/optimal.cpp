/*
 * Upper Bound in a Sorted Array - Optimal Approach (Binary Search Variant)
 *
 * Problem: Find the first (leftmost) index of the element that is STRICTLY greater 
 * than the target value. If no such element exists, return array size (n).
 *
 * Also known as: Upper Bound Problem
 * Definition: Upper Bound(x) = smallest index i such that arr[i] > x
 *
 * Algorithm: Modified Binary Search for Boundary Finding
 *
 * Key Difference from Lower Bound:
 * - Lower Bound: First element >= target
 * - Upper Bound: First element > target
 * - Upper Bound is strictly greater (strict inequality)
 *
 * Search Logic:
 * 1) If arr[mid] > target: This could be our answer, store it and search left for earlier occurrence
 *    -> Store mid in ans, move high to mid - 1 (continue left for leftmost)
 * 2) If arr[mid] <= target: This element is too small or equal, search right for larger elements
 *    -> Move low to mid + 1 (continue right)
 *
 * Invariants:
 * - 'ans' always holds the best candidate found so far (smallest index with arr[i] > target)
 * - We keep searching left when we find a valid candidate to ensure we get the LEFTMOST one
 * - All elements to the left of [low] are <= target
 * - All elements to the right of [high] are > target (already covered by ans)
 *
 * Relationship with Lower Bound:
 * - Lower Bound of (x) = Upper Bound of (x - 1)
 * - Upper Bound of (x) = Lower Bound of (x + 1)
 * - Upper Bound is always >= Lower Bound for same target
 *
 * Why this is optimal:
 * - O(log N) time: Halves search space each iteration
 * - O(1) space: Only constant extra variables
 * - Perfect for boundary problems on sorted arrays
 *
 * Time Complexity: O(log N) - Binary search with modified comparison
 * Space Complexity: O(1) - Only a few integer variables (low, high, mid, ans)
 *
 * This is the BEST approach for finding upper bound efficiently.
 */

#include <iostream>
using namespace std;

// Upper Bound function: returns smallest index where arr[i] > target, else n
int upperBound(int arr[], int n, int target)
{
    // Inclusive search boundaries
    int low = 0;
    int high = n - 1;

    // Store answer as array size initially (case when target >= all elements)
    // This will be updated whenever we find an element > target
    int ans = n;

    // Binary search loop
    while (low <= high)
    {
        // Safe mid calculation to prevent overflow
        int mid = low + (high - low) / 2;

        // CASE 1: arr[mid] > target (valid candidate for upper bound)
        if (arr[mid] > target)
        {
            // Store this position as a potential answer
            // This might be the leftmost element > target, but continue searching left to be sure
            ans = mid;

            // Search in the left half to find if there's an earlier occurrence
            // This ensures we get the LEFTMOST element > target
            high = mid - 1;
        }

        // CASE 2: arr[mid] <= target (element equal to or smaller than target)
        else
        {
            // Current element and all elements to its left are <= target
            // Upper bound must be to the right
            low = mid + 1;
        }
    }

    // Return the smallest index where arr[i] > target, or n if no such element exists
    return ans;
}

int main()
{
    // Sample sorted array with duplicate elements
    int arr[] = {1, 2, 5, 7, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element to find upper bound for
    int target = 7;

    // Find upper bound of target
    int index = upperBound(arr, n, target);

    // Report result
    if (index < n)
    {
        // Upper bound found: print its index
        // For target=7, this would print index 5 (first element > 7, which is 8)
        cout << "Upper Bound is: " << index;
    }

    else
    {
        // No upper bound exists: target >= all array elements
        cout << "Upper bound does not exist.";
    }

    return 0;
}