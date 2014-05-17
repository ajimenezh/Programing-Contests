#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int m[5010][5010];
int m2[5010][5010];

int a[15000];
int sz;

void fastLongestPalindrome(string s)
{
    int i = 0;
    int n = s.length();
    int palLen = 0;

    while (i < n)
    {
        if (i > palLen && s[i-palLen-1] == s[i])
        {
            palLen += 2;
            i += 1;
            continue;
        }
        a[sz++] = palLen;

        int c = sz - 2;
        int e = c - palLen;
        bool exit = false;

        for (int j=c; j>e; j--)
        {
            int d = j - e - 1;

            if (a[j] == d)
            {
                palLen = d;
                exit = true;
                break;
            }
            a[sz++]= (min(d,a[j]));
        }

        if (!exit)
        {
            palLen = 1;
            i += 1;
        }
    }

    a[sz++] = (palLen);

    int l = sz;
    int c = l - 2;
    int e = c - (2*n + 1 - l);
    for (i=c; i>e; i--)
    {
        int d = i - e - 1;
        a[sz++] = (min(d,a[i]));
    }
}

int main() {

    string s;
    cin>>s;

    fastLongestPalindrome(s);

    for (int i=0; i<s.length(); i++) for (int j=0; j<s.length(); j++) m[i][j] = 0;

    for (int i=1; i<sz-1; i++)
    {
        if (i%2==0)
        {
            for (int j=a[i]; j>0; j-=2)
            {
                m[i/2-1-(j-1)/2][i/2-1+1+(j-1)/2]++;
            }
        }
        if (i%2!=0)
        {
            for (int j=a[i]; j>0; j-=2) m[i/2-(j-1)/2][i/2+(j-1)/2]++;
        }
    }


    for (int i=0; i<s.length(); i++)
    {
        for (int j=s.length()-1; j>=0; j--) m[j][i] = j==s.length()-1 ? m[j][i] : m[j][i] + m[j+1][i];
        for (int j=s.length()-1; j>=0; j--) m[j][i] = i==0 ? m[j][i] : m[j][i] + m[j][i-1];
    }



    int q;
    cin>>q;

    for (int i=0; i<q; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        cout<<m[l][r]<<"\n";
    }


    return 0;

}
