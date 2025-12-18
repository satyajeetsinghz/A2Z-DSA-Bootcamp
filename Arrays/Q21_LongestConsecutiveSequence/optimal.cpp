/*
 * Longest Consecutive Sequence — Optimal (Hash Set) Approach
 *
 * Problem: Given an unsorted integer array, find the length of the longest
 *          consecutive sequence that can be formed from its elements.
 *          Example: [100, 4, 200, 1, 3, 2] → longest run is [1,2,3,4], length = 4.
 *
 * Algorithm (Hash Set, O(N) average time):
 * 1) Insert all numbers into an unordered_set for O(1) average membership checks.
 * 2) For each number x, only start a run if (x-1) is NOT in the set — this ensures
 *    x is the beginning of a run and avoids recounting the same sequence.
 * 3) From such a start, incrementally check x+1, x+2, ... while they exist in the set
 *    to measure the run length.
 * 4) Track the maximum run length found.
 *
 * Complexity:
 * - Time: O(N) average (each element inserted once, each run traversed once).
 *         Note: worst-case can degrade depending on hash behavior, but average is O(1) per op.
 * - Space: O(N) for the hash set.
 *
 * Notes:
 * - The "start-of-run" check (absent x-1) is the key to visiting each sequence once.
 * - Duplicates are naturally handled by the set; they don't affect run length.
 */

#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    // Sample input array
    int arr[] = {100, 102, 1, 4, 20, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // STEP 1: Insert all values into a hash set for O(1) average lookups.
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int longest = 0;

    // STEP 2: Try to start a sequence only at true starts (x-1 not present).
    // Why: Ensures each consecutive run is counted only once.
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i] - 1) == st.end())
        {
            int current = arr[i];
            int count = 1;

            // STEP 3: Extend the run to the right while next values exist.
            while (st.find(current + 1) != st.end())
            {
                current++;
                count++;
            }

            // STEP 4: Update the best answer.
            longest = max(longest, count);
        }
    }

    cout << "Longest Consecutive Sequence is: " << longest;
    return 0;
}