/*
 * Leaders in Array — Brute Force
 *
 * Problem: For a given integer array, an element is a leader if it is
 *          not smaller than any element to its right
 *          (i.e., arr[i] >= arr[j] for all j > i).
 *
 * Algorithm (Brute Force):
 * 1. For each index i from 0 to n-1, assume arr[i] is a leader.
 * 2. Scan the suffix (i+1 ... n-1). If any arr[j] > arr[i], mark it not a leader.
 * 3. If still a leader after the scan, output arr[i].
 *
 * Complexity:
 * - Time: O(N^2) due to the nested scan for each index.
 * - Space: O(1) extra space.
 *
 * Notes:
 * - The last element is always a leader (no elements to its right).
 * - With duplicates, this implementation treats equality as allowed (>=).
 * - For large N, prefer the optimal O(N) approach scanning from right while
 *   maintaining the running maximum.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array for which we will print all leaders
    int arr[] = {12, 14, 16, 7, 6, 2, 5};

    // Compute the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // STEP 1: Consider each element as a candidate leader
    for (int i = 0; i < n; i++)
    {
        // Assume current element is a leader until a larger element to its right is found
        bool isLeader = true;

        // STEP 2: Check elements to the right of current index i
        for (int j = i + 1; j < n; j++)
        {
            // If any right-side element is strictly greater, arr[i] cannot be a leader
            if (arr[j] > arr[i])
            {
                isLeader = false;
                break; // Early exit: no need to check further
            }
        }

        // STEP 3: If still a leader after the scan, print it
        if (isLeader)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}