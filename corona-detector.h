#pragma once

#include <string>

namespace Pandemic {

  class CoronaDetector {

    public:
      CoronaDetector(void);
      CoronaDetector(std::string name);
      CoronaDetector(std::string name, double temperature);

    public:
      std::string get_name(void);
      bool is_infected(void);
      bool is_infected(double temperature);

    private:
      std::string name = "";
      double temperature;
  };

};