// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X

#include <iostream>

using namespace std;

int N, M;

int arr[10][10], dp[10][10];

int fn(int i, int j)
{
    if (i == N - 1 && j == M - 1)
        return arr[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i < N - 1 && j < M - 1)
    {
        int op1 = fn(i + 1, j);
        int op2 = fn(i, j + 1);
        dp[i][j] = arr[i][j] + max(op1, op2);
        return dp[i][j];
    }

    if (i < N - 1 && j == M - 1)
    {
        dp[i][j] = arr[i][j] + fn(i + 1, j);
        return dp[i][j];
    }
    if (j < M - 1 && i == N - 1)
    {
        dp[i][j] = arr[i][j] + fn(i, j + 1);
        return dp[i][j];
    }

    return 0;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << fn(0, 0) << endl;

    return 0;
}