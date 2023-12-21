#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <regex>

using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)

vector<string> split(string s)
{
    vector<string> output;
    istringstream iss(s);
    string w;
    while (getline(iss, w, ' '))
    {
        output.push_back(w);
    }
    return output;
}

vector<string> match(string s, string rx)
{
    vector<string> output;

    smatch sm;

    regex rgx(rx);

    while (regex_search(s, sm, rgx))
    {
        output.push_back(sm[0]);
        s = sm.suffix();
    }

    // if (regex_search(s, sm, rgx))
    // {
    //     cout << "hoi\n";
    //     for (int i = 1; i < sm.size(); i++)
    //     {
    //         cout << sm[i] << endl;
    //         output.push_back(sm[i]);
    //     }
    // }

    return output;
}

vector<string> split(string s, string rx)
{
    vector<string> output;
    std::regex rgx(rx);
    std::sregex_token_iterator iter(s.begin(),
                                    s.end(),
                                    rgx,
                                    -1);
    std::sregex_token_iterator end;
    for (; iter != end; ++iter)
        output.push_back(*iter);

    return output;
}

int number_of_points = -1;

class Point
{
public:
    int x, y, c, h;
    int index;

    vector<Point> neigh;

    Point(){};

    Point(int nx, int ny)
    {
        index = number_of_points;
        number_of_points++;
        x = nx;
        y = ny;
    };

    double eu_distance(Point b)
    {
        return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
    }

    int man_distance(Point b)
    {
        return abs(x - b.x) + abs(y - b.y);
    }

    bool operator==(const Point &rhs) const
    {
        return (index == rhs.index);
    }
    bool operator!=(const Point &rhs) const
    {
        return !operator==(rhs);
    }
};

Point NIL = Point(-1, -1);

vector<Point> reconstruct_path(Point s, Point t, vector<Point> parent)
{
    Point c = t;
    vector<Point> path;
    path.push_back(c);
    while (c != s)
    {
        c = parent[c.index];
        path.push_back(c);
    }
    return path;
}

vector<Point> bfs(int n, Point s, Point t)
{
    list<Point> q;

    bool visited[n];
    vector<Point> parent;

    FOR(i, 0, n)
    {
        visited[i] = false;
        parent.push_back(Point());
    }

    visited[s.index] = true;
    q.push_back(s);

    Point c;

    while (!q.empty())
    {
        c = q.front();
        q.pop_front();

        if (s.index == t.index)
        {
            return reconstruct_path(s, t, parent);
        }

        for (Point b : c.neigh)
        {
            if (visited[b.index])
                continue;

            q.push_back(b);
            visited[b.index] = true;
        }
        // cout << endl;
        // for (vector<int> neigh : }) {

        // }
    }
    return {NIL};
}

vector<Point> dfs(int n, Point s, Point t)
{
    list<Point> q;

    bool visited[n];
    vector<Point> parent;

    FOR(i, 0, n)
    {
        visited[i] = false;
        parent.push_back(Point());
    }

    visited[s.index] = true;
    q.push_back(s);

    Point c;

    while (!q.empty())
    {
        c = q.front();
        q.pop_front();

        if (s.index == t.index)
        {
            return reconstruct_path(s, t, parent);
        }

        for (Point b : c.neigh)
        {
            if (visited[b.index])
                continue;

            q.push_front(b);
            visited[b.index] = true;
        }
        // cout << endl;
        // for (vector<int> neigh : }) {

        // }
    }
    return {NIL};
}
