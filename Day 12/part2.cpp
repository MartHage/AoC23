#include "util.hpp"

bool newCheck(int li, string l, int di, vector<int> digits)
{
    // if (li > 0 && l[li-1] == '#') {

    // }

    if (di != digits.size())
        return false;

    FOR(lj, li, l.size())
    {
        if (l[lj] != '.')
        {
            return false;
        }
    }
    return true;
}

bool check(int li, string l, int di, vector<int> digits)
{
    int index = di + 1;
    int c = 0;

    FOR(i, li, l.size())
    {
        if (l[i] == '#')
        {
            c++;
        }
        else if (l[i] == '?')
        {
            return false;
        }
        else
        {
            if (c > 0 && c != digits[index])
            {
                return false;
            }
            if (c > 0)
                index++;
            c = 0;
            // index++;
        }
    }
    if (c > 0)
    {
        return index == digits.size() - 1 && c == digits[index];
    }
    return index == digits.size();
}

void pr(int li, string l, int fd, int di, vector<int> digits)
{
    FOR(lj, 0, l.size())
    {
        if (lj == li)
            cout << "-";
        cout << l[lj];
    }
    cout << " : "
         << " ";

    bool first = true;
    ;
    FOR(dj, di, digits.size())
    {
        if (true)
            cout << (digits[dj] - fd) << " ";
        else
            cout << digits[dj] << " ";
        first = false;
    }
    cout << " : " << newCheck(li, l, di, digits);
    cout << endl;
}

pair<int, int> newDigits(int li, string l, int di, vector<int> digits)
{
    int index = di;
    int c = 0;

    // cout << "  ";
    // pr(li, l, di, digits);

    // cout << l << endl;

    vector<int> newDigits;

    // int lj = li;
    // if (l[li] == '#')
    // {
    //     while (lj > 0 && l[lj - 1] == '#')
    //     {
    //         lj--;
    //         c++;
    //     }
    //     // c--;
    // }
    // cout << c << endl;

    FOR(i, li, l.size())
    {
        if (l[i] == '#')
        {
            c++;
        }
        else if (l[i] == '?')
        {
            if (c == digits[index])
            {
                newDigits.push_back(digits[index]);
            }
            return {newDigits.size() + di, i};
        }
        else
        {

            if (c == digits[index] && c != 0)
            {
                newDigits.push_back(digits[index]);
                index++;
            }
            else if (c > 0 || index > digits.size())
            {
                return {-1, -1};
            }
            c = 0;
            // index++;
        }
    }

    if (c > 0)
    {
        if (c == digits[index])
        {
            newDigits.push_back(digits[index]);
        }
        else
        {
            return {-1, -1};
        }
    }
    // for (int di : newDigits)
    // {
    //     cout << di << " ";
    // }
    // cout << endl;

    return {newDigits.size() + di, l.size()};
}

pair<int, int> newDigits(int li, string l, int fd, int di, vector<int> digits)
{
    int index = di;
    int c = fd - 1;

    // cout << "  ";
    // pr(li, l, di, digits);

    // cout << l << endl;

    vector<int> newDigits;

    // int lj = li;
    // if (l[li] == '#')
    // {
    //     while (lj > 0 && l[lj - 1] == '#')
    //     {
    //         lj--;
    //         c++;
    //     }
    //     // c--;
    // }
    // cout << c << endl;

    bool first = true;

    FOR(i, li, l.size())
    {
        if (l[i] == '#')
        {
            c++;
        }
        else if (l[i] == '?')
        {
            if (c > digits[index])
            {
                return {-1, -1};
            }
            if (c == digits[index])
            {
                newDigits.push_back(digits[index]);
            }
            return {newDigits.size() + di, i};
        }
        else
        {
            // if (fd != 0 && first && fd != c)
            // {
            //     return {-1, -1};
            // }
            // if (fd != 0 && fd == c)
            // {
            //     newDigits.push_back(digits[index]);
            //     index++;
            // }
            if (c == digits[index] && c != 0)
            {
                newDigits.push_back(digits[index]);
                index++;
            }
            else if (c > 0 || index > digits.size())
            {
                return {-1, -1};
            }
            c = 0;
            fd = 0;
            first = false;
            // index++;
        }
    }

    if (c > 0)
    {
        if (c == digits[index])
        {
            newDigits.push_back(digits[index]);
        }
        else
        {
            return {-1, -1};
        }
    }
    // for (int di : newDigits)
    // {
    //     cout << di << " ";
    // }
    // cout << endl;

    return {newDigits.size() + di, l.size()};
}

