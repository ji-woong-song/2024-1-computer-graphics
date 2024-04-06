#pragma once
#ifndef PICK_UP_ARM_OBJECT_H
#define PICK_UP_ARM_OBJECT_H

class PickUpArm {
	
public:
	void rotateBase(double radius);
	void rotateElbow(double radius);
	void handleFinger(double radius);
};

#endif