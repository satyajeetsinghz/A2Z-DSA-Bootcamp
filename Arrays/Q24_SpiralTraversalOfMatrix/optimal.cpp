/*
 * Spiral Traversal of a Matrix - Optimal Approach (Boundary Shrinking)
 * 
 * Problem: Given a 2D matrix (rows x columns), traverse all elements in a 
 * spiral order (clockwise from outside to inside).
 * 
 * Example:
 * Matrix:        Expected Output:
 * 1  2  3  4     1 2 3 4 8 12 11 10 9 5 6 7
 * 5  6  7  8
 * 9 10 11 12
 * 
 * Spiral Order: Right -> Down -> Left -> Up -> Repeat until all elements visited
 * 
 * Algorithm: Four-Direction Boundary Traversal
 * 
 * The matrix boundaries are gradually shrunk inward after each complete layer:
 * - top row is traversed left to right, then top boundary moves down
 * - right column is traversed top to bottom, then right boundary moves left
 * - bottom row is traversed right to left, then bottom boundary moves up
 * - left column is traversed bottom to top, then left boundary moves right
 * 
 * Boundary Pointers:
 * - 'top': Row index of the topmost boundary
 * - 'bottom': Row index of the bottommost boundary
 * - 'left': Column index of the leftmost boundary
 * - 'right': Column index of the rightmost boundary
 * 
 * Why this is optimal:
 * - Single pass through all elements (O(rows * cols) time)
 * - No extra data structure needed (O(1) extra space - only 4 pointers)
 * - Clear and efficient boundary management
 * - Naturally handles rectangular matrices of any dimension
 * 
 * Time Complexity: O(rows * cols) - Visit each element exactly once
 * Space Complexity: O(1) - Only using 4 integer variables for boundaries
 * 
 * This is the BEST approach for this problem.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input matrix (3 rows x 4 columns)
    // Will be traversed in spiral order: 
    // 1 2 3 4 8 12 11 10 9 5 6 7
    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Dimensions of the matrix
    int rows = 3, cols = 4;

    // FOUR BOUNDARY POINTERS for Spiral Traversal:
    
    // 'top': Row index of the topmost unprocessed row
    // All rows above 'top' have been completely processed
    int top = 0;
    
    // 'bottom': Row index of the bottommost unprocessed row
    // All rows below 'bottom' have been completely processed
    int bottom = rows - 1;
    
    // 'left': Column index of the leftmost unprocessed column
    // All columns before 'left' have been completely processed
    int left = 0;
    
    // 'right': Column index of the rightmost unprocessed column
    // All columns after 'right' have been completely processed
    int right = cols - 1;

    // Main loop: Continue spiral traversal while there are unprocessed rows and columns
    // Loop exits when top boundary crosses bottom or left boundary crosses right
    while (top <= bottom && left <= right)
    {
        // STEP 1: TRAVERSE RIGHT (Left to Right on top row)
        // Process all elements in the topmost row from left column to right column
        // This covers the top edge of the remaining unprocessed region
        for (int i = left; i <= right; i++)
        {
            // Print element at position [top][i]
            cout << mat[top][i] << " ";
        }
        
        // After processing the top row, move the top boundary down
        // This row is now completely processed and won't be visited again
        top++;

        // STEP 2: TRAVERSE DOWN (Top to Bottom on right column)
        // Process all elements in the rightmost column from current top to bottom
        // This covers the right edge of the remaining unprocessed region
        // Start from 'top' because the previous step already processed mat[top][right]
        for (int i = top; i <= bottom; i++)
        {
            // Print element at position [i][right]
            cout << mat[i][right] << " ";
        }
        
        // After processing the right column, move the right boundary left
        // This column is now completely processed and won't be visited again
        right--;

        // STEP 3: TRAVERSE LEFT (Right to Left on bottom row)
        // Process the bottom row in reverse (right to left)
        // But only if there's still a row to process (handle single-row matrix case)
        // This covers the bottom edge of the remaining unprocessed region
        if (top <= bottom)
        {
            // Traverse from right boundary to left boundary in reverse
            for (int i = right; i >= left; i--)
            {
                // Print element at position [bottom][i]
                cout << mat[bottom][i] << " ";
            }
            
            // After processing the bottom row, move the bottom boundary up
            // This row is now completely processed and won't be visited again
            bottom--;
        }

        // STEP 4: TRAVERSE UP (Bottom to Top on left column)
        // Process the left column in reverse (bottom to top)
        // But only if there's still a column to process (handle single-column matrix case)
        // This covers the left edge of the remaining unprocessed region
        // Start from 'bottom' because the previous step already processed mat[bottom][left]
        if (left <= right)
        {
            // Traverse from bottom boundary to top boundary in reverse
            for (int i = bottom; i >= top; i--)
            {
                // Print element at position [i][left]
                cout << mat[i][left] << " ";
            }
            
            // After processing the left column, move the left boundary right
            // This column is now completely processed and won't be visited again
            left++;
        }
        
        // After completing all 4 directions, the outer layer is fully processed
        // The loop continues with the inner layer (same 4-step process)
    }

    return 0;
}