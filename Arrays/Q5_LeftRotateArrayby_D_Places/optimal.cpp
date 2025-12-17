/*
 * Left Rotate Array by D Places - Optimal (Reversal Algorithm)
 *
 * Problem: Rotate an array to the left by D positions while preserving the
 * relative order of elements.
 *
 * Idea (Reversal Technique):
 * - Reverse the first D elements
 * - Reverse the remaining (n - D) elements
 * - Reverse the whole array
 * This sequence transforms [A B] -> [A^R B^R] -> [ (A^R B^R)^R ] = [B A]
 * which is a left rotation by D.
 *
 * Notes:
 * - Normalize D via D %= n to handle D >= n; when D == 0, the array remains
 *   unchanged. Assumes n > 0 for meaningful rotation.
 * - In-place and stable with respect to rotation semantics (relative order
 *   inside the moved block preserved in the final arrangement).
 *
 * Complexity:
 * - Time: O(n) overall (each element participates in at most 3 swaps)
 * - Space: O(1) extra (in-place)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Input array and its size
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Number of left-rotation positions
    int d = 2;

    // Normalize D to avoid redundant full rotations
    d = d % n;

    // STEP 1: Reverse the first D elements: [0, d)
    reverse(arr, arr + d);

    // STEP 2: Reverse the remaining elements: [d, n)
    reverse(arr + d, arr + n);

    // STEP 3: Reverse the whole array: [0, n)
    reverse(arr, arr + n);

    // Print rotated array
    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}