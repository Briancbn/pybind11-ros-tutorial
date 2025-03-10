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

#ifndef PYBIND11_EXAMPLE__EXAMPLE_CLASS_HPP_
#define PYBIND11_EXAMPLE__EXAMPLE_CLASS_HPP_

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace pybind11_example
{

struct User
{
  using Ptr = std::shared_ptr<User>;
  using ConstPtr = std::shared_ptr<const User>;

  User() = default;
  virtual ~User() = default;

  // Not copiable
  User(const User &) = delete;
  User & operator=(const User &) = delete;


  std::string name;
  std::vector<std::string> data;

  inline bool operator==(const User & rhs) const
  {
    if (this->name != rhs.name) {return false;}
    if (this->data != rhs.data) {return false;}
    return true;
  }

  inline bool operator!=(const User & rhs) const
  {
    return !(*this == rhs);
  }

};

class Group
{
public:
  using Ptr = std::shared_ptr<Group>;
  using ConstPtr = std::shared_ptr<const Group>;

  explicit Group(const std::string & name);
  // Not copiable
  Group(const Group &) = delete;
  Group & operator=(const Group &) = delete;
  virtual ~Group();

  User::Ptr add_user(
    const std::string & name,
    const std::vector<std::string> & data
  );

  void add_user(const User::Ptr & user);

  void remove_user(
    const std::string & name
  );

  void remove_user(
    const User::Ptr & name
  );

  const std::string & name() const;

  User::ConstPtr get_user(const std::string & name) const;

  User::ConstPtr get_user(const char * name) const;

  bool get_user_no_throw(
    const std::string & name,
    User::ConstPtr * user,
    std::string * error
  ) const;

private:
  std::string name_;
  std::unordered_map<std::string, User::Ptr> user_map_;
};

}  // namespace pybind11_example

#endif  // PYBIND11_EXAMPLE__EXAMPLE_CLASS_HPP_
