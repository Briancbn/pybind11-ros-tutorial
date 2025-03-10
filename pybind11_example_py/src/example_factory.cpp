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

#include "pybind11_example_py/example_factory.hpp"
#include "pybind11_example/example_product.hpp"
#include "pybind11_example/example_factory.hpp"

namespace pybind11_example_py
{

void init_example_factory_py(py::module & m) {
  using namespace pybind11_example;  // NOLINT(build/namespaces)

  py::class_<Factory, Factory::Ptr>(
    m,
    "Factory",
    "A class for Factory"
  )
  .def(py::init<>())  // Constructor
  .def(
    "add_product",
    &Factory::add_product,
    py::arg("product")
  )
  .def(
    "print_all_products",
    &Factory::print_all_products
  )
  .def(
    "inpect_all_products",
    [](
      Factory & self
    ) {
      std::string error;
      bool result = self.inspect_all_products(&error);

      return std::make_tuple(result, error);
    }
  )
  ;
}

}  // namespace pybind11_example_py
