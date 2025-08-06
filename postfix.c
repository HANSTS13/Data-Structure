#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

// Check if character is an operand
int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'));
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Right-to-left associativity for ^
int isRightAssociative(char op) {
    return (op == '^');
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (ch == ' ') continue; // skip spaces

        if (isOperand(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1)
                postfix[k++] = pop();
            pop(); // Remove '('
        }
        else if (isOperator(ch)) {
            while (isOperator(peek()) &&
                   ((precedence(ch) < precedence(peek())) ||
                   (precedence(ch) == precedence(peek()) && !isRightAssociative(ch)))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);  // Using scanf instead of fgets

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
