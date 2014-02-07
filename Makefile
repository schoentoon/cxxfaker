override CFLAGS += -std=c++11 -g -Wall -O2 -pipe -fPIC
INC             += -Iinclude
override DEFINES:=

CC              := gcc
CXX             := g++
AR              := ar

NAME := cxxfaker
DEPS := $(patsubst %.cpp, %.o, $(shell find src/ -name \*.cpp -a \( ! -name \*_test.cpp \) -type f))

all: $(NAME).so $(NAME).a

.PHONY: clean

clean:
	find . -name "*.o" -delete
	find . -name "*.so" -delete
	find . -name "*.a" -delete

src/%.o: src/%.cpp include/%.h
	$(CXX) $(CFLAGS) $(INC) $(DEFINES) -c $< -o $@

$(NAME).so: $(DEPS)
	$(CXX) $(CFLAGS) $(INC) $(DEFINES) -shared -o $@ $(DEPS)

$(NAME).a: $(DEPS)
	$(AR) rcs $@ $(DEPS)


gtest-1.7.0.zip:
	wget -q http://googletest.googlecode.com/files/gtest-1.7.0.zip

libgtest.a: gtest-1.7.0.zip
	unzip -qqn gtest-1.7.0.zip
	$(CXX) $(CFLAGS) -Igtest-1.7.0/include -Igtest-1.7.0 -c gtest-1.7.0/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

TEST_DEPS := $(patsubst %_test.cpp, %_test.o, $(shell find src/ -name \*_test.cpp -type f))

%_test.o: %_test.cpp
	$(CXX) $(CFLAGS) $(INC) -Itest -Igtest-1.7.0/include $(DEFINES) -c $< -o $@

test.out: libgtest.a $(TEST_DEPS) $(NAME).a
	$(CXX) $(CFLAGS) $(INC) -Igtest-1.7.0/include $(DEFINES) -o $@ $(TEST_DEPS) $(NAME).a libgtest.a -pthread

.PHONY: test

test: test.out
	./test.out