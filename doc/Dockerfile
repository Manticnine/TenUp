FROM ubuntu

ENV TZ=Asia/Karachi
ENV DEBIAN_FRONTEND=noninteractive

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update -y && \
    apt-get install -y software-properties-common git build-essential cmake autoconf libtool bsdmainutils autotools-dev pkg-config automake python3 \
    qt5-default qtscript5-dev libssl-dev qttools5-dev qttools5-dev-tools qtmultimedia5-dev libqt5svg5-dev libqt5webkit5-dev \
    libsdl2-dev libasound2 libxmu-dev libxi-dev freeglut3-dev libasound2-dev libjack-jackd2-dev \
    libxrandr-dev libqt5xmlpatterns5-dev libqt5xmlpatterns5 \
    libgmp-dev libevent-dev libboost-all-dev libsodium-dev cargo

RUN add-apt-repository -y ppa:pivx/pivx && apt-get update
RUN apt-get install -y libdb4.8-dev libdb4.8++-dev

WORKDIR  /opt
RUN git clone https://github.com/tenup-coin/TenUp
WORKDIR /opt/TenUp

RUN git fetch && \
    git checkout 4.3

RUN chmod +x configure.ac && \
    chmod +x autogen.sh

RUN ./autogen.sh && ./configure

RUN make

RUN make install

RUN mkdir ~/.tenup

RUN echo -e "\
rpcuser=tenuprpc \n\
rpcpassword=tenuprpcpassword \n\
txindex=1 \n\
#bind=0.0.0.0:51482 \n\
server=1 \n\
rest=1 \n\
#rpcallowip=192.168.100.0/24 \n\
debug=1 \n\
#walletnotify=/home/mint/tenup-coin/tenup.wallet/Api/notifytx.sh %s \n\
testnet=1\
" > ~/.tenup/tenup.conf

ENTRYPOINT ["tenupd"]

