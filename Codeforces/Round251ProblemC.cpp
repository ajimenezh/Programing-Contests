#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,k,p;
vector<int> even;
vector<int> odd;
vector<vector<int> > res1, res2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>p;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        if (a%2==0) even.push_back(a);
        else odd.push_back(a);
    }

    res1.resize(p);
    res2.resize(k-p);

    int start = 0;
    if (p!=0) {
        for (int i=0; i<even.size(); i++) {
            res1[i%p].push_back(even[i]);
        }

        if (even.size()<p) {
            if (odd.size()/2+even.size()<p) {
                cout<<"NO"<<endl;
                return 0;
            }
            else {
                int j = 0;
                for (int i=even.size(); i<p; i++) {
                    res1[i].push_back(odd[j++]);
                    res1[i].push_back(odd[j++]);
                }
                start = j;
            }
        }
    }
    else {
        for (int i=0; i<even.size(); i++) {
            res2[i%(k-p)].push_back(even[i]);
        }
    }

    if (odd.size()-start<k-p) {
        cout<<"NO"<<endl;
        return 0;
    }

    int j = start;
    for (int i=0; i<k-p; i++) {
        res2[i].push_back(odd[j++]);
    }

    for (int i=j; i<odd.size(); i++) {
        if (i==odd.size()-1) {
            cout<<"NO"<<endl;
            return 0;
        }
        else {
            if (p==0) {
                res2[0].push_back(odd[i]);
                res2[0].push_back(odd[i+1]);
            }
            else {
                res1[0].push_back(odd[i]);
                res1[0].push_back(odd[i+1]);
            }
            i++;
        }

    }

    cout<<"YES"<<endl;
    for (int i=0; i<p; i++) {
        cout<<res1[i].size()<<" ";
        for (int j=0; j<res1[i].size(); j++) cout<<res1[i][j]<<" ";
        cout<<"\n";
    }

    for (int i=0; i<k-p; i++) {
        cout<<res2[i].size()<<" ";
        for (int j=0; j<res2[i].size(); j++) cout<<res2[i][j]<<" ";
        cout<<"\n";
    }

    return 0;

}
