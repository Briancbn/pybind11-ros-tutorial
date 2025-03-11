from setuptools import find_packages
from setuptools import setup

package_name = 'pybind11_demo'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
    ],
    install_requires=['pybind11_demo'],
    zip_safe=True,
    author='Chen bainian',
    author_email='chenbn@artc.a-star.edu.sg',
    maintainer='Chen Bainian',
    maintainer_email='chenbn@artc.a-star.edu.sg',
    keywords=[],
    classifiers=[
        'Environment :: Console',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python',
    ],
    description='A simple demo using pybind11',
    long_description="""\
The package provides the node command for the ROS 2 command line tools.""",
    license='Apache License, Version 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'count_1b_py = pybind11_demo.count_1b_py:main',
            'count_1b_pybind = pybind11_demo.count_1b_pybind:main',
            'factory_inspect = pybind11_demo.factory_inspect:main',
            'factory_listener = pybind11_demo.factory_listener:main',
        ],
    }
)
