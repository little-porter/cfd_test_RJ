# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\cfd_upgrade_app_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cfd_upgrade_app_autogen.dir\\ParseCache.txt"
  "cfd_upgrade_app_autogen"
  )
endif()
