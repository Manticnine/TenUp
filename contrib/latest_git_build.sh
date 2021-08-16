pushd /opt/TenUp

git fetch && \
    git checkout 4.3

chmod +x configure.ac && \
    chmod +x autogen.sh

./autogen.sh && ./configure

make

make install