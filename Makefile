CXX = $(shell which g++)
CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags opencv4) -I${SYSTEMC}/include
LDFLAGS = -L${SYSTEMC}/lib-linux64 -lsystemc $(shell pkg-config --libs opencv4) 
TARGET = load_image
SRCS = load_image.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)
	
.PHONY: clean
clean:
	rm $(TARGET)