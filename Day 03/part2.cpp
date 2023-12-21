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

        vector<string> m = match(line, "(\\d+|\\.+|[^\\.\\d])");

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

            vector<int> gears;
            if (numbers[i][j][0] == '*')
            {
                // int num = stoi(numbers[i][j]);
                bool good = false;

                if (j > 0)
                {
                    if (match(numbers[i][j - 1], "(\\d+)").size() > 0)
                    {
                        cout << "capot " << numbers[i][j - 1] << "\n";
                        gears.push_back(stoi(numbers[i][j - 1]));
                    }
                }
                if (j < numbers[i].size() - 1)
                {
                    // cout << numbers[i][j] << numbers[i][j + 1][0] << endl;
                    if (match(numbers[i][j + 1], "(\\d+)").size() > 0)
                    {
                        cout << "capot\n";
                        gears.push_back(stoi(numbers[i][j + 1]));
                    }
                }
                if (i > 0)
                {
                    int posa = 0;
                    FOR(k, 0, numbers[i - 1].size())
                    {
                        if (match(numbers[i - 1][k], "(\\d)").size() > 0)
                        {
                            if ((posa <= pos - 1 && pos <= posa + numbers[i - 1][k].size()) || (posa <= pos + 1 && pos + 1 <= posa + numbers[i - 1][k].size()))
                            {
                                cout << i << "-" << pos << " " << posa << " " << numbers[i - 1][k] << endl;
                                gears.push_back(stoi(numbers[i - 1][k]));
                            }
                        }

                        posa += numbers[i - 1][k].size();
                    }
                }
                if (i < lines.size() - 1)
                {
                    int posa = 0;
                    FOR(k, 0, numbers[i + 1].size())
                    {
                        if (match(numbers[i + 1][k], "(\\d)").size() > 0)
                        {
                            if ((posa <= pos - 1 && pos <= posa + numbers[i + 1][k].size()) || (posa <= pos + 1 && pos + 1 <= posa + numbers[i + 1][k].size()))
                            {
                                cout << i << "-" << pos << " " << posa << " " << numbers[i + 1][k] << endl;
                                gears.push_back(stoi(numbers[i + 1][k]));
                            }
                        }

                        posa += numbers[i + 1][k].size();
                    }
                }
                if (gears.size() == 2)
                {
                    cout << gears[0] << endl;
                    count += gears[0] * gears[1];
                }
                else
                {
                    // cout << i << " " << j << " " << numbers[i][j] << endl;
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