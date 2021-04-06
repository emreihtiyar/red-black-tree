#MAKEFILE YAZIMI GENEL ANLATIMI

#Kurallarin icindeki her islem konsolda teker teker calistirilir eger calismasini gormek istemiyorsak satirin basina `@` sembolu konulur.
	# echo deneme #ekrana deneme yazdirir
	# @echo deneme #ekrana deneme yazdirir ama bu satir ekranda gozukmez

# $(degiskenAdi) bu sekilde daha onceden tanimlanan degiskenlere ulasabiliyoruz.

# $< Tanimlanan kuraldaki On kosullu verir (Kullanildigi kuralin ilk on kosulunu)
# $@ Kullanildigi kuralin adini verir
# $^ Tanimlanan kuraldaki On kosullu verir (Kullanildigi kuralin tum kosullarini)

# EXAMPLE DOSYASI ICIN MAKEFILE YAZIMI

#Degisken tanimlamalari
CC = gcc

#-I => 
CFLAGS = -Wall -Werror -I./include -L./lib

SRCDIR = src
OBJDIR = obj
TESTDIR = test
LIBDIR = lib

SRCS = $(wildcard $(SRCDIR)/*.c) # calistirilan klasordeki tum .c uzantili dosyalari SRCS degislenine atar
OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

TESTS_C =  $(wildcard $(TESTDIR)/*.c)
TOBJS = $(TESTS_C:%.c=%)

#Kural tanimlama | c`deki fonksiyonlara benzer ve all Kurali c`deki main gibidir. herhangi bir kural beliritilmediginde calisir.
#KuralAdi: Onkosullar
#	yapilacakIsler

all: $(TOBJS)
	@echo MAKEFILE COMPLETED


lib: $(OBJS)
	mkdir -p $(LIBDIR)
	ar rcs $(LIBDIR)/libtests.a $^
	ranlib $(LIBDIR)/libtests.a
	rm -rf $(OBJDIR)

%: %.c lib
	$(CC) $(CFLAGS) $< -o $@ -ltests

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(LIBDIR)
	rm  $(TESTDIR)/test 
	rm -rf $(OBJDIR)

#Opsiyonel kisim
run: clean all
	@clear
	@./$(TOBJS)

debug: all
	./$(TOBJS)