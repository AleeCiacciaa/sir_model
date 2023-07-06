#ifndef SIR_MODEL_GRAPH_HPP
#define SIR_MODEL_GRAPH_HPP

#include <sciplot/sciplot.hpp>
#include <string>

#include "sir_model.hpp"

void graph_sir_model(Model const& model, int dec_3);
void susceptible_graph(Model const& model);
void infected_graph(Model const& model);
void removed_graph(Model const& model);
void general_graph(Model const& model);
void basic_plot(sciplot::Plot2D plot, std::string const& title);

#endif
