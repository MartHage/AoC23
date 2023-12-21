#include "util.hpp"

vector<char> C = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};

// struct compi
// {
//     bool operator()(const Bid &a, const Bid &b) const
//     {
//         return getScore(a.hand) < getScore(b.hand);
//     }
// };

// 253723241

ll getScore(string hand)
{
    ll occurA = 0;
    ll occurB = 0;

    for (char card : C)
    {
        string to_match = "(";
        to_match += card;
        to_match += ")";
        // cout << to_match << endl;

        if (match(hand, to_match).size() >= occurA)
        {
            occurB = occurA;
            occurA = match(hand, to_match).size();
        } else if (match(hand, to_match).size() > occurB) {
            occurB = match(hand, to_match).size();
        }
    }

    if (occurA == 5)
        return 0;
    else if (occurA == 4)
        return 1;
    else if (occurA == 3 && occurB == 2)
        return 2;
    else if (occurA == 3)
        return 3;
    else if (occurA == 2 && occurB == 2)
        return 4;
    else if (occurA == 2)
        return 5;
    else
        return 6;
}

bool lexoComp(string a, string b) {
    for (ll i = 0; i < a.size(); i++) {
        if (find(C.begin(), C.end(), a[i]) != find(C.begin(), C.end(), b[i])) {
            return find(C.begin(), C.end(), a[i]) < find(C.begin(), C.end(), b[i]);
        }
    }
    return true;
}

struct Bid
{
    string hand;
    ll value;

    bool operator<(const Bid &val) const
    {
        if (getScore(hand) == getScore(val.hand))
            return lexoComp(hand, val.hand);
        else
            return getScore(hand) < getScore(val.hand);
    }
};

int main()
{
    string line;

    ll score = 0;

    vector<Bid> bids;

    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        bids.push_back({split(line)[0], stoi(split(line)[1])});
        // cout << bids[0].hand << " " << bids[0].value << endl;
    }

    sort(bids.begin(), bids.end());

    ll r = bids.size();
    for (Bid bid : bids)
    {
        score += r * bid.value;
        r--;
        cout << bid.hand << " " << bid.value << ": " << getScore(bid.hand) << endl;
    }
    cout << score << endl;
}