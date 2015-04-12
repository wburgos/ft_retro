# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/11 17:07:19 by lrenoud-          #+#    #+#              #
#    Updated: 2015/04/12 22:16:53 by wburgos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_retro
rwildcard		=    $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)\
					$(filter $(subst *,%,$2),$d))

COMPILER		=    clang++
CFLAGS			=    -Wall -Wextra -Werror -I .. -c -O3
LFLAGS			=    -lncurses

OBJ_DIR			=    objs
SRCS			=    $(call rwildcard, ./, *.cpp)
OBJS			=    $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

OBJ_SUB_DIRS	=    $(dir $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "linking $@"
	@$(COMPILER) $^ $(LFLAGS) -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(foreach dir, $(OBJ_SUB_DIRS), mkdir -p $(dir);)

$(OBJ_DIR)/%.o: %.cpp
	@echo "compiling $(notdir $<)"
	@$(COMPILER) $(CFLAGS) $< -o $@

depend: .depend

.depend: $(SRCS)
	@rm -f ./.depend
	@$(foreach src, $^, $(COMPILER) $(CFLAGS) -MM -MT $(OBJ_DIR)/./$(src:.cpp=.o) $(src) >> ./.depend;)

-include .depend

clean:
	@echo "cleaning objects"
	@rm -rf $(OBJ_DIR)
	@rm -f ./.depend

fclean: clean
	@echo "cleaning $(NAME)"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
