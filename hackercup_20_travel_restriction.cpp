#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solv()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    vector<vector<char>> ans(n, vector<char>(n, 'Y'));
    /*
   ** 
NYYYNNYYYY
YYNYYNYYNY

NYYYNNNNNN
NYYYYNNNNN

   */
    for (int i = 0; i < n; ++i)
    {
        bool isValid = b[i] == 'N' ? false : true;
        for (int j = i+1; j < n; ++j)
        {
           if (isValid && a[j] == 'Y')
            {
                if (b[j] == 'Y')
                {
                    isValid = true;
                }
                else{
                    isValid = false;
                }
            }
            else
            {
                ans[i][j] = 'N';
                isValid = false;
            }
        }
        isValid = b[i] == 'N' ? false : true;

        for (int j = i - 1; j >= 0; --j)
        {

            if(isValid && a[j] == 'Y'){
                if(b[j] == 'Y' ){
                    continue;
                }
                else{
                    isValid = false;
                }
            }
            else
            {
                ans[i][j] = 'N';
                isValid = false;
            }
        }
    }

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y;
        }
        cout << endl;
    }
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;

    for (int i = 1; i <= tt; ++i)
    {
        cout << "Case #" << i << ": " << endl;
        ;
        solv();
    }
}
