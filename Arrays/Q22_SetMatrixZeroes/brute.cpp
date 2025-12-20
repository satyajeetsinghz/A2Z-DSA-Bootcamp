/*
 * Set Matrix Zeroes — Brute Force (with marker arrays)
 *
 * Problem: Given an MxN matrix, if any element is 0, set its entire row and
 *          column to 0. Do this in-place for the final matrix output.
 *
 * Algorithm (Two-pass with row/col markers):
 * 1) First pass: Scan all cells. When matrix[i][j] is 0, mark row i and col j
 *    in auxiliary boolean arrays zeroRows and zeroCols.
 * 2) Second pass (rows): For every row marked in zeroRows, set the whole row to 0.
 * 3) Third pass (cols): For every column marked in zeroCols, set the whole column to 0.
 *
 * Complexity:
 * - Time: O(M*N) for the scan plus row/col zeroing loops (still O(M*N)).
 * - Space: O(M + N) for the marker arrays (here fixed-size for 3x3 sample).
 *
 * Notes:
 * - This is the classic marker-array approach; an optimal variant reuses first
 *   row/col as markers to achieve O(1) extra space.
 * - Order of row-then-col zeroing is safe because markers are stored separately.
 */

#include <iostream>
using namespace std;
int main()
{
    // Sample 3x3 matrix; elements set to 0 will trigger row/col zeroing
    int matrix[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    int rows = 3; // number of rows in matrix
    int cols = 3; // number of columns in matrix

    // STEP 1: Marker arrays to remember which rows and columns must be zeroed.
    bool zeroRows[3] = {false, false, false}; // zeroRows[i] == true means row i will be set to 0
    bool zeroCols[3] = {false, false, false}; // zeroCols[j] == true means column j will be set to 0

    // STEP 2: First pass — find zeros and record their rows and columns.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0) // found a zero; remember its row and column
            {
                zeroRows[i] = true; // mark entire row i to be zeroed later
                zeroCols[j] = true; // mark entire column j to be zeroed later
            }
        }
    }

    // STEP 3: Zero out marked rows.
    for (int i = 0; i < rows; i++)
    {
        if (zeroRows[i]) // row i was marked, zero it out
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // STEP 4: Zero out marked columns.
    for (int j = 0; j < cols; j++)
    {
        if (zeroCols[j]) // column j was marked, zero it out
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Output final matrix
    cout << "Final Matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}