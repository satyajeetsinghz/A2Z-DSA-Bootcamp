/*
 * Missing Number (1..N) - Optimal XOR Approach
 *
 * Problem: Given an array of unique integers from 1..N with exactly one
 * missing value, find the missing number in O(N) time and O(1) space.
 *
 * Algorithm: XOR from 1..N with XOR of all array elements
 * - Let A = (1 ^ 2 ^ 3 ^ ... ^ N)
 * - Let B = (arr[0] ^ arr[1] ^ ... ^ arr[size-1])
 * - Missing number = A ^ B (since pairs cancel out by XOR properties)
 *
 * XOR Properties used:
 * - a ^ a = 0 (same numbers cancel)
 * - a ^ 0 = a (identity)
 * - Commutative and associative → order doesn't matter
 *
 * Assumptions:
 * - Array contains distinct numbers strictly within [1..N]
 * - Exactly one number is missing (no duplicates, no zeros)
 *
 * Complexity:
 * - Time: O(N) (two linear passes)
 * - Space: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array containing numbers from 1..n with exactly one missing
    int arr[] = {1, 2, 4, 5};

    // The expected upper bound of the range [1..n]
    int n = 5;

    // Compute the number of provided elements in the input array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Accumulators for XOR values
    // xor1 will store XOR of all numbers from 1..n
    // xor2 will store XOR of all elements present in the array
    int xor1 = 0, xor2 = 0;

    // XOR all integers from 1 through n
    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }

    // XOR all elements of the given array
    for (int i = 0; i < size; i++)
    {
        xor2 ^= arr[i];
    }

    // Missing number emerges by canceling common terms: (1^2^...^n) ^ (arr elements)
    int missing = xor1 ^ xor2;

    // Output the result
    cout << "Missing number is: " << missing;

    return 0;
}