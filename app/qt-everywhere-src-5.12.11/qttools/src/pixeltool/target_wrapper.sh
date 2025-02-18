#!/bin/sh
LD_LIBRARY_PATH=/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtbase/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtbase/plugins:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtvirtualkeyboard/plugins:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtsvg/plugins:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtimageformats/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec /code/sdb/git/test/SanyuJoJo_board_qemu/app/qt-everywhere-src-5.12.11/qttools/bin/pixeltool "$@"
