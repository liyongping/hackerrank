#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int PartSort(int* array1,int left,int right) {
    int array[10] = {4,1,7,6,9,2,8,0,3,5};

    int key = array[right];
    while(left < right) {
        while(left < right && array[left] <= key)
            { ++left; }
        array[right] = array[left];
        while(left < right && array[right] >= key)
            { --right; }
        array[left] = array[right];
    }
    array[right] = key;
    return right;
}


int main(int argc, char const *argv[])
{
    int data[10] = {4,1,7,6,9,2,8,0,3,5};
    PartSort(data,0,9);
    return 0;
}