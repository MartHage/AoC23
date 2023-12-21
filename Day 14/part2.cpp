#include "util.hpp"

void pr(vector<string> pl)
{
    for (string p : pl)
    {
        cout << p << endl;
    }
    cout << endl
         << endl;
}

int main()
{
    string line;

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

    list<string> prevs;
    bool skipped = false;

    FOR(q, 0, 1000000000)
    {
        ll score = 0;
        // pr(platform);
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
        // pr(platform);

        changed = true;
        while (changed)
        {
            changed = false;
            FOR(y, 0, Y)
            {
                FOR(x, 1, X)
                {
                    if (platform[y][x] == 'O' && platform[y][x - 1] == '.')
                    {
                        platform[y][x] = '.';
                        platform[y][x - 1] = 'O';
                        changed = true;
                    }
                }
            }
        }
        // pr(platform);

        changed = true;
        while (changed)
        {
            changed = false;
            FOR(x, 0, X)
            {
                FOR(y, 0, Y - 1)
                {
                    if (platform[y][x] == 'O' && platform[y + 1][x] == '.')
                    {
                        platform[y][x] = '.';
                        platform[y + 1][x] = 'O';
                        changed = true;
                    }
                }
            }
        }
        // pr(platform);
        changed = true;
        while (changed)
        {
            changed = false;
            FOR(y, 0, Y)
            {
                FOR(x, 0, X - 1)
                {
                    if (platform[y][x] == 'O' && platform[y][x + 1] == '.')
                    {
                        platform[y][x] = '.';
                        platform[y][x + 1] = 'O';
                        changed = true;
                    }
                }
            }
        }
        // pr(platform);
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

        if (skipped)
            continue;

        int i = 0;
        ll cyclesize = 1;
        string flPl = accumulate(platform.begin(), platform.end(), std::string(""));
        for (string prev : prevs)
        {
            if (same(prev, flPl))
            {
                cout << flPl << endl;
                for (string prev2 : prevs)
                {
                    cout << prev2 << endl;
                    if (same(prev2, flPl))
                        break;
                }
                cout << endl;


                cout << "c: " << cyclesize << endl;
                q += cyclesize * floor((1000000000 - q) / (cyclesize));
                skipped = true;
                break;
            }
            cyclesize++;
        }
        prevs.push_front(flPl);
    }
}
// 3214689053
// 3123458828