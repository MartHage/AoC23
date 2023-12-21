#include "util.hpp"


int main()
{
    string line;

    int score = 0;

    vector<ll> numbers;
    int prev = 100000000;
    int count = 1;
    int x = 0;
    int y = 0;

    vector<ll> time, distance;

    getline(cin, line);
    vector<string> m = match(line, "(\\d+)");

    for (string mi : m)
    {
        time.push_back(stoll(mi));
    }
    getline(cin, line);
    vector<string> m2 = match(line, "(\\d+)");

    for (string mi : m2)
    {
        distance.push_back(stoll(mi));
    }

    FOR(i, 0, time.size()) {
        ll ti = time[i];

        ll c = 0;
        FOR(t, 1, ti) {
            // cout << t << " " << ti << " " << (t * (ti - t)) << endl;;
            if (t * (ti - t) > distance[i]) {
                c++;
            }
        }

        count *= c;
        cout << c << endl;
        // break;
    }
    cout << count << endl;
}