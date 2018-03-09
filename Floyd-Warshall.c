// Floyd-Warshall

#include <stdio.h>

int main() {
    
    int N, M, k, i, j, w;
    float d[51][51];
    
    scanf("%d %d",&N,&M);
    if (N<=50 && N>=1 && M<=200 && M>=1) {
        
        for (i=1; i<=N; i++)
            for (j=1; j<=N; j++) d[i][j]=340000000;
        
        for (k=1; k<=M; k++) {
            scanf("%d %d %d",&i,&j,&w);
            d[i][j]=w;
        }
        for (k=1; k<=N; k++) d[k][k]=0;
        
        for (k=1; k<=N; k++) {
            for (i=1; i<=N; i++) {
                for (j=1; j<=N; j++) {
                    if(d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        for (i=1; i<=N; i++) {
            for (j=1; j<=N; j++) {
                if (d[i][j]==340000000) printf("N");
                else printf("%.0f",d[i][j]);
                if (j!=N) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}