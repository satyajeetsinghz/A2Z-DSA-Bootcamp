/*
 * Intersection of Two Arrays (with duplicates) - Brute Force using Visited Flags
 *
 * Problem: Given two (sorted) arrays, print their intersection including
 * duplicates. For each common value x, it should appear in the output as many
 * times as it appears in both arrays (min count across arrays).
 *
 * Approach: Nested loops with a `visited` array for arr2
 * - For each element in arr1, scan arr2 to find the first unmatched equal value
 * - Use a boolean `visited[j]` to ensure arr2[j] is used at most once
 * - When matched, push value to result and mark visited; break to avoid reusing
 *
 * Notes:
 * - Works regardless of arrays being sorted; sorting is not exploited here
 * - Handles duplicates correctly by preventing reuse of the same position in arr2
 *
 * Complexity:
 * - Time: O(n1 * n2) due to nested scans
 * - Space: O(n2) for the `visited` flags and O(k) for the result
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Input arrays (sorted in this example, but algorithm does not rely on sorting)
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 5};

    // Compute lengths of both arrays
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Result container for the intersection values (including duplicates)
    vector<int> ans;

    // `visited[j]` indicates whether arr2[j] has already been matched/used
    // Prevents counting the same occurrence from arr2 more than once
    vector<bool> visited(n2, false);

    // Outer loop: iterate each element of arr1 as a candidate
    for (int i = 0; i < n1; i++)
    {
        // Inner loop: scan arr2 to find a matching, unused occurrence
        for (int j = 0; j < n2; j++)
        {
            // Match found and not used yet → add to answer and mark as used
            if (arr1[i] == arr2[j] && !visited[j])
            {
                ans.push_back(arr1[i]);
                visited[j] = true;
                // Important: break to ensure each arr1[i] consumes at most one arr2[j]
                break;
            }
        }
    }

    // Print the resulting intersection sequence
    cout << "Intersection: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}