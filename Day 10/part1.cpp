#include "util.hpp"

struct Point
{
    int x, y, l;

    // int prev;
};

int main()
{
    string line;

    int score = 0;
    vector<string> grid;

    Point cur;

    int y = 0;
    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        grid.push_back(line);

        FOR(x, 0, line.size())
        {
            if (line[x] == 'S')
            {
                cur = {x, y, 0};
            }
        }
        y++;
        // score += history.size() == 1 ? history[0] : 0;
        // break;
    }

    bool found = false;

    list<Point> q;
    q.push_back({cur.x + 1, cur.y, 1});
    // q.push_back({cur.x - 1, cur.y, 1});
    // q.push_back({cur.x, cur.y + 1, 1});
    // q.push_back({cur.x, cur.y - 1, 1});

    while (!found)
    {
        Point prev = cur;
        cout << grid[cur.y][cur.x] << ": " << cur.x << " " << cur.y << endl;
        cur = q.front();
        q.pop_front();

        switch (grid[cur.y][cur.x])
        {
        case 'S':
            found = true;
            score = max(score, cur.l / 2);
            break;
        case '-':
            q.push_front({cur.x + (prev.x < cur.x ? 1 : -1), cur.y, cur.l + 1});
            break;
        case '|':
            q.push_front({cur.x, cur.y + (prev.y < cur.y ? 1 : -1), cur.l + 1});
            break;
        case 'F':
            q.push_front({cur.x + (prev.y > cur.y ? 1 : 0), cur.y + (prev.x > cur.x ? 1 : 0), cur.l + 1});
            break;
        case 'J':
            q.push_front({cur.x + (prev.y < cur.y ? -1 : 0), cur.y + (prev.x < cur.x ? -1 : 0), cur.l + 1});
            cout << (cur.x + (prev.y > cur.y ? -1 : 0)) << " " << (cur.y + (prev.x < cur.x ? -1 : 0)) << endl;
            break;
        case '7':
            q.push_front({cur.x + (prev.y > cur.y ? -1 : 0), cur.y + (prev.x < cur.x ? 1 : 0), cur.l + 1});
            break;
        case 'L':
            q.push_front({cur.x + (prev.y < cur.y ? 1 : 0), cur.y + (prev.x > cur.x ? -1 : 0), cur.l + 1});
            break;
        }
    }

    cout << score << endl;
}
// 3214689053
// 3123458828