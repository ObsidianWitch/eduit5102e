solution "IT5102E_OpenGL_Project"
    configurations { "Release" }
    
    buildoptions { "-std=c++11", "-Wall", "-Wextra" }
    
    project "project.out"
        kind "WindowedApp"
        language "C++"
        includedirs { "src" }
        files {
            "src/*.cpp", "src/*.hpp",
            "src/inputs/*.cpp", "src/inputs/*.hpp",
            "src/models/*.cpp", "src/models/*.hpp",
            "src/shaders/*.cpp", "src/shaders/*.hpp",
            "src/camera/*.cpp", "src/camera/*.hpp",
            "src/entities/*.cpp", "src/entities/*.hpp",
            "src/tools/*.cpp", "src/tools/*.hpp"
        }
        location "build"
        links { "glfw", "GL", "GLEW", "assimp" }
