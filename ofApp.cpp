#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	while (this->shapes.size() < 800) {

		auto location = glm::vec2(ofRandom(100, ofGetWidth() - 100), ofRandom(100, ofGetHeight() - 100));
		auto radius = ofRandom(5, 25);
		auto flag = true;
		for(auto& shape : this->shapes){

			if (glm::distance(location, glm::vec2(shape->location)) < shape->radius + radius) {

				flag = false;
				break;
			}
		}

		if (flag) {

			unique_ptr<My::Shape> shape;
			int r = ofRandom(2);
			switch (r) {

			case 0:

				shape = make_unique<My::Circle>(location, radius);
				break;

			case 1:

				shape = make_unique<My::Rectangle>(location, radius);
				break;
			}

			if (shape) { this->shapes.push_back(move(shape)); }
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (auto& shape : this->shapes) {

		shape->draw();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}