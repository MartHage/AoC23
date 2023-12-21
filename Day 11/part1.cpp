#include "util.hpp"

struct Poll
{
    ll x, y;

    // ll prev;
};

int main()
{
    string line;

    ll score = 0;
    vector<string> grid;
    vector<Poll> galaxies;

    Poll cur;

    ll d = 1;

    ll y = 0;
    while (true)
    {
        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        grid.push_back(line);
        cout << line << endl;

        bool fulld = true;
        FOR(x, 0, line.size())
        {
            if (line[x] == '#')
            {
                galaxies.push_back({x, y});

                cout << x << "-" << y << endl;

                fulld = false;
                // break;
            }
        }
        if (fulld)
        {
            grid.push_back(line);
            y += d;
        }
        y++;
        // score += history.size() == 1 ? history[0] : 0;
        // break;
    }

    FOR(i, 0, galaxies.size())
    {
        cout << i << ": " << galaxies[i].x << ", " << galaxies[i].y << endl;
    }

    ll xd = 0;
    FOR(x, 0, grid[0].size())
    {
        bool fulld = true;
        FOR(y, 0, grid.size())
        {
            if (grid[y][x] == '#')
            {
                fulld = false;
                break;
            }
        }
        if (fulld)
        {
            FOR(i, 0, galaxies.size())
            {
                if (galaxies[i].x - xd > x)
                {
                    galaxies[i].x += d;
                    y += d;
                }
            }
            xd += d;
        }
    }

    cout << abs(galaxies[0].x - galaxies[6].x) + abs(galaxies[0].y - galaxies[6].y) << endl;

    ll c = 0;
    FOR(i, 0, galaxies.size() - 1)
    {
        FOR(j, i + 1, galaxies.size())
        {
            cout << i << ": (" << galaxies[i].x << ", " << galaxies[i].y << "); " << j << ": (" << galaxies[j].x << ", " << galaxies[j].y << ") abs: " << (abs(galaxies[i].x - galaxies[j].x) + abs(galaxies[i].y - galaxies[j].y)) << endl;
            score += abs(galaxies[i].x - galaxies[j].x) + abs(galaxies[i].y - galaxies[j].y);
            c++;
        }
    }

    cout << score << " " << c << endl;
}
// 3214689053
// 3123458828