/*
 *  FlyingObject.h
 *  aladelta
 *
 *  Created by Miguel Sánchez Valdés on 08/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef _FLYINGOBJECT_
#define _FLYINGOBJECT_

#include "ofMain.h" 


class FlyingObject {
	
public:
	
	FlyingObject(){};
	FlyingObject(int x, int y, string name, float zoom);
	~FlyingObject(); 
	void initialize(); 
	void update(); 
	void draw();
	int getY();
	int getX();
	void setX(int x); 
	void setY(int y);
	int getWidth();
	int getHeight();
	ofImage getIcon();
	
	void setShadowOffset(float _x, float _y); 
	void setShadowScale(float _scale); 
	
	void setRotation(float _rotation); 
	void setZoom(float _zoom); 
	
	void applyForce(ofPoint force);
	

	

protected:
	ofPoint pos; 
	ofImage icon; 
	
	float fase;
	
	float shadowOffsetX, shadowOffsetY; 
	float shadowScale; 
	
	float zoom; 
	float rotation; 
	
	ofPoint vel;
	ofPoint acc;
	ofPoint prevAcc;
	float r;
	float maxspeed;
	float mass;
		
};

#endif	