solution "IT5102E_OpenGL_Project"
    configurations { "Release" }
    
    buildoptions { "-std=c++11", "-Wall", "-Wextra" }
    
    project "project.out"
        kind "WindowedApp"
        language "C++"
        includedirs { "src" }
        files { "src/*.cpp", "src/*.hpp" }
        location "build"
        links { "glfw", "GL", "GLEW", "assimp" }
