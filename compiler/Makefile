# config.mk contains the paths to antlr4 etc.
# Each student should have a config.mk corresponding to her system.
# Examples are  ubuntu.mk, DI.mk, fedora.mk
# Then config.mk should be in the .gitignore of your project
include config.mk

CC=g++
CCFLAGS=-g -c -std=c++17 -I$(ANTLRINC) -Wno-attributes # -Wno-defaulted-function-deleted -Wno-unknown-warning-option
LDFLAGS=-g

default: all
all: ifcc

##########################################
# link together all pieces of our compiler 
OBJECTS=src/build/ifccBaseVisitor.o \
	src/build/ifccLexer.o \
	src/build/ifccVisitor.o \
	src/build/ifccParser.o \
	src/build/main.o \
	src/build/CodeGenVisitor.o \
	src/build/SymbolTableVisitor.o

ifcc: $(OBJECTS)
	@mkdir -p src/build
	$(CC) $(LDFLAGS) src/build/*.o $(ANTLRLIB) -o ifcc

##########################################
# compile our hand-writen C++ code: main(), CodeGenVisitor, etc.
src/build/%.o: src/%.cpp src/generated/ifccParser.cpp
	@mkdir -p src/build
	$(CC) $(CCFLAGS) -MMD -o $@ $< 

##########################################
# compile all the antlr-generated C++
src/build/%.o: src/generated/%.cpp
	@mkdir -p src/build
	$(CC) $(CCFLAGS) -MMD -o $@ $< 

# automagic dependency management: `gcc -MMD` generates all the .d files for us
-include src/build/*.d
src/build/%.d:

##########################################
# generate the C++ implementation of our Lexer/Parser/Visitor
src/generated/ifccLexer.cpp: src/generated/ifccParser.cpp
src/generated/ifccVisitor.cpp: src/generated/ifccParser.cpp
src/generated/ifccBaseVisitor.cpp: src/generated/ifccParser.cpp
src/generated/ifccParser.cpp: src/ifcc.g4
	@mkdir -p src/generated
	cd src && $(ANTLR) -visitor -no-listener -Dlanguage=Cpp -o generated ifcc.g4

# prevent automatic cleanup of "intermediate" files like ifccLexer.cpp etc
.PRECIOUS: src/generated/ifcc%.cpp   

##########################################
# view the parse tree in a graphical window

# Usage: `make gui FILE=path/to/your/file.c`
FILE ?= ../tests/testfiles/1_return42.c

gui:
	@mkdir -p src/generated src/build
	cd src && $(ANTLR) -Dlanguage=Java -o generated ifcc.g4
	javac -cp $(ANTLRJAR) -d src/build src/generated/*.java
	java -cp $(ANTLRJAR):src/build org.antlr.v4.gui.TestRig ifcc axiom -gui $(FILE)

##########################################
# delete all machine-generated files
clean:
	rm -rf src/build src/generated
	rm -f ifcc