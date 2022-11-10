project(dpdk-toy)

find_package(PkgConfig REQUIRED)
pkg_check_modules(DPDK REQUIRED IMPORTED_TARGET libdpdk)

add_executable(dpdk-toy toy.cc)

target_link_libraries(dpdk-toy PkgConfig::DPDK)
