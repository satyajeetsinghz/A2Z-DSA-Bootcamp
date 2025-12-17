/*
 * Remove Duplicates from a Sorted Array - Optimal (In-Place Two Pointers)
 *
 * Problem: Given a sorted array, remove duplicates in-place so that each
 * element appears only once and return the count of unique elements. The
 * first `uniqueCount` positions of the array should contain the unique values
 * in order.
 *
 * Idea (Two pointers):
 * - Maintain `i` as the index of the last unique value placed so far.
 * - Scan `j` from 1..n-1. When `arr[j] != arr[i]`, advance `i` and copy
 *   `arr[j]` to `arr[i]` (writing the next unique into place).
 * - After the scan, the unique count is `i + 1` (handles n >= 1). For n == 0,
 *   unique count is 0 (add a guard if you generalize).
 *
 * Complexity:
 * - Time: O(n) single pass
 * - Space: O(1) extra (in-place)
 */

#include <iostream>
using namespace std;

int main()
{
    // Input: sorted array
    int arr[] = {1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Edge case note: for n == 0, uniqueCount is 0 (not illustrated here)

    // `i` tracks the position of the last unique element written
    int i = 0;

    // Scan with `j` to find next unique values and compact them to the front
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;          // move to next write position
            arr[i] = arr[j]; // write the newly found unique value
        }
    }

    // Length of unique prefix is i + 1 when n > 0
    int uniqueCount = i + 1;

    // Output the result prefix
    cout << "Unique elements count = " << uniqueCount << endl;
    cout << "Array after removing duplicates: ";
    for (int k = 0; k < uniqueCount; k++)
        cout << arr[k] << " ";

    return 0;
}