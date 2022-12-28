cmake_minimum_required(VERSION 3.23)
project(Nedozhdii_FI_03_lab3_SpRzOM)

set(CMAKE_CXX_STANDARD 17)

include_directories("SpRzOM CP3")

add_executable(Nedozhdii_FI_03_lab3_SpRzOM
#        "SpRzOM CP3/Field.cpp"
#        "SpRzOM CP3/Field.h"
#        "SpRzOM CP3/main.cpp"
        "SpRzOM CP4/main.cpp"
        "SpRzOM CP4/NB.cpp"
        "SpRzOM CP4/NB.h")
