/*
 *  FlyingObject.cpp
 *  aladelta
 *
 *  Created by Miguel Sánchez Valdés on 08/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */ 

#include "FlyingObject.h" 

FlyingObject::FlyingObject(int x, int y, string name, float _zoom){
	
	icon.loadImage(name); 
	zoom = _zoom;

	initialize(); 
	
} 


FlyingObject::~FlyingObject(){

};


void FlyingObject::initialize() { 
	
	fase = ofRandom(0, 2.0*PI);
	
	rotation = 0; 
	shadowScale = 1;
	shadowOffsetX = shadowOffsetY = 10; 
	
	acc = ofPoint(0,0);
	r = 5.0;
	maxspeed = 30.0;
	vel = ofPoint(0,0);
	
};

//--------------------------------------------------------------
void FlyingObject::update(){
		
	vel += acc;
	if (acc==0) vel=ofPoint(0,0);
	vel.x = ofClamp(vel.x, -maxspeed, maxspeed);
	vel.y = ofClamp(vel.y, -maxspeed, maxspeed); 

	
	acc = 0;
	
}


//--------------------------------------------------------------
void FlyingObject::draw() { 

	ofPushMatrix(); 
	ofTranslate(pos.x , pos.y); 
	ofRotateY(rotation); 
	ofScale(zoom, zoom, 1); 
	
	
	ofPushMatrix(); 
	ofTranslate(shadowOffsetX + 2 * sin(0.05 * ofGetFrameNum()), shadowOffsetY + 2 * cos(0.05 * ofGetFrameNum())); //shadow 
	ofScale(shadowScale, shadowScale, 1); //shadow 
	ofSetColor(0, 0, 0, 100); 
	icon.setAnchorPoint(icon.width / 2, icon.height / 2); 
	icon.draw(0, 0); 
	ofPopMatrix();

	
	ofPushMatrix(); 
	ofSetColor(255, 255, 255, 255);  
	icon.draw(0 ,0); 
	ofPopMatrix(); 
	
	ofPopMatrix(); 
	
	
}

//--------------------------------------------------------------
void FlyingObject::applyForce(ofPoint force) {
	force /= mass;
	acc += force;
}

//--------------------------------------------------------------
int FlyingObject::getY() { 
	
	return pos.y; 
}

//--------------------------------------------------------------
int FlyingObject::getX(){
	return pos.x;
} 

//--------------------------------------------------------------
void FlyingObject::setX(int x){
	pos.x = x;
} 

//--------------------------------------------------------------
void FlyingObject::setY(int y){
	pos.y = y;
} 

//--------------------------------------------------------------
int FlyingObject::getWidth(){
	return icon.getWidth()*zoom;
}

//--------------------------------------------------------------
int FlyingObject::getHeight(){
	return icon.getHeight()*zoom;
}

//--------------------------------------------------------------
void FlyingObject::setShadowOffset(float _x, float _y) { 
	shadowOffsetX = _x; 
	shadowOffsetY = _y; 

}

//--------------------------------------------------------------
void FlyingObject::setShadowScale(float _scale) {
	shadowScale = _scale; 
	
}  


//--------------------------------------------------------------
void FlyingObject::setRotation(float _rotation) {
	rotation = _rotation; 
	
} 


//--------------------------------------------------------------
void FlyingObject::setZoom(float _zoom) {
	zoom = _zoom; 
	
} 

//--------------------------------------------------------------
ofImage FlyingObject::getIcon() {
	return icon; 
	
} 





