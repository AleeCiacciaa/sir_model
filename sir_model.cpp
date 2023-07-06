#include "sir_model.hpp"

#include <cmath>
#include <iostream>
#include <vector>

Model::Model(int s, int i, int r, double beta, double gamma, int t)
    : s{s}, i{i}, r{r}, beta{beta}, gamma{gamma}, t{t}, n{s + i + r}, vS{s}, vI{i}, vR{r} {}

// for changing the values of s, i and r
void Model::update() {
  double beta_double = round((beta * s * i) / n);
  double gamma_double = round(gamma * i);

  s -= beta_double;
  i += (beta_double - gamma_double);
  r += gamma_double;

  vS.push_back(s);
  vI.push_back(i);
  vR.push_back(r);
}

// checks if the pandemic is in expansion (if in contraction return false)
bool Model::isExpanding(int argS) { return (beta * argS / n) > gamma; }

// print out the day the pandemic changes its trend
void Model::pandemic_trend(int x) {
  if (isExpanding(vS[x]) && x == 0) {
    std::cout << "\nThe pandemic is in expansion at [Day " << x << "].\n";
  }

  if (!isExpanding(vS[x]) && x == 0) {
    std::cout << "\nThe pandemic is in contraxtion at [Day " << x << "].\n";
  }

  if (isExpanding(vS[x - 1]) != isExpanding(vS[x]) && x != 0) {
    std::cout << "The pandemic is in contraction at [Day " << x << "].\n";
  }
}

// for showing off final result
void Model::final_result() {
  int x;
  for (x = 0; x < t; x++) {
    pandemic_trend(x);

    int old_s = s;
    int old_i = i;

    update();

    if (old_s == s && old_i == i) {  // it stops the program because of the semplicity of the model
      std::cout << "\n[Day " << x << "]  S: " << s << ", I: " << i << ", R: " << r << "\n";
      std::cout << "\n\nDue to the semplicity of this model, the analysis cannot go "
                   "further.\n"
                << "It has been interrupted on this day, sorry :(\n\n";
      break;
    }
  }

  if (x == t) {
    std::cout << "\n[Day " << t << "]  S: " << s << ", I: " << i << ", R: " << r << "\n\n";
  }
}

// for showing off every day evolution
void Model::time_evolution() {
  std::cout << "\n[Day 0]  S: " << s << ", I: " << i << ", R: " << r;

  if (isExpanding(vS[0])) {
    std::cout << "  --> The pandemic is in expansion.\n";
  } else {
    std::cout << "  --> The pandemic is in contraction.\n";
  }

  for (int j = 1; j <= t; j++) {
    update();

    if (vS[j - 1] == s && vI[j - 1] == i) {
      std::cout << "\n\nDue to the semplicity of this model, the analysis cannot go "
                   "further.\n"
                << "It has been interrupted on this day, sorry :(\n\n";
      break;
    }

    std::cout << "\n[Day " << j << "]  S: " << s << ", I: " << i << ", R: " << r;

    if (isExpanding(vS[j - 1]) != isExpanding(vS[j])) {
      std::cout << "  --> The pandemic is in contraction.";
    }
    std::cout << "\n";
  }

  std::cout << "\n";
}

int Model::get_s() const { return s; }

int Model::get_i() const { return i; }

int Model::get_r() const { return r; }

double Model::get_beta() const { return beta; }

double Model::get_gamma() const { return gamma; }

int Model::get_n() const { return n; }

int Model::get_t() const { return t; }

std::vector<int> Model::get_vS() const { return vS; }

std::vector<int> Model::get_vI() const { return vI; }

std::vector<int> Model::get_vR() const { return vR; }
