#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to simulate delay in transmission
void delay(int seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int main()
{
    string data = "12345";
   
    int n = data.length();
    int seq_no = 1;
    int ack;

    cout << "Sender's End : \n";
    while (seq_no < n)
    {
        cout << data[seq_no - 1] << " ";
        // send packet to receiver
        cout << "(Sent)";
        delay(1);
        cout << "(Received)" << endl;

        // wait for acknowledgement from receiver
        cout << "Enter acknowledgement\n";
        cin >> ack;
        if (ack != seq_no+1)
            cout << "please Enter correct acknowledgement\n";

        if (ack == seq_no+1)
        {
            seq_no++;
        }
    }
    cout << "\nTransmission successful!";
    return 0;
}
