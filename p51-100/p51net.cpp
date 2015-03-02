#include<iostream>

using namespace std;

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int p[100010];
int pIndex = 0;

inline int isPrime(int x)
{
    if (x <= 1)
        return 0;
    int m = (int)sqrt(x);
    for (int i = 2; i <= m; i++)
    {
        if (!(x % i))
            return 0;
    }
    return 1;
}

inline void genPrimeTable(int upBound)
{
    for (int i = 2; i <= upBound; i++)
    {
        if (isPrime(i))
            p[pIndex++] = i;
    }
}

inline int calcDigitsCount(int x)
{
    int ans = 0;
    while (x)
    {
        ans++;
        x /= 10;
    }
    return ans;
}

inline int replaceDigit(int x, int pos, int newVal)
{
    char buffer[15];
    sprintf(buffer, "%d", x);
    buffer[pos - 1] = newVal + '0';
    sscanf(buffer, "%d", &x);
    return x;
}

inline int calcMaxPrimeFamilyMemberCount(int x)
{
    int dc = calcDigitsCount(x);
    int retVal = 0;

    for (int i = 1; i < (1 << dc); i++)
    {
        int ans = 0;

        char bufferX[15];
        sprintf(bufferX, "%d", x);
        int preTestI = i;
        int hash[10];
        memset(hash, 0, sizeof(hash));

        for (int k = 1; k <= dc; k++)
        {
            int flag = preTestI & 0x1;
            preTestI >>= 1;

            if (flag)
                hash[bufferX[k - 1] - '0'] = 1;
        }

        int sum = 0;
        for (int k = 0; k <= 9; k++)
            sum += hash[k];
        if (sum != 1)
            continue;

        for (int newVal = 9; newVal >= 0; newVal--)
        {
            if ((i & 0x1) && !newVal)
                continue;

            int tmpRes = i;
            int tmpX = x;

            for (int j = 1; j <= dc; j++)
            {
                int flag = tmpRes & 0x1;
                tmpRes >>= 1;

                if (flag)
                    tmpX = replaceDigit(tmpX, j, newVal);

            }
            if (isPrime(tmpX))
                ans++;
        }

        retVal = retVal > ans ? retVal : ans;
    }

    return retVal;
}

int main()
{
    genPrimeTable(200000);

    int ans = 0;

    for (int i = 0; i < pIndex; i++)
    {
        int res = calcMaxPrimeFamilyMemberCount(p[i]);

        if (res == 8)
        {
            ans = p[i];
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}

