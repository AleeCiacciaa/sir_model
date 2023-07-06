#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include "sir_model.hpp"
#include "sir_model_graph.hpp"

Model make_model();
void decision_1(Model& model);
void decision_2(Model const& model);
void decision_3(Model const& model);

#endif
