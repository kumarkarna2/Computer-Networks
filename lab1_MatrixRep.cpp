#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ver;
    cout << "Enter number of vertices : "
         << "\n";
    cin >> ver;

    // user input
    int adj[ver][ver];
    int a = 1, b = 1;
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            cout << "Enter 1 if V" << a << " is connected to V" << b << " else enter zero\n";
            cin >> adj[i][j];
            b++;
        }
        a++;
        b = 1;
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
