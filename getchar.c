#include <stdio.h>
#include <stdlib.h>

int main() {
	//char * isim=(char*)malloc(sizeof(char));
	float nc=0;
	printf("isminizi giriniz");
	while(getchar()!='q') 
		++nc;
	printf("%.0f\n",nc);
	/*
	while (c!=EOF);
	for(int i=0;i<10;i++) {
		isim[i]=getchar();
		putchar(isim[i]);
	}*/
	return 0;
}

