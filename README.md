# IT5102E OpenGL Sandbox

![Screenshot](https://i.imgur.com/bf14MUA.jpg)

## Dependencies

* [premake4](https://premake.github.io/)
* [GLFW](http://www.glfw.org/)
* [GLEW](http://glew.sourceforge.net/)
* [GLM](http://glm.g-truc.net/0.9.7/index.html)
* [SOIL](http://www.lonesock.net/soil.html)
* [Assimp](https://github.com/assimp/assimp)
* [webgl-noise](https://github.com/ashima/webgl-noise) (`includes/webgl-noise`)

## Build instructions

```
> premake4 gmake
> make -j4
> ./project.out
```

## Controls

| Inputs                        | Actions                                      |
|-------------------------------|----------------------------------------------|
| up                            | move character forward                       |
| down                          | move character backward                      |
| left                          | rotate character left (around local Y-axis)  |
| right                         | rotate character right (around local Y-axis) |
| left + hold right click       | move character left (strafing)               |
| right + hold right click      | move character right (strafing)              |
| hold left click + move cursor | move camera around character                 |
| space                         | attack loading animation                     |
| alt + space                   | attack release animation                     |

## References

### Tutorials & Resources

* [Learn OpenGL](http://learnopengl.com/)
* [OGLdev](http://ogldev.atspace.co.uk/)
* [Blender Manual](https://www.blender.org/manual/contents.html)
* [Blender3D: UV Map Basics](https://en.wikibooks.org/wiki/Blender_3D:_Noob_to_Pro/UV_Map_Basics)
* [Blendswap](http://blendswap.com/)

### Credits

* [Elf Girl](https://sketchfab.com/models/52f2e84961b94760b7805c178890d644)
by [halloween](https://sketchfab.com/yellow09)
([CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/))
* [3 Low Poly Cliffs](http://www.blendswap.com/blends/view/71140)
by [OliverMH](http://www.blendswap.com/user/OliverMH)
([CC-BY 3.0](https://creativecommons.org/licenses/by/3.0/))
* [Cartoon Forest Tree](http://www.blendswap.com/blends/view/68465)
by [Explosive James](http://www.blendswap.com/user/Explosive+James)
([CC-BY 3.0](https://creativecommons.org/licenses/by/3.0/))
* [Rocks texture](http://eolneth.deviantart.com/art/Rocks-Tileable-Texture-213561648)
by [eolneth](http://eolneth.deviantart.com/)
([CC-BY-NC-ND 3.0](https://creativecommons.org/licenses/by-nc-nd/3.0/))
* [Ground texture](http://huaban.com/pins/262883374/)
* [Skybox](http://reije081.home.xs4all.nl/skyboxes/index.html)
([CC-BY-NC-SA 3.0](https://creativecommons.org/licenses/by-nc-sa/3.0/))
* [Belkan Triangle](http://nanoha.wikia.com/wiki/File:Belkan_Triangle.png)
* [Midchildan Circle](http://nanoha.wikia.com/wiki/File:DSC8209.png)
