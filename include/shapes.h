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

    virtual void create() {
      
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
    const sf::Color color_blue = sf::Color(200, 200, 200, 255);
    const sf::Color color_dark_blue = sf::Color(0, 51, 102, 255);
};

class Rectangle: public Shape {
public:
      float getWidth() {
        return width;
      }
      float getHeight() {
        return height;
      }

private:
};

class Circle: public Shape {
public:
    int getRadius() {
            return radius;
        }
};
#endif