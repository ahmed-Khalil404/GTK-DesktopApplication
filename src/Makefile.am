## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projectx

projectx_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	admin.c admin.h \
	clubs.c clubs.h \
	capteur.c capteur.h \
	stock.c stock.h \
	nutritioniste.c nutritioniste.h \
	agent.c agent.h \
	reclamation.h reclamation.c \
	email.c email.h

projectx_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

AM_LDFLAGS=-L/usr/bin
projectx_LDADD+=-lcurl
