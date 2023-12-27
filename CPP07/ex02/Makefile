# Das Progamm
NAME 				:=	array

# Compiler
CXX					:=	c++
CXXFLAGS			:=	-Wall -Werror -Wextra -std=c++98


# Includes
INC					:=	Array.tpp

# Sources	
SRCS				:=	main.cpp \
		
# Objects
OBJS_PATH			:=	./objs
OBJS_NAMES			:=	$(SRCS:.cpp=.o)
OBJS				:=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))
DEPS				:=	${OBJS:.o=.d}

all	:	$(NAME)

$(NAME)	: $(OBJS) $(INC)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "👾 ex02 - WOOP WOOP 👾"

$(OBJS_PATH)/%.o: %.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean	:
	@echo "Cleaning the mess (￣ー￣)ゞ "
	@rm -rf $(OBJS_PATH)
	@rm -rf $(DEPS)

fclean	:	clean
	@echo "🚀 Byyye minishit 🚀"
	@rm -rf $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus