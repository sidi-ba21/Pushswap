##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=	push_swap

TESTS		=	unit_test

CC		=	gcc

RM		=	rm -f

GCOVR		=	gcovr

LIB		=	-L./lib/my -lmy

INC		=	-I./includes

CRIT		=	-lcriterion

COVER		=	--coverage

BRANCH		=	--branches

EXCLUD		=	--exclude

CPPFLAGS 	=	$(INC) -Wall -Wextra -g3

SRC_DIR		=	src/

LIB_DIR		=	lib/my/

TESTS_DIR	=	tests/

OBJ		=	$(SRC:.c=.o)

UNIT_TEST	=	$(TESTS_DIR)tests_push_swap.c			\

SRC		=	$(SRC_DIR)my_list.c		\
			$(SRC_DIR)instruction.c		\
			$(SRC_DIR)main.c		\
			$(SRC_DIR)radix.c

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(INC) $(LIB) -O2

unit_tests:
	$(MAKE) -C lib/my
	$(CC) -o $(TESTS) $(UNIT_TEST) $(LIB) $(INC) $(COVER) $(CRIT)

run_tests: unit_tests
	./unit_test
	$(GCOVR) $(EXCLUD) $(TESTS_DIR)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR) $(BRANCH)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ) *gc*

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME) $(TESTS)

re:	fclean all

.PHONY: all tests fclean re
