/*
 * Find Largest Element - "Better" Approach (Sorting)
 *
 * Problem: Given an array, find the maximum (largest) element.
 *
 * Approach (Sort then pick last):
 * - Sort the array in non-decreasing order, then the last element is the largest.
 * - This is simple but not optimal for just finding a maximum.
 *
 * Trade-offs:
 * - Sorting costs O(n log n) vs. a single-pass O(n) scan that tracks the max.
 * - Use sorting only if you also need the array ordered for other reasons.
 *
 * Complexity:
 * - Time: O(n log n)
 * - Space: O(1) extra (implementation-dependent)
 */

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    // Input array and its size
    int arr[6] = {1, 2, 22, 5, 4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array so the largest value moves to the end
    sort(arr, arr + n);

    // After sorting, the last element is the maximum
    int largest = arr[n - 1];

    // Output the result
    cout << "Largest element (Better): " << largest << endl;

    return 0;
}