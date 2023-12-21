#include "util.hpp"

int main()
{
    string line;

    ll score = 0;

    vector<vector<string>> mirrors;

    while (true)
    {
        vector<string> mirror;

        while (true)
        {
            getline(cin, line);
            // cout << line << endl;

            if (!line.length())
                break;

            mirror.push_back(line);
        }

        if (mirror.size() == 0)
            break;

        bool hori = false;
        FOR(i, 1, mirror[0].size())
        {
            int c = 0;

            bool found = true;
            FOR(j, 0, i)
            {
                FOR(y, 0, mirror.size())
                {
                    if (2 * i - j - 1 < mirror[0].size())
                    {
                        cout << j << "-" << (2 * i - j-1) << " : ";
                        cout << mirror[y][j] << " - " << mirror[y][2 * i - j-1] << endl;
                        
                        if (mirror[y][j] != mirror[y][2 * i - j - 1])
                        {
                            c++;
                        }
                    }
                }
            }
            if (c == 1)
            {
                cout << "h " << i;
                score += i;
                hori = true;
            }
        }
        cout << endl;
        if (hori)
            continue;

        FOR(i, 1, mirror.size())
        {
            int c = 0;

            bool found = true;
            FOR(j, 0, i)
            {
                FOR(x, 0, mirror[0].size())
                {
                    if (2 * i - j -1 < mirror.size())
                    {
                        if (mirror[j][x] != mirror[2 * i - j-1][x])
                        {
                            c ++;
                        }
                    }
                }
            }
            if (c == 1)
            {
                score += (i * 100);
                hori = true;
                break;
            }
        }
    }
    cout << score << endl;
}
// 3214689053
// 3123458828