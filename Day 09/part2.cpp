#include "util.hpp"

bool allZ(vector<ll> h) {
    for (ll i : h) {
        if (i != 0) 
            return false;
    }
    return true;
}

int main()
{
    string line;

    ll score = 0;
    

    string instructions;


    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<string> m = match(line, ("(-\\d+|\\d+)"));

        vector<ll> history;
        for (string d : m) 
            history.push_back(stoll(d));


        // vector<vector<ll>> histories;
        // histories.push_back(history);
        // while (history[history.size()-1] != 0) {
        while (!allZ(history)) {
            score += history[0];
            vector<ll> nextHis;
            FOR(i, 1, history.size()) {
                cout << history[i-1] << " ";
                nextHis.push_back(history[i-1] - history[i]);
            }
            cout << history[history.size()-1] << endl;
            history = nextHis;
        }
        // score += history.size() == 1 ? history[0] : 0;
        // break;
    }

    cout << score << endl;
}
//3214689053
//3123458828