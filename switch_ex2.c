#include <stdio.h>

int main(void) {
	char ay[10];
	printf("Lütfen ay giriniz : ");
	scanf("%c",&ay);
	
	switch(ay) {
		case "ocak": case "subat" : case "aralik":
			printf("\nmevsim kış\n");
			break;
		case "mart": case "nisan": case "mayis":
			printf("\nmevsim ilkbahar\n");
			break;
		case "haziran": case "temmuz": case "agustos":
			printf("\nmevsim yaz\n");
			break;
		case "eylül": case "ekim": case "kasim":
			printf("\nmevsim sonbahar\n");
			break;
		default:
			printf("\ngecersiz_ay\n");
			break;

	}
	
	
	
}


