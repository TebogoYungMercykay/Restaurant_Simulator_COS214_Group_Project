FROM ubuntu:18.04
WORKDIR /usr/src/app
# Install g++, make, and cmake
RUN apt-get update && apt-get install -y g++ make cmake
# Copy your source code into the image
COPY . .
# Running cmake to generate a Makefile and then make to build the project
RUN cmake CMakeLists.txt && make
EXPOSE 8080
CMD [ "./main" ]
