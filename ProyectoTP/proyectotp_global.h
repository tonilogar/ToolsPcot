#ifndef PROYECTOTP_GLOBAL_H
#define PROYECTOTP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PROYECTOTP_LIBRARY)
#  define PROYECTOTPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PROYECTOTPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PROYECTOTP_GLOBAL_H
