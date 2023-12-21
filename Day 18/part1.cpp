#include "util.hpp"

#define L 0
#define R 1
#define D 2
#define U 3

struct Instruction
{
    char dir;
    int len;
};

struct Point
{
    int x, y;
};


double shoelace(vector<Point> points) {
	double leftSum = 0.0;
	double rightSum = 0.0;

	for (int i = points.size()-1; i >= 0; --i) {
		int j = (i + 1) % points.size();
		leftSum  += points[i].x * points[j].y;
		rightSum += points[j].x * points[i].y;
	}

	return 0.5 * abs(leftSum - rightSum);
}

int main()
{
    string line;

    ll score = 0;

    vector<vector<int>> grid;

    vector<Instruction> ins;

    while (true)
    {
        vector<string> mirror;

        getline(cin, line);
        // cout << line << endl;

        if (!line.length())
            break;

        vector<string> m = match(line, "(U|D|L|R|\\d)");

        ins.push_back({m[0][0], stoi(m[1])});
    }

    vector<Point> points;
    points.push_back({0, 0});

    switch (ins[0].dir)
    {
    case 'U':
        points.push_back({0, 1 + ins[0].len});
        break;
    case 'D':
        points.push_back({0, -1 - ins[0].len});
        break;
    case 'L':
        points.push_back({-1 - ins[0].len, 0});
        break;
    case 'R':
        points.push_back({1 + ins[0].len, 0});
        break;
    }

    FOR(i, 1, ins.size() - 1)
    {
        bool nLeft = (ins[i + 1].dir == 'R' && ins[i].dir == 'D') || (ins[i + 1].dir == 'D' && ins[i].dir == 'L') || (ins[i + 1].dir == 'L' && ins[i].dir == 'U') || (ins[i + 1].dir == 'U' && ins[i].dir == 'R');
        bool pLeft = (ins[i].dir == 'R' && ins[i - 1].dir == 'D') || (ins[i].dir == 'D' && ins[i - 1].dir == 'L') || (ins[i].dir == 'L' && ins[i - 1].dir == 'U') || (ins[i].dir == 'U' && ins[i - 1].dir == 'R');

        cout << ins[i].dir << " " << ins[i].len << " " << pLeft<< nLeft << endl;

        switch (ins[i].dir)
        {
        case 'U':
            points.push_back({points[i].x, points[i].y + ins[i].len + (nLeft ? 0 : 1) + (pLeft ? -1 : 0)});
            break;
        case 'D':
            points.push_back({points[i].x, points[i].y - ins[i].len - (nLeft ? 0 : 1) - (pLeft ? -1 : 0)});
            break;
        case 'L':
            points.push_back({points[i].x - ins[i].len - (nLeft ? -1 : 0) - (pLeft ? 0 : 0), points[i].y});
            break;
        case 'R':
            points.push_back({points[i].x + ins[i].len + (nLeft ? 0 : 1) + (pLeft ? -1 : 0), points[i].y});
            break;
        }
        cout << points[i + 1].x << ", " << points[i + 1].y << endl;
    }

    cout << shoelace(points) << endl;
}
