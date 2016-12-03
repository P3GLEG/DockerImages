FROM openjdk
MAINTAINER Paul Ganea <paul@paulganea.io>
RUN mkdir -p /burp/src && mkdir -p /burp/build
WORKDIR /burp
ADD src /burp/src
RUN javac -d build /burp/src/*.java
#RUN jar cf bin\burpextender.jar -C build burp