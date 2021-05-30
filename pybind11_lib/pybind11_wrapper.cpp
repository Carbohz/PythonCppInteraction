#include <pybind11/pybind11.h>
#include "wrapped_sum.h"

PYBIND11_MODULE(example, m) {
 m.doc() = "pybind11 example plugin"; // optional module docstring

 // m.def("add", &Sum, "A function which adds two numbers");
 m.def("wrapped_add", &WrappedSum, "A function which calls Sum function in it's implementation");
}