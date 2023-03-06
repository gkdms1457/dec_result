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

FROM base-x86 as relyze
USER root
RUN apt-get update \
    && apt-get install -y --no-install-recommends wget
RUN mkdir -pm755 /etc/apt/keyrings \
    && wget -nc --no-check-certificate -O /etc/apt/keyrings/winehq-archive.key https://dl.winehq.org/wine-builds/winehq.key \
    && wget -nc --no-check-certificate -P /etc/apt/sources.list.d/ https://dl.winehq.org/wine-builds/debian/dists/bullseye/winehq-bullseye.sources
RUN dpkg --add-architecture i386 \
    && apt-get update \
    && apt-get install -y --no-install-recommends winehq-stable \
    && rm -rf /var/lib/apt/lists/*
RUN wget -nc -O /innoextract_amd64.deb https://download.opensuse.org/repositories/home:/dscharrer/Debian_11/amd64/innoextract_1.9-0.1_amd64.deb \
    && apt-get update \
    && apt-get install -y --no-install-recommends /innoextract_amd64.deb \
    && rm /innoextract_amd64.deb \
    && rm -rf /var/lib/apt/lists/*

USER decompiler_user
WORKDIR /home/decompiler_user

RUN wget -O ./update_win64.xml https://www.relyze.com/update?family=RLZ\&plat=win\&arch=x64 \
    && wget -O ./Relyze_Desktop_x_x_x_win64.exe https://www.relyze.com/$(grep -oP "(?<=<Installer>)(\S+)(?=</Installer>)" update_win64.xml) \
    && rm ./update_win64.xml
RUN innoextract  -d ./RelyzeDesktop ./Relyze_Desktop_x_x_x_win64.exe \
    && rm ./Relyze_Desktop_x_x_x_win64.exe
ENV WINEPREFIX=/home/decompiler_user/.wine-relyze
RUN winecfg 2>/dev/null && wineserver --kill
ENV WINEDLLOVERRIDES="dbghelp=n;symsrv=n"
RUN rm -rf $WINEPREFIX/drive_c/users/decompiler_user/Documents
RUN mkdir $WINEPREFIX/drive_c/users/decompiler_user/Documents
RUN ln -s /home/decompiler_user/RelyzeDesktop/commonappdata/Relyze64 $WINEPREFIX/drive_c/ProgramData/Relyze64
RUN mkdir -p $WINEPREFIX/drive_c/users/decompiler_user/AppData/Roaming/Relyze

COPY ./License.txt $WINEPREFIX/drive_c/users/decompiler_user/AppData/Roaming/Relyze
COPY ./decompiler_explorer.rb .