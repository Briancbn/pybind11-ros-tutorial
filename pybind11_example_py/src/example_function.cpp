// Copyright 2025 Chen Bainian
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <pybind11/stl.h>

#include "pybind11_example_py/example_function.hpp"
#include "pybind11_example/example_function.hpp"

namespace pybind11_example_py
{

void init_example_function_py(py::module & m) {
  using namespace pybind11_example;  // NOLINT(build/namespaces)

  m.def(
    "add",
    &add,
    py::arg("i"),
    py::arg("j")
  );

  m.def(
    "say_c_str",
    py::overload_cast<const char *>(
      &say
    ),
    py::arg("word")
  );

  m.def(
    "say",
    py::overload_cast<const std::string &>(
      &say
    ),
    py::arg("word")
  );

  m.def(
    "say",
    py::overload_cast<const std::vector<std::string> &>(
      &say
    ),
    py::arg("words")
  );

  m.def(
    "count",
    &count,
    py::arg("total")
  );
}

}  // namespace pybind11_example_py
