#include <stdio.h>
#include <string.h>

#define MAX 100

// Product Structure
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product store[MAX];
int count = 0;

// Function declarations
void addProduct();
void updateProduct();
void deleteProduct();
void searchProduct();
void displayProducts();

int main() {
    int choice;

    while (1) {
        printf("\n===== STORE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Display All Products\n");
        printf("6. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addProduct();
        }
        else if (choice == 2) {
            updateProduct();
        }
        else if (choice == 3) {
            deleteProduct();
        }
        else if (choice == 4) {
            searchProduct();
        }
        else if (choice == 5) {
            displayProducts();
        }
        else if (choice == 6) {
            printf("Exiting Program...\n");
            return 0;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Add Product
void addProduct() {
    if (count >= MAX) {
        printf("Store is full! Cannot add more products.\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &store[count].id);

    printf("Enter Product Name: ");
    getchar();
    fgets(store[count].name, 50, stdin);
    store[count].name[strcspn(store[count].name, "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &store[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &store[count].quantity);

    count++;
    printf("Product added successfully!\n");
}

// Update Product
void updateProduct() {
    int id, found = 0;
    printf("Enter Product ID to Update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (store[i].id == id) {
            found = 1;

            printf("Enter New Name: ");
            getchar();
            fgets(store[i].name, 50, stdin);
            store[i].name[strcspn(store[i].name, "\n")] = '\0';

            printf("Enter New Price: ");
            scanf("%f", &store[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &store[i].quantity);

            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Product not found!\n");
}

// Delete Product
void deleteProduct() {
    int id, found = 0;
    printf("Enter Product ID to Delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (store[i].id == id) {
            found = 1;

            // Shift left to delete
            for (int j = i; j < count - 1; j++) {
                store[j] = store[j + 1];
            }

            count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Product not found!\n");
}

// Search Product
void searchProduct() {
    int id, found = 0;
    printf("Enter Product ID to Search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (store[i].id == id) {
            found = 1;

            printf("\n--- Product Found ---\n");
            printf("ID       : %d\n", store[i].id);
            printf("Name     : %s\n", store[i].name);
            printf("Price    : %.2f\n", store[i].price);
            printf("Quantity : %d\n", store[i].quantity);
            break;
        }
    }

    if (!found)
        printf("Product not found!\n");
}

// Display All Products
void displayProducts() {
    if (count == 0) {
        printf("No products available!\n");
        return;
    }

    printf("\n===== ALL PRODUCTS =====\n");
    for (int i = 0; i < count; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("ID       : %d\n", store[i].id);
        printf("Name     : %s\n", store[i].name);
        printf("Price    : %.2f\n", store[i].price);
        printf("Quantity : %d\n", store[i].quantity);
    }
}
