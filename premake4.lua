-- A solution contains projects, and defines the available configurations
solution "Zombie Walk"
   configurations { "Debug", "Release" }
   includedirs {"/usr/local/include", "include", "lib"}
   links {"SDL2", "SDL2_image" }
   libdirs {"/usr/local/lib", "lib"}
   kind "ConsoleApp"
   buildoptions {"-Wall", "-std=c++11" }
   language "C++"
 
   -- A project defines one build target
   project "zombie_walk"
      files { "**.h", "**.cpp" }
      excludes { "test/*" }
 
      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }

    project "test"
        files { "src/**.h", "src/**.cpp", "test/**.cpp", "lib/gtest/gtest_main.cc" }
        includedirs {"/usr/local/include", "lib"}
