#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ver;
    cout << "Enter number of vertices : "
         << "\n";
    cin >> ver;

    // user input
    int adj[ver][ver] = {0};
    for (int i = 0; i < ver; i++)
    {
        for (int j = i; j < ver; j++)
        {
            cout << "Enter 1 if V" << i + 1 << " is having an edge to V" << j + 1 << " else enter zero\n";
            cin >> adj[i][j];
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