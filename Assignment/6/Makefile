#DO_NOT_DEBUG = -DNDEBUG
CXX = g++
VERSION = -std=c++17
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DO_NOT_DEBUG)
LFLAGS = -Wall $(VERSION) 

INCS = canvas.h 

SRCS = canvas.cpp\
	colour.cpp
   
OBJS = $(SRCS:.cpp=.o)

EXEC = color

all: $(SRCS) $(EXEC)

# To make an object from source
#.cpp.o: 
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS) 
	$(CXX) $(LFLAGS) $(OBJS) -o $@

# for Windows
clean:
	del *.o  $(EXEC).exe
	@echo clean done

# for UNIX / Linux 
remove:
	\rm -f *.o $(EXEC)
	@echo clean done
