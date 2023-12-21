#include "util.hpp"

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

        platform.push_back(line);
    }
    int Y = platform.size();
    int X = platform[0].size();

    bool changed = true;
    while (changed)
    {
        changed = false;
        FOR(x, 0, X)
        {
            FOR(y, 1, Y)
            {
                if (platform[y][x] == 'O' && platform[y - 1][x] == '.')
                {
                    platform[y][x] = '.';
                    platform[y - 1][x] = 'O';
                    changed = true;
                }
            }
        }
    }

    FOR(x, 0, X)
    {
        FOR(y, 0, Y)
        {
            if (platform[y][x] == 'O')
            {
                score += Y - y;
            }
        }
    }
    cout << score << endl;
}
// 3214689053
// 3123458828