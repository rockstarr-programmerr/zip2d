FROM ubuntu:latest

WORKDIR /home

RUN apt-get update \
    && apt-get install -y build-essential
