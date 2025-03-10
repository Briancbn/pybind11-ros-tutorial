# Copyright 2025 Chen Bainian
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from typing import Tuple
from pybind11_example import Product, Factory

class Car(Product):
    def __init__(
        self,
        product_id: str,
        *,
        defective: bool = False
    ):
        super().__init__()
        self._id = product_id;
        self._defective = defective

    def type(self) -> str:
        return "car"

    def id(self) -> str:
        return self._id

    def inspect(self) -> Tuple[bool, str]:
        if self._defective:
            return False, "This product is defective!"

        return True, ""


class LegacyTruck(Product):
    def __init__(
        self,
        product_id: str,
    ):
        super().__init__()
        self._id = product_id;

    def type(self) -> str:
        return "truck"

    def id(self) -> str:
        return self._id

    def inspect(self) -> Tuple[bool, str]:
        return False, "This product is discontinued!"


def main():
    products = [
        Car("p1"),
        Car("p2", defective=True),
        Car("p3"),
        Car("p4"),
        LegacyTruck("t1"),
        LegacyTruck("t2"),
    ]
    factory = Factory()

    for product in products:
        factory.add_product(product)

    print("Product list:")
    factory.print_all_products()
    print("\nInspecting...")
    result, error = factory.inpect_all_products()
    if not result:
        print("Failed, error:")
        print(error)

    else:
        print("Success")

