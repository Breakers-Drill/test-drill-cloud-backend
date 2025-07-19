FROM ubuntu:20.04

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    g++ \
    curl \
    libcurl4-openssl-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY main.cpp .
COPY .env .

RUN g++ -std=c++11 -o send-request-app main.cpp -lcurl

RUN echo '#!/bin/sh\n\
set -a\n\
. /app/.env\n\
set +a\n\
./send-request-app' > /app/start.sh && chmod +x /app/start.sh

CMD ["/app/start.sh"]
