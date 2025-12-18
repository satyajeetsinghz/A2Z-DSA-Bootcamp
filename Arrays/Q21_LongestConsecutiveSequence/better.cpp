/*
 * Longest Consecutive Sequence — Sorting (Better) Approach
 *
 * Problem: Given an unsorted integer array, find the length of the longest
 *          consecutive sequence that can be formed from its elements.
 *          Example: [100, 4, 200, 1, 3, 2] → longest run is [1,2,3,4], length = 4.
 *
 * Algorithm (Sorting):
 * 1) Sort the array so that any consecutive numbers become neighbors.
 * 2) Scan once, growing the current run when arr[i] == arr[i-1] + 1.
 * 3) If arr[i] is a duplicate of arr[i-1], ignore it (doesn’t extend or break).
 * 4) Otherwise, reset the current run to length 1.
 * 5) Track the maximum run length seen.
 *
 * Complexity:
 * - Time: O(N log N) for sorting + O(N) for the linear scan.
 * - Space: O(1) extra beyond sorting (std::sort uses O(log N) stack space).
 *
 * Notes:
 * - Duplicates are handled by “do nothing” on equality; they don’t reset or extend.
 * - Prefer the hash-set approach for true O(N) average time.
 */

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    // Sample input array
    int arr[] = {100, 102, 1, 4, 20, 3, 2};
    // Compute number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // STEP 1: Sort the array so consecutive values become adjacent.
    // Why: This enables a single linear pass to count consecutive runs.
    sort(arr, arr + n);

    // STEP 2: Sweep once while tracking the current and longest run lengths.
    // Why: After sorting, we only need to compare each element with its neighbor.
    int longest = 1;
    int current = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            // Consecutive neighbor → extend current run
            current++;
        }
        else if (arr[i] != arr[i - 1])
        {
            // Not consecutive and not a duplicate → reset run
            // Why duplicates? If arr[i] == arr[i-1], do nothing (neither extend nor reset)
            current = 1;
        }

        // STEP 3: Update the best run length so far.
        longest = max(longest, current);
    }

    cout << "Longest Consecutive Sequence is: " << longest;

    return 0;
}