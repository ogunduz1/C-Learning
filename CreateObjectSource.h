#ifndef CreateObjectSource
#define CreateObjectSource
//structların initial değerleri 0 
struct p{
	int x=0;
	int y=0;
};
typedef p Point;

struct r{
	int width=0;
	int height=0;
	Point origin;
}; 
typedef r Rectangle;

Rectangle move(Rectangle,int ,int );

int getArea(Rectangle);

#endif

