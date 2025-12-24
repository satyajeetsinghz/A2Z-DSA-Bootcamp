/*
 * Rotate Matrix by 90 Degrees Clockwise — Brute Force
 *
 * Problem: Given an NxN square matrix, rotate it 90 degrees clockwise in-place.
 *          Example: [[1,2,3],[4,5,6],[7,8,9]] → [[7,4,1],[8,5,2],[9,6,3]]
 *
 * Algorithm (Brute Force with extra space):
 * 1) Create a new NxN matrix for the rotated result.
 * 2) For each element at position (i, j), place it at position (j, n-1-i) in the new matrix.
 *    This formula rotates 90° clockwise: row i becomes column j, column j becomes row (n-1-i).
 * 3) Copy the rotated matrix back or print it directly.
 *
 * Complexity:
 * - Time: O(N^2) to traverse all N×N cells.
 * - Space: O(N^2) for the extra rotated matrix.
 *
 * Notes:
 * - The rotation formula (i,j) → (j, n-1-i) is the core insight for 90° clockwise.
 * - Prefer the optimal in-place transpose + reverse approach for O(1) extra space.
 * - For counter-clockwise, use (i,j) → (n-1-j, i) instead.
 */

#include <iostream>
using namespace std;
int main()
{
    // Sample 3x3 input matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int n = 3;         // size of the square matrix (NxN)
    int rotated[n][n]; // new matrix to store the 90° clockwise rotated result

    // STEP 1: Map each cell to its rotated position in the new matrix.
    // Why: For a 90° clockwise rotation, element at (i, j) moves to (j, n-1-i).
    //       This formula ensures proper rotation without overwriting.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - 1 - i] = matrix[i][j]; // place matrix[i][j] at rotated position
        }
    }

    // STEP 2: Output the rotated matrix
    // Why: Display the final 90° clockwise rotated result.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << rotated[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}