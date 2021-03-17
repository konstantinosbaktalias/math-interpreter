#include "parser.hpp"

double Interpreter(Token *root)
{
    // If leaf node is reached return value (All leaf nodes are numbers)
    if(root -> type == NUMBER)
    {
        return root -> value;
    }

    // Check for addition parent
    if(root -> type == ADDITION)
    {
        return Interpreter(root -> left) + Interpreter(root -> right);
    }
    // Check for substraction parent
    else if(root -> type == SUBTRACTION)
    {
        return Interpreter(root -> left) - Interpreter(root -> right);
    }
    // Check for multiplication parent
    else if(root -> type == MULTIPLICATION)
    {
        return Interpreter(root -> left) * Interpreter(root -> right);
    }
    // Check for division parent
    else if(root -> type == DIVITION)
    {
        return Interpreter(root -> left) / Interpreter(root -> right);
    }
}