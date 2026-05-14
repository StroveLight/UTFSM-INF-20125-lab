// fuente: https://github.com/argonautica/sorting-algorithms/blob/master/C/heapsort.c
/*
 * Código de heapsort
 */ 
#include <stdio.h>
#include <stdlib.h>
 
void main()
{
    int *heap, no, c, root;
    printf("\nNúmero elementos:");
    scanf("%d", &no);
    heap = malloc((no+1)*sizeof(int));
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
        printf("%d\t ", heap[i]);
    for (int j = no - 1; j >= 0; j--)
    {
        int temp = heap[0];
        heap[0] = heap[j]; 
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\nArreglo ordenado:");
    for (int i = 0; i < no; i++)
       printf("\t %d", heap[i]);
    free(heap);
    printf("\n");
}
