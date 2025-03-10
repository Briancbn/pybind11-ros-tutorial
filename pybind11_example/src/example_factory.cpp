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

#include <iostream>

#include "pybind11_example/example_factory.hpp"
#include "pybind11_example/example_product.hpp"

namespace pybind11_example
{

Factory::Factory() {
}

Factory::~Factory() {
}

void Factory::add_product(
  const Product::Ptr & product
) {
  if (!product) {
    return;
  }
  products_.push_back(product);
}

void Factory::print_all_products() const {
  for (auto & product : products_) {
    std::cout << "type: [" << product->type() << "], id: [" << product->id() << "]" << std::endl;
  }
}

bool Factory::inspect_all_products(std::string * error) const {
  bool result = true;
  for (auto & product : products_) {
    std::string product_error;
    if (!product->inspect(&product_error)) {
      result = false;

      if (error != nullptr) {
        *error += "type: [" + product->type() + "], id: ["
          + product->id() + "] error: " + product_error + "\n";
      }
    }
  }

  return result;
}

}  // namespace pybind11_example
