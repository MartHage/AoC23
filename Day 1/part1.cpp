#include "util.hpp"

int main()
{
    string line;

    int score = 0;

    vector<int> numbers;
    int prev = 100000000;
    int count = 0;
    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<string> numbers = match(line, "(\\d)");

        count += stoi(numbers[0] + numbers[numbers.size()-1]);
        // cout << stoi(numbers[0] + numbers[numbers.size()-1]) << endl;
    }


    // for (int a : numbers) {
    //     count += floor(a / 3) -2;
    // }

    cout << count << endl;
    // cout << count << endl;

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