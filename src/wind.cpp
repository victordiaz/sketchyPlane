/*
 *  wind.cpp
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */ 


#include "wind.h"

wind::wind(){
	
	//------------------------- 
	gravity.y = 0.2;	

	//qq 
	
} 


wind::wind(int _x, int _y, int _rotationX, int _rotationY, int _rotationZ){
	
	//------------------------- 
	x = _x; 
	y = _y; 
	rotationX = _rotationX; 
	rotationY = _rotationY; 
	rotationZ = _rotationZ; 

	gravity.y = 1;	
		
} 

//--------------------------------------------------------------
void wind::update(){
	
	//------------------------------- 
	ps.applyForce(gravity);
	ps.update();
	
	for(int i=0; i<1; i++) {
		ps.addParticle(0, 0);
	} 
	
} 

//--------------------------------------------------------------
void wind::draw(){
	
	ofPushMatrix(); 
	ofTranslate(x, y, 0); 
	ofRotateX(rotationX); 
	ofRotateY(rotationY); 
	ofRotateZ(rotationZ); 

	ps.draw(); 
	ofPopMatrix(); 

} 


void wind::setIntensity(float x, float y) { 
	gravity.x = x; 
	gravity.y = y; 

} 

ofPoint wind::getIntensity() { 
	return gravity; 	
} 

void wind::setRotationY(int _rotationY) { 
	rotationY = _rotationY; 
} 

