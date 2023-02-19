// crc generator n-bit
// crc n-1 bit
//  append n-1 zeros to the end of the message
//  xor the codeword by the generator polynomial
//  the remainder is the crc
//  append the crc to the end of the message
//  the message is now the codeword
//  the codeword is the message transmitted over the channel
//  the receiver receives the codeword
//  the receiver divides the codeword by the generator polynomial
//  if the remainder is 0, the codeword is accepted
//  if the remainder is not 0, the codeword is rejected

#include <bits/stdc++.h>
using namespace std;

string Xor(string geneator, string temp)
{
    string result = "";
    for (int i = 1; i < temp.length(); i++)
    {
        if (geneator[i] == temp[i])
            result += "0";
        else
            result += "1";
    }
    // cout<<"Xor: "<<result<<endl;
    return result;
}

string bitDiv(string &codeWord, string generator)
{
    int genLen = generator.length();
    int codeLen = codeWord.length();
    string temp = codeWord.substr(0, genLen);
    // cout << "Remainder: " <<  << endl;
    while (genLen < codeLen)
    {
        if (temp[0] == '1')
        {
            temp = Xor(generator, temp) + codeWord[genLen];
        }
        else
        {
            temp = Xor(string(genLen, '0'), temp) + codeWord[genLen];
        }
        genLen++;
    }

    if (temp[0] == '1')
    {
        temp = Xor(generator, temp);
    }
    else
    {
        temp = Xor(string(genLen, '0'), temp);
    }
    return temp;
}

int main()
{
    string generator = "10111";
    string crc = "";
    string msg = "1010011110";

    string codeWord = msg;
    int genLen = generator.length();

    // appending n-1 zeros to the end of the message
    for (int i = 0; i < genLen - 1; i++)
    {
        codeWord += "0";
    }

    // division of codeWord by generator
    string rem = bitDiv(codeWord, generator);
    cout << "Remainder: " << rem << endl;

    // appending the remainder to the end of the message
    string encode = msg + rem;
    cout << "Encoded message: " << encode << endl;

    // encode = "10011101101";
    // checking if the message received by receiver is correct or not. If the remainder is all 0 then it is correct, else wrong.
    string rec = bitDiv(encode, generator);
    if (rec.find('1') != string::npos)
    {
        cout << "there is some error in data" << endl;
    }
    else
    {
        cout << "correct message received" << endl;
    }

    return 0;
}