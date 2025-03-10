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

#ifndef PYBIND11_EXAMPLE_PY__EXAMPLE_FACTORY_HPP_
#define PYBIND11_EXAMPLE_PY__EXAMPLE_FACTORY_HPP_

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace pybind11_example_py
{

void init_example_factory_py(py::module & m);

}  // namespace pybind11_example_py

#endif  // PYBIND11_EXAMPLE_PY__EXAMPLE_FACTORY_HPP_
