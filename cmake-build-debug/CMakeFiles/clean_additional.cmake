# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\fractalDrawing_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\fractalDrawing_autogen.dir\\ParseCache.txt"
  "fractalDrawing_autogen"
  )
endif()
