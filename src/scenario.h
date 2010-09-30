/*
 *  scenario.h
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _SCENARIO_
#define _SCENARIO_

#include "ofMain.h" 

class scenario { 
	
public:
	
	scenario(); 
	scenario(float _x, float _y, string bg_name); 
	
	void initialize(); 
	
	void update();
	void draw(); 

	void setRotation(float _rotation); 
	
	void setZoom(float _zoom); 

	float x, y; 
	float rotation; 
	float zoom; 
	
	ofImage background; 
	
	
};

#endif	

