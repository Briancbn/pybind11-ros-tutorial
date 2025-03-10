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

#include "pybind11_example/example_class.hpp"

namespace pybind11_example
{

Group::Group(const std::string & name)
: name_(name)
{
}

Group::~Group()
{
}

User::Ptr Group::add_user(
  const std::string & name,
  const std::vector<std::string> & data
)
{
  auto user = std::make_shared<User>();
  user->name = name;
  user->data = data;
  user_map_[name] = user;
  return user;
}

void Group::add_user(
  const User::Ptr & user
)
{
  if (!user) {
    return;
  }

  user_map_[user->name] = user;
}

void Group::remove_user(
  const std::string & name
) {
  user_map_.erase(name);
}

void Group::remove_user(
  const User::Ptr & user
) {
  if (!user) {
    return;
  }
  user_map_.erase(user->name);
}

const std::string & Group::name() const
{
  return name_;
}

User::ConstPtr Group::get_user(const std::string & name) const
{
  return user_map_.at(name);
}

User::ConstPtr Group::get_user(const char * name) const
{
  return user_map_.at(std::string(name));
}

bool Group::get_user_no_throw(
  const std::string & name,
  User::ConstPtr * user,
  std::string * error
) const {
  auto itr = user_map_.find(name);
  if (itr == user_map_.end()) {
    if (error != nullptr) {
      *error = "No user [" + name + "] in group [" + name_ + "].";
    }

    return false;
  }

  if (user != nullptr) {
    *user = itr->second;
  }

  return true;
}

}  // namespace pybind11_example
