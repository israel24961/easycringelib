# This is an example PKGBUILD file. Use this as a start to creating your own,
# and remove these comments. For more information, see 'man PKGBUILD'.
# NOTE: Please fill out the license field for your package! If it is unknown,
# then please put 'unknown'.

# Maintainer: Your Name <youremail@domain.com>
pkgname=easycringelib-git
pkgver=1.0.1
pkgrel=1
epoch=1
pkgdesc="Personal library for useful types"
arch=('x86_64')
url=""
license=('custom')
source=("$pkgname::git+https://github.com/israel24961/easycringelib.git")
md5sums=('SKIP')


pkgver() {
    cd "$srcdir/$pkgname"
    git describe --tags
}
build() {
    printf "SRC: $srcdir/build\n"
    mkdir -p "$srcdir/build"
    cd "$srcdir/build"  || return 1
    cmake "../$pkgname" \
        -DCMAKE_INSTALL_PREFIX="$pkgdir"\
        -DCMAKE_INSTALL_LIBDIR="./usr/lib" \
        -DCMAKE_INSTALL_INCLUDEDIR="./usr/include"
    make
}

check() {
    printf "No tests to run\n $pkgname\n"
}

package() {
    cd "$srcdir/build" || return 1
    make install
}
