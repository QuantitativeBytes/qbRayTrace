# Define the link target.
linkTarget = qbRay

# Define libraries that we need,
LIBS = -lSDL2

# Define flags.
# CFLAGS = -std=c++17 -pg
CFLAGS = -std=c++17

# Define the object files that we need to use.
objects = main.o \
					CApp.o \
					$(patsubst %.cpp,%.o,$(wildcard ./qbRayTrace/*.cpp))
					
# Define the rebuildables.
rebuildables = $(objects) $(linkTarget)

# Rule to actually perform the build.
$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)
	
# Rule to create the .o files.
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONEY:
clean:
	rm $(rebuildables)
