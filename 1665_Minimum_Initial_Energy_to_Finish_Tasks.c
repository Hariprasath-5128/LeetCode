#include <stdlib.h>

int cmp(const void *a, const void *b){

    int *x = *(int**)a;
    int *y = *(int**)b;

    // x[0] = actual
    // x[1] = minimum

    return (y[1] - y[0]) - (x[1] - x[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {

    qsort(tasks, tasksSize, sizeof(int*), cmp);

    int start = tasks[0][1];
    int copy = start;

    for(int i = 0; i<tasksSize; i++){
        int minimum = tasks[i][1];
        int actual = tasks[i][0];
        if(minimum > start){
            int temp = minimum - start;
            copy = copy + temp;
            start = minimum - actual;
        }
        else{
            start = start - actual;
        }
    }
    return copy;
}

