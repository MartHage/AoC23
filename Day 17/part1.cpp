#include "util.hpp"

#define L 0
#define R 1
#define D 2
#define U 3

struct Node
{
    int d;
    int h;
    int x, y;
    int sd;
    int sD;
};

void pr(Node no)
{
    cout << "(" << no.x << ", " << no.y << ") "
         << " D:" << no.sD << ", dis: " << no.sd << "  ";
}

int h(vector<vector<int>> grid, int x, int y)
{
    return grid.size() - y + grid[0].size() - x - 2;
}

int main()
{
    string line;

    ll score = 0;

    vector<vector<int>> grid;

    while (true)
    {
        vector<string> mirror;

        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<int> t;
        for (string w : match(line, "(\\d)"))
        {
            t.push_back(stoi(w));
        }
        grid.push_back(t);
    }

    auto compare = [](Node a, Node b)
    { return a.d + a.h > b.d + b.h; };
    priority_queue<Node, std::vector<Node>, decltype(compare)> q(compare);

    vector<vector<vector<vector<int>>>> dis;
    FOR(y, 0, grid.size())
    {
        vector<vector<vector<int>>> temp;
        FOR(x, 0, grid[0].size())
        {

            temp.push_back({{INT_MAX, INT_MAX, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX}});
        }
        dis.push_back(temp);
    }

    q.push({0, 0, 0, 0, D, 2});
    q.push({0, 0, 0, 0, R, 2});

    int c = 0;

    while (!q.empty())
    {
        Node cur = q.top();
        q.pop();

        // cout << "1\n";
        if (cur.d > dis[cur.y][cur.x][cur.sD][cur.sd])
            continue;

        c++;

        dis[cur.y][cur.x][cur.sD][cur.sd] = cur.d;

        if (
            dis[grid.size() - 1][grid[0].size() - 1][D][0] < INT_MAX &&
            dis[grid.size() - 1][grid[0].size() - 1][D][1] < INT_MAX &&
            dis[grid.size() - 1][grid[0].size() - 1][D][2] < INT_MAX &&
            dis[grid.size() - 1][grid[0].size() - 1][R][0] < INT_MAX &&
            dis[grid.size() - 1][grid[0].size() - 1][R][1] < INT_MAX &&
            dis[grid.size() - 1][grid[0].size() - 1][R][2] < INT_MAX)
            break;

        // pr(cur);
        // cout << "2\n";
        switch (cur.sD)
        {
        case L:
            if (cur.sd > 0 && cur.x > 0)
                q.push({cur.d + grid[cur.y][cur.x - 1], h(grid, cur.x - 1, cur.y), cur.x - 1, cur.y, cur.sd - 1, L});
            if (cur.y < grid.size() - 1)
                q.push({cur.d + grid[cur.y + 1][cur.x], h(grid, cur.x, cur.y + 1), cur.x, cur.y + 1, 2, D});
            if (cur.y > 0)
                q.push({cur.d + grid[cur.y - 1][cur.x], h(grid, cur.x, cur.y - 1), cur.x, cur.y - 1, 2, U});
            break;
        case R:
            if (cur.sd > 0 && cur.x < grid[0].size() - 1)
                q.push({cur.d + grid[cur.y][cur.x + 1], h(grid, cur.x + 1, cur.y), cur.x + 1, cur.y, cur.sd - 1, R});
            if (cur.y < grid.size() - 1)
                q.push({cur.d + grid[cur.y + 1][cur.x], h(grid, cur.x, cur.y + 1), cur.x, cur.y + 1, 2, D});
            if (cur.y > 0)
                q.push({cur.d + grid[cur.y - 1][cur.x], h(grid, cur.x, cur.y - 1), cur.x, cur.y - 1, 2, U});
            break;
        case U:
            if (cur.sd > 0 && cur.y > 0)
                q.push({cur.d + grid[cur.y - 1][cur.x], h(grid, cur.x, cur.y - 1), cur.x, cur.y - 1, cur.sd - 1, U});
            if (cur.x < grid[0].size() - 1)
                q.push({cur.d + grid[cur.y][cur.x + 1], h(grid, cur.x + 1, cur.y), cur.x + 1, cur.y, 2, R});
            if (cur.x > 0)
                q.push({cur.d + grid[cur.y][cur.x - 1], h(grid, cur.x - 1, cur.y), cur.x - 1, cur.y, 2, L});
            break;
        case D:
            if (cur.sd > 0 && cur.y < grid.size() - 1)
                q.push({cur.d + grid[cur.y + 1][cur.x], h(grid, cur.x, cur.y + 1), cur.x, cur.y + 1, cur.sd - 1, D});
            if (cur.x < grid[0].size() - 1)
                q.push({cur.d + grid[cur.y][cur.x + 1], h(grid, cur.x + 1, cur.y), cur.x + 1, cur.y, 2, R});
            if (cur.x > 0)
                q.push({cur.d + grid[cur.y][cur.x - 1], h(grid, cur.x - 1, cur.y), cur.x - 1, cur.y, 2, L});
            break;
        }
    }

    cout << dis[grid.size() - 1][grid[0].size() - 1][D][0] << endl;
    cout << dis[grid.size() - 1][grid[0].size() - 1][D][1] << endl;
    cout << dis[grid.size() - 1][grid[0].size() - 1][D][2] << endl;
    cout << dis[grid.size() - 1][grid[0].size() - 1][R][0] << endl;
    cout << dis[grid.size() - 1][grid[0].size() - 1][R][1] << endl;
    cout << dis[grid.size() - 1][grid[0].size() - 1][R][2] << endl;
    cout << c << endl;
}
