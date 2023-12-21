#include "util.hpp"

int main()
{
    string line;

    int score = 0;

    vector<vector<string>> numbers;
    vector<string> lines;
    int prev = 100000000;
    int count = 0;
    int x = 0;
    int y = 0;
    while (true)
    {
        getline(cin, line);
        cout << line << endl;

        if (!line.length())
            break;

        vector<string> m = match(line, "(\\d+|\\.+|\\$|\\+|\\*)");

        lines.push_back(line);
        numbers.push_back(m);

        // count += stoi(numbers[0] + numbers[numbers.size()-1]);
        // cout << stoi(numbers[0] + numbers[numbers.size()-1]) << endl;
    }

    FOR(i, 0, numbers.size())
    {

        int pos = 0;
        FOR(j, 0, numbers[i].size())
        {

            if (match(numbers[i][j], "(\\d+)").size() > 0)
            {
                int num = stoi(numbers[i][j]);
                bool good = false;

                if (j > 0)
                {
                    if (numbers[i][j - 1][0] != '.')
                    {
                        good = true;
                    }
                }
                if (j < numbers[i].size() - 1)
                {
                    if (numbers[i][j + 1][0] != '.')
                    {
                        good = true;
                    }
                }
                if (i > 0)
                {
                    if (match(lines[i - 1].substr(pos - (pos > 0 ? 1 : 0), numbers[i][j].size() + 2), "([^\\.\\n])").size() > 0)
                    {
                        good = true;
                    } else {
                        // cout << " " << lines[i - 1].substr(pos - (pos > 0 ? 1 : 0), numbers[i][j].size() + 2) << endl;
                    }
                }
                if (i < lines.size() - 1)
                {
                    if (match(lines[i + 1].substr(pos - (pos > 0 ? 1 : 0), numbers[i][j].size() + 2), "([^\\.\\n])").size() > 0)
                    {
                        good = true;
                    } else {

                        // cout << " " << lines[i + 1].substr(pos - (pos > 0 ? 1 : 0), numbers[i][j].size() + 2) << endl;
                    }
                }
                if (good)
                {
                    count += num;
                }
                else
                {
                    cout << i << " " << j << " " << numbers[i][j] << endl;
                }
            }
            pos += numbers[i][j].size();
        }
    }

    // for (int a : numbers) {
    //     count += floor(a / 3) -2;
    // }

    // cout << x * y << endl;
    cout << count << endl;

    // sort(numbers.begin(), numbers.end());

    // FOR(i, 0, numbers.size())
    // {
    //     FOR(j, i + 1, numbers.size())
    //     {
    //         FOR(k, j + 1, numbers.size())
    //         {
    //             if (numbers[i] + numbers[j] + numbers[k] == 2020) {
    //                 cout << numbers[i] * numbers[j] * numbers[k] << endl;
    //             }
    //         }
    //     }
    // }
}