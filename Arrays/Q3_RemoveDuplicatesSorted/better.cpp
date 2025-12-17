/*
 * Remove Duplicates from a Sorted Array - Better Approach (Using Temp Buffer)
 *
 * Problem: Given a sorted array, create a de-duplicated sequence that keeps
 * exactly one occurrence of each value and report the count of unique values.
 *
 * Approach (Single scan with adjacent comparison):
 * - Because the array is sorted, duplicates appear in contiguous runs.
 * - Scan i from 0..n-2, and whenever arr[i] != arr[i+1], copy arr[i] to temp.
 * - After the loop, also copy the last element arr[n-1] (it closes the final run).
 * - The resulting temp[0..j-1] holds all unique elements in order.
 *
 * Notes:
 * - Requires O(n) extra space for the temp buffer (this is the "better" (simple)
 *   approach; the optimal O(1) extra space solution uses two pointers in-place).
 * - Assumes n > 0; handle empty arrays separately if generalizing.
 *
 * Complexity:
 * - Time: O(n) single pass
 * - Space: O(n) for the temporary array
 */

#include <iostream>
using namespace std;

int main()
{
    // Input sorted array; duplicates occur in contiguous groups
    int arr[] = {1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Temporary buffer to collect unique elements in order
    int temp[n];
    int j = 0; // length of the unique sequence we are building

    // Copy an element whenever the next element differs
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            temp[j++] = arr[i];
        }
    }

    // Close the final run by adding the last element
    temp[j++] = arr[n - 1];

    // Output the count and the de-duplicated sequence
    cout << "Unique elements count = " << j << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < j; i++)
        cout << temp[i] << " ";

    return 0;
}