#=====================================================================================================
# General Stuff
AUTOMAKE_OPTIONS        = subdir-objects foreign
ACLOCAL_AMFLAGS = -I /Applications/root/build/misc
AM_CPPFLAGS = $(DEPS_CFLAGS) -I$(ROOTINCDIR) 
AM_CFLAGS = $(LAYOUT_CFLAGS)

#=====================================================================================================
# hSimple program
bin_PROGRAMS = bin/hSimple
bin_hSimple_SOURCES = src/hSimple.cc
bin_hSimple_CXXFLAGS = @ROOTCFLAGS@
bin_hSimple_LDADD = -L@ROOTLIBDIR@ @ROOTGLIBS@ @ROOTLIBS@ @LIBS@ ${DEPS_LIBS}

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

