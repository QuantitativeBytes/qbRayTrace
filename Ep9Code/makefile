# Define the link target.
linkTarget = qbRay

# Define the libraries that we need.
LIBS = -lSDL2

# Define any flags.
CFLAGS = -std=c++17 -Ofast

# Define the object files that we need to use.
objects =	main.o \
					CApp.o \
					$(patsubst %.cpp,%.o,$(wildcard ./qbRayTrace/*.cpp)) \
					$(patsubst %.cpp,%.o,$(wildcard ./qbRayTrace/qbPrimatives/*.cpp)) \
					$(patsubst %.cpp,%.o,$(wildcard ./qbRayTrace/qbLights/*.cpp)) \
					$(patsubst %.cpp,%.o,$(wildcard ./qbRayTrace/qbMaterials/*.cpp)) \
					$(patsubst %.cpp,%.o,$(wildcard ./qbRayTrace/qbTextures/*.cpp))
					
# Define the rebuildables.
rebuildables = $(objects) $(linkTarget)

# Rule to actually perform the build.
$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)
	
# Rule to create the .o (object) files.
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)
	
.PHONEY:
clean:
	rm $(rebuildables)
