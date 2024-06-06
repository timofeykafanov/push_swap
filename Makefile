################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g -I $(INCLUDES)
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= push_swap
NAME_B		= checker_bonus

SRCSDIR		= srcs
INCLUDES	= includes

SRCS		= \
			$(SRCSDIR)/push_swap.c \
			$(SRCSDIR)/swap.c \
			$(SRCSDIR)/push.c \
			$(SRCSDIR)/rotate.c \
			$(SRCSDIR)/utils.c \
			$(SRCSDIR)/define_direction.c \
			$(SRCSDIR)/init.c \
			$(SRCSDIR)/operations.c \
			$(SRCSDIR)/free.c \
			$(SRCSDIR)/optimize.c \
			$(SRCSDIR)/checks.c

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
		@make wait

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

# wait	:
# 	@echo -n "\r  5%  [\033[0;31m█\033[m.........................]"
# 	@sleep 0.2
# 	@echo -n "\r 10%  [\033[0;31m███\033[m.......................]"
# 	@sleep 0.2
# 	@echo -n "\r 15%  [\033[0;31m████\033[m......................]"
# 	@sleep 0.2
# 	@echo -n "\r 20%  [\033[0;31m██████\033[m....................]"
# 	@sleep 0.2
# 	@echo -n "\r 27%  [\033[0;31m████████\033[m..................]"
# 	@sleep 0.2
# 	@echo -n "\r 32%  [\033[0;31m██████████\033[m................]"
# 	@sleep 0.2
# 	@echo -n "\r 35%  [\033[0;31m███████████\033[m...............]"
# 	@sleep 0.2
# 	@echo -n "\r 45%  [\033[0;31m█████████████\033[m.............]"
# 	@sleep 0.2
# 	@echo -n "\r 50%  [\033[0;31m███████████████\033[m...........]"
# 	@sleep 0.2
# 	@echo -n "\r 65%  [\033[0;31m██████████████████\033[m........]"
# 	@sleep 0.2
# 	@echo -n "\r 80%  [\033[0;31m█████████████████████\033[m.....]"
# 	@sleep 0.2
# 	@echo -n "\r 90%  [\033[0;31m████████████████████████\033[m..]"
# 	@sleep 0.2
# 	@echo -n "\r 95%  [\033[0;31m█████████████████████████\033[m.]"
# 	@sleep 0.2
# 	@echo -n "\r 99%  [\033[0;31m██████████████████████████\033[m]"
# 	@sleep 1
# 	@echo -n "\r 100% [\033[0;32m██████████████████████████\033[m]\033[0;32m compilation finished ✓\n\033[0;m"

-include $(DEPS)

.PHONY	: all clean fclean re bonus reb
