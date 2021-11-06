##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


LD		=       ld

ASM		=       nasm

RM		 =       rm -f

ASMFLAGS        =       -f elf64

SRCS            =	strlen.asm	\
			memcpy.asm	\
                        memset.asm	\
			strstr.asm	\
                        strcmp.asm	\

OBJS            =       $(SRCS:.asm=.o)

NAME            =       libasm.so

all: $(NAME)

$(NAME): $(OBJS)
	 $(LD) -o $(NAME) -shared $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

%.o : %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<
