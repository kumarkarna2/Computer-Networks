#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v = 4;
    int e = 5;
    int arr[v][e];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < v; i++)
    {
        int a;
        cout << "Enter the number of edge outgoing from V" << i + 1 << "\n";
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cout << "Enter edge number"
                 << "\n";
            cin >> b;
            arr[i][b - 1] = 1;
        }
    }
    for (int i = 0; i < v; i++)
    {
        int a;
        cout << "Enter the number of edge incoming to V" << i + 1 << "\n";
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cout << "Enter edge number"
                 << "\n";
            cin >> b;
            arr[i][b] = -1;
        }
    }

    cout << "e  ";
    for (int i = 0; i < e; i++)
    {
        cout << i + 1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < v; i++)
    {
        cout << "V" << i + 1
             << " ";

        for (int j = 0; j < e; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}