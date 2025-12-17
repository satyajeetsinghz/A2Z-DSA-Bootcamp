/*
 * Second Largest Element in Array - Optimal (Single Pass, O(1) Space)
 *
 * Problem: Find the second largest distinct element. If it doesn't exist
 * (e.g., all equal or size < 2), use a sentinel such as -1.
 *
 * Approach (Track two bests):
 * - Maintain `largest` and `secondLargest` while scanning once from left to right.
 * - When a new value is greater than `largest`, demote `largest` to `secondLargest`
 *   and set `largest` to the new value.
 * - Otherwise, if the value is strictly between `secondLargest` and `largest`,
 *   update `secondLargest`.
 * - This preserves distinctness: we never set `secondLargest` equal to `largest`.
 *
 * Notes & Edge Cases:
 * - Sentinel -1 assumes non-negative inputs; for general arrays, consider
 *   initializing with a very small value (e.g., `INT_MIN`) and/or a found flag.
 * - Works correctly with duplicates: e.g., for [7,7,...], `secondLargest` stays sentinel.
 *
 * Complexity:
 * - Time: O(n) single pass
 * - Space: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array and length
    int arr[] = {1, 6, 2, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize trackers
    int largest = arr[0];
    int secondLargest = -1; // sentinel for "not found" in non-negative arrays

    // Single pass to update `largest` and `secondLargest`
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest; // previous best becomes second best
            largest = arr[i];        // update new best
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];  // better second best, still < largest
        }
    }

    // Output result
    cout << "The largest element is: " << largest
         << " and Second largest element is: " << secondLargest << endl;

    return 0;
}