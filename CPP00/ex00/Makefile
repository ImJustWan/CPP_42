# Das Progamm
NAME 				:=	megaphone

# Compiler
CXX					:=	c++
CXXFLAGS			:=	-Wall -Werror -Wextra -std=c++98

DEPS				:=	${OBJS:.o=.d}

# Sources	
SRCS				:=	megaphone.cpp

# Objects
OBJS_PATH			:=	./objs
OBJS_NAMES			:=	$(SRCS_NAMES:.cpp=.o)
OBJS				:=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

all	:	$(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(NAME)	: $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "👾 ex00 - WOOP WOOP 👾"

clean	:
	@echo "Cleaning the mess (￣ー￣)ゞ"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(DEPS)

fclean	:	clean
	@echo "🚀 Byyye minishit 🚀"
	@rm -rf $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus