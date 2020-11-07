# having the option -DNDEBUG when compiling, means NO debugging occurs
# comment out the next line if you want debugging
NO_DEBUGGING_STATEMENTS = -DNDEBUG
CXX = g++
VERSION = -std=c++17
#DEBUG = -g
CFLAGS = -pedantic -Wall -Wextra $(DEBUG) $(VERSION) $(NO_DEBUGGING_STATEMENTS) -g
LFLAGS = -Wall $(VERSION) 

INCS = Term.h\
	Polynomial.h
SRCS = Polynomial.cpp\
	doMath.cpp
	
OBJS = $(SRCS:.cpp=.o)
EXEC = doMath

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
