#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
	
		
	fondo = scenario(ofGetWidth(), ofGetHeight(), "images/bg/Squared_Notepad_mod.jpg"); 
	avion = plane(ofGetWidth()/2,ofGetHeight()/2,"images/plane.png",0.3); 
	
	icon.loadImage("images/plane.png"); 
	icon.resize(icon.width / 10, icon.height / 10); 


	
	wind_left = wind(0, ofGetHeight(), 0, 0, 10); 
	wind_right = wind(ofGetWidth(), ofGetHeight(), 0, 180, 10); 
	
	//OSC 
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << endl;
	receiver.setup( PORT ); 
	

	//set background to black
	ofBackground(0, 0, 0);

	//for smooth animation, set vertical sync if we can
	ofSetVerticalSync(true);
	// also, frame rate:
	ofSetFrameRate(60);
	
	time = time2 = time3 = ofGetElapsedTimeMillis();
	
	// Información sobre pantalla
	vidas = 5;
	puntuacion = 0;
	
	ofSetColor(0, 0, 0); 
	vidasMsg = "Lives: "+ ofToString(vidas);
	puntuacionMsg = "Points: "+ ofToString(puntuacion);


	
	mySound.loadSound("sounds/mum.mp3"); 
	mySound.setVolume(0.5); 
	mySound.setLoop(true); //Sound will loop	
	mySound.play();
	
	initialize(); 
	
} 


//--------------------------------------------------------------
void testApp::initialize() {	
		
	worldTranslateX = worldTranslateY = worldTranslateZ = 0; 
	worldScaleX = worldScaleY = worldScaleZ = 1; 
	worldRotateX = worldRotateY = worldRotateZ = 180; 

	
} 


//--------------------------------------------------------------
void testApp::update() {	
	
	receiveOSC(); 
	fondo.update(); 
	
	//---------------------- Viento -----------------------// 

	
	wind_right.update(); 
	wind_left.update();
	
	ofPoint windRight = wind_right.getIntensity();
	ofPoint windLeft = wind_left.getIntensity();
		
	ofPoint windIntensity;
	windRight.set(-windRight.x, -ofMap(windRight.y, 0, 1, 1, 0)/2, windRight.z);
	windLeft.set(windLeft.x, -ofMap(windLeft.y, 0, 1, 1, 0)/2, windLeft.z); 
	windIntensity = windRight + windLeft;
	
	//---------------------- Pajaritos -----------------------// 
	
	for(int i=0;i<pajaros.size(); i++)
	{
		pajaros[i].applyForce(windIntensity);
		pajaros[i].update();
		
		if (pajaros[i].getY()>(ofGetHeight()+pajaros[i].getHeight()/2)) {
			pajaros.erase(pajaros.begin());
		}
		
		// Calculo si colisiona con el avion
		
		if (avion.collidesWithBird(pajaros[i].getX(), pajaros[i].getY(), pajaros[i].getWidth(), pajaros[i].getHeight()))
		{
			pajaros.erase(pajaros.begin()+i);
			vidas--;
		}
	}
		
	if ((ofGetElapsedTimeMillis() - time) >= 7000)
	{
		time = ofGetElapsedTimeMillis(); 
		// Calculo con random el tipo de pájaro y la posición
		//ofSeedRandom();
		int pajaro = ofRandom(1, 5.9999);
		char name[50];
		sprintf(name,"images/bird%d.png", pajaro);
		
		pajaros.push_back(bird(ofRandom(0, (ofGetWidth()-200)),0,name, 0.3)); 
		

	}
	
	
	//---------------------- nubes -----------------------// 
	
	for(int i=0;i<nubes.size(); i++)
	{
		nubes[i].applyForce(windIntensity);
		nubes[i].update();
		
		if (nubes[i].getX()>(ofGetWidth()+nubes[i].getWidth()/2)) {
			nubes.erase(nubes.begin());
		}
		
	}
	
	if ((ofGetElapsedTimeMillis() - time2) >= 3000)
	{
		time2 = ofGetElapsedTimeMillis(); 
		//ofSeedRandom();
		int nube = ofRandom(1, 3.9999);
		char name[50];
		sprintf(name,"images/cloud%d.png", nube);
		
		nubes.push_back(cloud(0, ofRandom( 0, ofGetHeight()),name, ofRandom(0.4, 1))); 
		
		
	}
	
	//---------------------- Avión -----------------------//

	avion.applyForce(windIntensity);
	avion.update();
	
	//---------------------- Puntuacion -----------------------//
	
	if ((ofGetElapsedTimeMillis() - time3) >= 1000)
	{
		time3 = ofGetElapsedTimeMillis(); 
		puntuacion++;
	}
	
	vidasMsg = "Lives: "+ ofToString(vidas);
	puntuacionMsg = "Points: "+ ofToString(puntuacion);

} 


