NAME		=mutantstack
CXX			=c++
CXXFLAGS	=-Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic
SRCS		=main.cpp
OBJS		=$(SRCS:.cpp=.o)
DEPS		=$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
