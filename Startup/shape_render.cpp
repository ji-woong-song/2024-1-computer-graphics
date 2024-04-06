#include "shape_render.h"

ShapeRender* ShapeRender::instance = nullptr;

ShapeRender* ShapeRender::getInstance() {
	if (instance == nullptr) {
		ShapeRender::instance = new ShapeRender();
	}
	return ShapeRender::instance;
}

void ShapeRender::enroll(Shape* shape) {
	shapes.push_back(shape);
}

void ShapeRender::withdraw(Shape* shape) {
	auto it = std::find(shapes.begin(), shapes.end(), shape);
	shapes.erase(it);
}

void ShapeRender::render() {
	for (Shape* shape : shapes) {
		shape->render();
	}
}
