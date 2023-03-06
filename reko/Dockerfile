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

FROM base-x86 as reko
USER root
RUN apt-get update \
    && apt-get install -y --no-install-recommends git build-essential cmake wget gcc g++ libcapstone-dev pkg-config p7zip-full unzip \
    && wget https://packages.microsoft.com/config/debian/11/packages-microsoft-prod.deb -O packages-microsoft-prod.deb \
    && dpkg -i packages-microsoft-prod.deb \
    && rm packages-microsoft-prod.deb \
    && apt-get update \
    && apt-get install -y apt-transport-https \
    && apt-get update \
    && apt-get install -y dotnet-sdk-6.0 \
    && rm -rf /var/lib/apt/lists/*

USER decompiler_user
WORKDIR /home/decompiler_user
RUN git clone --depth=1 https://github.com/uxmal/reko.git \
    && cd reko \
    && dotnet msbuild -p:Platform=x64 -p:Configuration=UnixRelease -t:build_solution -m ./src/BuildTargets/BuildTargets.csproj \
    && dotnet msbuild -p:Platform=x64 -p:Configuration=Release -t:create_runtime_nupkg -m ./src/BuildTargets/BuildTargets.csproj \
    && dotnet msbuild -p:Platform=x64 -p:Configuration=Release -t:create_release -m ./src/BuildTargets/BuildTargets.csproj \
    && cp bin/CmdLine*.zip ../CmdLine.zip \
    && cd .. \
    && rm -rf reko .nuget

RUN mkdir reko \
    && cd reko \
    && unzip ../CmdLine.zip

WORKDIR /home/decompiler_user