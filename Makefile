CC = gcc

CFLAGS = -Wall -Werror -I./include -L./lib

SRCDIR = src
OBJDIR = obj
TESTDIR = test
LIBDIR = lib

SRCS = $(wildcard $(SRCDIR)/*.c) # calistirilan klasordeki tum .c uzantili dosyalari SRCS degislenine atar
OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

TESTS_C =  $(wildcard $(TESTDIR)/*.c)
TESTS_OUT = $(filter-out $(TESTS_C), $(wildcard $(TESTDIR)/*))
TOBJS = $(TESTS_C:%.c=%)

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
	rm  $(TESTS_OUT)
	rm -rf $(OBJDIR)

#Opsiyonel kisim
run: $(TESTDIR)/test
	@clear
	@./$(TOBJS)

debug: all
	./$(TOBJS)

den: $(TESTDIR)/den_test
	@clear
	@./$(TOBJS)