cmake_minimum_required(VERSION 3.20)

project(imgui-nvrhi-binding)

find_package(imgui CONFIG REQUIRED)
find_package(nvrhi CONFIG REQUIRED)

add_library(imgui-nvrhi-binding STATIC imgui_nvrhi_binding.cpp )
target_link_libraries(imgui-nvrhi-binding PUBLIC
    imgui::imgui
    nvrhi
)


add_executable(example main.cpp)
target_link_libraries(example PUBLIC
    imgui-nvrhi-binding
)
