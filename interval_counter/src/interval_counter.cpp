#include <stdio.h>

#include <argparse.hpp>


int interval_counter(int start, int end) {
  int sum = 0;
  for (int i = start; i < end; i++) sum++;  // For loop to be able to time it
  return sum;
}


int main(int argc, char** argv ) {
  argparse::ArgumentParser parser("C++ module test");
  parser.add_argument("start").required().action([](const std::string& value) { return std::stoi(value); }).help("From where to start looking for primes");
  parser.add_argument("end").required().action([](const std::string& value) { return std::stoi(value); }).help("Where to stop");

  try {
    parser.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
    std::cout << err.what() << std::endl;
    std::cout << parser;
    exit(0);
  }

  int start = parser.get<int>("start");
  int end = parser.get<int>("end");

  int sum = interval_counter(start, end);
  std::cout << "Works fine!" << std::endl;
  std::cout << sum << std::endl;
}
