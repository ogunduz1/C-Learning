#include <stdio.h>

int main(void) {
	char ay;
	printf("Lütfen ay giriniz : ");
	scanf("%c",&ay);
	
	switch(ay) {
		case 'o': case 's': case 'a':
			printf("\nmevsim kış\n");
			break;
		case 'm': case 'r': case 'n':
			printf("\nmevsim ilkbahar\n");
			break;
		case 'h': case 't': case 'g':
			printf("\nmevsim yaz\n");
			break;
		case 'e': case 'c': case 'k':
			printf("\nmevsim sonbahar\n");
			break;
		default:
			printf("\ngecersiz_ay\n");
			break;

	}
	
	
	
}


