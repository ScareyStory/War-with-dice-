CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS = DieMain.cpp Die.cpp LoadedDie.cpp menu.cpp
OBJS = ${SRCS: .cpp = .o}
HEADERS = Die.hpp LoadedDie.hpp menu.hpp

MAIN = war

all: ${MAIN}
	@echo sucessfully compiled!

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
