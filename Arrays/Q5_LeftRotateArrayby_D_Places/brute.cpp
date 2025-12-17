/*
 * Left Rotate Array by D Places - Brute/Easy (Using Temp Buffer)
 *
 * Problem: Given an array and an integer D, rotate the array to the left by D
 * positions while preserving the relative order of elements.
 *
 * Approach: Three-step buffer method with a temporary array of size D
 * 1) Copy the first D elements to a temp buffer
 * 2) Shift the remaining (n-D) elements left by D positions
 * 3) Copy the D buffered elements to the array tail
 *
 * Notes:
 * - We apply D %= n to support D >= n (effective rotation)
 * - Stable rotation: relative order preserved
 *
 * Complexity:
 * - Time: O(n) with two linear passes and a tail copy
 * - Space: O(D) extra buffer
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array and its length
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Number of left-rotation positions
    int d = 2; // Rotate left by 2 places

    // Normalize D in case it is >= n (no-op when D == 0)
    d = d % n; // Handle case for d >= n

    // Temporary buffer to hold the first D elements
    int temp[d];

    // STEP 1: Copy the first D elements into temp
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    // STEP 2: Shift the remaining elements left by D positions
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // STEP 3: Place the buffered elements at the tail, preserving order
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }

    // Print rotated array
    cout << "Array after [D=2] rotation: ";
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
}