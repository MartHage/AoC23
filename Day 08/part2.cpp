#include "util.hpp"

struct Node
{
    string name;
    int l;
    int r;
};

bool all_end(vector<Node> nodes, vector<int> pos)
{
    for (int p : pos)
    {
        if (nodes[p].name[2] != 'Z')
            return false;
    }
    return true;
}

int main()
{
    string line;

    ll score = 0;

    vector<Node> nodes;
    vector<pair<string, string>> neigh;

    string instructions;

    getline(cin, line);
    instructions = line;

    getline(cin, line);
    cout << "hoi\n";

    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<string> m = match(line, ("[0-9A-Z]{3}"));
        cout << m[0] << endl;

        nodes.push_back({m[0], -1, -1});

        neigh.push_back({m[1], m[2]});
        // cout << bids[0].hand << " " << bids[0].value << endl;
    }

    cout << nodes.size() << "hoi2\n";
    vector<int> vs;

    FOR(i, 0, nodes.size())
    {
        auto p = neigh[i];
        cout << p.first << "-" << p.second << endl;
        FOR(j, 0, nodes.size())
        {
            // cout << p.first << " " << nodes[]
            if (same(p.first, nodes[j].name))
            {
                nodes[i].l = j;
                break;
            }
        }
        FOR(j, 0, nodes.size())
        {
            if (same(p.second, nodes[j].name))
            {
                nodes[i].r = j;
                break;
            }
        }

        cout << " " << nodes[i].l << "-" << nodes[i].r << endl;

        if (nodes[i].name[2] == 'A')
        {
            vs.push_back(i);
        }
    }
    cout << "done\n";

    for (Node node : nodes)
    {
        cout << node.name << ": (" << nodes[node.l].name << ", " << nodes[node.r].name << ")\n";
    }

    vector<ll> lengths;

    FOR(k, 0, vs.size())
    {
        ll i = 0;
        while (nodes[vs[k]].name[2] != 'Z')
        {
            char instr = instructions[i % instructions.size()];

            switch (instr)
            {
            case 'L':
                vs[k] = nodes[vs[k]].l;

                break;
            case 'R':
                vs[k] = nodes[vs[k]].r;

                break;
            }

            i++;
        }
        lengths.push_back(i);
    }

    ll l = lengths[0];

    FOR (i, 1, lengths.size()) {
        l = lcm(l, lengths[i]);
    }

    cout << l << endl;

    // cout << i << endl;
}