#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push to stack
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
    else
        printf("Stack overflow\n");
}

// Pop from stack
char pop() {
    if (top >= 0)
        return stack[top--];
    else
        return '\0';  // Stack underflow
}

// Check matching pair
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Check balanced parentheses
int isBalanced(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if (!isMatchingPair(topChar, ch))
                return 0;
        }
    }

    return (top == -1);  // Stack should be empty
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Remove newline

    if (isBalanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression has unbalanced parentheses.\n");

    return 0;
}
