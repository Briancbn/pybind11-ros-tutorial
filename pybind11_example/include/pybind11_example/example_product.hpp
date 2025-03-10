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

#ifndef PYBIND11_EXAMPLE__EXAMPLE_PRODUCT_HPP_
#define PYBIND11_EXAMPLE__EXAMPLE_PRODUCT_HPP_

#include <string>
#include <memory>

namespace pybind11_example
{

class Product
{
public:
  using Ptr = std::shared_ptr<Product>;
  using ConstPtr = std::shared_ptr<const Product>;

  // Not copiable
  Product(const Product &) = delete;
  Product & operator=(const Product &) = delete;
  Product() = default;
  virtual ~Product() = default;

  virtual std::string type() const = 0;
  virtual std::string id() const = 0;
  virtual bool inspect(std::string * error) const = 0;
};

}  // namespace pybind11_example

#endif  // PYBIND11_EXAMPLE__EXAMPLE_FUNCTION_HPP_
