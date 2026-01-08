#include <cmath>
#include <iostream>
#define epsilon 0.00001

struct list {
    int head;
    int tail;
    int size;
    int *buffer;
};

bool isequal(float n1, float n2) {
    float diff = fabs(n1-n2);
    n1 = fabs(n1);
    n2 = fabs(n2);
    float largest = n1 > n2 ? n1 : n2;
    if (diff <= largest*epsilon)
        return true;
    return false;
}


int merge_arr(struct list *ptr, int **v, int n1) {
    int n = (ptr->tail - ptr->head + ptr->size)%ptr->size;
    (*v) = (int *)malloc(n*sizeof(int));
    int l=0;
    int r=0;
    while (l<n1 && r< n-n1) {
        if (ptr->buffer[(ptr->head+l)%ptr->size] <  ptr->buffer[(ptr->head+r+n1)%ptr->size]) {
            (*v)[l+r] = ptr->buffer[(ptr->head+l)%ptr->size];
            l++;
        }
        else {
            (*v)[l+r] = ptr->buffer[(ptr->head+r+n1)%ptr->size];
            r++;
        }
    }
    while (l<n1) {
        (*v)[l+r] = ptr->buffer[(ptr->head+l)%ptr->size];
        l++;
    }
    while (r< n-n1) {
        (*v)[l+r] = ptr->buffer[(ptr->head+r+n1)%ptr->size];
        r++;
    }
    return n;
}