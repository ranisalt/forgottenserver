FROM alpine:3.16.2 AS build
# crypto++-dev is in edge/testing
RUN apk add --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ \
  binutils \
  boost-dev \
  build-base \
  clang \
  crypto++-dev \
  gcc \
  luajit-dev \
  make \
  mariadb-connector-c-dev \
  meson \
  ninja

COPY src /usr/src/forgottenserver/src/
COPY meson.build /usr/src/forgottenserver/
WORKDIR /usr/src/forgottenserver
RUN meson setup build && ninja -C build

FROM alpine:3.16.2
# crypto++ is in edge/testing
RUN apk add --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ \
  boost-iostreams \
  boost-system \
  crypto++ \
  luajit \
  mariadb-connector-c

COPY --from=build /usr/src/forgottenserver/build/tfs /bin/tfs
COPY data /srv/data/
COPY LICENSE README.md *.dist *.sql key.pem /srv/

EXPOSE 7171 7172
WORKDIR /srv
VOLUME /srv
ENTRYPOINT ["/bin/tfs"]
