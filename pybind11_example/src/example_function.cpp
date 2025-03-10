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
#include "pybind11_example/example_function.hpp"

namespace pybind11_example
{

int add(int i, int k) {
  return i + k;
}

void say(const char * word) {
  std::cout << word << std::endl;
}

void say(const std::string & word) {
  say(word.c_str());
}

void say(const std::vector<std::string> & words) {
  for (auto & word : words) {
    say(word);
  }
}

void count(size_t total) {
  size_t counter = 0;
  while (counter < total) {
    counter++;
  }

  std::cout << counter << std::endl;
}
}  // namespace pybind11_example
