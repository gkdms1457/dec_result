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

FROM base-x86 as snowman
USER root
RUN apt-get update \
    && apt-get install -y --no-install-recommends build-essential cmake git libboost-dev qtbase5-dev qt5-qmake qtbase5-dev-tools \
    && rm -rf /var/lib/apt/lists/*

USER decompiler_user
WORKDIR /home/decompiler_user
RUN git clone https://github.com/yegord/snowman.git \
    && cmake -B snowman/build -DNC_QT5=YES -DCMAKE_INSTALL_PREFIX=install snowman/src/ \
    && cmake --build snowman/build -j$(nproc) \
    && cmake --install snowman/build \
    && rm -rf snowman