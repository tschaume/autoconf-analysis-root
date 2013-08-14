#=====================================================================================================
# General Stuff
AUTOMAKE_OPTIONS        = subdir-objects foreign
ACLOCAL_AMFLAGS = -I /Applications/root/build/misc
AM_CPPFLAGS = $(DEPS_CFLAGS) -I$(ROOTINCDIR) 
AM_CFLAGS = $(LAYOUT_CFLAGS)

#=====================================================================================================
# Options dictionary/library
CLEANFILES = src/Options/OptionsDict.cxx src/Options/OptionsDict.h
pkglib_LTLIBRARIES = src/Options/libOptions.la
pkginclude_HEADERS = src/Options/Options.h
noinst_HEADERS = src/Options/LinkDef.h
src_Options_libOptions_la_SOURCES = src/Options/Options.cxx
nodist_src_Options_libOptions_la_SOURCES = src/Options/OptionsDict.cxx
# run rootcint
src/Options/OptionsDict.cxx src/Options/OptionsDict.h:src/Options/Options.h src/Options/LinkDef.h
	$(ROOTCINT) -f src/Options/OptionsDict.cxx -c $(AM_CPPFLAGS) $^

#=====================================================================================================
# hSimple dictionary/library
CLEANFILES += src/hSimple/hSimpleDict.cxx src/hSimple/hSimpleDict.h
pkglib_LTLIBRARIES += src/hSimple/libhSimple.la
pkginclude_HEADERS += src/hSimple/hSimple.h 
noinst_HEADERS += src/hSimple/LinkDef.h
src_hSimple_libhSimple_la_SOURCES  = src/hSimple/hSimple.cxx 
nodist_src_hSimple_libhSimple_la_SOURCES = src/hSimple/hSimpleDict.cxx
src_hSimple_libhSimple_la_LIBADD = src/Options/libOptions.la
# run rootcint
src/hSimple/hSimpleDict.cxx src/hSimple/hSimpleDict.h:src/hSimple/hSimple.h src/hSimple/LinkDef.h
	$(ROOTCINT) -f src/hSimple/hSimpleDict.cxx -c $(AM_CPPFLAGS) $^
# runhSimple
bin_PROGRAMS = bin/runhSimple 
bin_runhSimple_SOURCES = src/runhSimple.cc
bin_runhSimple_LDADD = src/Options/libOptions.la src/hSimple/libhSimple.la 
bin_runhSimple_LDADD += -L@ROOTLIBDIR@ @ROOTGLIBS@ 
bin_runhSimple_LDADD += @ROOTLIBS@ @LIBS@ ${DEPS_LIBS}
bin_runhSimple_LDFLAGS = -R $(ROOTLIBDIR) -L$(ROOTLIBDIR)
bin_runhSimple_CXXFLAGS = @ROOTCFLAGS@

#=====================================================================================================
# distribution package extras
EXTRA_DIST = src/mainpage.cc configure.ac Makefile.am 
dist_doc_DATA           = README 

#=====================================================================================================
# doxygen
if HAVE_DOXYGEN
all-local: 
	rm -rf $(top_srcdir)/docs/html
	mkdir docs/html
#	./bin/copy_files.sh # copy pics included w/ <a href> tag
	$(DOXYGEN) docs/Doxyfile
	cp docs/refman_mod.tex docs/latex/
	cp docs/Makefile_mod docs/latex/
endif

