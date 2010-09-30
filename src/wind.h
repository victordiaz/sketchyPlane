/*
 *  wind.h
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _WIND_
#define _WIND_

#include "ofMain.h" 
#include "ParticleSystem.h"

class wind {
	
public:
	
	wind(); 
	wind(int _x, int _y, int _rotateX, int _rotateY, int _rotateZ); 
	void update();
	void draw(); 
	void setIntensity(float x, float y); 
	ofPoint getIntensity();
	void setRotationY(int _rotationY);
	
	
	//--------------------------------------------- 
	ParticleSystem ps; 
	ofPoint gravity; 
	
	int x, y; 
	int rotationX, rotationY, rotationZ; 
	
};

#endif	

