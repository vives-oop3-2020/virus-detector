#include "corona-detector.h"

namespace Pandemic {

  CoronaDetector::CoronaDetector(void)
    : CoronaDetector("Anonymous") {
  }

  CoronaDetector::CoronaDetector(std::string name)
    : CoronaDetector(name, 36.7) {
  }

  CoronaDetector::CoronaDetector(std::string name, double temperature) {
    this->name = name;
    this->temperature = temperature;
  }

  std::string CoronaDetector::get_name(void) {
    return name;
  }

  bool CoronaDetector::is_infected(double temperature) {
    this->temperature = temperature;
    return is_infected();
  }

  bool CoronaDetector::is_infected(void) {
    return temperature > 38.2;
  }

};