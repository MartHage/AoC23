#include "util.hpp"

struct Interval
{
    ll d;
    ll s;
    ll l;
};

bool in(Interval inter, ll test)
{
    return (inter.s <= test && test < inter.s + inter.l);
}

ll transfer(Interval inter, ll test)
{
    if (in(inter, test))
    {
        return test - inter.s + inter.d;
    }
    else
    {
        return test;
    }
}

int main()
{
    string line;

    int score = 0;

    vector<ll> numbers;
    int prev = 100000000;
    int count = 0;
    int x = 0;
    int y = 0;

    getline(cin, line);
    vector<string> m = match(line, "(\\d+)");

    for (string mi : m)
    {
        numbers.push_back(stoll(mi));
    }

    getline(cin, line);

    FOR(q, 0, 8)
    {
        getline(cin, line);

        vector<Interval> inters;

        while (true)
        {
            getline(cin, line);
            cout << line << endl;

            if (!line.length())
                break;

            vector<string> m = match(line, "(\\d+)");

            // lines.push_back(line);
            inters.push_back({stoll(m[0]), stoll(m[1]), stoll(m[2])});

            // count += stoi(numbers[0] + numbers[numbers.size()-1]);
            // cout << stoi(numbers[0] + numbers[numbers.size()-1]) << endl;
        }

        FOR(i, 0, numbers.size())
        {
            // bool process = false;
            for (Interval inter : inters)
            {
                if (in(inter, numbers[i]))
                {
                    // cout << "HHHHHHH" << endl;
                    numbers[i] = transfer(inter, numbers[i]);
                    break;
                }
            }
        }
        cout << endl;
        // break;
    }

    cout << *min_element(numbers.begin(), numbers.end()) << endl;
}