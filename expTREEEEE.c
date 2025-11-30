#include <stdio.h>
#include <stdlib.h>

int main() {

    struct node {
        char data;
        struct node *left, *right;
    };

    struct node* stack[50];
    int top = -1;

    char postfix[50];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    // Build expression tree
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // Check if operand (letter or digit)
        int isOperand = 
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9');

        if (isOperand) {
            struct node* t = (struct node*)malloc(sizeof(struct node));
            t->data = ch;
            t->left = t->right = NULL;
            stack[++top] = t;
        }
        else {
            struct node* t = (struct node*)malloc(sizeof(struct node));
            t->data = ch;

            struct node* right = stack[top--];
            struct node* left  = stack[top--];

            t->right = right;
            t->left = left;

            stack[++top] = t;
        }
    }

    struct node* root = stack[top];

    // Inorder traversal function inside main
    void inorder(struct node* r) {
        if (r != NULL) {
            inorder(r->left);
            printf("%c ", r->data);
            inorder(r->right);
        }
    }

    printf("Inorder traversal:\n");
    inorder(root);

    return 0;
}