//--------------------------------------------------------------
void testApp::draw() { 
	ofBackground(100,100,100);
	ofSetupScreen(); 
	
	ofPushMatrix(); 
	ofTranslate(worldTranslateX, worldTranslateY, worldTranslateZ); 
	
	ofScale(worldScaleX, worldScaleY, worldScaleZ); 
	ofRotate(worldRotateX, 1, 0, 0); 
	ofRotate(worldRotateY, 0, 1, 0); 
	ofRotate(worldRotateZ, 0, 0, 1); 


	
	ofEnableAlphaBlending();
	
	fondo.draw(); 	
	avion.draw();

	for(int i=0;i<pajaros.size(); i++)
	{
		pajaros[i].draw();
	}
	
	for(int i=0;i<nubes.size(); i++)
	{
		nubes[i].draw();
	}

	
	ofSetColor(0, 0, 0); 
	//ofDrawBitmapString(vidasMsg,20,20);
	ofDrawBitmapString(puntuacionMsg, 10, 20); 
	ofSetColor(255, 255, 255); 
	
	
	for (int i = 0; i < vidas; i++) { 
		icon.draw(10 + 22 * i, 25); 
	} 

	
	wind_right.draw(); 
	wind_left.draw(); 
	
	
	ofPopMatrix(); 
}


void testApp::receiveOSC() { 
	
	// hide old messages
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
	}
	
	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m ); 
		
		
		cout << "Llega mensaje OSC" << endl; 
		
		
		if ( m.getAddress() == "/world/" ) { 
			
			// both the arguments are floats 
			worldTranslateX = m.getArgAsFloat(0); 
			worldTranslateY = m.getArgAsFloat(1);  
			worldTranslateZ = m.getArgAsFloat(2);  
			worldRotateX = m.getArgAsFloat(3); 
			worldRotateY = m.getArgAsFloat(4); 
			worldRotateZ = m.getArgAsFloat(5); 
			worldScaleX = m.getArgAsFloat(6); 
			worldScaleY = m.getArgAsFloat(7); 
			worldScaleZ = m.getArgAsFloat(8); 
			
			cout << "world: " << endl; // << wind_left_intensity_x << " , " << wind_left_intensity_y  << ", "  << wind_right_intensity_x << " , " << wind_right_intensity_y  << endl; 
			
			//wind_left.setIntensity(wind_left_intensity_x, wind_left_intensity_y); 
			//wind_right.setIntensity(wind_right_intensity_x, wind_right_intensity_y); 
			
		} 
		
		
		
		if ( m.getAddress() == "/wind/" ) { 
			
			// both the arguments are floats 
			float wind_left_intensity_x = m.getArgAsFloat(0); 
			float wind_left_intensity_y = m.getArgAsFloat(1);  
			float wind_right_intensity_x = m.getArgAsFloat(2); 
			float wind_right_intensity_y = m.getArgAsFloat(3);  
			
			cout << "wind: " << wind_left_intensity_x << " , " << wind_left_intensity_y  << ", "  << wind_right_intensity_x << " , " << wind_right_intensity_y  << endl; 
			
			wind_left.setIntensity(wind_left_intensity_x, ofMap(wind_left_intensity_y, 0, 1, 1, 0)); 
			wind_right.setIntensity(wind_right_intensity_x, ofMap(wind_right_intensity_y, 0, 1, 1, 0)); 
			
		} 
		
		
		
		if ( m.getAddress() == "/floor/" ) { 

			// both the arguments are floats 
			
			float zoom = m.getArgAsFloat(0); 
			float rotation = m.getArgAsFloat(1); 
			
			fondo.setZoom(zoom); 
			fondo.setRotation(rotation); 
			
			
			
			cout << "floor: " << zoom  << endl; 
			
		} 
		
		
		if ( m.getAddress() == "/plane/" ) { 
			
			// both the arguments are floats 
			float x = m.getArgAsFloat(0); 
			float y = m.getArgAsFloat(1);  
			float rotation = m.getArgAsFloat(2); 
			float zoom = m.getArgAsFloat(3);  
			float shadowX =  m.getArgAsFloat(4); 
			float shadowY = m.getArgAsFloat(5); 
			float shadow_scale = m.getArgAsFloat(6); 
			
			//cout << "plane: " << wind_left_intensity_x << " , " << wind_left_intensity_y  << ", "  << wind_right_intensity_x << " , " << wind_right_intensity_y  << endl; 

			
			avion.setPosition(x, y);  
			avion.setRotation(rotation); 
			avion.setZoom(zoom); 
			avion.setShadowOffset(shadowX, shadowY); 
			avion.setShadowScale(shadow_scale); 
			
			
		} 
		
		
		if ( m.getAddress() == "/birds/" ) { 
			
			// both the arguments are floats 
			//float wind_left_intensity_x = m.getArgAsFloat(0); 
			//float wind_left_intensity_y = m.getArgAsFloat(1);  
			//float wind_right_intensity_x = m.getArgAsFloat(2); 
			//float wind_right_intensity_y = m.getArgAsFloat(3);  
			
			//cout << "birds: " << wind_left_intensity_x << " , " << wind_left_intensity_y  << ", "  << wind_right_intensity_x << " , " << wind_right_intensity_y  << endl; 
			
			//wind_left.setIntensity(wind_left_intensity_x, wind_left_intensity_y); 
			//wind_right.setIntensity(wind_right_intensity_x, wind_right_intensity_y); 
			
		} 
		
	} 
	
	
} 


//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

	//avion.setPosition(x, y);
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

} 

