FROM emscripten/emsdk:3.1.74 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y locales dos2unix
RUN rm -rf /var/lib/apt/lists/*
RUN localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG=en_US.utf8

RUN apt-get update
RUN apt-get -y install tzdata git cmake ninja-build pkg-config \
    clang-15 clang++-15 clangd-15 \
    libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev  \
    libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

RUN mkdir /export

WORKDIR /src
COPY . .

WORKDIR /src/build
RUN cmake .. -G Ninja -DCUSTOMIZE_BUILD=ON -DPLATFORM="Desktop" -DBUILD_EXAMPLES=OFF -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Debug  \
    -DGLFW_BUILD_WAYLAND=ON
RUN cmake --build . --target all

RUN rm -rf CMakeFiles/ CMakeCache.txt

RUN emcmake cmake .. -G Ninja -DCUSTOMIZE_BUILD=ON -DPLATFORM="Web" -DBUILD_EXAMPLES=OFF -DBUILD_SHARED_LIBS=OFF
RUN cmake --build . --target all
RUN mv test0* /export

FROM ubuntu:22.04

RUN mkdir /apps
COPY --from=builder /export/* /apps
