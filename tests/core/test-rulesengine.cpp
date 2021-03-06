//
// Created by tristan on 09/04/19.
//

#include "../../src/core/RulesEngine.cpp"
#include "../catch.hpp"

TEST_CASE("RE can recognize simple polygon from triangle to decagon.", "[RE]") {
  RulesEngine rulesEngine;
  Label labels[] = {TRIANGLE, TETRAGON, PENTAGON, HEXAGON,
                    HEPTAGON, OCTAGON,  NONAGON,  DECAGON};

  for (int x = 0; x < (sizeof(labels) / sizeof(*labels)); x++) {
    Record record(x + 3, 0, 0, 0);
    rulesEngine.fill(record);
    REQUIRE(record.get_label() == labels[x]);
  }

  SECTION("RE can recognize specific triangles.") {
    Record right_triangle(3, 1, 0, 0);
    rulesEngine.fill(right_triangle);
    REQUIRE(right_triangle.get_label() == RIGHT_TRIANGLE);

    Record equilateral_triangle(3, 0, 0, 3);
    rulesEngine.fill(equilateral_triangle);
    REQUIRE(equilateral_triangle.get_label() == EQUILATERAL_TRIANGLE);

    Record isosceles_triangle(3, 0, 0, 2);
    rulesEngine.fill(isosceles_triangle);
    REQUIRE(isosceles_triangle.get_label() == ISOSCELES_TRIANGLE);

    Record right_isosceles_triangle(3, 1, 0, 2);
    rulesEngine.fill(right_isosceles_triangle);
    REQUIRE(right_isosceles_triangle.get_label() == RIGHT_ISOSCELES_TRIANGLE);
  }

  SECTION("RE can recognize specific tetragons.") {
    Record square(4, 4, 4, 4);
    rulesEngine.fill(square);
    REQUIRE(square.get_label() == SQUARE);

    Record rectangles(4, 4, 4, 2);
    rulesEngine.fill(rectangles);
    REQUIRE(rectangles.get_label() == RECTANGLE);

    Record trapezium(4, 0, 2, 0);
    rulesEngine.fill(trapezium);
    REQUIRE(trapezium.get_label() == TRAPEZIUM);

    Record isosceles_trapezium(4, 0, 2, 2);
    rulesEngine.fill(isosceles_trapezium);
    REQUIRE(isosceles_trapezium.get_label() == ISOSCELES_TRAPEZIUM);

    Record parallelogram(4, 0, 4, 2);
    rulesEngine.fill(parallelogram);
    REQUIRE(parallelogram.get_label() == PARALLELOGRAM);

    Record rhombus(4, 0, 4, 4);
    rulesEngine.fill(rhombus);
    REQUIRE(rhombus.get_label() == RHOMBUS);
  }

  SECTION("RE can recognize specific pentagons.") {
    Record pentagon(5, 0, 0, 5);
    rulesEngine.fill(pentagon);
    REQUIRE(pentagon.get_label() == EQUILATERAL_PENTAGON);
  }

  SECTION("RE can recognize regular hexagon to decagon.") {
    Record hexagon(6, 0, 0, 6);
    rulesEngine.fill(hexagon);
    REQUIRE(hexagon.get_label() == REGULAR_HEXAGON);

    Record octagon(8, 0, 0, 8);
    rulesEngine.fill(octagon);
    REQUIRE(octagon.get_label() == REGULAR_OCTAGON);

    Record decagon(10, 0, 0, 10);
    rulesEngine.fill(decagon);
    REQUIRE(decagon.get_label() == REGULAR_DECAGON);
  }
}
