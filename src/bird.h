/*
 *  bird.h
 *  aladelta
 *
 *  Created by Miguel Sanchez Valdes on 05/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _BIRD_
#define _BIRD_

#include "ofMain.h"
#include "FlyingObject.h"


class bird : public FlyingObject {
	
public:
	
	bird(int _x, int _y, string _name, float _zoom);
	~bird(){};
	void update();
	
private:
	float xCentral;

		
};

#endif	

