# File: CMakeLists.txt
#----------------------------------------------------------------------------
# Setup the project
#
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(some_project)
#Встановлення імені вихідного бінарника
set(EXE_NAME exgps)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Додаємо сорси та хідери (.cpp .h) для цього проекту
#знайти всі файли типу .cc/cpp в директорії src та додати до проекту:
#знайти всі файти типу .hh/.h в директорії include та додати до проекту:
file(GLOB sources_cc ${CMAKE_SOURCE_DIR}/src/*.cc)
file(GLOB headers_hh ${CMAKE_SOURCE_DIR}/include/*.hh)
file(GLOB sources_cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB headers_h${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB proj_cc ${CMAKE_SOURCE_DIR}/*.cc)
file(GLOB proj_cpp ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB proj_C ${CMAKE_SOURCE_DIR}/*.C)
# Якщо є якісь файли окрім директорії src, то їх потрібно дописати в змінну OTHER_SOURCES
#set(OTHER_SOURCES file1.cpp file2.cpp fileN.cpp)
#set(OTHER_HEADERS file1.h file2.h fileN.h)
#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
add_executable(${EXE_NAME} 
${proj_cpp} ${proj_cc} ${proj_C}
 ${sources_cc} ${sources_cpp} ${headers_h} ${headers_hh}
 ${OTHER_SOURCES} ${OTHER_HEADERS})
target_link_libraries(${EXE_NAME} ${Geant4_LIBRARIES})

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build N01. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(COPY_SCRIPTS

  )

foreach(_script ${COPY_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()
