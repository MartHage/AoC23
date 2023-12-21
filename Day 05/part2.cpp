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

// pair<vector<Interval>, Interval> subt(Interval numbers, Interval trans) {
//     vector<Interval> res;
//     Interval trans({-1, -1, -1});
//     if (in(numbers, trans.s) && in(numbers, trans.s + trans.l)) {
//         res.push_back({-1, numbers.s, trans.s - numbers.s});
//         res.push_back({-1, trans.s + trans.l + 1, numbers.s + numbers.l - (trans.s + trans.l + 1)});
//         trans = {-1, trans.d + numbers.s - trans.s, numbers.l};
//     } else if (in(numbers, trans.s) && !in(numbers, trans.s + trans.l)) {
//         // t = 55 13

//         res.push_back({-1, numbers.s, trans.s - numbers.s});
//         trans = {-1, trans.d + numbers.s - trans.s, numbers.l - ()};
//     } else if (!in(numbers, trans.s) && in(numbers, trans.s + trans.l)) {
//         res.push_back({-1, trans.s + trans.l + 1, numbers.s + numbers.l - (trans.s + trans.l + 1)});
//     } else if (in(trans, numbers.s) && in(trans, numbers.s + numbers.l)){

//     } else {
//         res.push_back(numbers);
//     }

// }

// ll process(vector<vector<Interval>> trans, ll test)
// {
//     FOR(q, 0, 8)
//     {
//         for (Interval inter : trans[q])
//         {
//             if (in(inter, test))
//             {
//                 // cout << "HHHHHHH" << endl;
//                 test = transfer(inter, test);
//                 break;
//             }
//         }
//     }
//     return test;
// }

int main()
{
    string line;

    int score = 0;

    vector<I> numbers;
    int prev = 100000000;
    int count = 0;
    int x = 0;
    int y = 0;

    getline(cin, line);
    vector<string> m = match(line, "(\\d+)");

    for (ll i = 0; i < m.size(); i += 2)
    {
        numbers.push_back(I::right_open(stoll(m[i]),)});
    }
    cout << "done" << endl;

    getline(cin, line);
    vector<vector<Interval>> trans;

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
        trans.push_back(inters);

        // vector<Interval> nextN;
        // FOR(i, 0, numbers.size())
        // {
        //     // bool process = false;
        //     for (Interval inter : inters)
        //     {
        //         if (in(inter, numbers[i]))
        //         {
        //             // cout << "HHHHHHH" << endl;
        //             numbers[i] = transfer(inter, numbers[i]);
        //             break;
        //         }
        //     }
        // }
        // cout << endl;/
        // break;
    }

    ll small = LLONG_MAX;
    int i = 0;
    for (Interval number : numbers)
    {
        cout << i << " " << numbers.size() << ": " << number.s << " - " << number.l << endl;
        //     // for (ll i = number.s; i < number.s + number.l; i++) {
        //     //     small =  min(small, process(trans, i));
        //     // }
        // }

        cout << small << endl;
    }