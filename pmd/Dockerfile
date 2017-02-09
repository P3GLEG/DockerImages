FROM maven:3.3.9-jdk-8
MAINTAINER Paul Ganea k4ch0w@linux.com
RUN apt-get -y update && apt-get install -y git
RUN git clone https://github.com/pmd/pmd.git /pmd/
WORKDIR /pmd
COPY toolchains.xml /root/.m2/toolchains.xml
COPY src/ /root/source
RUN mvn clean install -DskipTests=true && \
mvn install site site:stage -Psite
RUN unzip /pmd/pmd-dist/target/pmd-bin-*-SNAPSHOT.zip && mv /pmd/pmd-bin-*-SNAPSHOT/ /opt/pmd
CMD ["/opt/pmd/bin/run.sh","pmd","-d","/root/source","-R","rulesets/internal/all-java.xml"]
