#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int found = -1;
    for (int i = A; i <= B; i++)
    {
        if(i%C==0)
        {
            found = i;
            break;
        } 
    }
    cout << found << endl;
    
    return 0;
}