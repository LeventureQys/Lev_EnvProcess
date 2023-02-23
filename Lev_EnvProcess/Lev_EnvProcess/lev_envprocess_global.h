#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LEV_ENVPROCESS_LIB)
#  define LEV_ENVPROCESS_EXPORT Q_DECL_EXPORT
# else
#  define LEV_ENVPROCESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define LEV_ENVPROCESS_EXPORT
#endif
