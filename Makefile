
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wall -I./include #-fsanitize=address -fsanitize=undefined
#SFML_INCLUDE_DIR = /opt/homebrew/Cellar/sfml/2.6.1/include
#SFML_LIBRARY_DIR = /opt/homebrew/Cellar/sfml/2.6.1/lib
SFML_INCLUDE_DIR = /usr/include
SFML_LIBRARY_DIR = /usr/lib

LDFLAGS = -L$(SFML_LIBRARY_DIR)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LFLAGS = -L./files $(LDFLAGS) $(LDLIBS)
SRCDIR = src
OBJDIR = obj
BINDIR = .
EXECUTABLE = $(BINDIR)/pvz.out
MEDIA_PATH = ./files/

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(SRCDIR)/*.hpp)
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(MEDIA_PATH)

clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)
