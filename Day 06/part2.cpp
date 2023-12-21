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
        ll first = -1;
        FOR(t, 1, ti) {
            // cout << t << " " << ti << " " << (t * (ti - t)) << endl;;
            if (t * (ti - t) > distance[i]) {
                first = t;
                break;
                // cout << "hoi\n";
                // c++;
            }
        }
        int a = first, b = ti;

        while (a < b -1) {
            ll mid = (a + b)/2;
            cout << a <<" "  << mid <<" " << b << endl;

            if (mid * (ti - mid) > distance[i]) {  
                a = mid;
            } else {
                b = mid;
            }
        }

        cout << (a - first + 1) << endl;


        count *= c;
        cout << c << endl;
        break;
    }
    cout << count << endl;
}