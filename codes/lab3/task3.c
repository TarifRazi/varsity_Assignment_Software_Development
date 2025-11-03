#include <stdio.h>

int main() {
    int N, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d integers:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Duplicate numbers are: ");
    int found = 0;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                found = 1;
                break; 
            }
        }
    }

    if (!found)
        printf("None");

    printf("\n");
    return 0;
}
