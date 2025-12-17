/*
 * Missing Number (1..N) - Brute Force via Sum Formula
 *
 * Problem: Given N and an array containing numbers from 1..N with exactly one
 * number missing (no duplicates), find the missing number.
 *
 * Approach: Use Gauss' Summation Formula
 * - Sum of 1..N is: N*(N+1)/2
 * - Missing = (sum of 1..N) - (sum of given elements)
 *
 * Assumptions:
 * - The array contains unique integers strictly within [1..N] except one missing value
 * - Exactly one number is missing
 *
 * Caveats:
 * - For very large N or values, prefer using 64-bit (long long) to avoid overflow
 *
 * Complexity:
 * - Time: O(actualSize) to sum array elements
 * - Space: O(1) auxiliary space
 */

#include <iostream>
using namespace std;

int main()
{
    // Input array containing numbers from the range [1..n] with one missing
    int arr[] = {1, 2, 4, 5};

    // Upper bound N of the expected full range [1..N]
    // Note: This represents the intended range, not the array length
    int n = 5;

    // Compute the actual number of elements provided in the input array
    int actualSize = sizeof(arr) / sizeof(arr[0]);

    // Accumulate the sum of the provided elements
    int actualSum = 0;
    for (int i = 0; i < actualSize; i++)
    {
        actualSum += arr[i];
    }

    // Compute the theoretical sum of a complete 1..N sequence using Gauss' formula
    int totalSum = n * (n + 1) / 2;

    // The missing number is the difference between theoretical and actual sums
    int missingNumber = totalSum - actualSum;

    // Output the identified missing number
    cout << "Missing number is: " << missingNumber;

    return 0;
}