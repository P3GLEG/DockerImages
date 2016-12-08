FROM openjdk:8-jdk
MAINTAINER Paul Ganea <paul@paulganea.io>
RUN mkdir -p /burp/src && mkdir -p /burp/build
WORKDIR /burp
CMD javac -d build src/burp/*.java  && jar -cf bin/burpextender.jar -C build burp
