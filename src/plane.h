/*
 *  plane.h
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _PLANE_
#define _PLANE_

#include "ofMain.h"
#include "FlyingObject.h"


class plane : public FlyingObject {
	
public:
	
	plane(){};
	plane(int x, int y, string name, float zoom);
	~plane(){};
	
	void update();
	void setPosition(int x, int y );
	bool collidesWithBird(int x, int y, int w, int h);
	
	
};

#endif	

