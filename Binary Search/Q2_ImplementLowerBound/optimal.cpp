/*
 * Lower Bound in a Sorted Array - Optimal Approach (Binary Search Variant)
 *
 * Problem: Find the first (leftmost) index of the element that is greater than 
 * or equal to the target value. If no such element exists, return array size (n).
 *
 * Also known as: Lower Bound Problem
 * Definition: Lower Bound(x) = smallest index i such that arr[i] >= x
 *
 * Algorithm: Modified Binary Search for Boundary Finding
 *
 * Key Difference from Standard Binary Search:
 * - Instead of returning on first match, we continue searching for the LEFTMOST occurrence
 * - We store candidate answers and narrow the search to the left when arr[mid] >= target
 *
 * Search Logic:
 * 1) If arr[mid] >= target: This could be our answer, store it and search left for earlier occurrence
 *    -> Store mid in ans, move high to mid - 1 (continue left)
 * 2) If arr[mid] < target: This element is too small, search right for larger elements
 *    -> Move low to mid + 1 (continue right)
 *
 * Invariants:
 * - 'ans' always holds the best candidate found so far (smallest index with arr[i] >= target)
 * - We keep searching left when we find a valid candidate to ensure we get the LEFTMOST one
 * - Elements to the left of [low] are all < target
 * - Elements to the right of [high] are all >= target (already covered by ans)
 *
 * Why this is optimal:
 * - O(log N) time: Halves search space each iteration
 * - O(1) space: Only constant extra variables
 * - Perfect for boundary problems on sorted arrays
 *
 * Time Complexity: O(log N) - Binary search with modified stopping condition
 * Space Complexity: O(1) - Only a few integer variables (low, high, mid, ans)
 *
 * This is the BEST approach for finding lower bound efficiently.
 */

#include <iostream>
using namespace std;

// Lower Bound function: returns smallest index where arr[i] >= target, else n
int lowerBound(int arr[], int n, int target)
{
    // Inclusive search boundaries
    int low = 0;
    int high = n - 1;

    // Store answer as array size initially (case when target > all elements)
    // This will be updated whenever we find an element >= target
    int ans = n;

    // Binary search loop
    while (low <= high)
    {
        // Safe mid calculation to prevent overflow
        int mid = low + (high - low) / 2;

        // CASE 1: arr[mid] >= target (valid candidate for lower bound)
        if (arr[mid] >= target)
        {
            // Store this position as a potential answer
            // This might be the leftmost element >= target, but continue searching left to be sure
            ans = mid;
            
            // Search in the left half to find if there's an earlier occurrence
            // This ensures we get the LEFTMOST element >= target
            high = mid - 1;
        }

        // CASE 2: arr[mid] < target (element too small, target is to the right)
        else
        {
            // Current element and all elements to its left are < target
            // Lower bound must be to the right
            low = mid + 1;
        }
    }

    // Return the smallest index where arr[i] >= target, or n if no such element exists
    return ans;
}

int main()
{
    // Sample sorted array with duplicate elements
    int arr[] = {1, 2, 5, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element to find lower bound for
    int target = 8;

    // Find lower bound of target
    int index = lowerBound(arr, n, target);

    // Report result
    if (index < n)
    {
        // Lower bound found: print its index
        // For target=6, this would print index 3 (first occurrence of 6)
        cout << "Lower Bound index is: " << index;
    }

    else
    {
        // No lower bound exists: target is greater than all array elements
        cout << "Lower Bound does not exist.";
    }

    return 0;
}