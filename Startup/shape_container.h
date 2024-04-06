#pragma once
class Shape;

class ShapeContainer {
public:
	virtual void enroll(Shape* shape) = 0;
	virtual void withdraw(Shape* shape) = 0;
	virtual void render() = 0;
};