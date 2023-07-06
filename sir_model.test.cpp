#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "sir_model.hpp"

#include "doctest.h"

TEST_CASE("Testing SIR model") {
  Model model_1(1000, 50, 50, 0.8, 0.2, 30);
  Model model_2(1000, 50, 50, 0.8, 0.2, 30);
  Model model_3(150, 50, 50, 0.8, 0.6, 30);

  SUBCASE("Testing the update function") {
    model_1.update();
    CHECK(model_1.get_s() == 964);
    CHECK(model_1.get_i() == 76);
    CHECK(model_1.get_r() == 60);
  }

  SUBCASE("Testing the final_result and time_evolution functions") {
    model_1.final_result();
    model_2.time_evolution();
    CHECK(model_1.get_s() == model_2.get_s());
    CHECK(model_1.get_i() == model_2.get_i());
    CHECK(model_1.get_r() == model_2.get_r());
  }

  SUBCASE("Testing the isExpanding function") {
    CHECK(model_1.isExpanding(model_1.get_s()));   // se è vero
    CHECK(!model_3.isExpanding(model_3.get_s()));  // se è falso
  }
}
