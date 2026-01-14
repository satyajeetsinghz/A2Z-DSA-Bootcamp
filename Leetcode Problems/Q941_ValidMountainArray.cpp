/*
 * Valid Mountain Array (LeetCode Q941)
 *
 * Problem: Validate if an array is a valid mountain array.
 * A valid mountain array must satisfy:
 * 1. Length >= 3
 * 2. Elements strictly increase up to a peak
 * 3. Elements strictly decrease after the peak
 * 4. Peak is neither at the start nor at the end
 *
 * Approach (Two-Pass Validation):
 * - First pass: Move pointer forward while elements are strictly increasing
 * - Check if peak exists (not at boundaries)
 * - Second pass: Move pointer forward while elements are strictly decreasing
 * - If pointer reaches the end after both passes, array is valid mountain
 *
 * Example:
 * - Input: [0, 1, 3, 5, 4, 3, 1] → Valid (increases to 5, then decreases)
 * - Input: [0, 1, 2, 3] → Invalid (no decrease phase)
 * - Input: [0, 3, 2, 1] → Invalid (no increase phase)
 *
 * Complexity:
 * - Time: O(n) - two passes through the array
 * - Space: O(1) - only using pointer variable
 */

#include <iostream>
using namespace std;

/**
 * Validates whether the input array forms a valid mountain shape
 * @param arr[] - input integer array to validate
 * @param arraySize - total number of elements in the array
 * @return true if array is a valid mountain, false otherwise
 */
bool validMountainArray(int arr[], int arraySize)
{
    // Check minimum length requirement for a valid mountain array
    if (arraySize < 3)
        return false;

    // Pointer to track position, starting from the beginning
    int peakIndex = 0;

    // PHASE 1: Traverse the strictly increasing part (uphill)
    // Continue while we haven't reached the end and current element is less than next
    while (peakIndex + 1 < arraySize && arr[peakIndex] < arr[peakIndex + 1])
    {
        peakIndex++; // Move pointer forward along the increasing sequence
    }

    // Validate peak existence: peak cannot be at boundaries
    // If peak is at index 0 or last index, there's no valid mountain
    if (peakIndex == 0 || peakIndex == arraySize - 1)
    {
        return false; // No valid uphill or downhill phase exists
    }

    // PHASE 2: Traverse the strictly decreasing part (downhill)
    // Continue while we haven't reached the end and current element is greater than next
    while (peakIndex + 1 < arraySize && arr[peakIndex] > arr[peakIndex + 1])
    {
        peakIndex++; // Move pointer forward along the decreasing sequence
    }

    // Valid mountain if pointer reached the very last index
    // This confirms the downhill phase extended to the array's end
    return peakIndex == arraySize - 1;
}

int main()
{
    // Test case: array with valid mountain shape [0,1,3,5,4,3,1]
    // Increases from 0 to peak 5, then decreases back to 1
    int testArray[] = {0, 1, 3, 5, 4, 3, 1};

    // Calculate the size of the array dynamically
    // This approach works for statically allocated arrays
    int arrayLength = sizeof(testArray) / sizeof(testArray[0]);

    // Validate the test array and display result
    if (!validMountainArray(testArray, arrayLength))
    {
        // Output when validation fails
        cout << "Not a Valid Mountain Array." << endl;
    }
    else
    {
        // Output when validation succeeds
        cout << "A Valid Mountain Array." << endl;
    }

    return 0; // Successful program termination
}
