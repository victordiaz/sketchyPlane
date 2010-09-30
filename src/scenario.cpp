/*
 *  scenario.cpp
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */ 

#include "scenario.h"

scenario::scenario() {} 

scenario::scenario(float _x, float _y, string bg_name) { 
	
	x = _x; 
	y = _y; 
	
	background.loadImage(bg_name);	
	
	initialize(); 
	
} 


void scenario::initialize() { 
	rotation = 0; 
	zoom = 1.4; 
} 

//--------------------------------------------------------------
void scenario::update() {
	

} 

//--------------------------------------------------------------
void scenario::draw(){
	
	ofPushMatrix(); 
	ofTranslate(x / 2, y / 2, 0); 
	ofRotate(rotation); 	
	ofScale(zoom, zoom, 0); 
	
	background.setAnchorPoint(background.width / 2, background.height / 2); 
	background.draw(0, 0); 
	
	ofPopMatrix(); 
	
} 


//--------------------------------------------------------------
void scenario::setRotation(float _rotation) {
	rotation = _rotation; 
	
} 



//--------------------------------------------------------------
void scenario::setZoom(float _zoom) {
	zoom = ofClamp(_zoom, 1.4, 5); 
	
} 





