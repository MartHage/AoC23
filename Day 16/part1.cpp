#include "util.hpp"

struct Beam
{
    int x, y;
    int dx, dy;
};

int main()
{
    string line;

    ll score = 0;

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

    FOR(l, 0, grid.size())
    {
        beams.clear();
        FOR (y, 0, energized.size()) {
            FOR (x, 0, energized[0].size()) {
                energized[y][x] = '.';
            }
        }

        beams.push_back({-1, l, 1, 0});

        bool first = true;
        int i = 10000000;

        while (!beams.empty() && i > 0)
        {
            Beam b = beams.front();
            beams.pop_front();
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
        cout << endl;
        for (string gri : energized)
        {
            cout << gri << endl;
            for (char gr : gri)
            {
                if (gr == '#')
                    c++;
            }
        }
        score = max(score, c);
    }
    cout << score << endl;
}
