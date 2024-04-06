#include "shape.h"
#include "shape_render.h"
#include "../usr/include/glfw/glfw3.h"

void Shape::changeColor(const Color color) {
	this->color[0] = color.red;
	this->color[1] = color.blue;
	this->color[2] = color.green;
}

Shape::Shape(const Color color){
	this->color[0] = color.red;
	this->color[1] = color.blue;
	this->color[2] = color.green;
}

Shape::~Shape() {
	this->container->withdraw(this);
}

void Shape::render() {
	for (Shape* shape : shapes) {
		shape->render();
	}
}

void Shape::enroll(Shape* shape) {
	shapes.push_back(shape);
	shape->container = this;
}

void Shape::withdraw(Shape* shape) {
	auto it = std::find(shapes.begin(), shapes.end(), shape);
	shapes.erase(it);
}
