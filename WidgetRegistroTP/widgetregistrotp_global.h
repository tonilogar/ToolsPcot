#ifndef WIDGETREGISTROTP_GLOBAL_H
#define WIDGETREGISTROTP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WIDGETREGISTROTP_LIBRARY)
#  define WIDGETREGISTROTPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WIDGETREGISTROTPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WIDGETREGISTROTP_GLOBAL_H