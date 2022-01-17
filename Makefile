# makefile
.phony: all clean clean-doc compile default doc help install-dev lint lint-test run test

APP=hello-world
BROWSER=chromium-browser
CC=g++
SEPARATOR = "~~~~~~~~~~~~~~~~~~~~~~~~~~~"

all: compile-doc lint run

clean:
	@echo $(SEPARATOR)
	rm -rf target/*

clean-doc:
	@echo $(SEPARATOR)
	rm -rf docs/*

compile: clean
	@echo $(SEPARATOR)
	$(CC) -Wall -o target/$(APP) src/$(APP)/main.cpp

compile-doc: clean-doc
	@echo $(SEPARATOR)
	doxygen Doxyfile

default: all

doc: compile-doc
	$(BROWSER) docs/html/index.html || lynx docs/html/index.html

install-dev:
	sudo apt update
	sudo apt -y install make g++ doxygen graphviz clang-format lynx cppcheck libgtest-dev

help:
	@echo "make targets for $(APP) app:"
	@echo " all		# clean, clean-docs, compile-doc, lint, compile, and run (default)"
	@echo " clean		# remove all target files and binaries"
	@echo " clean-docs	# remove existing docs"
	@echo " compile	# compile app"
	@echo " compile-docs	# remove old doc and create doxygen doc"
	@echo " doc		# create doxygen doc and open it in the browser $(BROWSER)"
	@echo " help		# this help text"
	@echo " install-dev	# install dev tools"
	@echo " lint		# format and lint the code"
	@echo " lint-tests	# format the tests"
	@echo " run		# compile and run app"
	@echo " test		# compile and run tests"

lint:
	@echo $(SEPARATOR)
	clang-format -i src/$(APP)/*
	cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem src/

lint-tests:
	@echo $(SEPARATOR)
	clang-format -i src/$(APP)/*

run: compile
	@echo $(SEPARATOR)
	@target/$(APP)

test:
	@echo $(SEPARATOR)
	$(CC) -pthread tests/*.cpp -lgtest -lgtest_main -o target/$(APP)-test
	@echo $(SEPARATOR)
	target/$(APP)-test
