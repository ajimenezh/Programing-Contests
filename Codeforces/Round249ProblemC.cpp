#include <iostream>
using namespace std;

int a[1100];
char m[1010][1010];
int n;

int main() {

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];

    for (int i=0; i<1010; i++) for (int j=0; j<1010; j++) m[i][j] = ' ';

    int l = 0, u = 0, x = 0;
    for (int i=0; i<n; i++) {
        if (i%2==0) x += a[i];
        else x -= a[i];
        l = min(l, x);
        u = max(u, x);
    }

    x = 0;
    int y = u;
    for (int i=0; i<n; i++) {
        if (i%2==0) {
            for (int j=x; j<x+a[i]; j++) {
                m[y][j] = '/';
                y--;
            }
            x += a[i];
            y++;
        }
        else {
            for (int j=x; j<x+a[i]; j++) {
                m[y][j] = '\\';
                y++;
            }
            x += a[i];
            y--;
        }
    }

    for (int i=1; i<=u-l; i++) {
        for (int j=0; j<x; j++) cout<<m[i][j]; cout<<"\n";
    }

    return 0;
}
