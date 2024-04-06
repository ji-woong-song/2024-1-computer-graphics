#pragma once
#include "shape.h"
#include <vector>
#include "shape_container.h"

class ShapeRender : public ShapeContainer{
private:
	static ShapeRender* instance;
	std::vector<Shape*> shapes;
	ShapeRender() { }
public:
	static ShapeRender* getInstance();
	void render() override;
	void enroll(Shape* shape) override;
	void withdraw(Shape* shape) override;
};
