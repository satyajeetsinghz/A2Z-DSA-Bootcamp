/*
 * LeetCode 69: Sqrt(x)
 *
 * Problem: Given a non-negative integer `x`, return the integer square root of `x`.
 *          The integer square root is the largest integer `y` such that y * y <= x.
 *          Example: x = 8 → sqrt(8) = 2 (since 2*2=4 <= 8 and 3*3=9 > 8).
 *
 * Approach (Binary Search):
 * - Use binary search on the range [1, x] to find the largest number whose square
 *   is <= x.
 * - For each mid value, check if mid*mid <= x using division (mid <= x/mid) to
 *   avoid overflow with large integers.
 * - If mid satisfies the condition, it could be the answer; move right to search
 *   for potentially larger values.
 * - Otherwise, mid is too large; search left.
 * - Return the largest mid found that satisfies mid*mid <= x.
 *
 * Complexity:
 * - Time: O(log x) binary search
 * - Space: O(1) constant extra space
 *
 * Notes:
 * - Edge case: x < 2 returns x itself (sqrt(0)=0, sqrt(1)=1).
 * - Division check (mid <= x/mid) avoids overflow on mid*mid.
 * - Works correctly for all non-negative integers.
 */

#include <iostream>
using namespace std;

// Find the integer square root of x using binary search
// Returns the largest integer y such that y*y <= x
int findSqrt(int x)
{
    // STEP 0: Handle edge cases
    if (x < 2)
        return x;

    // STEP 1: Initialize binary search bounds and result variable
    long long low = 1, high = x, ans = 0;

    // STEP 2: Binary search for the square root
    while (low <= high)
    {
        // Calculate mid-point using addition to avoid overflow
        long long mid = low + (high - low) / 2;

        // Check if mid*mid <= x using division to avoid overflow
        if (mid <= x / mid)
        {
            // mid is valid, store it and search for potentially larger values
            ans = mid;
            low = mid + 1;
        }
        else
        {
            // mid is too large, search in the smaller half
            high = mid - 1;
        }
    }

    // STEP 3: Return the largest valid square root found
    return ans;
}

int main()
{
    // Example: Find integer square root of 9
    int x = 64;
    cout << "Sqrt of " << x << " is " << findSqrt(x);

    return 0;
}