#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(a>=b)
        {
            cout << a << "\n";
        }
        else if((2*b)<=b)
        {
            cout << 0 << "\n";
        } 
        else
        {
            cout << (2*a)-b << "\n";
        }
    }
    return 0;
}