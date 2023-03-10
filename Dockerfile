# syntax=docker/dockerfile:1.2
FROM alpine AS builder

RUN apk add --no-cache clang musl-dev lld compiler-rt upx
WORKDIR /fibonacci
COPY fib.c .
RUN clang -o fib fib.c -fuse-ld=lld --rtlib=compiler-rt -static -s -Oz && upx --ultra-brute fib

FROM scratch

WORKDIR /fibonacci
COPY --from=builder /fibonacci/fib .
CMD ["./fib"]