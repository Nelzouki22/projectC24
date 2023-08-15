#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[100];
    float price;
};

struct CartItem {
    struct Product product;
    int quantity;
};

struct ShoppingCart {
    struct CartItem items[100];
    int itemCount;
    float totalAmount;
};

void initializeCart(struct ShoppingCart *cart) {
    cart->itemCount = 0;
    cart->totalAmount = 0;
}

void addToCart(struct ShoppingCart *cart, struct Product product, int quantity) {
    cart->items[cart->itemCount].product = product;
    cart->items[cart->itemCount].quantity = quantity;
    cart->totalAmount += product.price * quantity;
    cart->itemCount++;
}

void displayCart(struct ShoppingCart cart) {
    printf("Cart Contents:\n");
    for (int i = 0; i < cart.itemCount; i++) {
        printf("%d. %s - $%.2f x %d\n", i + 1, cart.items[i].product.name,
               cart.items[i].product.price, cart.items[i].quantity);
    }
    printf("Total Amount: $%.2f\n", cart.totalAmount);
}

int main() {
    struct Product products[3];
    products[0] = (struct Product){1, "Product 1", 10.99};
    products[1] = (struct Product){2, "Product 2", 20.49};
    products[2] = (struct Product){3, "Product 3", 5.75};

    struct ShoppingCart cart;
    initializeCart(&cart);

    int choice;
    do {
        printf("\nAvailable Products:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s - $%.2f\n", products[i].id, products[i].name, products[i].price);
        }
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            int quantity;
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addToCart(&cart, products[choice - 1], quantity);
        } else if (choice == 4) {
            displayCart(cart);
        } else if (choice != 5) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    printf("Thank you for shopping with us!\n");

    return 0;
}
