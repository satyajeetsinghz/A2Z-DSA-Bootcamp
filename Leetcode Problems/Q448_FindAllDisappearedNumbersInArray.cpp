/*
 * LeetCode 448: Find All Numbers Disappeared in an Array
 *
 * Problem: Given an array `nums` of length `n` where each element is in the
 *          range [1, n], some numbers may appear twice and others once. Return
 *          all numbers in [1, n] that do not appear in `nums`.
 *
 * Approach (In-place marking via sign):
 * - For each value `v` in the array, compute index `v-1` and mark that index
 *   as seen by negating `arr[v-1]` if it is positive.
 * - After the marking pass, any position that remains positive indicates the
 *   value `i+1` is missing from the array.
 *
 * Complexity:
 * - Time: O(n) for two linear passes
 * - Space: O(1) extra (ignoring the output list) — we mutate in-place via sign
 *
 * Notes:
 * - Crucial constraint: values must lie within [1, n]. Out-of-range values
 *   will produce invalid indices and break the logic.
 * - If original values are needed later, a final pass can restore with `abs()`.
 */

#include <iostream>
#include <cmath>
using namespace std;

// Marks present numbers by negating at index (value - 1), then prints
// all numbers in [1..n] that never got marked (i.e., stayed positive).
void findDisappeared(int arr[], int n)
{
    // STEP 1: Mark seen numbers by flipping the sign at their mapped index
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0)
        {
            arr[index] = -arr[index];
        }
    }

    // STEP 2: Any index left positive corresponds to a missing number (i + 1)
    cout << "Missing numbers: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{
    // Example usage (ensure values are within [1, n] for correctness under constraints)
    int arr[] = {9, 5, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findDisappeared(arr, n);

    return 0;
}
