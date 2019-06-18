#include "MyShapes.h"

// Shape
My::Shape::Shape(glm::vec2 location, float radius) {

	this->location = location;
	this->radius = radius;
	this->fill = ofRandom(1) < 0.5 ? true : false;
}

// Circle
My::Circle::Circle(glm::vec2 location, float radius) : Shape(location, radius) {

	this->deg = ofRandom(360);
}

void My::Circle::draw() {

	ofPushMatrix();
	ofTranslate(this->location);
	ofRotate(this->deg);

	this->fill ? ofFill() : ofNoFill();
	ofSetColor(39);
	ofDrawCircle(glm::vec2(), this->radius);

	float tmp_radius = ofNoise(this->location.x * 0.005, this->location.y * 0.005, ofGetFrameNum() * 0.005) * this->radius;

	this->fill ? ofSetColor(239) : ofFill();
	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 36) {

		if (deg % 72 == 0) {

			ofVertex(tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD));
		}
		else {

			ofVertex(tmp_radius * 0.5 * cos(deg * DEG_TO_RAD), tmp_radius * 0.5 * sin(deg * DEG_TO_RAD));
		}
	}
	ofEndShape(true);

	ofPopMatrix();
}

// Rectangle
My::Rectangle::Rectangle(glm::vec2 location, float radius) : Shape(location, radius) {

	this->len = radius * sqrt(2);
	this->speed = ofRandom(0.5, 3);
	this->direction = ofRandom(1) < 0.5 ? -1 : 1;
}

void My::Rectangle::draw() {

	ofPushMatrix();
	ofTranslate(this->location);
	ofRotate(ofGetFrameNum() * this->speed * this->direction);

	this->fill ? ofFill() : ofNoFill();
	ofSetColor(39);
	ofDrawRectangle(glm::vec2(), this->len, this->len);

	ofPopMatrix();
}