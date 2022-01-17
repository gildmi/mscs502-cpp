FROM ubuntu:latest

RUN apt update && apt -y upgrade && apt -y install make g++ doxygen graphviz clang-format lynx cppcheck libgtest-dev 

WORKDIR /hello-world
COPY * ./

CMD ["bash"]