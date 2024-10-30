#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//vim :set nu -- line numbers
//vim :bo term -- open terminal below vim editor


int original_main(){
    int product = 1;
    int nums[] = {1, 2, 3, 4, 5};
    int i = 0;
    while (i < 5) {
        product *= nums[i];
        i++;
    }
    printf("final product: %d\n", product); // Should print "final product: 120"
    return 0;
}


//gdb:  p &nums -- get address of nums
//gdb:  x/7wd &nums -- show 7 decimal values of nums array in memory (w- word (8bytes)) (d- decimal format)

int program_path(int argc, char** argv) { 
    printf("%s\n", argv[0]); //Q: What is argv[0]?
    for (int i = 0; argv[0][i] != 0; i++) {
        printf("%x-%c     ", (*argv)[i], (*argv)[i]); //Q: why does *argv[i] causes a segfault? 
    }
    printf("\n");
    return 0;
}


//gdb: x/100bc argv[0] -- Show 100 characters at the memory address of argv[0] (b- byte) (c- character format)



// //Final product from argv
int main(int argc, char** argv) {
    int product = 1;
    int i = 1;
    while (i < argc) { //C doesn't know array lengths --> why we need argc
        product *= *argv[i] - '0'; //Convert argument value to integer value
        i++;
    }
    printf("final product: %d\n", product); // ./disc3 1 2 3 4 5 --> final product: 120
    return 0;
}
