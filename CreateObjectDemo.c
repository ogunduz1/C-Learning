#include <stdio.h>
#include <stdlib.h>
#include "CreateObjectSource.h"

int main() {
	Point originOne;
	Rectangle rectOne;
	Rectangle rectTwo;
		
	originOne.x=23;
	originOne.y=94;
	rectOne.origin=originOne;
	rectOne.width=100;
	rectOne.height=200;
	rectTwo.width=50;
	rectTwo.height=100;
	
	printf("Width of rectOne: %d\n",rectOne.width);
	printf("Height of rectOne: %d\n" , rectOne.height);
	printf("Area of rectOne: %d\n" , getArea(rectOne));

	rectTwo.origin = originOne;
	
	printf("X Position of rectTwo: %d\n" ,rectTwo.origin.x);
	printf("Y Position of rectTwo: %d\n" ,rectTwo.origin.y);
	
	rectTwo=move(rectTwo,40, 72);

	printf("X Position of rectTwo: %d\n" ,rectTwo.origin.x);
	printf("Y Position of rectTwo: %d\n" ,rectTwo.origin.y);
	
	return 0;
	
}	


