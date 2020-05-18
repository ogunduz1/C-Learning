#include <stdio.h>
#include <stdlib.h>
#include "CreateObjectSource.h"

Rectangle move(Rectangle rec,int x,int y) {
	rec.origin.x=x;
	rec.origin.y=y;	
	return rec;
}

int getArea(Rectangle rec) {
	return rec.width*rec.height;
}

