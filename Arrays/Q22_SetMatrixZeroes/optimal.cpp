/*
 * Set Matrix Zeroes — Optimal (O(1) extra space with first row/col as markers)
 *
 * Problem: Given an MxN matrix, if any element is 0, set its entire row and
 *          column to 0. Achieve O(1) extra space by reusing matrix itself.
 *
 * Algorithm (In-place marker technique):
 * 1) Check if the first column has any 0 and store in firstColZero flag.
 *    (Can't use matrix[i][0] directly as a marker since we need its original state.)
 * 2) Scan matrix; use matrix[i][0] and matrix[0][j] as markers for row i and col j.
 * 3) Scan inner matrix again; zero out cells where their row/col marker is 0.
 * 4) Handle the first row based on matrix[0][0] marker.
 * 5) Handle the first column based on the firstColZero flag.
 *
 * Complexity:
 * - Time: O(M*N) for three passes.
 * - Space: O(1) extra space (only one boolean flag).
 *
 * Notes:
 * - Reuses first row and first column as a marker grid to track which rows/cols to zero.
 * - Order of operations ensures markers aren't overwritten prematurely.
 */

#include <iostream>
using namespace std;
int main()
{
    // Sample 3x3 matrix
    int matrix[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    int rows = 3; // number of rows
    int cols = 3; // number of columns

    // Flag to remember if first column itself needs to be zeroed
    bool firstColZero = false;

    // STEP 1: Check and mark the first column separately.
    // Why: We need matrix[i][0] as a marker for later steps, so we must store
    // the first column's zero status before using matrix[*][0] as markers.
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0) // if any cell in first column is 0, remember it
        {
            firstColZero = true; // we'll zero the entire first column later
        }

        // STEP 2: Mark rows and columns based on zeros found (skip first column).
        // Why: Use matrix[i][0] to mark row i, matrix[0][j] to mark column j.
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0) // found a zero in row i, column j
            {
                matrix[i][0] = 0; // mark row i by setting matrix[i][0] = 0
                matrix[0][j] = 0; // mark column j by setting matrix[0][j] = 0
            }
        }
    }

    // STEP 3: Use markers to zero out the inner matrix.
    // Why: If row i is marked (matrix[i][0] == 0) or column j is marked (matrix[0][j] == 0),
    // then matrix[i][j] should be 0. Start from (1,1) to preserve markers.
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) // row i or column j is marked
            {
                matrix[i][j] = 0; // zero this cell
            }
        }
    }

    // STEP 4: Zero the first row if matrix[0][0] was marked.
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[0][j] = 0; // zero entire first row
        }
    }

    // STEP 5: Zero the first column if it had any zeros originally.
    if (firstColZero)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0; // zero entire first column
        }
    }

    return 0;
}