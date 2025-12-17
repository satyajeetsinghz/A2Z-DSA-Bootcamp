/*
 * Intersection of Two Sorted Arrays (with duplicates) - Two Pointers (Optimal)
 *
 * Problem: Given two sorted arrays, print their intersection including duplicates.
 * For each common value x, output it as many times as it appears in both arrays
 * (i.e., min(count in A, count in B)).
 *
 * Approach: Two-pointer linear scan leveraging sorted order
 * - Maintain indices i (arr1) and j (arr2)
 * - If arr1[i] == arr2[j], it's a common element → push and advance both
 * - If arr1[i] < arr2[j], advance i (need larger value to match)
 * - Else advance j (need smaller value to match)
 *
 * Why it works:
 * - Arrays are sorted, so relative ordering allows skipping impossible matches
 * - Advancing the pointer at the smaller value moves us closer to a potential match
 * - Duplicate handling is natural: equal elements consumed one-by-one from both sides
 *
 * Complexity:
 * - Time: O(n1 + n2) single pass
 * - Space: O(k) for the result (or O(1) if streaming output)
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Sorted input arrays (ascending)
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 5};

    // Compute sizes
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Result container for intersection values (including duplicates)
    vector<int> ans;

    // Two pointers i (arr1) and j (arr2)
    int i = 0, j = 0;

    // Linear merge-style scan over both arrays
    while (i < n1 && j < n2)
    {
        // CASE 1: Equal elements → common, append and advance both
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        // CASE 2: arr1 value is smaller → move i to catch up
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        // CASE 3: arr2 value is smaller → move j to catch up
        else
        {
            j++;
        }
    }

    // Output the intersection sequence
    cout << "Intersection: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}