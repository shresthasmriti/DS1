//
//  main.cpp
//  Data Structures #7
//
//  Created by Smriti Shrestha on 13/3/2564 BE.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

void freq(ifstream &muwords)
{
    vector<string> Uwords;
    string x;

    while (muwords)
    {
        muwords >> x;
        Uwords.push_back(x);
    }
    int sizes = Uwords.size();
    sort(Uwords.begin(), Uwords.end());

    int total = 0;
    int n = 1;
    string mostused;
    string vec = Uwords[0];

    int print = sizes;
    int T = 0;
    int fused[10];
    string Tenwords[10];

    while (T < 10)
    {
        for (int i = 0; i < sizes; i++)
        {
            if (vec == Uwords[i])
            {
                vec = Uwords[i];
                n++;
            }

            else if (vec != Uwords[i] && n < print)
            {
                if (total < n)
                {
                    mostused = vec;
                    total = n;
                }
                n = 0;
                vec = Uwords[i];

            }
            else
            {
                vec = Uwords[i];
                n = 0;
            }

        }
        print = total;
        fused[T] = total;

        Tenwords[T] = mostused;
        n = 0;
        T++;
    }


    for (int i = 0; i < 10; i++)
    {
        cout << " " << endl;

        cout << (i + 1) << ": " << fused[i] << "most frequent word= " << Tenwords[i] << endl;

    }
}

//command line param!
int main()
{
    ifstream result;
    result.open("pandp11.txt");
    freq(result);

    return 0;
}
