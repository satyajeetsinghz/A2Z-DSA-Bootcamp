/*
 * Move All Zeros to End - Optimal In-Place Two-Pointer Approach
 *
 * Problem: Given an integer array, move all zeros to the end while preserving
 * the relative order of non-zero elements. Do this in-place with O(1) extra space.
 *
 * Approach (Two Pointers - compaction via first-zero index):
 * - Find the index `j` of the first zero in the array. If there is no zero,
 *   the array is already in the desired state.
 * - Scan the rest of the array from `i = j+1` to end:
 *   - When a non-zero is found at `i`, swap it with the element at `j`.
 *   - Increment `j` to point to the next zero position.
 * - This compacts non-zeros to the front in their original relative order
 *   and shifts zeros towards the end.
 *
 * Stability:
 * - Relative order of non-zero elements is preserved.
 * - Zeros are gathered to the tail.
 *
 * Complexity:
 * - Time: O(n) single pass after the initial first-zero search
 * - Space: O(1) in-place
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array (can contain zero and non-zero values)
    // Note: This example currently has no zeros; the early-exit path will print as-is
    int arr[] = {1, 2, 4, 3, 5};

    // Number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // `j` will store the index of the first zero encountered; -1 means no zero found yet
    int j = -1;

    // STEP 1: Find the first zero's index; this becomes the initial write position
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // If no zero exists, array is already in correct form; print and exit
    if (j == -1)
    {
        cout << "Result: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        return 0;
    }

    // STEP 2: Sweep remaining elements; swap non-zeros into the zero slots and advance `j`
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            // Place the non-zero at the earliest zero position, preserving order
            swap(arr[i], arr[j]);
            j++;
        }
    }

    // Output the result after moving zeros to the end
    cout << "Result: ";
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";

    return 0;
}