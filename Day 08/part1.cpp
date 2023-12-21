#include "util.hpp"

struct Node
{
    string name;
    int l;
    int r;
};

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

        vector<string> m = match(line, ("[A-Z]{3}"));

        nodes.push_back({m[0], -1, -1});

        neigh.push_back({m[1], m[2]});
        // cout << bids[0].hand << " " << bids[0].value << endl;
    }

    cout << nodes.size() << "hoi2\n";
    int v;

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

        if (same(nodes[i].name, "AAA"))
        {
            v = i;
        }
    }
    cout << "done\n";

    for (Node node : nodes)
    {
        cout << node.name << ": (" << nodes[node.l].name << ", " << nodes[node.r].name << ")\n";
    }
    cout << v << endl;

    int i = 0;
    while (!same(nodes[v].name, "ZZZ"))
    {
        // cout << start->name  << " " << start->l->name << " " << start->r->name << endl;
        char instr = instructions[i % instructions.size()];

        switch (instr)
        {
        case 'L':
            v = nodes[v].l;
            break;
        case 'R':
            v = nodes[v].r;
            break;
        }

        i++;
    }
    cout << i << endl;
}