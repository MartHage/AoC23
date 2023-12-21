#include "util.hpp"

int main()
{
    string line;

    int score = 0;

    vector<vector<string>> numbers;
    vector<string> lines;
    int prev = 100000000;
    int count = 0;
    int x = 0;
    int y = 0;

    while (true)
    {
        getline(cin, line);

        if (!line.length())
            break;

        vector<string> m = match(line, "(\\d+|red|green|blue)");

        int red = 0, green = 0, blue = 0;

        bool bad = false;
        for (int i = 1; i < m.size(); i += 2)
        {
            switch (m[i + 1][0])
            {
            case ('r'):
                if (stoi(m[i]) > red) 
                    red = stoi(m[i]);
                break;
            case ('g'):
                if (stoi(m[i]) >= green)
                    green = stoi(m[i]);
                break;
            case ('b'):
                if (stoi(m[i]) >= blue)
                     blue = stoi(m[i]);
                break;
            }
        }

        if (red == 0 || green == 0 || blue == 0) {
            
        } else {
            count += red * green * blue;
        }
    }

    cout << count << endl;

}