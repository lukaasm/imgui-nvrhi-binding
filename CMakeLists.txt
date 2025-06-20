cmake_minimum_required(VERSION 3.20)

project(imgui-nvrhi)

find_package(imgui CONFIG REQUIRED)
find_package(nvrhi CONFIG REQUIRED)

add_library(imgui-nvrhi STATIC imgui_nvrhi_binding.cpp )
target_link_libraries(imgui-nvrhi PUBLIC
    imgui::imgui
    nvrhi
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

install(
    FILES imgui_nvrhi_binding.h
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(
    TARGETS imgui-nvrhi
    EXPORT imguinvrhiTargets
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

configure_file(cmake/imgui-nvrhi-config.cmake.in imgui-nvrhi-config.cmake @ONLY)

write_basic_package_version_file(
    imgui-nvrhi-config-version.cmake
    COMPATIBILITY SameMinorVersion
)

set(
    IMGUI_NVRHI_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/imgui-nvrhi"
    CACHE STRING "CMake package config location relative to the install prefix"
)
mark_as_advanced(SIMDUTF_INSTALL_CMAKEDIR)

install(
    FILES
    "${PROJECT_BINARY_DIR}/imgui-nvrhi-config.cmake"
    "${PROJECT_BINARY_DIR}/imgui-nvrhi-config-version.cmake"
    DESTINATION "${IMGUI_NVRHI_INSTALL_CMAKEDIR}"
)

install(
    EXPORT imguinvrhiTargets
    NAMESPACE imgui-nvrhi::
    DESTINATION "${IMGUI_NVRHI_INSTALL_CMAKEDIR}"
)
