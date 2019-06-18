#pragma once
#pragma once
#include "ofMain.h"

namespace My {

	class Shape {
	public:
		Shape(glm::vec2 location, float radius);
		~Shape() {};
		virtual void draw() = 0;

		glm::vec2 location;
		float radius;
		bool fill;
	};

	class Circle : public Shape {
	public:
		Circle(glm::vec2 location, float radius);
		void draw() override;
	private:
		int deg;
	};

	class Rectangle : public Shape {
	public:
		Rectangle(glm::vec2 location, float radius);
		void draw() override;
	private:
		float len;
		float speed;
		int direction;
	};
}