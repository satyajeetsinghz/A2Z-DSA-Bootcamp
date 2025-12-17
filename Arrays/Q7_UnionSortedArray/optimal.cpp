/*
 * Union of Two Sorted Arrays - Optimal Two-Pointer Merge (Distinct Output)
 *
 * Problem: Given two sorted arrays (may contain duplicates), produce their union
 * as a sorted list of DISTINCT values (each value appears at most once).
 *
 * Approach: Two pointers with duplicate skipping via last-pushed check
 * - Maintain indices i (arr1) and j (arr2)
 * - Compare arr1[i] and arr2[j]:
 *   - If arr1[i] < arr2[j], candidate is arr1[i] → push if new, i++
 *   - If arr2[j] < arr1[i], candidate is arr2[j] → push if new, j++
 *   - Else equal: push once (if new) and advance both
 * - After one array ends, append remaining values from the other array, still skipping duplicates
 *
 * De-duplication strategy:
 * - Before pushing, check `unionArr.empty() || unionArr.back() != candidate`
 * - Ensures each distinct value appears only once in the result
 *
 * Complexity:
 * - Time: O(n1 + n2) single linear pass
 * - Space: O(u) for u distinct elements (output size)
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Sorted input arrays (contain duplicates)
    int arr1[] = {1, 2, 2, 3, 4, 4, 5, 6};
    int arr2[] = {2, 3, 3, 4, 5, 5};

    // Compute sizes
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Result container for distinct union values in sorted order
    vector<int> unionArr;

    // Two-pointer indices for arr1 and arr2
    int i = 0, j = 0;

    // Merge-like scan while both arrays have remaining elements
    while (i < n1 && j < n2)
    {
        // CASE 1: arr1 has the smaller value → consider arr1[i]
        if (arr1[i] < arr2[j])
        {
            if (unionArr.empty() || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        // CASE 2: arr2 has the smaller value → consider arr2[j]
        else if (arr2[j] < arr1[i])
        {
            if (unionArr.empty() || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        // CASE 3: Values are equal → add once, advance both
        else
        {
            if (unionArr.empty() || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Drain remaining elements from arr1 (skip duplicates)
    while (i < n1)
    {
        if (unionArr.empty() || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    // Drain remaining elements from arr2 (skip duplicates)
    while (j < n2)
    {
        if (unionArr.empty() || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    // Output distinct union
    cout << "Union: ";
    for (int x : unionArr)
    {
        cout << x << " ";
    }

    return 0;
}