/*
 * Left Rotate Array by One Place - Simple/Brute Approach
 *
 * Problem: Given an array of size n, rotate it left by exactly one position
 * while preserving the relative order of the remaining elements.
 *
 * Approach:
 * 1) Save the first element in a temporary variable
 * 2) Shift all elements one position to the left (i from 1..n-1 → arr[i-1]=arr[i])
 * 3) Place the saved element at the end (arr[n-1] = temp)
 *
 * Properties:
 * - Stable with respect to rotation semantics
 * - No extra allocations (O(1) extra space)
 *
 * Complexity:
 * - Time: O(n) due to one linear pass for shifting
 * - Space: O(1) extra
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array and its size
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // STEP 1: Store the first element before overwriting it
    int temp = arr[0];

    // STEP 2: Shift elements one position to the left
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    // STEP 3: Put the saved first element at the last position
    arr[n - 1] = temp;

    // Print the rotated array
    cout << "Array after left rotation by one place: ";
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}