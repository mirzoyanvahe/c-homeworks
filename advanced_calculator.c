#include <stdio.h>
#include <stdlib.h>

// Define a structure for AST nodes
typedef struct {
    char type; // 'C' for constant, 'V' for variable, 'O' for operator
    int value; // value for constants, index for variables, operator for operators
} Node;

// Define constants for operator types
enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
};

// Function to prompt user for variable input
int getInput(char variable) {
    int value;
    printf("Enter value for '%c': ", variable);
    scanf("%d", &value);
    return value;
}

// Function to evaluate AST
int evaluate(Node *node) {
    if (node->type == 'C') {
        return node->value;
    } else if (node->type == 'V') {
        return getInput('A' + node->value); // Convert variable index to corresponding character
    } else {
        int left = evaluate(node - 1);
        int right = evaluate(node + 1);

        switch (node->value) {
            case OP_ADD: return left + right;
            case OP_SUB: return left - right;
            case OP_MUL: return left * right;
            case OP_DIV: return left / right;
            default: return 0; // Handle invalid operator
        }
    }
}

int main() {
    // Example program
    Node ast[] = {
        {'V', 1}, {'V', 2}, {'C', 8}, {'C', 5}, {'O', OP_MUL},
        {'O', OP_ADD},
        {'V', 0}, {'C', 6}, {'O', OP_SUB},
        {'O', '='},
    };

    int result = evaluate(ast + sizeof(ast) / sizeof(ast[0]) - 1);

    printf("Result: %d\n", result);

    return 0;
}
