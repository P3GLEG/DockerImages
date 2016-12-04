FROM openjdk:9-jdk
MAINTAINER Paul Ganea <paul@paulganea.io>
RUN mkdir -p /burp/src && mkdir -p /burp/build && mkdir -p /tmp/burp
WORKDIR /burp
CMD javac -d /tmp/burp src/*.java &&  jar cf build/burpextender.jar /tmp/burp
