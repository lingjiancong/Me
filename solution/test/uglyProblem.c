#include <stdio.h>
#include <malloc.h>


// shit interview
void foo(char *a, char *b, int len) {
	printf("%d\n", len & 0x7);
	switch(len & 0x7) {
		default :
		{ 
			while (len > 7) {
				len -= 8;
				*a++ = *b++;
				printf("while %d\n", len);
			case 7: *a++ = *b++;
					printf("%d\n", len);
			case 6: *a++ = *b++;
					printf("%d\n", len);
			case 5: *a++ = *b++;
					printf("%d\n", len);
			case 4: *a++ = *b++;
					printf("%d\n", len);
			case 3: *a++ = *b++;
					printf("%d\n", len);	
			case 2: *a++ = *b++;
					printf("%d\n", len);
			case 1: *a++ = *b++;
					printf("%d\n", len);
			}
		}
	}
}

void main(void) {
	int i;
	int len = 26;
	char *a = (char*)malloc(100);
	char *b = "abcdefghijklmnopqrstuvwxyz\0";

	for (i = 0; i < 100; i++) {
		a[i] = '\0';
	}
	foo(a, b, len);
	printf("%s\n%s\n", a, b);
}