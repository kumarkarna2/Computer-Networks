// find sum of all elements in an data array
// find 1's complement of sum
// append 1's complement i.e. chksum value to end of data array
// at receiver, find sum of all elements in data array and subtract chksum value
// if sum is 0, data is accepted
// if sum is not 0, data is rejected

#include <bits/stdc++.h>
using namespace std;

string invert(string);
string Xor(string, string);
string divide(string data);

string sender(string data)
{
    cout << "At sender's end ->" << endl;
    string sum = divide(data);
    string chkSum = invert(sum);

    cout << "Sum: " << sum << endl;
    cout << "Checksum is : " << chkSum << endl;
    return chkSum;
}

string divide(string data)
{
    int size = data.length() / 8;
    string sum;

    for (int i = 0; i < size - 1; i++)
    {
        string temp1 = data.substr(i * 8, 8);
        sum = data.substr((i + 1 * 8), 8);
        sum = Xor(temp1, sum);
    }

    return sum;
}

string Xor(string s1, string s2)
{
    int carry = 0;
    string sum;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        if (s1[i] == '0' && s2[i] == '0')
        {
            if (carry == 0)
            {
                sum = "0" + sum;
                carry = 0;
            }
            else
            {
                sum = "1" + sum;
                carry = 0;
            }
        }
        else if (s1[i] == '1' && s2[i] == '1')
        {
            if (carry == 0)
            {
                sum = "0" + sum;
                carry = 1;
            }
            else
            {
                sum = "1" + sum;
                carry = 1;
            }
        }
        else
        {
            if (carry == 0)
            {
                sum = "1" + sum;
                carry = 0;
            }
            else
            {
                sum = "0" + sum;
                carry = 1;
            }
        }
    }
    if (carry == 1)
    {
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            if (sum[i] == '1')
            {
                sum[i] = '0';
                carry = 1;
            }
            else
            {
                sum[i] = '1';
                carry = 0;
                break;
            }
        }
    }
    return sum;
}

string invert(string sum)
{
    for (int i = 0; i < sum.length(); i++)
    {
        if (sum[i] == '1')
            sum[i] = '0';
        else
            sum[i] = '1';
    }
    return sum;
}

void receiver(string data, string chkSum)
{
    string sum = divide(data);
    string rec = invert(Xor(sum, chkSum));

    cout << "\nAt receiver's end ->" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Checksum is : " << chkSum << endl;
    cout << "Received data: " << rec << endl;

    if (rec.find('1') != string::npos)
        cout << "Data is corrupted" << endl;
    else
        cout << "Data is not corrupted" << endl;
}

int main()
{
    string data = "1100110010101010";

    string chkSum = sender(data);

    receiver(data, chkSum);
    return 0;
}
