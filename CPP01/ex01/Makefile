# Das Progamm
NAME 				:=	zombiez

# Compiler
CXX					:=	c++
CXXFLAGS			:=	-Wall -Werror -Wextra -std=c++98

DEPS				:=	${OBJS:.o=.d}

# Includes
INC					:=	Zombie.hpp 

# Sources	
SRCS				:=	main.cpp \
						Zombie.cpp \
						zombieHorde.cpp
		
# Objects
OBJS_PATH			:=	./objs
OBJS_NAMES			:=	$(SRCS:.cpp=.o)
OBJS				:=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

all	:	$(NAME)

$(NAME)	: $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "👾 ex01 - WOOP WOOP 👾"

$(OBJS_PATH)/%.o: %.cpp
	@mkdir -p $(OBJS_PATH)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

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