#include "util.hpp"

struct Point
{
    int x, y;

    // int prev;
};

void pr(vector<vector<char>> grid)
{
    for (auto gri : grid)
    {
        for (auto gr : gri)
        {
            cout << gr;
            // if (gr == '.')
                // count++;
        }
        cout << endl;
    }
    // cout << count << /endl;
}

vector<Point> neighs(Point cur, int n, int m)
{
    vector<Point> neigh;
    if (cur.x > 0)
        neigh.push_back({cur.x - 1, cur.y});
    if (cur.x < n)
        neigh.push_back({cur.x + 1, cur.y});
    if (cur.y > 0)
        neigh.push_back({cur.x, cur.y - 1});
    if (cur.y < m)
        neigh.push_back({cur.x, cur.y + 1});

    return neigh;
}

int main()
{
    string line;

    int score = 0;
    vector<vector<char>> grid;

    Point cur;

    int y = 0;

    vector<char> gline;

    getline(cin, line);
    gline.push_back(line[0]);
    FOR(i, 1, line.size())
    {
        gline.push_back(' ');
        gline.push_back(line[i]);
    }
    grid.push_back(gline);

    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<char> place;
        FOR(i, 0, grid[0].size())
        {
            place.push_back(' ');
        }
        grid.push_back(place);

        vector<char> gline;

        gline.push_back(line[0]);
        FOR(i, 1, line.size())
        {
            gline.push_back(' ');
            gline.push_back(line[i]);
        }
        grid.push_back(gline);

        // grid.push_back(line);

        // y++;
        // score += history.size() == 1 ? history[0] : 0;
        // break;
    }

    FOR(y, 0, grid.size())
    {
        FOR(x, 0, grid[0].size())
        {
            if (grid[y][x] == 'S')
            {
                cur = {x, y};
            }

            if (grid[y][x] == ' ')
            {
                if (x > 0 && x < grid[0].size() - 1)
                {
                    if ((grid[y][x - 1] == 'F' || grid[y][x - 1] == 'S' || grid[y][x - 1] == 'L' || grid[y][x - 1] == '-') && (grid[y][x + 1] == '7' || grid[y][x + 1] == 'J' || grid[y][x + 1] == '-'))
                        grid[y][x] = '-';
                }

                if (y > 0 && y < grid.size() - 1)
                {
                    if ((grid[y + 1][x] == 'L' || grid[y + 1][x] == 'S' || grid[y + 1][x] == 'J' || grid[y + 1][x] == '|') && (grid[y - 1][x] == 'F' || grid[y - 1][x] == '7' || grid[y - 1][x] == '|'))
                        grid[y][x] = '|';
                }
            }
        }
    }

    pr(grid);
    // return 0;

    list<Point> mq;
    mq.push_back({cur.x + 1, cur.y});

    bool found = false;

    while (!found)
    {
        Point prev = cur;
        cout << grid[cur.y][cur.x] << ": " << cur.x << " " << cur.y << endl;
        cur = mq.front();
        // q.pop_front();

        switch (grid[cur.y][cur.x])
        {
        case 'S':
            found = true;
            break;
        case '-':
            mq.push_front({cur.x + (prev.x < cur.x ? 1 : -1), cur.y});
            break;
        case '|':
            mq.push_front({cur.x, cur.y + (prev.y < cur.y ? 1 : -1)});
            break;
        case 'F':
            mq.push_front({cur.x + (prev.y > cur.y ? 1 : 0), cur.y + (prev.x > cur.x ? 1 : 0)});
            break;
        case 'J':
            mq.push_front({cur.x + (prev.y < cur.y ? -1 : 0), cur.y + (prev.x < cur.x ? -1 : 0)});
            // cout << (cur.x + (prev.y > cur.y ? -1 : 0)) << " " << (cur.y + (prev.x < cur.x ? -1 : 0)) << endl;
            break;
        case '7':
            mq.push_front({cur.x + (prev.y > cur.y ? -1 : 0), cur.y + (prev.x < cur.x ? 1 : 0)});
            break;
        case 'L':
            mq.push_front({cur.x + (prev.y < cur.y ? 1 : 0), cur.y + (prev.x > cur.x ? -1 : 0)});
            break;
        }

        if (cur.x == 7 && cur.y == 0)
            break;
    }

    FOR(y, 0, grid.size())
    {
        FOR(x, 0, grid[0].size())
        {
            grid[y][x] = '.';
        }
    }

    for (Point p : mq)
    {
        grid[p.y][p.x] = '0';
    }

    pr(grid);

    list<Point> q;

    FOR(y, 0, grid.size())
    {
        if (grid[y][0] == '.' || grid[y][0] == ' ')
            q.push_back({0, y});

        int n = grid[0].size() - 1;
        if (grid[y][n] == '.' || grid[y][n] == ' ')
            q.push_back({n, y});
    }

    FOR(x, 0, grid[0].size())
    {
        if (grid[0][x] == '.' || grid[0][x] == ' ')
            q.push_back({x, 0});

        int n = grid.size() - 1;
        if (grid[n][x] == '.' || grid[n][x] == ' ')
            q.push_back({x, n});
    }

    while (!q.empty())
    {
        Point c = q.front();
        q.pop_front();
        if (grid[c.y][c.x] == 'X')
            continue;

        grid[c.y][c.x] = 'X';

        for (Point nei : neighs(c, grid[0].size() - 1, grid.size() - 1))
        {
            if (grid[nei.y][nei.x] == '.' || grid[nei.y][nei.x] == ' ')
            {
                q.push_back(nei);
            }
        }
    }

    cout << endl;
    pr(grid);

    for (int y = 0; y < grid.size(); y += 2)
    {
        for (int x = 0; x < grid[y].size(); x += 2)
        {
            if (grid[y][x] == '.') {
                score ++;
            }
        }
    }
    cout << score << endl;

    // bool found = false;

    // list<Point> q;

    // FOR (y, 0, grid.size() - 1) {
    //     q.push_back({0, y, 0, false, true});
    //     int n = grid[0].size()-1;
    //     q.push_back({n, y, 0, false, true});
    // }

    // FOR (x, 0, grid[0].size() - 1) {
    //     q.push_back({x, 0, 0, true, false});
    //     int n = grid[0].size()-1;
    //     q.push_back({n, y, 0, false, true});
    // }

    // while (!found)
    // {
    //     Point prev = cur;
    //     cout << grid[cur.y][cur.x] << ": " << cur.x << " " << cur.y << endl;
    //     cur = q.front();
    //     q.pop_front();

    //     switch (grid[cur.y][cur.x])
    //     {
    //     case 'S':
    //         found = true;
    //         score = max(score, cur.l / 2);
    //         break;
    //     case '-':
    //         q.push_front({cur.x + (prev.x < cur.x ? 1 : -1), cur.y});
    //         break;
    //     case '|':
    //         q.push_front({cur.x, cur.y + (prev.y < cur.y ? 1 : -1)});
    //         break;
    //     case 'F':
    //         q.push_front({cur.x + (prev.y > cur.y ? 1 : 0), cur.y + (prev.x > cur.x ? 1 : 0)});
    //         break;
    //     case 'J':
    //         q.push_front({cur.x + (prev.y < cur.y ? -1 : 0), cur.y + (prev.x < cur.x ? -1 : 0)});
    //         cout << (cur.x + (prev.y > cur.y ? -1 : 0)) << " " << (cur.y + (prev.x < cur.x ? -1 : 0)) << endl;
    //         break;
    //     case '7':
    //         q.push_front({cur.x + (prev.y > cur.y ? -1 : 0), cur.y + (prev.x < cur.x ? 1 : 0)});
    //         break;
    //     case 'L':
    //         q.push_front({cur.x + (prev.y < cur.y ? 1 : 0), cur.y + (prev.x > cur.x ? -1 : 0)});
    //         break;
    //     }
    // }

    // cout << score << endl;
}
// 3214689053
// 3123458828