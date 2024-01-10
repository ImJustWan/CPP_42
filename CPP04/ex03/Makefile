# Das Progamm
NAME 				:=	interfaces

# Compiler
CXX					:=	c++
CXXFLAGS			:=	-Wall -Werror -Wextra -std=c++98

DEPS				:=	${OBJS:.o=.d}

# Includes
INC					:=	AMateria.hpp \
						ICharacter.hpp \
						IMateriaSource.hpp \
						Character.hpp \
						Cure.hpp \
						Ice.hpp \
						MateriaSource.hpp \


# Sources	
SRCS				:=	main.cpp \
						AMateria.cpp \
						ICharacter.cpp \
						IMateriaSource.cpp \
						Character.cpp \
						Cure.cpp \
						Ice.cpp \
						MateriaSource.cpp

# Objects
OBJS_PATH			:=	./objs
OBJS_NAMES			:=	$(SRCS:.cpp=.o)
OBJS				:=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

all	:	$(NAME)

$(NAME)	: $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "👾 ex03 - WOOP WOOP 👾"

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