/*
 * Move All Zeros to End - Brute/Easy Approach (Using Extra Array)
 *
 * Problem: Given an integer array, move all zeros to the end while preserving
 * the relative order of non-zero elements.
 *
 * Approach: Stable partition into a temporary array
 * - First pass: copy all non-zero elements to `temp` from left to right
 * - Second pass: fill the remaining positions in `temp` with zeros
 * - Print (or copy back) the result
 *
 * Properties:
 * - Stability preserved for non-zero elements (relative order unchanged)
 *
 * Complexity:
 * - Time: O(n) two linear passes
 * - Space: O(n) extra array `temp`
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array containing both zero and non-zero values
    int arr[] = {1, 2, 0, 3, 4, 0, 3, 5};

    // Compute the number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Temporary array to store the rearranged elements (non-zeros first)
    int temp[n];

    // Write index for the temp array (next position to fill with a non-zero)
    int index = 0;

    // PASS 1: Copy all non-zero elements to temp in their original order
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[index++] = arr[i];
        }
    }

    // PASS 2: Fill the remaining positions with zeros
    while (index < n)
    {
        temp[index++] = 0;
    }

    // Output the final array with zeros shifted to the end
    cout << "After shifting all zeroes to end: ";
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }

    return 0;
}