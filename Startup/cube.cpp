#include "cube.h"
#include "../usr/include/glfw/glfw3.h"

Cube::Cube(Dot3D center, double x_len, double y_len, double z_len, const Color color) :
	Shape(color), x_length(x_len), y_length(y_len), z_length(z_len), center(center)
{}


void Cube::render() {
	const double dx = x_length / 2;
	const double dy = y_length / 2;
	const double dz = z_length / 2;

	const double dot[8][3] = {
		{-dx, dy, dz},
		{-dx, -dy, dz},
		{+dx, -dy, dz},
		{+dx, +dy, dz},

		{-dx, dy, -dz},
		{-dx, -dy, -dz},
		{+dx, -dy, -dz},
		{+dx, +dy, -dz}
	};
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glTranslatef(center.x,center.y,center.z);
	glPushMatrix();
	{
		glColor3fv(this->color);
		glBegin(GL_QUADS);
		{
			// Front
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3dv(dot[TOP_FRONT_LEFT]);
			glVertex3dv(dot[BOTTOM_FRONT_LEFT]);
			glVertex3dv(dot[BOTTOM_FRONT_RIGHT]);
			glVertex3dv(dot[TOP_FRONT_RIGHT]);

			{
				// Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3dv(dot[TOP_FRONT_RIGHT]);
				glVertex3dv(dot[BOTTOM_FRONT_RIGHT]);
				glVertex3dv(dot[BOTTOM_REAR_RIGHT]);
				glVertex3dv(dot[TOP_REAR_RIGHT]);

				// Back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3dv(dot[TOP_REAR_RIGHT]);
				glVertex3dv(dot[BOTTOM_REAR_RIGHT]);
				glVertex3dv(dot[BOTTOM_REAR_LEFT]);
				glVertex3dv(dot[TOP_REAR_LEFT]);

				// Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3dv(dot[TOP_FRONT_LEFT]);
				glVertex3dv(dot[TOP_REAR_LEFT]);
				glVertex3dv(dot[BOTTOM_REAR_LEFT]);
				glVertex3dv(dot[BOTTOM_FRONT_LEFT]);

				// Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3dv(dot[TOP_FRONT_LEFT]);
				glVertex3dv(dot[TOP_FRONT_RIGHT]);
				glVertex3dv(dot[TOP_REAR_RIGHT]);
				glVertex3dv(dot[TOP_REAR_LEFT]);
			}

			// Bottom
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3dv(dot[BOTTOM_FRONT_LEFT]);
			glVertex3dv(dot[BOTTOM_REAR_RIGHT]);
			glVertex3dv(dot[BOTTOM_REAR_RIGHT]);
			glVertex3dv(dot[BOTTOM_FRONT_RIGHT]);
		}
		glEnd();
		Shape::render();
	}
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
}