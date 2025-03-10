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

#include "pybind11_example_py/example_product.hpp"
#include "pybind11_example/example_product.hpp"

namespace pybind11_example
{

class PyProduct : public Product
{
public:
  // Inherit the constructor
  using Product::Product;

  // Trampoline
  std::string type() const override {
    PYBIND11_OVERRIDE_PURE(
        std::string,
        Product,
        type
    );
  }

  // Trampoline
  std::string id() const override {
    PYBIND11_OVERRIDE_PURE(
        std::string,
        Product,
        id
    );
  }

  // Custom Trampoline
  bool inspect(std::string * error) const override {

    pybind11::gil_scoped_acquire gil;  // Acquire the GIL while in this scope.

    // Try to look up the overridden method on the Python side.
    pybind11::function override = pybind11::get_override(this, "inspect");

    if (!override) {
      if (error != nullptr) {
        *error = "inspect failed: cannot find defined Python function";
      }
      return false;
    }

    auto obj = override();
    if (!py::isinstance<py::tuple>(obj)) {
      if (error != nullptr) {
        *error = "inspect failed: Invalid Python return type.";
      }
      return false;
    }

    py::tuple tuple_obj = obj;
    if (py::len(tuple_obj) != 2) {
      if (error != nullptr) {
        *error = "inspect failed: Invalid Python number of returns.";
      }
      return false;
    }

    bool result = tuple_obj[0].cast<bool>();
    if (!result) {
      if (error != nullptr) {
        *error = tuple_obj[1].cast<std::string>();
      }
      return false;
    }

    return true;
  }
};

}  // namespace pybind11_example

namespace pybind11_example_py
{

void init_example_product_py(py::module & m) {
  using namespace pybind11_example;  // NOLINT(build/namespaces)

  py::class_<Product, PyProduct, Product::Ptr>(
    m,
    "Product",
    "A class for Product"
  )
  .def(py::init<>())  // Constructor
  .def(
    "type",
    &Product::type
  )
  .def(
    "id",
    &Product::id
  )
  .def(
    "inpect",
    [](
      Product & self
    ) {
      std::string error;
      bool result = self.inspect(&error);

      return std::make_tuple(result, error);
    }
  )
  ;
}

}  // namespace pybind11_example_py
