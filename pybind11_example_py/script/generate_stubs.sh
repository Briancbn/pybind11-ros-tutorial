#!/bin/bash

(cd script && \
  pybind11-stubgen pybind11_example -o ../
)

