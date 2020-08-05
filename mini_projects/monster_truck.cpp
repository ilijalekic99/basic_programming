#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    char matrica[55][55];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrica[i][j];
        }
    }
    int cnt[5];
    for (int i = 0; i < 5; i++) cnt[i] = 0;

    for (int i = 0; i < r-1; i++){
        for (int j = 0; j < c-1; j++){
            int curCnt = 0;

            if (matrica[i][j] == 'X') curCnt++;
            if (matrica[i+1][j] == 'X') curCnt++;
            if (matrica[i][j+1] == 'X') curCnt++;
            if (matrica[i+1][j+1] == 'X') curCnt++;

            int cntHash = 0;
            if (matrica[i][j] == '#') cntHash++;
            if (matrica[i+1][j] == '#') cntHash++;
            if (matrica[i][j+1] == '#') cntHash++;
            if (matrica[i+1][j+1] == '#') cntHash++;

            if (cntHash == 0)
                cnt[curCnt]++;
        }
    }

    for (int i = 0; i < 5; i++){
        cout << cnt[i] << "\n";
    }

}
