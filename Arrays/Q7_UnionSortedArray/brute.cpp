/*
 * Union of Two Sorted Arrays - Set-based (Brute/Easy) Approach
 *
 * Problem: Given two arrays (possibly with duplicates), return their union
 * containing all distinct elements present in either array, in sorted order.
 *
 * Approach: Insert all elements from both arrays into an ordered set
 * - `std::set` stores unique elements and maintains them in ascending order
 * - Insert all elements from arr1 and arr2; duplicates are automatically ignored
 * - Iterate the set to print the union
 *
 * Notes:
 * - Works even if input arrays are not sorted (sorting guaranteed by set)
 * - This outputs distinct elements only (true union), not multiset union
 *
 * Complexity:
 * - Let M = n1 + n2 total insertions
 * - Time: O(M log M) due to ordered set insertions (logarithmic per insert)
 * - Space: O(U) where U is number of unique elements across both arrays
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    // Sample inputs (contain duplicates); union should contain distinct values in sorted order
    int arr1[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int arr2[] = {2, 3, 3, 4, 5, 5, 6};

    // Compute lengths of the input arrays
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Ordered set to accumulate distinct elements from both arrays
    set<int> st;

    // Insert all elements from the first array; duplicates are ignored by set
    for (int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
    }

    // Insert all elements from the second array; duplicates are ignored by set
    for (int i = 0; i < n2; i++)
    {
        st.insert(arr2[i]);
    }

    // Print the union (distinct elements) in ascending order
    cout << "Union: ";
    for (int x : st)
    {
        cout << x << " ";
    }

    return 0;
}