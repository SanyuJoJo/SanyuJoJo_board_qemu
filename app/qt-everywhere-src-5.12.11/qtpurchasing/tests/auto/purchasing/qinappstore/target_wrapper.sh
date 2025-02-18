#!/bin/sh
LD_LIBRARY_PATH=/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtbase/lib:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtpurchasing/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtbase/plugins:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtsvg/plugins:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtimageformats/plugins:/code/sdb/sanyusdk/app/qt-everywhere-src-5.12.11/qtvirtualkeyboard/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
