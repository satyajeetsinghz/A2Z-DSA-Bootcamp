/*
 * Second Largest Element in Array - Better Approach (Two Passes)
 *
 * Problem: Find the second largest distinct element in an array. If no such
 * value exists (e.g., all elements equal or array size < 2), report a sentinel
 * such as -1.
 *
 * Approach:
 * 1) First pass to find the maximum (`largest`).
 * 2) Second pass to find the maximum value strictly less than `largest`
 *    (this becomes `secondLargest`).
 *
 * Notes & Edge Cases:
 * - Distinctness: We require `secondLargest != largest`.
 * - Initialization: Using -1 as sentinel assumes non-negative array values;
 *   for full generality, initialize with something like `INT_MIN`.
 * - This method preserves O(n) time with two linear scans and O(1) space.
 *
 * Complexity:
 * - Time: O(n) with 2 passes
 * - Space: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array and length
    int arr[] = {1, 6, 2, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // First pass: find the largest value
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    // Second pass: find best candidate strictly less than `largest`
    int secondLargest = -1; // sentinel: no second largest found yet
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    // Output result
    cout << "The largest element is: " << largest
         << " and Second largest element is: " << secondLargest << endl;

    return 0;
}