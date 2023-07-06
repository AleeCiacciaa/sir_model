#ifndef SIR_MODEL_HPP
#define SIR_MODEL_HPP

#include <vector>

class Model {
 private:
  int s;         // suscetible
  int i;         // infected
  int r;         // removed
  double beta;   // probability of infection
  double gamma;  // probability of recovery
  int t;         // time span
  const int n;   // total of the polulation

  std::vector<int> vS;  // time serie of suscetible
  std::vector<int> vI;  // time serie of infected
  std::vector<int> vR;  // time serie of removed

 public:
  Model(int s, int i, int r, double beta, double gamma, int t);

  void update();
  bool isExpanding(int argS);

  void final_result();
  void time_evolution();
  void pandemic_trend(int x);

  int get_s() const;
  int get_i() const;
  int get_r() const;
  double get_beta() const;
  double get_gamma() const;
  int get_n() const;
  int get_t() const;

  std::vector<int> get_vS() const;
  std::vector<int> get_vI() const;
  std::vector<int> get_vR() const;
};

#endif
