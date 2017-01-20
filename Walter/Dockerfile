FROM alpine:edge
EXPOSE 8118 9050
RUN apk --update add privoxy tor runit
COPY privoxy /etc/privoxy/config
CMD ["privoxy --no-daemon", "tor"]
