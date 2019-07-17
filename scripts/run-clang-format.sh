#!/bin/bash
clang-format -verbose -i -style=file src/*.cpp
clang-format -verbose -i -style=file test/*.cpp
clang-format -verbose -i -style=file include/*.hpp
clang-format -verbose -i -style=file examples/*/*.hpp
clang-format -verbose -i -style=file examples/*/*.cpp
