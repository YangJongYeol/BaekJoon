#include<iostream>
using namespace std;
int num[2][3],result[3];

int main() {
    for (int i=0; i<2; i++) for (int j=0; j<3; j++) scanf(" %1d",&num[i][j]);
    for (int i=2; i>=0; i--) {
        int amt=0, digit=1;
        for (int j=2; j>=0; j--) {
            amt+=num[1][i]*num[0][j]*digit;
            digit*=10;
        }
        result[i]=amt;
        printf("%d",amt);
        printf("\n");
    }

    int ans=0;
    for (int i=0; i<3; i++) {
        ans*=10;
        ans+=result[i];
    }
    printf("%d",ans);
    return 0;
}