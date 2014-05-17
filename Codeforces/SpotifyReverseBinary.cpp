#include <stdio.h>

using namespace std;

int binaryInverse(int n) {
    int m = 0;
    int s = 31;
    for (;!(n&(1<<s)); s--);
    for (int i = s; i>=0; i--) {
        if ((1<<i)&n) {
            m += 1<<(s-i);
        }
    }
    return m;
}

int main() {

    int n;

    scanf("%d",&n);

    n = binaryInverse(n);

    printf("%d\n",n);

    return 0;

}
