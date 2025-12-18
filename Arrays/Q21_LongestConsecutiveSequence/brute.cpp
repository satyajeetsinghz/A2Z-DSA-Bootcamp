/*
 * Longest Consecutive Sequence — Brute Force
 *
 * Problem: Given an unsorted integer array, find the length of the longest
 *          consecutive sequence that can be formed from its elements.
 *          Example: [100, 4, 200, 1, 3, 2] → longest run is [1,2,3,4], length = 4.
 *
 * Algorithm (Brute Force):
 * 1) For each element arr[i], treat it as a potential start of a sequence.
 * 2) Repeatedly check if (current + 1) exists anywhere in the array (linear scan).
 * 3) Count how far we can extend and track the maximum length across all starts.
 *
 * Complexity:
 * - Time: O(N^3) worst case (N starts × up to N extensions × O(N) search each).
 * - Space: O(1) extra space.
 *
 * Notes:
 * - Duplicates neither extend nor break a run; they are just skipped by search.
 * - Prefer the sorting O(N log N) or hash-set O(N) approaches for large inputs.
 */

#include <iostream>
using namespace std;

// Linear membership check used by the brute-force extension step.
bool LinearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Sample input
    int arr[] = {100, 102, 1, 4, 20, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // STEP 1: Initialize the best length found so far.
    // Why: We'll try every index as a start and keep the maximum length.
    int longest = 1;

    // STEP 2: For each element, greedily extend the sequence to the right.
    // Why: Consecutive sequences grow by +1 increments if present in the array.
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;

        // STEP 3: While the next integer exists, extend the current run.
        // Why: LinearSearch is O(N), making this approach brute-force.
        while (LinearSearch(arr, n, x + 1))
        {
            x++;
            count++;
        }

        // STEP 4: Update the global maximum length.
        longest = max(longest, count);
    }

    cout << "Longest Consecutive Sequence is: " << longest;
    return 0;
}