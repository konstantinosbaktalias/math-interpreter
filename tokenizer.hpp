#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TYPES
int NUMBER = 1;
int ADDITION = 2;
int SUBTRACTION = 3;
int MULTIPLICATION = 4;
int DIVITION = 5;
int OPEN_PAREN = 6;
int CLOSE_PAREN = 7;

// TOKEN STRUCT
struct Token
{
    int type = 0;
    float value = 0;

    Token *left = NULL;
    Token *right = NULL;
};

// TOKENIZER
vector<Token> Tokenizer(string text)
{
    vector<Token> tokens {};
    Token curr_token;

    char curr_char;
    char next_char;

    string curr_value = "";

    // Loop through each character of the text input
    for(int i=0; i < text.length(); ++i)
    {
        curr_char = text[i];
        next_char = (i + 1 < text.length()) ? text[i+1] : ' ';

        // Insert current character to a string that holds the value of the token
        if(curr_char != ' ')
        {
            curr_value += curr_char;
        }

        // Check for types
        if(curr_char == '+')
        {
            curr_token.type = ADDITION;
            curr_token.value = 0;

            tokens.push_back(curr_token);
            curr_value = "";
        }
        else if(curr_char == '-')
        {
            curr_token.type = SUBTRACTION;
            curr_token.value = 0;

            tokens.push_back(curr_token);
            curr_value = "";
        }
        else if(curr_char == '*')
        {
            curr_token.type = MULTIPLICATION;
            curr_token.value = 0;

            tokens.push_back(curr_token);
            curr_value = "";
        }
        else if(curr_char == '/')
        {
            curr_token.type = DIVITION;
            curr_token.value = 0;

            tokens.push_back(curr_token);
            curr_value = "";
        }
        else if(curr_char == '(')
        {
            curr_token.type = OPEN_PAREN;
            curr_token.value = 0;

            tokens.push_back(curr_token);
            curr_value = "";
        }
        else if(curr_char == ')')
        {
            curr_token.type = CLOSE_PAREN;
            curr_token.value = 0;

            tokens.push_back(curr_token);
            curr_value = "";
        }
        else if(
            (next_char == ' ' || next_char == '+' || next_char == '-'
            || next_char == '*' || next_char == '/' || next_char == '('
            || next_char == ')') && curr_value.length() > 0
        )
        {   
            curr_token.type = NUMBER;
            curr_token.value = stod(curr_value);

            tokens.push_back(curr_token);
            curr_value = "";
        }
    }

    return tokens;
} 