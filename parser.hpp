#include "tokenizer.hpp"

// PARSER
class Parser
{
    public:
        vector<Token> tokens{};
        Token *root;
        Token *curr_token;

        int idx = 0;

    // Initializer
    Parser(vector<Token> _tokens)
    {
        tokens = _tokens;
        root = &tokens[0];
        curr_token = &tokens[0];
    }   

    // Get the next token of the token vector
    void propagate()
    {
        if(idx + 1 < tokens.size())
        {
            ++idx;
            curr_token = &tokens[idx];
        }
    }
    
    // Return the root node of the abstract syntax tree
    Token *parse()
    {
        return expr();
    }

    // Check for expression (+, -)
    Token *expr()
    {
        Token *token = term();
        Token *temp;

        while(curr_token -> type == ADDITION || curr_token -> type == SUBTRACTION)
        {
            temp = curr_token;
            propagate();

            temp -> left = token;
            temp -> right = term();
            token = temp;
        }

        return token;
    }

    // Check for term (*, /)
    Token *term()
    {
        Token *token = factor();
        Token *temp;

        while(curr_token -> type == MULTIPLICATION || curr_token -> type == DIVITION)
        {
            temp = curr_token;
            propagate();

            temp -> left = token;
            temp -> right = factor();
            token = temp;
        }

        return token;
    }

    // Check for factor (number, parenthesis)
    Token *factor()
    {
        if(curr_token -> type == NUMBER)
        {
            Token *token = curr_token;
            propagate();
            return token;
        }
        else if(curr_token -> type == OPEN_PAREN)
        {
            propagate();
            Token *subtree = expr();
            if(curr_token -> type != CLOSE_PAREN)
            {
                throw "Syntax error";
            }
            return subtree;
        }
    }
};