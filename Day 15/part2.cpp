#include "util.hpp"

int hashing(string h)
{
    int cv = 0;
    for (char c : h)
    {
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
    list<pair<string, int>> map[256];

    while (true)
    {
        vector<string> mirror;

        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<string> m = match(line, "([a-z]+|[=|-]|\\d+)");

        cout << line << " " << hashing(m[0]) << endl;
        // cout << m[0] << " " << hashing(m[0]) << endl;
        int to = hashing(m[0]);

        if (m[1][0] == '-')
        {
            int i = 0;
            for (auto it = map[to].begin(); it != map[to].end(); it++)
            {
                if (same((*it).first, m[0]))
                {

                    map[to].erase(it);
                    break;
                }
            }
        }
        else
        {
            bool found = false;

            for (auto it = map[to].begin(); it != map[to].end(); it++)
            {
                if (same((*it).first, m[0]))
                {
                    it->second = stoi(m[2]);
                    found = true;
                }
            }
            if (!found)
            {
                map[to].push_back({m[0], stoi(m[2])});
            }
        }

        FOR(i, 0, 4)
        {
            if (map[i].empty())
                continue;
            cout << i << ":";
            for (pair<string, int> lens : map[i])
            {
                cout << ", (" << lens.first << ", " << lens.second << ")";
            }
            cout << endl;
        }
        cout << endl;
        // score += hashing(line);
    }

    FOR(i, 0, 256)
    {
        if (map[i].empty())
            continue;
        cout << i << ":";
        int j = 1;
        for (pair<string, int> lens : map[i])
        {

            cout << ", (" << lens.first << ", " << lens.second << "*" << j << ")";
            score += (i+1) * j * lens.second;
            j++;
        }
        cout << endl;
    }

    cout << score << endl;
}