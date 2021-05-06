#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

class Shape {
public:
    // setfillcolor
    // setoutlinethickness
    // setoutline color
    sf::RectangleShape createR() {

    }

    sf::CircleShape createC() {

    }

      void setWidth(float width) {
         this->width = width;
      }
      void setHeight(float height) {
         this->height = height;
      }
      void setRadius(float radius) {
          this->radius = radius;
      }
protected:
    float width;
    float height;
    float radius;
};

class Rectangle: public Shape {
public:
      float getWidth() {
        return width;
      }
      float getHeight() {
        return height;
      }
};

class Circle: public Shape {
public:
    int getRadius() {
            return radius;
        }
};
#endif