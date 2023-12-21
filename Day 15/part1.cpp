#include "util.hpp"

int hashing(string h)
{
    int cv = 0;
    for (char c : h) {
        cv += c;
        cv *= 17;
        cv %= 256;
    }
    return cv;
}

int main()
{
    string line;

    ll score = 0;

    vector<string> platform;

    while (true)
    {
        vector<string> mirror;

        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;
        
        score += hashing(line);
    }

    cout << score << endl;
}