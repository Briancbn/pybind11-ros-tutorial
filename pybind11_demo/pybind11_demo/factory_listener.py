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

import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from std_msgs.msg import String
from std_srvs.srv import Empty


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


class FactoryListener(Node):

    def __init__(self):
        super().__init__('listener')
        self._factory = Factory()
        self._product = []
        self.truck_sub = self.create_subscription(String, 'add_truck', self.add_truck_callback, 10)
        self.car_sub = self.create_subscription(String, 'add_car', self.add_car_callback, 10)
        self.srv = self.create_service(Empty, 'inspect', self.inspect_callback)

    def inspect_callback(self, request, response):
        print("Inspecting")
        result, error = self._factory.inpect_all_products()
        if not result:
            print("Inspection failed")
            print(error)

        else:
            print("Inspection completed successfully")
        return response

    def add_truck_callback(self, msg):
        product = LegacyTruck(msg.data)
        self._factory.add_product(product)
        print("Inventory updated")
        self._factory.print_all_products()
        self._product.append(product)

    def add_car_callback(self, msg):
        self.get_logger().info('Add car: [%s]' % msg.data)
        product = Car(msg.data)
        self._factory.add_product(product)
        print("Inventory updated")
        self._factory.print_all_products()
        self._product.append(product)


def main(args=None):
    rclpy.init(args=args)
    node = FactoryListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
