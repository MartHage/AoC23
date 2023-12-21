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

pair<int, int> getRem(int li, string l, vector<int> digits)
{
    int index = 0;
    int c = 0;
    FOR(i, 0, li + 1)
    {
        if (l[i] == '#')
            c++;
        else
        {
            if (c > 0 && digits[index] != c)
                return {-1, -1};
            else if (c > 0)
            {
                index++;
            }

            c = 0;
        }
    }
    if ((index > digits.size() - 1))
    {
        return {0 - c, index};
    }
    else if (c == digits[index])
    {
        return {0, index + 1};
    }
    else
    {
        return {digits[index] - c, index};
    }
}

vector<vector<vector<ll>>> T;

ll getNum(int li, string l, int fd, int di, vector<int> digits)
{

    // pr(li, l, fd, di, digits);

    // if (newCheck(li, l, di, digits))
    // {

    //     // cout << "YEAH "  << i  << " " << li << " " << l << " " << di  << endl;
    //     return 1;
    // }
    if (li >= l.size())
    {

        pair<int, int> dj = getRem(li, l, digits);
        cout << l << " - " << dj.first << " " << (dj.second) << endl;
        dj = getRem(li, l, digits);
        return dj.first == 0 && dj.second == digits.size();
    }

    ll score = 0;

    if (l[li] == '.' || l[li] == '#')
    {
        pair<int, int> dj = getRem(li, l, digits);
        if (dj.first >= 0)
        {
            if (T[li + 1][dj.first][dj.second] == -1)
                T[li + 1][dj.first][dj.second] = getNum(li + 1, l, dj.first, dj.second, digits);
            score += T[li + 1][dj.first][dj.second];
        }
    }
    else
    {
        l[li] = '.';
        pair<int, int> dj = getRem(li, l, digits);
        if (dj.first >= 0)
        {
            if (T[li + 1][dj.first][dj.second] == -1)
                T[li + 1][dj.first][dj.second] = getNum(li + 1, l, dj.first, dj.second, digits);
            score += T[li + 1][dj.first][dj.second];
        }

        l[li] = '#';
        dj = getRem(li, l, digits);
        if (dj.first >= 0)
        {
            if (T[li + 1][dj.first][dj.second] == -1)
                T[li + 1][dj.first][dj.second] = getNum(li + 1, l, dj.first, dj.second, digits);
            score += T[li + 1][dj.first][dj.second];
        }
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
        FOR(i, 0, 4)
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
        FOR(p, 0, word.size() + 10)
        {
            vector<vector<ll>> temp;

            FOR(q, 0, word.size() + 10)
            {
                vector<ll> tem;

                FOR(r, 0, qLoc.size() + 10)
                {
                    tem.push_back(-1);
                }
                temp.push_back(tem);
            }
            T.push_back(temp);
        }

        // cout << newDigits(".###.##..#.#", {3, 2, 1}).first << " " << newDigits(".###.##..#.#", {3, 2, 1}).second << endl;
        score += getNum(0, word, 0, 0, repInfo);

        // word[qLoc[0]] = '.';
        // cout << check(word, qLoc, repInfo, 1, 1);
        // T[0][0] = check(word, qLoc, repInfo, 1, 1);
        // word[qLoc[0]] = '#';
        // cout << check(word, qLoc, repInfo, 1, 1);
        // T[0][1] = check(word, qLoc, repInfo, 1, 1);

        // T[qi, 0] = T[qi - 1][0] + T[qi - 1][1]

        cout << " : " << score << endl;
        // break;
    }
    cout << score << endl;
}
// 19319501625
// 40794338105

