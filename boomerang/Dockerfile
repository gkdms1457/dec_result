FROM python:3.8-slim-bullseye as base

RUN useradd -ms /bin/false decompiler_user
RUN apt-get update \
    && apt-get install -y --no-install-recommends curl \
    && rm -rf /var/lib/apt/lists/*

USER decompiler_user
WORKDIR /home/decompiler_user

RUN pip install --user 'requests>=2.27,<3.0'

FROM --platform=amd64 python:3.8-slim-bullseye as base-x86

RUN useradd -ms /bin/false decompiler_user
RUN apt-get update \
    && apt-get install -y --no-install-recommends curl \
    && rm -rf /var/lib/apt/lists/*

USER decompiler_user
WORKDIR /home/decompiler_user

RUN pip install --user 'requests>=2.27,<3.0'

FROM base-x86 as boomerang
USER root
RUN apt-get update \
    && apt-get install -y --no-install-recommends wget bzip2 libexpat1 qtbase5-dev libcapstone-dev \
    && rm -rf /var/lib/apt/lists/*

RUN wget https://github.com/BoomerangDecompiler/boomerang/releases/download/v0.5.2/boomerang-v0.5.2-linux64.tar.gz -O boomerang.tar.gz \
    && tar xf boomerang.tar.gz \
    && rm boomerang.tar.gz \
    && cp -r boomerang*/* /usr \
    && ln -s /usr/lib/boomerang/libboomerang.so /usr/lib

USER decompiler_user
WORKDIR /home/decompiler_user