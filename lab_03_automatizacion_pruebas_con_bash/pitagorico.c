#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_pitagorico(int a, int b, int c){
    int max = a;
    int x=b, y=c;
    if (a < b){
        max = b;
        x=a;
        y=c;
    }
    if (b < c || a < c){
        max = c;
        x=a;
        y=b;
    }
    if (x * x + y * y == max * max)
        return 1;
    return 0;
}

int main() {
    int cantidad;
    int cantidad_pitagoricos = 0;
    scanf("%d", &cantidad);
    int a, b, c;
    for (int i=0; i<cantidad; i++){
        scanf("%d %d %d", &a, &b, &c);
        if (es_pitagorico(a, b, c)){
            printf("Es pitagórico: %d %d %d\n", a, b, c);
            cantidad_pitagoricos++;
        }
    }
    printf("Porcentaje pitagoricos: %f%%\n", (float)cantidad_pitagoricos/(float)cantidad*100.0);
    return 0;
}
