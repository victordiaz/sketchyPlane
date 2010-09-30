/*
 *  bird.cpp
 *  aladelta
 *
 *  Created by Miguel Sánchez Valdés on 05/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "bird.h"

bird::bird(int _x, int _y, string _name, float _zoom):FlyingObject(_x,_y,_name,_zoom)
{
	pos.x = _x;
	pos.y = _y-icon.height/2*_zoom;
	
	xCentral = _x;
	
	mass = 75.0;

}

//--------------------------------------------------------------
void bird::update(){
		
	FlyingObject::update();

	pos.x = xCentral + 50 * sin(0.01 * ofGetFrameNum()+fase) + vel.x;
	pos.y += 1 + vel.y;
	
	xCentral += vel.x;

}

