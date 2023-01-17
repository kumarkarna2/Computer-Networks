#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ver;
    cout << "Enter number of vertices : "
         << "\n";
    cin >> ver;

    int adj[ver][ver] = {0};
    for (int i = 0; i < ver; i++)
    {
        int a;
        cout << "Enter number of outgoing edge from V" << i + 1 << " : "
             << "\n";
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cout << "Enter vertex to which V" << i + 1 << " is connected to : ";
            cin >> b;
            adj[i][b - 1] = 1;
        }
    }
    // printing the matrix
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}