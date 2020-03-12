#include <iostream>
#include <vector>

#include "corona-detector.h"

using namespace std;

int main(void) {
  cout << "Welcome to sensors" << endl;

  // Pandemic::CoronaDetector detector("Loete");
  // if (detector.is_infected(40)) {
  //   cout << detector.get_name() << " may be infected" << endl;
  // } else {
  //   cout << detector.get_name() << " is probable in the clear" << endl;
  // }

  std::vector<Pandemic::CoronaDetector *> people;

  bool keepAsking = true;
  do {
    std::string name;
    cout << "Please enter persons name (STOP to stop): ";
    cin >> name;

    if (name != "STOP") {
      double temperature = 0;
      cout << "Please enter temperature of " << name << ": ";
      cin >> temperature;

      Pandemic::CoronaDetector * detector
        = new Pandemic::CoronaDetector(name, temperature);

      people.push_back(detector);
    } else {
      keepAsking = false;
    }
  } while(keepAsking);

  // Afterwards
  for (unsigned int i = 0; i < people.size(); i++) {
    Pandemic::CoronaDetector * detector = people[i];

    if (detector->is_infected()) {
      cout << detector->get_name() << " may be infected" << endl;
    } else {
      cout << detector->get_name() << " is probable in the clear" << endl;
    }
  }

  // De-allocate detectors
  for (unsigned int i = 0; i < people.size(); i++) {
    delete people[i];   // Each detector
  }
  people.clear();   // Remove pointers from vector



  return 0;
}