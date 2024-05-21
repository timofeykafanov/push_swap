################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= push_swap
NAME_B		= checker_bonus

SRCS		= \
			push_swap.c \
			swap.c \
			push.c \
			rotate.c \
			utils.c

SRCS_B		= \
			checker.c \

OBJSDIR		= objs
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

OBJSDIR_B	= objs_bonus
OBJS_B		= $(addprefix $(OBJSDIR_B)/, $(SRCS_B:.c=.o))
DEPS_B		= $(addprefix $(OBJSDIR_B)/, $(SRCS_B:.c=.d))

################################################################################
######                               LIBFT                                ######
################################################################################

LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libft.a

################################################################################
######                               RULES                                ######
################################################################################

all		: $(NAME)

bonus	: $(NAME_B)

$(NAME)	: ${OBJS}
		$(MAKE) -C ${LIBDIR} all
		$(CC) ${CFLAGS} -o $@ $^ -L. ${LIBFT}

$(NAME_B)	: ${OBJS_B}
		$(MAKE) -C ${LIBDIR} all
		$(CC) ${CFLAGS} -o $@ $^ -L. ${LIBFT}

${OBJSDIR}/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

${OBJSDIR_B}/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

clean	:
		$(MAKE) -C ${LIBDIR} clean
		$(RM) $(OBJSDIR) $(OBJSDIR_B)

fclean	:
		$(MAKE) -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR) $(NAME) $(OBJSDIR_B) $(NAME_B)

re		:
		$(MAKE) -C ${LIBDIR} re
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

reb		:
		$(MAKE) -C ${LIBDIR} re
		$(RM) $(OBJSDIR_B) $(NAME_B)
		$(MAKE) bonus

run		:
		$(MAKE) re
		./$(NAME)

brun	:
		$(MAKE) reb
		./$(NAME_B)

test	:
		$(MAKE) re
		valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean bonus re test run bonus reb brun
