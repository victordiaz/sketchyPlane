/*
 *  plane.cpp
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */ 

#include "plane.h"


plane::plane(int x, int y, string name, float zoom):FlyingObject(x,y,name,zoom)
{
	pos.x = x;
	pos.y = y;
	
	mass = 20.0;

};

//--------------------------------------------------------------
void plane::update(){
	
	if (acc != 0) {
		prevAcc = acc;
	}
	
	FlyingObject::update();
	
	pos+=vel;
	
	if (vel==0) 
	{	
		pos.y++; 
		if (prevAcc.x>0) prevAcc.x-=0.1;
		else prevAcc.x+=0.1;
		pos.x+=prevAcc.x;
	}
	
	if (pos.x > ofGetWidth()) pos.x = ofGetWidth();
	if (pos.y > ofGetHeight() - 200) pos.y = ofGetHeight() - 200;
	if (pos.x < 0) pos.x = 0;
	if (pos.y < 0) pos.y = 0;
	
} 


//--------------------------------------------------------------
bool plane::collidesWithBird(int x, int y, int w, int h){
	
	
	float centroX = pos.x;
	float centroY = pos.y;
	
	float centroPajaroX = x; 
	float centroPajaroY = y; 
		
	float distancia = ofDist(centroX, centroY, centroPajaroX, centroPajaroY);
	
	float distanciaLateral = ofDist(centroX, centroY, pos.x+ getWidth()/2, centroY);
	float distanciaLateralPajaro = ofDist(centroPajaroX, centroPajaroY, x+w/2, centroPajaroY);
	
	if (distancia <= distanciaLateral + distanciaLateralPajaro)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//--------------------------------------------------------------
void plane::setPosition(int x, int y ){
	
	int i=pos.x;
	int j=pos.y;
	pos.x=x*.25+i*.75;
	pos.y=y*.25+j*.75;
	
}