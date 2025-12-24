/*
 * Rotate Matrix by 90 Degrees Clockwise — Optimal (In-place)
 *
 * Problem: Given an NxN square matrix, rotate it 90 degrees clockwise in-place.
 *          Example: [[1,2,3],[4,5,6],[7,8,9]] → [[7,4,1],[8,5,2],[9,6,3]]
 *
 * Algorithm (Transpose + Reverse):
 * 1) Transpose the matrix: Swap matrix[i][j] with matrix[j][i] for all i < j.
 *    This converts rows to columns.
 * 2) Reverse each row: Reverse the elements in each row left-to-right.
 *    This completes the 90° clockwise rotation.
 *
 * Complexity:
 * - Time: O(N^2) for transpose + O(N^2) for reversing = O(N^2) total.
 * - Space: O(1) extra space (in-place transformation).
 *
 * Notes:
 * - Transpose + reverse is the key trick for in-place rotation without extra matrix.
 * - For counter-clockwise: transpose then reverse each column instead.
 * - This avoids the O(N^2) extra space needed in the brute-force approach.
 */

#include <iostream>
#include <algorithm>
using namespace std;

// Helper function to reverse an array in-place
void reverseArray(int arr[], int n)
{
    int p1 = 0, p2 = n - 1; // two pointers: start and end of array

    // Swap elements from both ends moving towards center
    while (p1 < p2)
    {
        swap(arr[p1], arr[p2]); // swap elements at p1 and p2
        p1++;                   // move left pointer right
        p2--;                   // move right pointer left
    }
}

int main()
{
    int n = 3; // size of the NxN square matrix
    int matrix[n][n] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    // STEP 1: Transpose the matrix (convert rows to columns)
    // Why: Transposing swaps (i,j) with (j,i), preparing for the final rotation.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // STEP 2: Reverse each row to complete the 90° clockwise rotation
    // Why: After transpose, reversing rows converts columns to the final rotated positions.
    for (int i = 0; i < n; i++)
    {
        reverseArray(matrix[i], n); // reverse row i in-place
    }

    // STEP 3: Output the final rotated matrix
    cout << "Rotated matrix: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}