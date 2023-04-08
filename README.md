# graphd

A graph database implementation

## Libraries

### Boost 1.77

```shell
# bootstrap the build
./bootstrap.sh --prefix=/home/michael/Source/lib/boost_1_77_0 --without-icu

# generate headers
./b2 headers

# build and install
./b2 -j7 --disable-icu --ignore-site-config variant=release threading=multi install
```