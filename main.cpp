#include <iostream>

#include "sir_model.hpp"
#include "sir_model_graph.hpp"
#include "user_interface.hpp"

int main() {
  Model model = make_model();

  decision_1(model);
  decision_2(model);

  return 0;
}
