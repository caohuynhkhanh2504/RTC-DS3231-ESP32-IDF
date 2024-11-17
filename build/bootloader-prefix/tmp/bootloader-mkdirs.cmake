# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Espressif/frameworks/esp-idf-v4.4.6/components/bootloader/subproject"
  "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader"
  "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader-prefix"
  "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader-prefix/tmp"
  "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader-prefix/src/bootloader-stamp"
  "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader-prefix/src"
  "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/VIAM_LAB/Set-Time-RTC-master/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
