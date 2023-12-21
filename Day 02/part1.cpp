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

        if (!line.length())
            break;

        vector<string> m = match(line, "(\\d+|red|green|blue)");

        int red = 0, green = 0, blue = 0;

        bool bad = false;
        for (int i = 1; i < m.size(); i += 2)
        {
            switch (m[i + 1][0])
            {
            case ('r'):
                if (stoi(m[i]) <= 12) {
                    // red += stoi(m[i]);
                } else {
                    bad = true;
                }
                break;
            case ('g'):
                if (stoi(m[i]) <= 13){}
                    // green += stoi(m[i]);
                else
                    bad = true;
                break;
            case ('b'):
                if (stoi(m[i]) <= 14){}
                    // blue += stoi(m[i]);
                else
                    bad = true;
                break;
            }
        }

        if (red <= 12 && green <= 13 && blue <= 14 && !bad)
        {
            cout << line << endl;
            count += stoi(m[0]);
        }

        // count += stoi(numbers[0] + numbers[numbers.size()-1]);
        // cout << stoi(numbers[0] + numbers[numbers.size()-1]) << endl;
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