#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "bird.h"
#include "plane.h"
#include "cloud.h"

#include "ofxOsc.h" 
#include "wind.h" 
#include "scenario.h" 



// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20


class testApp : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw(); 
	
	void initialize(); 
	
	void keyPressed(int key);
	void keyReleased(int key); 
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h); 
	
	void receiveOSC(); 
	
	
private: 
	
	ofxOscReceiver	receiver;
	string		msg_strings[NUM_MSG_STRINGS];
	float		timers[NUM_MSG_STRINGS]; 
	float		wind_left_intensity_x, wind_left_intensity_y; 
	float		wind_right_intensity_x, wind_right_intensity_y;
	int time, time2, time3; 
	
	ofImage icon; 
	
	float mx,my,r,i,j;
	vector <bird> pajaros;
	vector <cloud> nubes;
	plane avion; 
	scenario fondo; 
	wind wind_left, wind_right;
	
	float worldTranslateX, worldTranslateY, worldTranslateZ;  
	float worldRotateX, worldRotateY, worldRotateZ; 
	float worldScaleX, worldScaleY, worldScaleZ; 
	
	int vidas;
	int puntuacion;
	string vidasMsg;
	string puntuacionMsg; 
	
	ofSoundPlayer mySound; 

	
};

#endif	
