#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Library {
    int id;
    char name[200];
    char writerName[20];
};

int main() {
    struct Library book[10];
    int choice, cnt = 0, i;

    while (1) {
        printf("\n==== Library Management System ====\n");
        printf("1. Add Book\n");
        printf("2. Display books\n");
        printf("3. Search Books by ID\n");
        printf("4. Update Books by ID\n");
        printf("5. Delete Books by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (cnt >= 10) {
                printf("Library list full!\n");
                continue;
            }

            printf("Enter ID: ");
            scanf("%d", &book[cnt].id);
            printf("Enter Name: ");
            scanf(" %[^\n]", book[cnt].name);
            printf("Enter writer: ");
            scanf(" %[^\n]", book[cnt].writerName);
            cnt++;
            printf(" Library added!\n");
        }
        else if (choice == 2) {
            if (cnt == 0) {
                printf("No Librarys to display.\n");
            } else {
                printf("\n--- Librarys List ---\n");
                for (i = 0; i < cnt; i++) {
                    printf("ID: %d | Name: %s | Writer: %s\n", book[i].id, book[i].name, book[i].writerName);
                }
            }
        }
        else if (choice == 3) {
            int id, found = 0;
            printf("Enter ID to search: ");
            scanf("%d", &id);
            for (i = 0; i < cnt; i++) {
                if (book[i].id == id) {
                    printf("Library Found: ID: %d | Name: %s | Writer: %s\n", book[i].id, book[i].name, book[i].writerName);
                    found = 1;
                    break;
                }
            }
            if (!found) printf(" Library not found.\n");
        }
        else if (choice == 4) { // Update
            int id, found = 0;
            printf("Enter ID to update: ");
            scanf("%d", &id);
            for (i = 0; i < cnt; i++) {
                if (book[i].id == id) {
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", book[i].name);
                    printf("Enter new Writer: ");
                    scanf(" %[^\n]", book[i].writerName);
                    printf("Library updated!\n");
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Library not found.\n");
        }
        else if (choice == 5) { // Delete
            int id, found = 0;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            for (i = 0; i < cnt; i++) {
                if (book[i].id == id) {
                    // Shift all Librarys after i one step left
                    for (int j = i; j < cnt - 1; j++) {
                        book[j] = book[j + 1];
                    }
                    cnt--;
                    printf("Library deleted!\n");
                    found = 1;
                    break;
                }
            }
            if (!found) printf(" Library not found.\n");
        }
        else if (choice == 6) {
            printf("Exiting program.\n");
            exit(0);
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