vector<vector<vector<int>>> T;

int getNum(int i, vector<int> qLoc, int li, string l, int fd, int di, vector<int> digits)
{

    // pr(li, l, fd, di, digits);

    if (newCheck(li, l, di, digits))
    {

        // cout << "YEAH "  << i  << " " << li << " " << l << " " << di  << endl;
        return 1;
    }
    if (i >= qLoc.size())
    {
        return 0;
    }

    int score = 0;
    // cout << " fd " << fd << " " << ((fd > 0) ? (fd - 1) : digits[di]) << endl;
    // if (fd == 0)
    // {
    l[qLoc[i]] = '.';
    pair<int, int> dj = newDigits(li, l, 0, di, digits);
    // cout << " " << dj.first << " " << dj.second << endl;
    // dj = newDigits(0, l, 0, digits);
    // cout << " " << dj.first << " " << dj.second << endl;

    if (dj.first != -1)
    {
        // cout << i << ": " << l << endl;
        // if (T[i + 1][qLoc[dj]][dj] == -1) {
        score += getNum(i + 1, qLoc, dj.second, l, 0, dj.first, digits);
        // }

        // score += T[i + 1][qLoc[dj]][dj];
    }
    // }
    l[qLoc[i]] = '#';

    // pr(li, l, fd, di, digits);
    // if (!(qLoc[i] > 0 && l[qLoc[i] - 1] == '#' && fd == 0))
    // {
    int lj = qLoc[i];
    dj = newDigits(li, l, fd + 1, di, digits);
    // cout << fd << " " << dj.first << " " << dj.second << endl;
    if (dj.first != -1)
    {
        // cout << l << endl;
        // if (T[i + 1][dj.second][dj.first] == -1)
        T[i + 1][dj.second][dj.first] = getNum(i + 1, qLoc, dj.second, l, ((fd + 1)), dj.first, digits);

        score += T[i + 1][dj.second][dj.first];
    }
    // }
    // l[qLoc[i + 1]] = '?';

    // l[qLoc[i + 1]] = '#';
    // score += getNum(i + 1, qLoc, l, digits);
    return score;
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
        vector<string> linem = match(line, "([\\.|#|\\?]+)");

        string word;

        for (string m : ma)
        {
            repInfo.push_back(stoi(m));
        }
        word += linem[0];
        FOR(i, 0, 0)
        {
            for (string m : ma)
            {
                repInfo.push_back(stoi(m));
            }
            word += "?";
            word += linem[0];
        }

        vector<int> qLoc;
        FOR(i, 0, word.size())
        {
            if (word[i] == '?')
            {
                qLoc.push_back(i);
            }
        }

        // cout << word << " options: " << pow(2, qLoc.size()) << endl;

        T.clear();
        FOR(p, 0, qLoc.size() + 10)
        {
            vector<vector<int>> temp;

            FOR(q, 0, word.size() + 10)
            {
                vector<int> tem;

                FOR(r, 0, qLoc.size() + 10)
                {
                    tem.push_back(-1);
                }
                temp.push_back(tem);
            }
            T.push_back(temp);
        }

        // cout << newDigits(".###.##..#.#", {3, 2, 1}).first << " " << newDigits(".###.##..#.#", {3, 2, 1}).second << endl;
        score += getNum(0, qLoc, 0, word, 0, 0, repInfo);

        // word[qLoc[0]] = '.';
        // cout << check(word, qLoc, repInfo, 1, 1);
        // T[0][0] = check(word, qLoc, repInfo, 1, 1);
        // word[qLoc[0]] = '#';
        // cout << check(word, qLoc, repInfo, 1, 1);
        // T[0][1] = check(word, qLoc, repInfo, 1, 1);

        // T[qi, 0] = T[qi - 1][0] + T[qi - 1][1]

        cout << " : " << score << endl;
        break;
    }
    cout << score << endl;
}
// 3214689053
// 3123458828