#include "interpreter.hpp"

int main()
{
    string input;

    while(true)
    {
        cout << "-> "; getline(cin, input);

        vector<Token> tokens = Tokenizer(input);

        Parser parser(tokens);
        Token *root = parser.parse();

        cout << Interpreter(root) << endl;
    }

    return 0;
}