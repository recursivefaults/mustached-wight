-- A solution contains projects, and defines the available configurations
solution "Zombie Walk"
   configurations { "Debug", "Release" }
 
   -- A project defines one build target
   project "Zombie Walk"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "**.cpp" }
      links {"SDL2", "SDL2_image"}
      libdirs {"/usr/local/lib"}
      includedirs {"/usr/local/include"}
      buildoptions {"-Wall", "-std=c++11" }
 
      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }
