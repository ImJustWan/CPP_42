# Das Progamm
NAME 				:=	bsp

# Compiler
CXX					:=	c++
CXXFLAGS			:=	-Wall -Werror -Wextra -std=c++98

DEPS				:=	${OBJS:.o=.d}

# Includes
INC					:=	Fixed.hpp \
						Point.hpp

# Sources	
SRCS				:=	main.cpp \
						Fixed.cpp \
						Point.cpp \
						bsp.cpp
# Objects
OBJS_PATH			:=	./objs
OBJS_NAMES			:=	$(SRCS:.cpp=.o)
OBJS				:=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

all	:	$(NAME)

$(NAME)	: $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "👾 ex00 - WOOP WOOP 👾"

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