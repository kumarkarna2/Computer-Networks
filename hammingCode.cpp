#include <bits/stdc++.h>
using std::cout, std::cin, std::endl;
using std::string, std::vector;

void print(vector<int> &hCode)
{
    cout << "Hamming code : ";

    for (auto i : hCode)
    {
        cout << i << " ";
    }
}

void setParity(vector<int> hCode, int m, int r)
{
    int bit = 0;
    int size = m + r;
    while (bit < r)
    {
        int i = pow(2, bit);
        int loc = 0;
        int parity = -1;
        while (loc <= size)
        {
            int skip = i, accept = i;
            loc += skip;
            while (accept && loc <= size)
            {
                if (hCode[loc - 1] != -1)
                {
                    if (parity == -1)
                        parity = hCode[loc - 1];
                    else
                        parity ^= hCode[loc - 1];
                }
                loc++;
                accept++;
            }
        }
        bit++;
        hCode[i - 1] = parity;
    }

    // for (auto i : hCode)
    // {
    //     cout << i << " ";
    // }
    print(hCode);
}

void setRedBit(string data, int m, int r)
{
    vector<int> hCode(m + r);

    // setting -1 at parity position
    for (int i = 0; i < r; i++)
    {
        hCode[pow(2, i) - 1] = -1;
    }

    // inserting data values
    int pos = 0;
    for (int i = 0; i < (m + r); i++)
    {
        if (hCode[i] != -1)
        {
            hCode[i] = data[pos] - '0';
            pos++;
        }
    }
    setParity(hCode, m, r);
}

int main()
{
    string data = "1011";
    int m = data.length();
    int r = 0, i = 0;
    cout << "Original msg : " << data << endl;
    while (1)
    {
        if (pow(2, i) >= (m + r + 1))
            break;

        r++, i++;
    }
    cout << "Value of r : " << r << endl;
    setRedBit(data, m, r);

    return 0;
}