#include <stdio.h>

// Function to find and print the subarray starting and ending with a duplicate element
void findAndPrintDuplicateSubarray(int arr[], int n, int start, int end) {
    // Check for duplicates in the subarray
    for (int i = start; i <= end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (arr[i] == arr[j]) {
                // Print the duplicate subarray
                printf("Duplicate subarray: ");
                for (int k = i; k <= j; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
                return;
            }
        }
    }
}

// Recursive function to find the subarray starting and ending with a duplicate element
void findDuplicateSubarray(int arr[], int n, int start, int end) {
    // Base case: If the subarray has only one element
    if (start == end) {
        return;
    }

    // Check for duplicates in the subarray
    findAndPrintDuplicateSubarray(arr, n, start, end);

    // Divide the subarray into two halves and recursively check for duplicates
    int mid = (start + end) / 2;
    findDuplicateSubarray(arr, n, start, mid);
    findDuplicateSubarray(arr, n, mid + 1, end);
}

// Driver program to test the above functions
int main() {
    int arr[] = {1, 2, 3, 4, 5, 2,10,11,12, 2, 7, 8, 9,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find and print duplicate subarrays
    findDuplicateSubarray(arr, n, 0, n - 1);

    return 0;
}
