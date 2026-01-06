/*
 * LeetCode 441: Arranging Coins — Brute Force
 *
 * Problem: With n coins, build a staircase where the k-th row has exactly k coins.
 *          Return how many complete rows can be formed.
 *          Example: n=5 → rows [1,2] full, row 3 incomplete → answer = 2.
 *
 * Algorithm (incremental subtraction):
 * 1) Start with row size = 1.
 * 2) While you have enough coins for the current row, subtract row size from n,
 *    then move to the next row (row size + 1).
 * 3) When you cannot fill the next row, the previous row count is the answer.
 *
 * Complexity:
 * - Time: O(answer) ≈ O(sqrt(n)) because 1 + 2 + ... + k ~ k^2/2 ≈ n.
 * - Space: O(1) extra.
 *
 * Notes:
 * - A math/closed-form O(1) solution exists via quadratic formula; this keeps it simple.
 */

#include <iostream>
using namespace std;

// Return how many full rows can be built with n coins
int arrangeCoins(int n)
{
    int currentRow = 1; // coins needed for the current row

    // STEP 1: Keep forming rows while enough coins remain
    while (n >= currentRow)
    {
        n -= currentRow; // spend coins on this row
        currentRow++;    // next row needs one more coin than current
    }

    // STEP 2: currentRow is now one past the last full row
    return currentRow - 1;
}

int main()
{
    int n; // total coins available
    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Maximum full rows: " << arrangeCoins(n);
    return 0;
}
