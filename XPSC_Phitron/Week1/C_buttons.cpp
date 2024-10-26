#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int max_coin = max(A+B,max(2*A-1,2*B-1));
    cout << max_coin << endl;

    return 0;
}