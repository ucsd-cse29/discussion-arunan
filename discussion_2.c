#include <stdio.h>
#include <string.h>


int my_strlen(char str[]) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int main() {
    // char emoji[] = "🫡";
    // char buffer[20];
    // printf("String to measure: ");
    // fgets(buffer, 20, stdin);
    // printf("%d", my_strlen(buffer));
    char hi[] = {'H', 'i', ' ', 'a', 'l', 'l', '!', '!' }; //8
    char helloeveryone[] = { 'H', 'e', 'l', 'l', 'o', ',', ' ',
                             'e', 'v', 'e', 'r', 'y', 'o', 'n', 'e', '!' }; //16
    hi[12] = '\0'
    
    printf("%s\n", helloeveryone);
    printf("%s\n", hi);
    printf("%ld\n", strlen(hi));
    printf("%ld\n", strlen(helloeveryone));

    printf("\n");
    return 0;
}