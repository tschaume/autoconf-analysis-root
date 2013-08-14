AC_INIT([My Simple Example], [11.11.14], [phuck@lbl.gov], [MySimpleExample], [http://www.star.bnl.gov/protected/lfspectra/huck/])
AC_PREREQ(2.59)
AM_SILENT_RULES([yes])
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE([-Wall no-define])
AC_PROG_CC
AC_PROG_CXX
ROOT_PATH
AM_PROG_LIBTOOL
AC_SUBST(DEPS_CFLAGS)
AC_SUBST(DEPS_LIBS)
AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing w/o support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN],[test -n "$DOXYGEN"]) AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile])])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
