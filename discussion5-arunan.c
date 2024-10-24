#include <stdlib.h>
#include <stdio.h>

int32_t width_from_start_byte(char start_byte) {
    if ((start_byte & 0x80) == 0) {
        return 1; //ASCII
    }
    if ((start_byte & 0b11100000) == 0b11000000) { //0xE0 0xC0
        return 2;
    }
    if ((start_byte & 0b11110000) == 0b11100000) {
        return 3;
    }
    if ((start_byte & 0b11111000) == 0b11110000) {
        return 4;
    }
    return -1;
}

int32_t codepoint_index_to_byte_index(char str[], int32_t cpi) {
    //foor loop to loop thro string, use width, keep byte index, 
    //skip continuation bytes, ccpi - current cpi
    if (cpi < 0) {
        return -1;
    }
    int len = 0; //current cpi
    int i = 0;
    while (str[i] != 0) {
        if (len == cpi) {
            return i;
        }
        int width = width_from_start_byte(str[i]);
        i += width;
        len++;

    }
    return -1; //Out of bounds

}

int32_t codepoint_at(char str[], int32_t cpi) {
    //return decimal value of the codepoint at cpi in str
    //change cpi to byte index --> Get width of codepoint at cpi --> 4 cases (byte widths)
    int byte_offset = codepoint_index_to_byte_index(str, cpi);
    char* codepoint = str+byte_offset;
    int codepoint_width = width_from_start_byte(codepoint[0]);
    if (codepoint_width == -1) {
        return -1;
    }
    if (codepoint_width == 1) {
        //ASCII
        return codepoint[0];
    }
    //continuation bytes 0b 10xxxxxx -> & 0b00111111 = 0x3F 
    if (codepoint_width == 2) {
        return ((codepoint[0] & 0b00011111) << 6 | (codepoint[1] & 0x3F));
    }
    if (codepoint_width == 3) {
        return ((codepoint[0] & 0b00001111) << 12 |
         (codepoint[1] & 0x3F) << 6|
         (codepoint[2] & 0x3F));
    }
    if (codepoint_width == 4) {
        return ((codepoint[0] & 0b00000111) << 18 |
         (codepoint[1] & 0x3F) << 12 |
         (codepoint[2] & 0x3F) << 6|
         (codepoint[3] & 0x3F)) ;
    }
    return -1;

}

char is_animal_emoji(char str[], int32_t cpi) {
    //return 1 if cpi in str is "rat" "chipmunk" or animal range
    int codepoint = codepoint_at(str, cpi);
    if(codepoint >= 0x1F400 && codepoint <= 0x1F43F){
        return 1;
    }
    if (codepoint >= 0x1F980 && codepoint <= 0x1F9AE) {
        return 1;
    }
    return 0;

}

int main () {
    char salute[] = "🫡";
    char crab[] = "🦀";
    printf("Is %s an animal? %d\n", salute, is_animal_emoji(salute, 0));
    printf("Is %s an animal? %d\n", crab, is_animal_emoji(crab, 0));
    return 0;
}