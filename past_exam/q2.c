#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ShapeText(TYPE)              \
  char name[10];                     \
  double (*perimeter)(struct TYPE*); \
  double (*area)(struct TYPE*);

// Circle

typedef struct _Circle {
  ShapeText(_Circle);
  double radius;
} Circle;
double circle_perimeter(Circle* circle) {
  return 2 * 3.14 * circle->radius;
}
double circle_area(Circle* circle) {
  return 3.14 * circle->radius * circle->radius;
}
Circle* new_Circle(double radius) {
  Circle* circle = malloc(sizeof(Circle));
  strcpy(circle->name, "Circle");
  circle->radius = radius;
  circle->perimeter = circle_perimeter;
  circle->area = circle_area;
  return circle;
}

// Rectangular

typedef struct _Rectangular {
  ShapeText(_Rectangular);
  double width;
  double length;
} Rectangular;
double rectangular_perimeter(Rectangular* rectangular) {
  return 2 * rectangular->width + 2 * rectangular->length;
}
double rectangular_area(Rectangular* rectangular) {
  return rectangular->width * rectangular->length;
}
Rectangular* new_Rectangular(double width, double length) { // STUDY
  Rectangular* rectangular = malloc(sizeof(Rectangular));
  strcpy(rectangular->name, "Rectangular");
  rectangular->width = width;
  rectangular->length = length;
  rectangular->perimeter = rectangular_perimeter;
  rectangular->area = rectangular_area;
  return rectangular;
}

// Square

typedef struct _Square {
  ShapeText(_Square);
  double width;
} Square;
double square_perimeter(Square* square) {
  return 4 * square->width;
}
double square_area(Square* square) {
  return square->width * square->width;
}
Square* new_Square(double width) {
  Square* square = malloc(sizeof(Square));
  strcpy(square->name, "Square");
  square->width = width;
  square->perimeter = square_perimeter;
  square->area = square_area;
  return square;
}

// Triangle

typedef struct _Triangle {
  ShapeText(_Triangle);
  double a;
  double b;
  double c;
} Triangle;
double triangle_perimeter(Triangle* triangle) {
  return triangle->a + triangle->b + triangle->c;
}
double triangle_area(Triangle* triangle) {
  double s = triangle_perimeter(triangle) / 2; // semi_perimeter
  return sqrt(s * (s - triangle->a) * (s - triangle->b) * (s - triangle->c)); // STUDY
}
Triangle* new_Triangle(double a, double b, double c) {
  Triangle* triangle = malloc(sizeof(Triangle));
  strcpy(triangle->name, "Triangle");
  triangle->a = a;
  triangle->b = b;
  triangle->c = c;
  triangle->perimeter = triangle_perimeter;
  triangle->area = triangle_area;
  return triangle;
}

int main() {
  int input_count;
  scanf(" %d", &input_count);
  double perimeters[input_count];
  double sum_of_perimeters = 0;

  for (int i = 0; i < input_count; i++) {
    char input_type;
    scanf(" %c", &input_type);

    switch (input_type) {
    case 'C': {
      double radius;
      scanf(" %lf", &radius);

      Circle* circle = new_Circle(radius);

      double perimeter = circle->perimeter(circle);
      printf("%.0lf\n", perimeter); // STUDY
      sum_of_perimeters += perimeter;
      break;
    }
    case 'R': {
      double width;
      scanf(" %lf", &width);
      double length;
      scanf(" %lf", &length);

      Rectangular* rectangular = new_Rectangular(width, length);

      double perimeter = rectangular->perimeter(rectangular);
      printf("%.0lf\n", perimeter);
      sum_of_perimeters += perimeter;
      break;
    }
    case 'S': {
      double width;
      scanf(" %lf", &width);

      Square* square = new_Square(width);

      double perimeter = square->perimeter(square);
      printf("%.0lf\n", perimeter);
      sum_of_perimeters += perimeter;
      break;
    }
    case 'T': {
      double a;
      scanf(" %lf", &a);
      double b;
      scanf(" %lf", &b);
      double c;
      scanf(" %lf", &c);

      Triangle* triangle = new_Triangle(a, b, c);

      double perimeter = triangle->perimeter(triangle);
      printf("%.0lf\n", perimeter);
      sum_of_perimeters += perimeter;
      break;
    }
    }
  }

  printf("%.0lf", sum_of_perimeters);
}