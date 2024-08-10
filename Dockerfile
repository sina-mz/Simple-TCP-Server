FROM gcc:latest

# prepare build tools
RUN	set -ex; \
	apt-get update; \
	apt-get install -y cmake;


# copy the source files
WORKDIR /src/serverTCP/
COPY . .
RUN rm -r build/*


# build the application
WORKDIR /src/serverTCP/build/
RUN cmake ..
RUN make


# the entry
CMD [ "/src/serverTCP/build/server-x86" ]
