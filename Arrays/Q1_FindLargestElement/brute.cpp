/*
 * Find Largest Element - Brute Force (Pairwise Comparison)
 *
 * Problem: Given an array, determine the maximum element.
 *
 * Approach (O(n^2)):
 * - For each element `arr[i]`, check against every other element `arr[j]`.
 * - If any `arr[j] > arr[i]`, then `arr[i]` cannot be the maximum.
 * - If no larger element exists for `arr[i]`, record it as the maximum.
 *
 * Notes:
 * - This is the naive method; use a single-pass O(n) scan for an optimal solution.
 * - Space usage is O(1); time is O(n^2) due to the nested loop.
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array and its size
    int arr[6] = {1, 2, 2, 5, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize with any array element (updated when we confirm a max)
    int largest = arr[0];

    // For each element, verify that no other element is greater
    for (int i = 0; i < n; i++)
    {
        bool isMax = true; // assume arr[i] is max until disproved

        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                isMax = false; // found a larger element
                break;          // no need to continue inner loop
            }
        }

        // If none greater than arr[i], it is the maximum
        if (isMax)
        {
            largest = arr[i];
        }
    }

    // Output the result
    cout << "Largest element (Brute): " << largest << endl;

    return 0;
}