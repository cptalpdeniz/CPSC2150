DEBUG  = -g
CXX = g++
VERSION = -std=c++17
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG)
LFLAGS = -Wall $(VERSION) $(DEBUG)

TEST = stackTimings

INCS = Stack.h
SRCS = Stack.cpp\
	$(TEST).cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = $(TEST)

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
	\rm -f *.o  $(EXEC)	
	@echo clean done
