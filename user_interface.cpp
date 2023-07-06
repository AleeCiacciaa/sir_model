#include "user_interface.hpp"

#include <iostream>

#include "sir_model.hpp"
#include "sir_model_graph.hpp"

Model make_model() {
  int s, i, r, t;
  double beta, gamma;
  bool insertionErr;  // it checks for user's errors

  // in case an exception has been raised the user has the possibility of insert again the values
  do {
    insertionErr = true;

    try {
      std::cout << "\nWelcome to the evolution of pandemic's program.\n";
      std::cout << "Provide the number of susceptible: ";
      std::cin >> s;
      if (s <= 0) throw(s);  // number of people has to be positive

      std::cout << "Provide the number of infected: ";
      std::cin >> i;
      if (i <= 0) throw(i);  // number of people has to be positive

      std::cout << "Provide the number of removed: ";
      std::cin >> r;
      if (r <= 0) throw(r);  // number of people has to be positive

      std::cout << "Provide probability of infection: ";
      std::cin >> beta;
      if (beta < 0. || beta > 1.)
        throw(beta);  // it has to be between 0 and 1 because it is a probability

      std::cout << "Provide probability of recovery: ";
      std::cin >> gamma;
      if (gamma < 0. || gamma > 1.)
        throw(gamma);  // it has to be between 0 and 1 because it is a probability

      if (beta / gamma <= 1.) throw(false);  // otherwise the pandemic will not start

      std::cout << "Provide the time span: ";
      std::cin >> t;
      if (t <= 0) throw(t);  // time has to be positive
    }

    catch (int Error_int) {  // every integer must be positve
      std::cout << "\nYou insert an invalid argument: all the values must be "
                   "positive. \nStart again. \n\n";
      insertionErr = false;
    }

    catch (double Error_double) {  // every double must be between 0 and 1
      std::cout << "\nYou insert an invalid argument: beta and gamma must be "
                   "between 0 and 1. \nStart again. \n\n";
      insertionErr = false;
    }

    catch (bool Error_bool) {  // bolean catcher for cheching that the pandemic starts
      std::cout << "\nYou insert an invalid argument: probability of infection must "
                   "be bigger than probability of recovery. \nStart again. \n\n";
      insertionErr = false;
    }

    catch (...) {  // default catcher
      std::cout << "\nError: you insert an invalid argument. \nStart again. \n\n";
      insertionErr = false;
    }
  } while (!insertionErr);

  return Model(s, i, r, beta, gamma, t);
}

// calls the function for the pandemic model's trend visualisation chosen by the user
void decision_1(Model& model) {
  int dec_1;

  std::cout << "\nPress: \n";
  std::cout << "[1] If you want to see just the final result.\n";
  std::cout << "[2] If you want to see the evolution of the pandemic day by day.\n\n";
  std::cin >> dec_1;

  switch (dec_1) {
    case 1:
      model.final_result();
      break;
    case 2:
      model.time_evolution();
      break;
    default:
      throw std::invalid_argument("Received an invalid number");
  }
}

// asks the user if he wants to visualise a graph
void decision_2(Model const& model) {  // prova a fare con booleani
  char dec_2;

  std::cout << "Do you want to see the graph? (Y/N) \n";
  std::cin >> dec_2;

  if (dec_2 == 'Y' || dec_2 == 'y') {
    decision_3(model);
  }

  else if (dec_2 == 'N' || dec_2 == 'n') {
    std::cout << "\nOkay, that's all :) \n\n";
  }

  else {
    throw std::invalid_argument("Received an invalid answer");
  }
}

// let the user chose the graph(s)
void decision_3(Model const& model) {
  int dec_3;

  std::cout << "\nPress:\n";
  std::cout << "[1] If you want to see the graph of susceptible.\n";
  std::cout << "[2] If you want to see the graph of infected.\n";
  std::cout << "[3] If you want to see the graph of removed.\n";
  std::cout << "[4] If you want to see the general graph.\n";
  std::cout << "[5] All of the above.\n\n";
  std::cin >> dec_3;

  graph_sir_model(model, dec_3);

  std::cout << "\nThanks for using the program!\n\n";
}
