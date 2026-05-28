// fuente: https://github.com/argonautica/sorting-algorithms/blob/master/C/heapsort.c
/*
 * Código de heapsort
 */ 
#include <stdio.h>
#include <stdlib.h>
 
void main()
{
    int *heap, *heap2, no, c, root;
    printf("\nNúmero elementos:");
    scanf("%d", &no);
    heap = malloc((no+1)*sizeof(int));
    heap2 = malloc((no+1)*sizeof(int));
    printf("\nNúmeros:");
    for (int i = 0; i < no; i++)
       scanf("%d", &heap[i]);
    for (int i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("Heap array : ");
    for (int i = 0; i < no; i++)
        heap2[i] = heap[i];
    // debug
    free(heap);
    for (int j = no - 1; j >= 0; j--)
    {
        int temp = heap2[0];
        heap2[0] = heap2[j]; 
        heap2[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;
            if ((heap2[c] < heap2[c + 1]) && c < j-1)
                c++;
            if (heap2[root]<heap2[c] && c<j)
            {
                temp = heap2[root];
                heap2[root] = heap2[c];
                heap2[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    free(heap2);
}
