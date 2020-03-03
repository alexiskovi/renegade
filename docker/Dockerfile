FROM osrf/ros:kinetic-desktop-full

MAINTAINER kov_alexis@mail.ru

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    vim \
    wget \
    protobuf-compiler

RUN apt-get install -y \
    python3-dev \
    python3-pip \
    python3-setuptools

WORKDIR /renegade
