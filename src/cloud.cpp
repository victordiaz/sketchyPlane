/*
 *  cloud.cpp
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "cloud.h"

cloud::cloud(int _x, int _y, string _name, float _zoom):FlyingObject(_x,_y,_name,_zoom)
{	
	pos.x = _x-icon.width/2*_zoom;
	pos.y = _y;
	
	yCentral = _y;
	
	mass = 40.0;

}

//--------------------------------------------------------------
void cloud::update(){
		
	FlyingObject::update();
	
	pos.x += 1 + vel.x;
	pos.y = yCentral + 50 * sin(0.01 * ofGetFrameNum()+fase) + vel.y;
	
	yCentral += vel.y;
	
}




