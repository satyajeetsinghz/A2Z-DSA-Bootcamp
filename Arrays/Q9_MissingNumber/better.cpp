/*
 * Missing Number(s) from 1..N - Better Approach using Presence Array (Hashing)
 * 
 * Problem: Given an array of integers containing numbers in the range [1..N]
 * with some numbers possibly missing, find the missing number(s).
 * 
 * Assumptions:
 * - Input numbers are intended to be within 1..N (inclusive). Values > N are ignored.
 * - This prints ALL missing values between 1 and N (not just a single one).
 * 
 * Approach: Presence Hashing
 * - Create a boolean/presence array `hash` of size N+1 (index 0 unused)
 * - Mark `hash[x] = 1` when value x appears in the input array
 * - Iterate from 1..N and print all indices where `hash[i] == 0`
 * 
 * Complexity:
 * - Time: O(N + actualSize) → O(N) overall
 * - Space: O(N) for the presence array
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Input array with values in the range [1..N]; example has 3 missing
    // Present values: {1, 2, 4, 5}; Missing in 1..5 is: {3}
    int arr[] = {1, 2, 4, 5};

    // Compute the number of provided elements in the input array
    int actualSize = sizeof(arr) / sizeof(arr[0]);

    // The upper bound N of the expected range [1..N]
    // Change N as per problem constraints/input
    int N = 5;

    // Presence array of size N+1 (ignore index 0) initialized to 0 (not seen)
    // When a value v in [1..N] is observed, we set hash[v] = 1
    vector<int> hash(N + 1, 0);

    // Mark presence of each valid value from the input array
    for (int i = 0; i < actualSize; i++)
    {
        // Guard: only mark values that fall within 1..N
        if (arr[i] >= 1 && arr[i] <= N)
        {
            hash[arr[i]] = 1;
        }
    }

    // Report all numbers in 1..N that were not present in the input
    cout << "Missing Number(s): ";
    for (int i = 1; i <= N; i++)
    {
        // If not seen, then i is missing
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}