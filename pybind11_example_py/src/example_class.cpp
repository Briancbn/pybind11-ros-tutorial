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
#include <pybind11/operators.h>

#include "pybind11_example_py/example_class.hpp"
#include "pybind11_example/example_class.hpp"

namespace pybind11_example_py
{

void init_example_class_py(py::module & m) {
  using namespace pybind11_example;  // NOLINT(build/namespaces)

  py::class_<User, User::Ptr>(
    m,
    "User",
    "A class for User"
  )
  .def(py::init<>())  // Constructor
  .def_readwrite(
    "name",
    &User::name
  )
  .def_readwrite(
    "data",
    &User::data
  )
  .def(py::self == py::self)
  .def(py::self != py::self)
  ;

  py::class_<Group, Group::Ptr>(
    m,
    "Group",
    "A class for Group"
  )
  .def(py::init<const std::string &>(), py::arg("name"))  // Constructor
  .def(
    "add_user",
    py::overload_cast<const std::string &, const std::vector<std::string> &>(
      &Group::add_user
    ),
    py::arg("name"),
    py::arg("data")
  )
  .def(
    "add_user",
    py::overload_cast<const User::Ptr &>(
      &Group::add_user
    ),
    py::arg("user")
  )
  .def(
    "remove_user",
    py::overload_cast<const std::string &>(
      &Group::remove_user
    ),
    py::arg("name")
  )
  .def(
    "remove_user",
    py::overload_cast<const User::Ptr &>(
      &Group::add_user
    ),
    py::arg("user")
  )
  .def(
    "name",
    &Group::name
  )
  .def(
    "get_user",
    py::overload_cast<const std::string &>(
      &Group::get_user,
      py::const_
    ),
    py::arg("name")
  )
  .def(
    "get_user_no_throw",
    [](
      Group & self,
      std::string & name
    ) {
      User::ConstPtr user;
      std::string error;
      bool result = self.get_user_no_throw(name, &user, &error);

      return std::make_tuple(result, error, user);
    }
  )
  ;
}

}  // namespace pybind11_example_py
