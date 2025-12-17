/*
 * Find Largest Element - Optimal (Single-Pass Scan)
 *
 * Problem: Given an array, find the maximum element efficiently.
 *
 * Approach:
 * - Initialize `largest` with the first element.
 * - Scan once through the array; whenever a value exceeds `largest`, update it.
 * - This is the optimal O(n) approach with O(1) extra space.
 *
 * Notes:
 * - For empty arrays, you'd guard before reading arr[0].
 * - Works correctly with duplicates and any integer values.
 *
 * Complexity:
 * - Time: O(n)
 * - Space: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array and its size
    int arr[6] = {1, 2, 22, 50, 4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize running maximum with the first element
    int largest = arr[0];

    // Single pass: update `largest` whenever we see a bigger value
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    // Output the result
    cout << "Largest element (Optimal): " << largest << endl;

    return 0;
}