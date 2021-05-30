#include "sum.h"
#include <iostream>
#include <pybind11/pybind11.h>

using namespace std;

namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  m.def("add", &add, "A function which adds two numbers");
}

int main() {
  int a = 2;
  int b = 3;
  cout << "Sum of "s << a << " and "s << b << " is "s << Sum(a, b) << endl;
  return 0;
}