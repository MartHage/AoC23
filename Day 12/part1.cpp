#include "util.hpp"

bool check(string l, vector<int> digits)
{
    int index = 0;
    int c = 0;
    FOR (i, 0, l.size()) {
        if (l[i] == '#') {
            c++;
        } else  {}
    }

    vector<string> check = match(l, "([#|\\?]+)");
    // cout << check[0] << endl;
    if (check.size() != digits.size())
    {
        // cout << " h\n";
        return false;
    }
    FOR(i, 0, check.size())
    {
        if (check[i].size() != digits[i])
        {
            // cout << check[i] << endl;
            // cout << " s " << check[i].size() << " " << digits[i] << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    string line;

    ll score = 0;

    ll d = 1;

    ll y = 0;

    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<string> conditions;
        vector<int> repInfo;

        // conditions = match(line, "([#|\\?]+)");
        vector<string> ma = match(line, "(\\d+)");
        for (string m : ma) {
            repInfo.push_back(stoi(m));
        }

        vector<int> qLoc;
        FOR(i, 0, line.size())
        {
            if (line[i] == '?')
            {
                qLoc.push_back(i);
            }
        }
        cout << " " << qLoc.size() << endl;

        FOR(binC, 0, pow(2, qLoc.size()))
        {

            FOR(p, 0, qLoc.size())
            {
                int bit = (((1 << 1) - 1) & (binC >> (p)));
                if (bit)
                    line[qLoc[p]] = '.';
                else
                    line[qLoc[p]] = '#';
            }
            // cout << line << endl;

            if (check(line, repInfo))
                score++;
        }
        break;
    }
    cout << score << endl;
}
// 3214689053
// 3123458828