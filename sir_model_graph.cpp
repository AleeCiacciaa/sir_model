#include "sir_model_graph.hpp"

#include <iostream>
#include <sciplot/sciplot.hpp>
#include <vector>

#include "sir_model.hpp"
#include "user_interface.hpp"

void graph_sir_model(Model const& model, int dec_3) {
  switch (dec_3) {
    case 1:
      susceptible_graph(model);
      break;

    case 2:
      infected_graph(model);
      break;

    case 3:
      removed_graph(model);
      break;

    case 4:
      general_graph(model);
      break;

    case 5:
      susceptible_graph(model);
      infected_graph(model);
      removed_graph(model);
      general_graph(model);
      break;

    default:
      throw std::invalid_argument("Received an invalid number");
  }
}

// provide the graph for the susceptible
void susceptible_graph(Model const& model) {
  sciplot::Vec time = sciplot::linspace(0.0, model.get_t(), model.get_t());
  sciplot::Plot2D plot;

  plot.ylabel("S").fontSize(14);
  plot.drawCurve(time, model.get_vS()).label("Susceptible").lineColor("pink");

  basic_plot(plot, "Susceptible");
}

// provide the graph for the infected
void infected_graph(Model const& model) {
  sciplot::Vec time = sciplot::linspace(0.0, model.get_t(), model.get_t());
  sciplot::Plot2D plot;

  plot.ylabel("I").fontSize(14);
  plot.drawCurve(time, model.get_vI()).label("Infected").lineColor("purple");

  basic_plot(plot, "Infected");
}

// provide the graph for the removed
void removed_graph(Model const& model) {
  sciplot::Vec time = sciplot::linspace(0.0, model.get_t(), model.get_t());
  sciplot::Plot2D plot;

  plot.ylabel("R").fontSize(14);
  plot.drawCurve(time, model.get_vR()).label("Removed").lineColor("blue");

  basic_plot(plot, "Removed");
}

// provide the graph for all the categories
void general_graph(Model const& model) {
  sciplot::Vec time = sciplot::linspace(0.0, model.get_t(), model.get_t());
  sciplot::Plot2D plot;

  plot.ylabel("SIR").fontSize(14);
  plot.drawCurve(time, model.get_vS()).label("Susceptible").lineColor("pink");
  plot.drawCurve(time, model.get_vI()).label("Infected").lineColor("purple");
  plot.drawCurve(time, model.get_vR()).label("Removed").lineColor("blue");

  basic_plot(plot, "General graph");
}

// graphic visualisation
void basic_plot(sciplot::Plot2D plot, std::string const& title) {
  plot.xlabel("time").fontSize(8);

  plot.size(360, 200)
      .legend()
      .atOutsideBottom()
      .fontSize(10)
      .displayHorizontal()
      .displayExpandWidthBy(2);

  sciplot::Figure fig = {{plot}};
  sciplot::Canvas myCanvas = {{fig}};
  myCanvas.title(title);
  myCanvas.show();
}
