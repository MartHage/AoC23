#include "util.hpp"

struct Beam
{
    int x, y;
    int dx, dy;
};

bool operator==(const Beam &l, const Beam &r)
{
    return l.x == r.x && l.y == r.y && l.dx == r.dx && l.dy == r.dy;
}

int simulate(Beam b, vector<string> grid, int i)
{
    list<Beam> covered;
    list<Beam> beams;
    beams.push_back(b);

    vector<string> energized;
    FOR(y, 0, grid.size())
    {
        energized.push_back(string(grid[y].size(), '.'));
    }

    // beams.push_back({(int)energized[0].size(), l, -1, 0});

    bool first = true;

    while (!beams.empty())
    {
        Beam b = beams.front();
        beams.pop_front();

        if (find(covered.begin(), covered.end(), b) != covered.end())
            continue;

        covered.push_back(b);
        // cout << b.x << " " << b.y << " " << b.dx << " " << b.dy  << " " << endl;

        if (!first)
        {
            if (b.x + b.dx < 0 || b.x + b.dx >= grid[0].size() || b.y + b.dy < 0 || b.y + b.dy >= grid.size())
                continue;
        }
        first = false;

        // cout << b.x << " " << b.y << " " << b.dx << " " << b.dy << " " << grid[b.y + b.dy][b.x + b.dx] << endl;

        energized[b.y + b.dy][b.x + b.dx] = '#';

        switch (grid[b.y + b.dy][b.x + b.dx])
        {
        case '.':
            beams.push_back({b.x + b.dx, b.y + b.dy, b.dx, b.dy});
            break;
        case '-':
            if (b.dy == 0)
            {
                beams.push_back({b.x + b.dx, b.y + b.dy, b.dx, b.dy});
            }
            else
            {
                beams.push_back({b.x, b.y + b.dy, -1, 0});
                beams.push_back({b.x, b.y + b.dy, 1, 0});
            }
            break;
        case '|':
            if (b.dx == 0)
            {
                beams.push_back({b.x + b.dx, b.y + b.dy, b.dx, b.dy});
            }
            else
            {
                // cout << "h\n";
                beams.push_back({b.x + b.dx, b.y, 0, -1});
                beams.push_back({b.x + b.dx, b.y, 0, 1});
            }
            break;
        case '\\':
            if (b.dy == 0)
                beams.push_back({b.x + b.dx, b.y + b.dy, b.dy, b.dx});
            else
                beams.push_back({b.x + b.dx, b.y + b.dy, b.dy, -b.dx});
            break;
        case '/':
            if (b.dx == 0)
                beams.push_back({b.x + b.dx, b.y + b.dy, -b.dy, b.dx});
            else
                beams.push_back({b.x + b.dx, b.y + b.dy, -b.dy, -b.dx});
            break;
        }
        i--;
    }

    ll c = 0;
    for (string gri : energized)
    {
        // cout << gri << endl;
        for (char gr : gri)
        {
            if (gr == '#')
                c++;
        }
    }
    return c;
}

int main()
{
    string line;

    int score = 0;

    vector<string> grid;
    vector<string> energized;
    list<Beam> beams;

    while (true)
    {
        vector<string> mirror;

        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        grid.push_back(line);

        energized.push_back(string(line.size(), '.'));
    }

    int n = 10e7;

    FOR(l, 0, grid.size())
    {
        cout << "h: " << l << "/" << grid.size() << endl;
        score = max(score, simulate({-1, l, 1, 0}, grid, n));
        score = max(score, simulate({(int)grid[0].size(), l, -1, 0}, grid, n));
    }
    FOR(l, 0, grid[0].size())
    {
        cout << "b: " << l << "/" << grid[0].size() << endl;
        score = max(score, simulate({l, -1, 0, 1}, grid, n));
        score = max(score, simulate({l, (int)grid.size(), 0, -1}, grid, n));
    }
    cout << score << endl;
}
