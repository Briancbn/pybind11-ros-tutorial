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

#include <pybind11/pybind11.h>

#include "pybind11_example_py/example_function.hpp"
#include "pybind11_example_py/example_class.hpp"
#include "pybind11_example_py/example_product.hpp"
#include "pybind11_example_py/example_factory.hpp"

PYBIND11_MODULE(core, m)
{
  using namespace pybind11_example_py;  // NOLINT(build/namespaces)

  init_example_function_py(m);
  init_example_class_py(m);
  init_example_product_py(m);
  init_example_factory_py(m);
}
