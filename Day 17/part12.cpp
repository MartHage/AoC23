#include "util.hpp"

#define H 0
#define V 1

struct Node
{
    int d;
    int h;
    int x, y;
    int sD;
};

void pr(Node no)
{
    cout << "(" << no.x << ", " << no.y << ") "
         << " D:" << no.sD << "  ";
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

    vector<vector<vector<int>>> dis;
    FOR(y, 0, grid.size())
    {
        vector<vector<int>> temp;
        FOR(x, 0, grid[0].size())
        {

            temp.push_back({INT_MAX, INT_MAX});
        }
        dis.push_back(temp);
    }

    q.push({0, 0, 0, 0, H});
    q.push({0, 0, 0, 0, V});

    int c = 0;

    while (!q.empty())
    {
        Node cur = q.top();
        q.pop();

        // cout << "1\n";
        if (cur.d > dis[cur.y][cur.x][cur.sD])
            continue;

        // cout << cur.x << " " << cur.x << " " << cur.sD << " " << cur.d << endl;


        dis[cur.y][cur.x][cur.sD] = cur.d;
        c++;

        if (
            dis[grid.size() - 1][grid[0].size() - 1][H] < INT_MAX &&
            dis[grid.size() - 1][grid[0].size() - 1][V] < INT_MAX)
            break;

        // pr(cur);
        // cout << "2\n";

        vector<Node> neighs;
        if (cur.sD == V)
        {
            int nx = cur.x;
            int nd = cur.d;
            FOR(i, 0, 10)
            {
                if (nx > 0)
                {
                    nx--;
                    nd += grid[cur.y][nx];
                    if (i < 3)
                        continue;
                    if (nd < dis[cur.y][nx][H])
                    {
                        dis[cur.y][nx][H] = nd;
                        q.push({nd, 0, nx, cur.y, H});
                    }
                }
            }
            nx = cur.x;
            nd = cur.d;
            FOR(i, 0, 10)
            {
                if (nx < grid[0].size() - 1)
                {
                    nx++;
                    nd += grid[cur.y][nx];
                    if (i < 3)
                        continue;
                    if (nd < dis[cur.y][nx][H])
                    {
                        dis[cur.y][nx][H] = nd;
                        q.push({nd, 0, nx, cur.y, H});
                    }
                }
            }
        }
        else
        {
            int ny = cur.y;
            int nd = cur.d;
            FOR(i, 0, 10)
            {
                if (ny > 0)
                {
                    ny--;
                    nd += grid[ny][cur.x];
                    if (i < 3)
                        continue;
                    if (nd < dis[ny][cur.x][V])
                    {
                        dis[ny][cur.x][V] = nd;
                        q.push({nd, 0, cur.x, ny, V});
                    }
                }
            }
            ny = cur.y;
            nd = cur.d;
            FOR(i, 0, 10)
            {
                if (ny < grid.size() - 1)
                {
                    ny++;
                    nd += grid[ny][cur.x];
                    if (i < 3)
                        continue;
                    if (nd < dis[ny][cur.x][V])
                    {
                        dis[ny][cur.x][V] = nd;
                        q.push({nd, 0, cur.x, ny, V});
                    }
                }
            }
        }
    }

    cout << dis[grid.size() - 1][grid[0].size() - 1][H] << endl;
    cout << dis[grid.size() - 1][grid[0].size() - 1][V] << endl;
    cout << c << endl;
}
