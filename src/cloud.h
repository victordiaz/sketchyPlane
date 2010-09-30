/*
 *  cloud.h
 *  aladelta
 *
 *  Created by biquillo on 07/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CLOUD_
#define _CLOUD_

#include "ofMain.h"
#include "FlyingObject.h"


class cloud : public FlyingObject {
	
public:
	
	cloud(int _x, int _y, string _name, float _zoom);
	~cloud(){};
	void update();

private:
	int yCentral;

};

#endif	