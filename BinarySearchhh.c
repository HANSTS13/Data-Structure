#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct node {
    int data;
    struct node *lchild, *rchild;
};

// Create a new node
struct node* createNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

// Insert a node into BST
struct node* insert(struct node* root, int item) {
    // If tree/subtree is empty, new node becomes root
    if (root == NULL)
        return createNode(item);

    // Otherwise find correct position
    if (item < root->data)
        root->lchild = insert(root->lchild, item);
    else if (item > root->data)
        root->rchild = insert(root->rchild, item);

    return root;   // always return unchanged/or updated root
}

// Search for an element in BST
struct node* search(struct node* root, int item) {
    if (root == NULL || root->data == item)
        return root;

    if (item < root->data)
        return search(root->lchild, item);
    else
        return search(root->rchild, item);
}

// Find minimum element (leftmost node)
struct node* findMin(struct node* root) {
    while (root && root->lchild != NULL)
        root = root->lchild;
    return root;
}

// Delete a node from BST
struct node* delete(struct node* root, int item) {
    if (root == NULL)
        return root;

    // Search for the node to delete
    if (item < root->data)
        root->lchild = delete(root->lchild, item);

    else if (item > root->data)
        root->rchild = delete(root->rchild, item);

    else {
        // Node found

        // Case 1 & 2: Node has 0 or 1 child
        if (root->lchild == NULL) {
            struct node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL) {
            struct node* temp = root->lchild;
            free(root);
            return temp;
        }

        // Case 3: Node has 2 children
        struct node* temp = findMin(root->rchild);
        root->data = temp->data;  // replace data
        root->rchild = delete(root->rchild, temp->data); // delete inorder successor
    }

    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

int main() {
    struct node* root = NULL;
    int choice, item;

    while (1) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display (Inorder)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &item);
                if (search(root, item) != NULL)
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &item);
                root = delete(root, item);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
