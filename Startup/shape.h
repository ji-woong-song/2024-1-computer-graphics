#pragma once
#ifndef SHAPE_H
#define SHAPE_H
# include "color.h"
# include "shape_container.h"
# include <vector>

class Shape : public ShapeContainer {
private:
	std::vector<Shape*> shapes;
	ShapeContainer *container = nullptr;
protected:
	float color[3] = { 1.0f, 0.0f, 0.0f };
public:
	Shape(const Color color = {1.0, 0.0, 0.0});
	void changeColor(const Color color);
	
	void render() override;
	void enroll(Shape* shape) override;
	void withdraw(Shape* shape) override;
	~Shape();
};
#endif