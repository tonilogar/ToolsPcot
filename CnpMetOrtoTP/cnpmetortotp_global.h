#ifndef CNPMETORTOTP_GLOBAL_H
#define CNPMETORTOTP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CNPMETORTOTP_LIBRARY)
#  define CNPMETORTOTPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CNPMETORTOTPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CNPMETORTOTP_GLOBAL_H
