/*
 *  Particle.cpp
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Particle.h"

Particle::Particle() {
	acc = ofPoint(0,0);
    r = 5.0;
    timer = 100.0;
    maxspeed = 20.0;
	mass = 1.0; 
	colorSelect = ofRandom(0, 1);  
	
	
	if(colorSelect < 0.5) { 
		//ofSetColor(32, 105, 245*colorSelect, 180); //, timer); 
		particleColor.r = 82; 
		particleColor.g = 125; 
		particleColor.b = 208;  
		particleColor.a = 180; 
		
	} else { 
		particleColor.r = 125; 
		particleColor.g = 165; 
		particleColor.b = 242; 
		particleColor.a = 180; 
		
	} 
	
	

}

void Particle::update() {
	vel += acc;
	vel.x = ofClamp(vel.x, -maxspeed, maxspeed);
	vel.y = ofClamp(vel.y, -maxspeed, maxspeed);
	loc += vel;
	acc = 0;
	timer -= 0.5;
}

void Particle::applyForce(ofPoint force) {
	force /= mass;
	acc += force;
} 

void Particle::draw() {
	
	ofPushStyle(); 
	ofPushMatrix();
	ofTranslate(loc.x, loc.y);
	ofEnableAlphaBlending();
	ofFill(); 

	ofSetColor(particleColor.r, particleColor.g, particleColor.b, particleColor.a); 	
	
	ofCircle(0, 0, r*ofMap(timer, 100, 0, 2, 0));
	//ofSetColor(255, 0, 0, timer);
	//ofLine(0, 0, vel.x, vel.y);
	ofPopMatrix(); 
	ofPopStyle(); 
}

bool Particle::dead() {
	if(timer <= 0.0) {
		return true;
	} else {
		return false;
	}
}