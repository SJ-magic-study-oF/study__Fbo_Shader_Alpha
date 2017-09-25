/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle( "study" );
	ofSetWindowShape( WIDTH, HEIGHT );
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetEscapeQuitsApp(false);

	/********************
	********************/
	ofSetCircleResolution(32);
	fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGBA);
	pixels.allocate( ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
	
	shader.load( "shaderVert.c", "shaderFrag.c" );
}

//--------------------------------------------------------------
void ofApp::update(){

}

#define CHECK_SHADER
#ifdef CHECK_SHADER
//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	ofBackground(0, 0, 0, 0);
	
	/********************
	********************/
	fbo.begin();
		shader.begin();
		
		// ofEnableAlphaBlending();
		ofDisableAlphaBlending();
		
		ofBackground(0, 0, 0, 0);
		ofSetColor(255, 0, 0, 100);
		ofDrawRectangle(0, 0, 200, 200);
		
		// ofSetColor(255, 0, 0, 200);
		// ofDrawRectangle(100, 100, 200, 200);
	
		shader.end();
	fbo.end();
	
	/********************
	********************/
	fbo.readToPixels(pixels);
	ofColor c = pixels.getColor(mouseX, mouseY);
	printf("(%3d, %3d, %3d, %3d)\r", c.r, c.g, c.b, c.a);
	fflush(stdout);
	
	/********************
	********************/
	/*
	ofEnableAlphaBlending();
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	*/
	ofDisableAlphaBlending();
	ofBackground(0, 0, 0, 0);
	fbo.draw(0, 0);
}

#else

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	fbo.begin();
		// ofDisableAlphaBlending();
		ofEnableAlphaBlending();
		// ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
		ofBackground(0, 0, 0, 0);
		ofSetColor(255, 0, 0, 200);
		ofDrawRectangle(0, 0, 200, 200);
		
		// ofSetColor(255, 0, 0, 200);
		ofDrawRectangle(100, 100, 200, 200);
	fbo.end();
	
	/********************
	********************/
	fbo.readToPixels(pixels);
	ofColor c = pixels.getColor(mouseX, mouseY);
	printf("(%3d, %3d, %3d, %3d)\r", c.r, c.g, c.b, c.a);
	fflush(stdout);
	
	/********************
	********************/
	/*
	ofEnableAlphaBlending();
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	*/
	ofDisableAlphaBlending();
	ofBackground(0, 0, 0, 0);
	fbo.draw(0, 0);
	
}
#endif

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
