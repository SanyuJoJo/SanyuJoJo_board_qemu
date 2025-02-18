#!/bin/sh
QT_VERSION=5.12.11
export QT_VERSION
QT_VER=5.12
export QT_VER
QT_VERSION_TAG=51211
export QT_VERSION_TAG
QT_INSTALL_DOCS=/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtbase/doc
export QT_INSTALL_DOCS
BUILDDIR=/code/sdb/git/test/SanyuJoJo_board_qemu/app/qt-everywhere-src-5.12.11/qttools/src/assistant/assistant
export BUILDDIR
exec /code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qttools/bin/qdoc "$@"
