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

        vector<string> m = match(line, "(\\d+|\\|)");

        // lines.push_back(line);
        numbers.push_back(m);

        // count += stoi(numbers[0] + numbers[numbers.size()-1]);
        // cout << stoi(numbers[0] + numbers[numbers.size()-1]) << endl;
    }

    vector<int> copies(numbers.size(), 1);
    // copies[0] = 1;
    FOR(i, 0, numbers.size())
    {
        vector<int> lotto;
        vector<int> mine;

        bool isLotto = true;
        bool firstMatch = false;

        int card = 0;

        FOR(j, 1, numbers[i].size())
        {
            string in = numbers[i][j];
            if (in[0] == '|')
            {
                isLotto = false;
                continue;
            }
            if (isLotto)
            {
                // cout << in << endl;
                lotto.push_back(stoi(in));
            }
            else
            {
                if (find(lotto.begin(), lotto.end(), stoi(in)) != lotto.end())
                {
                    card ++;
                }
            }
        }

        FOR (j, 1, card +1) {
            copies[i + j] += copies[i];
        }

        count += copies[i];
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