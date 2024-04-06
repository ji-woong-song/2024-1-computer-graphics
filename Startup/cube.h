#pragma once
#include "shape.h"
#include "dot_3d.h"

#define TOP_FRONT_LEFT 0
#define BOTTOM_FRONT_LEFT 1
#define BOTTOM_FRONT_RIGHT 2
#define TOP_FRONT_RIGHT 3
#define TOP_REAR_LEFT 4
#define BOTTOM_REAR_LEFT 5
#define BOTTOM_REAR_RIGHT 6
#define TOP_REAR_RIGHT 7

class Cube : public Shape {
private:
	Dot3D center;
	double x_length;
	double y_length;
	double z_length;
public:
	Cube(Dot3D center, double x_len, double y_len, double z_len, const Color color = {1.0f, 0.0f, 0.0f});
	void render() override;

	static Cube *bottomCenter(Dot3D center, double x_len, double y_len, double z_len, const Color color = { 1.0f, 0.0f, 0.0f }) {
		return new Cube({ center.x, center.y + y_len / 2, center.z }, x_len, y_len, z_len, color);
	}
};