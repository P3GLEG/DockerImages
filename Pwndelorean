FROM kalilinux/kali-linux-docker
MAINTAINER Paul Ganea <paul@casaba.com>
RUN apt-get update -y && apt-get install git \
g++ \
gcc \
libre2-dev \
 -y
RUN git clone --recursive https://github.com/pegleg2060/PwnDelorean.git /opt/PwnDelorean && cd /opt/PwnDelorean && ./build.sh