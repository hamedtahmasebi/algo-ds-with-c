#include <stdio.h>

int bin_search(int val, int* arr,int arrlen);

typedef struct {
    int* arr;
    int arrlen;
    int val;
    int expected;
} TestCase;

int bin_search(int val, int* arr, int arrlen);

int main()
{
    // Array of test cases
    TestCase testCases[] = {
        // Test case 1: Value is present in the middle of the array
        { .arr = (int[]){1, 2, 3, 4, 5}, .arrlen = 5, .val = 3, .expected = 2 },
        // Test case 2: Value is present at the beginning of the array
        { .arr = (int[]){10, 20, 30, 40, 50}, .arrlen = 5, .val = 10, .expected = 0 },
        // Test case 3: Value is present at the end of the array
        { .arr = (int[]){100, 200, 300, 400, 500}, .arrlen = 5, .val = 500, .expected = 4 },
        // Test case 4: Value is not present in the array
        { .arr = (int[]){1, 2, 3, 4, 5}, .arrlen = 5, .val = 6, .expected = -1 }
    };

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; ++i) {
        int result = bin_search(testCases[i].val, testCases[i].arr, testCases[i].arrlen);
        printf("Test case %d: Result = %d\n", i + 1, result);
        printf("Expected: %d\n", testCases[i].expected);
        printf("\n");
    }

    return 0;
}


int bin_search(int val,int* arr, int arrlen) {
    int low_idx = 0;
    int high_idx = arrlen - 1;
    int mid_idx = (high_idx - low_idx) / 2;
    // the <= is for handling cases when the value is not in the array.
    //  
    while (low_idx <= high_idx) {
        mid_idx = (high_idx + low_idx) / 2;
        if (val == arr[mid_idx]) {
            return mid_idx;
        }
        if (val > arr[mid_idx]) {
            low_idx = mid_idx + 1;
            continue;
        }
        if (val < arr[mid_idx]) {
            high_idx = mid_idx - 1;
            continue;
        }
    }
    return -1;
}


