# qbRayTrace

Welcome to my new series on building a ray tracer from scratch in C++ with the SDL2 library! Follow me in this 'code with me' style series as I build a simple but functional ray tracer from scratch in C++. As far as possible, I use only the standard libraries, with the addition of SDL2 to allow the display of the final image in a window. 

**Note that the SDL2 library is not included here, you will have to obtain and install that yourself from the SDL2 website in order to use the qbRayTrace code.

The code corresponding to each episode of the video series is in the corresponding sub-folder, so Ep1Code for episode 1, Ep2Code for episode 2 and so on. Each of these is intended to be stand-alone and the code for that specific episode can be compiled with the makefile in the folder and run.

This code is intended to be primarily for educational purposes and to be studied alongside the corresponding videos on the QuantitativeBytes YouTube channel.

As the code corresponds to specific episodes of the series, pull requests will not be accepted.

The QuantitativeBytes YouTube channel can be found here:
www.youtube.com/c/QuantitativeBytes

Please note that after Episode 10, I stopped putting the code for each episode into a seperate directory / folder and instead all the more recent code is in a new repository at https://github.com/QuantitativeBytes/qbRayTrace2.

## Episode 1

In this first episode I give a basic introduction to how ray tracing works and then go on to put together the basic code that is going to form the core structure of the final project.

https://youtu.be/JN5yUrJPThI

## Episode 2

In this episode I go over the basic geometry of the virtual camera that we use to actually make ray tracing work. We take a look at the basic geometry and how it works and then go on to look at how to implement that in C++ code.

https://youtu.be/KBK6g6RFgdA

Note that for this episode and beyond, the qbLinAlg repository code is also included.

## Episode 3

This episode focuses on ray-sphere intersection and the problem of how to compute the location of the intersection. We then go on to look at how to write code to actual implement this to allow us to produce our first, very simple, image of a sphere shaded by distance from the camera.

https://youtu.be/8fWZM8hCX5E

## Episode 4

In this episode we extend our code to allow support for multiple objects and add support for simple point lights, going on to produce an image of the red sphere shaded by the light of a single point source. We will go on to build on this in later episodes, adding greater complexity as we go, but we are already producing an image that is starting to look a bit more interesting!

https://youtu.be/dUtkihuUvvo

## Episode 5

In this episode of my series on writing a ray tracer in C++ with the SDL2 library, I cover the topic of geometric transforms and how we can move between local and world coordinate systems. I show how to build a class to allow us to work with geometric transforms easily and then use this to allow us to not only position objects anywhere in our scene, but also to scale them by different amounts on each axis. Although we can still only render spheres at the moment, we can now scale them unevenly to give ovoid shapes. This approach of defining objects in a local coordinate system and then transforming that into the world coordinate system makes it much easier to create more complex shapes such as cones and cylinders, as we will see in later episodes.

https://youtu.be/-Apu2BNp3t8

## Episode 6

Continuing with the series of writing a ray tracer from scratch using C++ and the SDL2 library, this episode focuses on implementing planes. Spheres and planes are the staple of ray tracing tutorials, as they are the most easy shapes to implement. But, the geometric transform code that we created in the last episode makes implementing planes even easier because we can define the object in it's own, local coordinate system. We also take a look at the lighting code and modify that so that objects cast shadows and we modify the image handling code to automatically take care of the dynamic range for us.

https://youtu.be/9K9ZYq6KgFY

## Episode 7

Continuing with the series of writing a ray tracer from scratch using C++ and the SDL2 library, this episode focuses on how to implement basic materials. We take a look at the theory of modelling diffuse shading, specular highlights based on the Phong model and reflections. These can be combined in different combinations to give the effect of different materials for objects. We also take some time to re-arrange the code base to make it tidier as we add more files, which will be especially useful later on.

https://youtu.be/F5vIgpRF_Qo

## Episode 8

Continuing with the series of writing a ray tracer from scratch using C++ and the SDL2 library, this episode focuses on how to implement some different shapes, in particular cones and cylinders. This is made relatively easy by the geometric transform work that we did back in Episode 5 which allows us to only worry about creating a unit cylinder or cone located at the origin in the local coordinate system. These are then transformed back into the global coordinate system to get the final result. Implementing cones and cylinders in this way gives a good example of how we can implement any surface that we can define in the implicit form.

https://youtu.be/UTz7ytMJ2yk

## Episode 9

This episode focuses on UV space (or UV unwrapping) and how we can map textures onto the surfaces of our shapes. I introduce the basic theory of UV unwrapping and explain how it can be applied in the context of ray tracing before going on to show how to modify the ray tracing code that we have developed so far over this series to implement basic texture mapping. This finally allows us to produce a more 'classical' looking ray-traced image with a chequered floor! 

https://youtu.be/d35gDi98gEY

## Episode 10

Continuing with my series on writing a ray tracing in C++ using, as far as possible, only the standard libraries (and the SDL2 library to display results in a window), this episode focuses on how we can implement basic refractive materials such as glass or water. As usual, I start with a simple explanation of what refraction is and show some of the mathematics behind it before going on to show how to add this feature to the qbRayTracer project.

Note that this also includes the code for Episode 9a (Image Textures).

Episode 9a - https://youtu.be/lGTa8ceYIjA
Episode 10 - https://youtu.be/6slB1euGMFw
