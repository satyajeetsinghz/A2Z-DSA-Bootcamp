/*
 * Binary Search in a Sorted Array - Optimal Approach (Divide & Conquer)
 *
 * Problem: Given a sorted array and a target value, find the index of the target.
 * If the target is not present, return -1.
 *
 * Also known as: Classic Binary Search
 *
 * Algorithm: Repeatedly halve the search space using mid comparison
 *
 * Search Space Invariants (inclusive bounds):
 * [low ... high] is the current candidate region that may contain the target.
 * Elements outside this range are already proven absent.
 *
 * Steps per iteration:
 * 1) Compute mid safely (avoids overflow): mid = low + (high - low) / 2
 * 2) Compare arr[mid] with target:
 *    - If equal: target found at mid
 *    - If arr[mid] < target: discard left half -> move low to mid + 1
 *    - If arr[mid] > target: discard right half -> move high to mid - 1
 *
 * Why this is optimal:
 * - Cuts search space in half each step -> O(log N) time
 * - In-place search -> O(1) extra space
 * - Deterministic and minimal comparisons for sorted arrays
 *
 * Time Complexity: O(log N) - Halving the range each iteration
 * Space Complexity: O(1) - Only a few integer variables
 *
 * This is the BEST general-purpose search for sorted arrays.
 */

#include <iostream>
using namespace std;

// Binary Search function: returns index of target if found, else -1
int binarySearch(int arr[], int n, int target)
{
    // Inclusive search boundaries
    int low = 0;
    int high = n - 1;

    // Loop until search space is exhausted
    while (low <= high)
    {
        // Safe mid calculation to prevent overflow on large indices
        int mid = low + (high - low) / 2;

        // CASE 1: Target found at mid
        if (arr[mid] == target)
        {
            return mid;
        }

        // CASE 2: Target is greater; discard left half including mid
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }

        // CASE 3: Target is smaller; discard right half including mid
        else
        {
            high = mid - 1;
        }
    }

    // Target not found after search space is exhausted
    return -1;
}

int main()
{
    // Sample sorted array (ascending order)
    int arr[] = {1, 2, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element to search for
    int target = 7;

    // Perform binary search
    int index = binarySearch(arr, n, target);

    // Report result
    if (index != -1)
    {
        cout << "Element [" << target << "] found at index: " << index;
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}