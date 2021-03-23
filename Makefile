NAME	=	doubly_linked_list.a

SRC_D  = src
INC_D = inc
OBJ_D = obj
TEST_D = tests

SRC =	$(SRC_D)/doubly_linked_list.c
		
INC =	$(INC_D)/doubly_linked_list.h

OBJ := $(SRC:$(SRC_D)/%.c=$(OBJ_D)/%.o)

CC = clang
CC_FLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

AR_COMMAND	=	ar rsv

all: $(NAME)

$(NAME): $(OBJ_D) $(OBJ) $(INC_D) $(INC)
			$(AR_COMMAND) $(NAME) $(OBJ)

$(OBJ_D):
		mkdir -p $(OBJ_D)

$(OBJ): $(OBJ_D)/%.o: $(SRC_D)/%.c
		@$(CC) $(CC_FLAGS) -I$(INC_D) -c $< -o $@

clean:
		rm -rf $(OBJ_D)
		rm -f test
		rm	-rf *.dSYM

fclean: clean
	rm -f $(NAME)

test: $(NAME)
	@$(CC) $(CC_FLAGS) -I$(INC_D) -o test $(TEST_D)/main.c $(NAME)
	@./test

re: fclean all
