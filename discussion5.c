#include <string.h>
#include <stdint.h>
#include<stdio.h>

uint8_t hex_to_byte(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	if ('a' <= c && c <= 'f') return c - 'a' + 10;
	if ('A' <= c && c <= 'F') return c - 'A' + 10;
	return -1;

}

void url_decode(char *src, char *dest){
	int i = 0;
	char *dest_ptr = dest;
	while (*(src+i) != 0){
		if(*(src+i)=='%'){
			uint8_t a = hex_to_byte(*(src+i+1));
		       	uint8_t b = hex_to_byte(*(src+i+2));
			*dest_ptr=(unsigned char)((a<< 4)| b);
			dest_ptr++;
			i +=2; 
		} else {
			*dest_ptr = *(src+i);
			dest_ptr++;

		}	
		i++;
	}
	*dest_ptr = 0;
}

int main() {
	char simple[] = "abc";
	char url[] = "5\%25\%20of\%20200"; //5% of 25/200
	char emoji[] = "It\%20works\%20with\%20non\%2Dascii\%20too\%21\%20\%F0\%9F\%98\%81";
	char simple_decoded[strlen(simple)];
	url_decode(simple, simple_decoded);
	printf("original string: %s  decoded string: %s\n", simple, simple_decoded);	
	char url_decoded[strlen(url)+ 1];
	url_decode(url, url_decoded);
	printf("original string:%s  decoded string: %s\n", url, url_decoded);
	char emoji_decoded[strlen(emoji)+1];
	url_decode(emoji, emoji_decoded);
	printf("original string:%s  decoded string: %s\n", emoji, emoji_decoded);
	return 0;
}
