#include <stdio.h>

int bestFit(int freeBlocks[], int numBlocks, int alloc_size) {
    int best_fit_index = -1;

    for (int i = 0; i < numBlocks; i++) {
        if (freeBlocks[i] == alloc_size) {
            freeBlocks[i]  -= alloc_size;
            return i;
        }
        if (freeBlocks[i] > alloc_size){
            if (best_fit_index == -1 || freeBlocks[i] < freeBlocks[best_fit_index]){
                best_fit_index = i;
            }
        } 
        /*
        - If freeBlock[i] > alloc_size and freeBlock[i] < freeBlock[best_fit_index]
            True: reassign best_fit_index
        */
    }
    if (best_fit_index != -1) {
        freeBlocks[best_fit_index]  -= alloc_size;
    }
    return best_fit_index;
}

//Implement Best Fit
void printBlocks(int freeBlocks[]) {
    printf("FREE BLOCKS: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", freeBlocks[i]);
    }
    printf("\n");
    return;
}

int main() {
    int freeBlocks[] = {600, 100, 500, 200, 300};
    //malloc(20) --> {80, 500, 200, 300, 600};
    //sizeof(freeBlocks) = 20;
    //sizeof(freeBlocks[0]) = 4;
    //size of array = sizeof(freeBlocks) / sizeof(freeBlocks[0]) --> 5
    int allocations[] = {212, 417, 112, 426};
    //Pre-allocations
    printBlocks(freeBlocks);
    for (int i = 0; i < 4; i++) {
        printf("Allocation of size %d placed at block %d\n"
        , allocations[i], bestFit(freeBlocks, 5, allocations[i]));
        printBlocks(freeBlocks);
    }
    //POST Allocations
    return 0;
}