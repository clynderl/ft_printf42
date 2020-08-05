NAME = libftprintf.a
PATHPRINTF = ./srcs/
PATHLIBFT = ./libft/
PATHOBJ = ./objs/
FILESPRINTF = ft_printf \
			ft_nbutils \
			ft_parseflag \
			ft_parsemodificator \
			ft_parseprecision \
			ft_parser \
			ft_parsewidth \
			ft_printascii \
			ft_printbin \
			ft_printfloat \
			ft_printpercent \
			ft_printptr \
			ft_printsgn \
			ft_printsgn_neg \
			ft_printuns \
			ft_process \
			ft_utils
FILESLIBFT = ft_atoi \
	  ft_bzero \
	  ft_isalnum \
	  ft_isalpha \
	  ft_isascii \
	  ft_isdigit \
	  ft_islower \
	  ft_isprint \
	  ft_isupper \
	  ft_itoa \
	  ft_lstadd \
	  ft_lstdel \
	  ft_lstdelone \
	  ft_lstiter \
	  ft_lstmap \
	  ft_lstnew \
	  ft_memalloc \
	  ft_memccpy \
	  ft_memchr \
	  ft_memcmp \
	  ft_memcpy \
	  ft_memdel \
	  ft_memmove \
	  ft_memset \
	  ft_putchar \
	  ft_putchar_fd \
	  ft_putendl \
	  ft_putendl_fd \
	  ft_putnbr \
	  ft_putnbr_fd \
	  ft_putstr \
	  ft_putstr_fd \
	  ft_strcat \
	  ft_strchr \
	  ft_strclr \
	  ft_strcmp \
	  ft_strcpy \
	  ft_strdel \
	  ft_strdel \
	  ft_strdup \
	  ft_strequ \
	  ft_striter \
	  ft_striteri \
	  ft_strjoin \
	  ft_strlcat \
	  ft_strlen \
	  ft_strmap \
	  ft_strmapi \
	  ft_strncat \
	  ft_strcmp \
	  ft_strncmp \
	  ft_strncpy \
	  ft_strnequ \
	  ft_strnew \
	  ft_strnstr \
	  ft_strrchr \
	  ft_strsplit \
	  ft_strstr \
	  ft_strsub \
	  ft_strtrim \
	  ft_tolower \
	  ft_toupper \
	  get_next_line
SRCLIBFT = $(addprefix $(PATHLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OBJLIBFT = $(addprefix $(PATHOBJ), $(addsuffix .o, $(FILESLIBFT:.c=.o)))
INCLIBFT = $(PATHLIBFT)/includes
SRCPRINTF = $(addprefix $(PATHPRINTF), $(addsuffix .c, $(FILESPRINTF)))
OBJPRINTF = $(addprefix $(PATHOBJ), $(addsuffix .o, $(FILESPRINTF:.c=.o)))
INCPRINTF = ./includes/
CC = clang $(CFLAGS)
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJLIBFT) $(OBJPRINTF)
	@printf "$(NAME):%73s\r" "[---                 ]"
	@sleep 0.1
	@ar rc $(NAME) $(OBJLIBFT) $(OBJPRINTF)
	@printf "$(NAME):%73s\r" "[--------            ]"
	@sleep 0.1
	@ranlib $(NAME)
	@printf "$(NAME):%73s\r" "[--------------      ]"
	@sleep 0.1
	@printf "$(NAME):%73s\r" "[--------------------]"
	@sleep 0.1
	@echo "Successfully created $(NAME)"

$(PATHOBJ)%.o: $(PATHLIBFT)%.c
	@mkdir $(PATHOBJ) 2> /dev/null || true
	@$(CC) -o $@ -c $< -I$(INCLIBFT)
	@printf "[Building] libft objects\r"

$(PATHOBJ)%.o: $(PATHPRINTF)%.c
	@mkdir $(PATHOBJ) 2> /dev/null || true
	@$(CC) -o $@ -c $< -I$(INCPRINTF)
	@printf "[Building] ft_printf objects\r"

clean:
	@/bin/rm -f $(OBJPRINTF) $(OBJLIBFT)
	@/bin/rmdir $(PATHOBJ) 2> /dev/null || true
	@printf "clean:%81s\n" "[--------------------]"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "fclean:%80s\n" "[--------------------]"

re: fclean all

norme:
	norminette
