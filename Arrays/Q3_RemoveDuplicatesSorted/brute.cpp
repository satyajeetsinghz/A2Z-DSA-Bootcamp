/*
 * Remove Duplicates from a Sorted Array - Brute Approach (Using std::set)
 *
 * Problem: Given a sorted array, remove duplicates so that each element
 * appears only once, and report the count of unique elements.
 *
 * Approach:
 * - Insert all elements into a std::set (stores unique, ordered values).
 * - Copy the set contents back into the original array's prefix.
 * - The number of unique elements equals the set size.
 *
 * Trade-offs:
 * - Simpler to write but uses O(n) extra memory and O(n log n) time due to
 *   balanced tree insertions. Since the input is already sorted, more optimal
 *   O(1) extra space, O(n) time in-place two-pointer solutions exist.
 *
 * Complexity:
 * - Time: O(n log n) (n inserts into set)
 * - Space: O(n) for the set
 */

#include <iostream>
#include <set>
using namespace std;

int main()
{
    // Input sorted array; duplicates exist
    int arr[] = {1, 1, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Collect unique elements in sorted order using set
    set<int> st;

    // Insert every element; set keeps only one of each value
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    // Copy unique values back into the array's prefix
    int idx = 0;
    for (auto x : st)
    {
        arr[idx++] = x;
    }

    // Output the count and the de-duplicated prefix
    cout << "Unique element count: " << idx << endl;
    cout << "New array (no duplicates) ";
    for (int i = 0; i < idx; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}