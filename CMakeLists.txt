cmake_minimum_required(VERSION 3.25)
project(fine7)

set(CMAKE_CXX_STANDARD 14)

add_executable(fine7 main.cpp populatePlats.cpp populatePlats.h stru.h movePlats.cpp movePlats.h generatePlats.cpp generatePlats.h overlapnig_detector.cpp overlapnig_detector.h )

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(fine7 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)