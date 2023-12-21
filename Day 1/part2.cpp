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
        cout << line << endl;

        if (!line.length())
            break;

        vector<string> numbers = match(line, "(?=(\\d|one|two|three|four|five|six|seven|eight|nine))");
        cout << line << endl;

        cout << numbers[0] << endl;
        if (numbers[0].size() != 1)
        {

            if (numbers[0].compare("zero") == 0)
            {
                numbers[0] = "0";
            }

            if (numbers[0].compare("one") == 0)
            {
                numbers[0] = "1";
            }

            if (numbers[0].compare("two") == 0)
            {
                numbers[0] = "2";
            }

            if (numbers[0].compare("three") == 0)
            {
                numbers[0] = "3";
            }

            if (numbers[0].compare("four") == 0)
            {
                numbers[0] = "4";
            }

            if (numbers[0].compare("five") == 0)
            {
                numbers[0] = "5";
            }
            if (numbers[0].compare("six") == 0)
            {
                numbers[0] = "6";
            }
            if (numbers[0].compare("seven") == 0)
            {
                numbers[0] = "7";
            }
            if (numbers[0].compare("eight") == 0)
            {
                numbers[0] = "8";
            }
            if (numbers[0].compare("nine") == 0)
            {
                numbers[0] = "9";
            }
        }
        cout << numbers[numbers.size() - 1] << endl;

        if (numbers[numbers.size() - 1].size() != 1)
        {
            if (numbers[numbers.size() - 1].compare("zero") == 0)
            {
                numbers[numbers.size() - 1] = "0";
            }

            if (numbers[numbers.size() - 1].compare("one") == 0)
            {
                numbers[numbers.size() - 1] = "1";
            }

            if (numbers[numbers.size() - 1].compare("two") == 0)
            {
                numbers[numbers.size() - 1] = "2";
            }

            if (numbers[numbers.size() - 1].compare("three") == 0)
            {
                numbers[numbers.size() - 1] = "3";
            }

            if (numbers[numbers.size() - 1].compare("four") == 0)
            {
                numbers[numbers.size() - 1] = "4";
            }

            if (numbers[numbers.size() - 1].compare("five") == 0)
            {
                numbers[numbers.size() - 1] = "5";
            }
            if (numbers[numbers.size() - 1].compare("six") == 0)
            {
                numbers[numbers.size() - 1] = "6";
            }
            if (numbers[numbers.size() - 1].compare("seven") == 0)
            {
                numbers[numbers.size() - 1] = "7";
            }
            if (numbers[numbers.size() - 1].compare("eight") == 0)
            {
                numbers[numbers.size() - 1] = "8";
            }
            if (numbers[numbers.size() - 1].compare("nine") == 0)
            {
                numbers[numbers.size() - 1] = "9";
            }
        }

        count += stoi(numbers[0] + numbers[numbers.size() - 1]);
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