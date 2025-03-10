cmake_minimum_required(VERSION 3.5)
project(pybind11_example_py)

find_package(ament_cmake REQUIRED)
find_package(pybind11_example REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11_vendor REQUIRED)
find_package(pybind11 REQUIRED)

include_directories(
  include
)

ament_python_install_package(pybind11_example)

pybind11_add_module(core
  src/core.cpp
  src/example_function.cpp
  src/example_class.cpp
  src/example_product.cpp
  src/example_factory.cpp
)

target_link_libraries(core
  PRIVATE
  ${pybind11_example_LIBRARIES}
)

target_include_directories(core
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    ${pybind11_example_INCLUDE_DIRS}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  # Override flake8 config
  set(ament_cmake_flake8_CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/test/ament_flake8.ini)

  ament_lint_auto_find_test_dependencies()

  # add_subdirectory(test)
endif()

install(TARGETS
  core
  DESTINATION "${PYTHON_INSTALL_DIR}/pybind11_example"
)

ament_package()
