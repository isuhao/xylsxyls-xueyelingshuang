#include "Point.h"

namespace xyls {

Point::Point(){
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

void Point::SetPoint(int x, int y){
	this->x = x;
	this->y = y;
}

}