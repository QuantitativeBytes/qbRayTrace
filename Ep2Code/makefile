# ***********************************************************
#
#	makefile
#	
#	The makefile for use with gmake to handle building the
#	project.
#	
#	This file forms part of the qbRayTrace project as described
#	in the series of videos on the QuantitativeBytes YouTube
#	channel.
#	
#	This code corresponds specifically to Episode 2 of the series,
#	which may be found here:
#	https://youtu.be/KBK6g6RFgdA
#	
#	The whole series may be found on the QuantitativeBytes 
#	YouTube channel at:
#	www.youtube.com/c/QuantitativeBytes
#	
#	GPLv3 LICENSE
#	Copyright (c) 2021 Michael Bennett
#	
# ***********************************************************

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
