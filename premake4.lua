-- A solution contains projects, and defines the available configurations
solution "Zombie Walk"
   configurations { "Debug", "Release" }
 
   -- A project defines one build target
   project "zombie_walk"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "**.cpp" }
      excludes { "test/*" }
      links {"SDL2", "SDL2_image"}
      libdirs {"/usr/local/lib"}
      includedirs {"/usr/local/include", "include", "lib"}
      buildoptions {"-Wall", "-std=c++11" }
 
      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }

    project "test"
        kind "ConsoleApp"
        language "C++"
        files { "src/**.h", "src/**.cpp", "test/**.cpp", "lib/gtest/gtest_main.cc" }
        links {"SDL2", "SDL2_image" }
        libdirs {"/usr/local/lib", "lib"}
        includedirs {"/usr/local/include", "lib"}
        buildoptions {"-Wall", "-std=c++11" }
