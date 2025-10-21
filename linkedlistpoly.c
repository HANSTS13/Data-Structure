#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

// Append node at end
void append(struct Node** head, int coeff, int exp) {
    struct Node* node = createNode(coeff, exp);
    if (*head == NULL)
        *head = node;
    else {
        struct Node* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
    }
}

// Print polynomial
void printPoly(struct Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly) printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            append(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            append(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                append(&result, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        append(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        append(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        append(&poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        append(&poly2, coeff, exp);
    }

    printf("\nFirst polynomial: ");
    printPoly(poly1);

    printf("Second polynomial: ");
    printPoly(poly2);

    sum = addPoly(poly1, poly2);
    printf("\nSum of polynomials: ");
    printPoly(sum);

    return 0;
}
