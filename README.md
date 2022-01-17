# hello-world
Simple hello world application template

## Usage
```
~/hello-world$ ./targets/hello-world -h
hello-world
Simple hello world template.
Version: 0.0.1

-h         Print this help text
-v         Verbose mode
```

## Compiling
A Makefile has been included for convience.  
Simply issue `make compile`  
or  
`g++ -Wall -o targets/hello-world src/hello-world/main.cpp`

## Running
Issue a `make run` or run the target directly.  For conveince, the default `make` target will clean the targets, generate the doc, perform linting, compile, then run the program.

## Docker
1. Download and install Docker [https://docs.docker.com/desktop/](https://docs.docker.com/desktop/)
2. Build the mscs502 image with `docker build -t mscs502 .`
3. Run the container based on mscs502 image with `docker run -it --rm -v $PWD:/hello-world mscs502`
4. Use VSCode or your IDE of choice to edit your code locally.  HINT: Run `code .` from the terminal when in the folder
5. Compile and run the code as you would locally from teh Docker container bash prompt

## Tests
[GoogleTest](https://github.com/google/googletest) is used as the Test Framework. To execute unit tests run `make test`.

## Contributing
- All code (classes, files, global variables, members, and functions) must be thoroughly documented using Doxygen accepted format.
- All existing unit tests must pass. HINT: Use `make test`
- New unit tests are encouraged!
- README, help text, makefile, and other artifacts must be up to date.
- Program version number should be incremented.  HINT: In *Doxyfile* and *global variables*
- Use proper git ettiquete with frequent commits and [good commit messages](https://cbea.ms/git-commit/).
- All code must be formatted using *clang-format*.  HINT: Use `make lint` and `make lint-tests`
- Binary files and other metadata shall not be committed. HINT: Update the .gitignore, if necessary
- No warnings or errors shall be produced by the compiler with '-Wall' options.
- No warnings or errors shall be produced by *cppcheck*.  HINT: Use `make lint`