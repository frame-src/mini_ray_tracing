NAME = image

SDIR = src
ODIR = obj

SRC = 	./src/color.c \
		./src/operation.c \
		./src/main.c \
		./src/ray.c \
		./src/view.c 

OBJ=	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

CC = cc
CFLAGS = -Wall -Wextra 

all:	$(NAME)

$(NAME):$(ODIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "done;"

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm $(NAME) image.ppm 

re: fclean all

ppm:
	./image > image.ppm

$(ODIR):
	mkdir -p $(ODIR)