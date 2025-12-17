/*
 * Second Largest Element in Array - Brute Approach (Sort + Scan)
 *
 * Problem: Find the second largest distinct element in an array. If there is
 * no such element (e.g., all elements equal or array size < 2), return a
 * sentinel such as -1.
 *
 * Approach:
 * - Sort the array in non-decreasing order.
 * - Let `largest = arr[n-1]`. Scan from the end (i = n-2 down to 0) to find
 *   the first value strictly less than `largest` → that is the second largest.
 *
 * Notes & Edge Cases:
 * - This uses -1 as a sentinel; if input may contain negatives, consider
 *   using a boolean flag to indicate not found or print a message.
 * - Sorting dominates the cost; better/optimal solutions can achieve O(n)
 *   without sorting.
 *
 * Complexity:
 * - Time: O(n log n) due to sorting
 * - Space: O(1) extra (in-place sort) or O(log n) stack depending on impl.
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // Input array and its length
    int arr[] = {1, 2, 3, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array to position the largest at the end
    sort(arr, arr + n);

    // After sort, the largest element is at the last index
    int largest = arr[n - 1];
    int secondLargest = -1; // sentinel for "not found"

    // Scan from the second last element to find first value < largest
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            secondLargest = arr[i];
            break;
        }
    }

    // Output the second largest (or sentinel if none)
    cout << "Second largest element is: " << secondLargest;

    return 0;
}