# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:17:07 by rgriffit          #+#    #+#              #
#    Updated: 2024/05/21 18:01:39 by rgriffit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of archive file
NAME	= libftprintf.a

# Header, Source and Object folders/files
HEADER	= ./includes/ft_printf.h
SRC	= ./sources/ft_printf.c \

# Object files 
OBJ	= $(SRC:.c=.o)

# Compiler and its flags
COMPILE	= cc

CFLAGS	= -Wall -Wextra -Werror -I$(HEADER)

# 'make all' target builds libftprintft.a
all: $(NAME)

#  Will build the library libfttprintft.a by using *.c files making *.o files
# '@' suppress the echoing default command 'echo' will then print thee mesage you want for it to display moree neatly
# 'ar' creates an archive libftprintft.a from the object files
# -r replaces/adds files to archive 
# -c create new/replace existing archive
# -s writes an object-file index into the archives, improves speed
# -t displays a table of contents of the archive and lists the files in the archive
# -d deletes files from an archive and lists the files in the archive 
# -v 'Verbose mode' - displays detailed information about the operations performed by 'ar'. 
# -v ( --verbose) Can be used also on 'make' command
# Verbose mode is helpful for debugging build issues, understanding what the tool is doing behind the scenes, and getting insight into the build process. 
$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ) 
	@echo "$(NAME) created"
# Creates the object files by compiling *.c files 
# '%' is used as a wildcard that matches any string eg: '%.c' matches any string ending with .c
# Compile - translates the C source code into machine-readable object code (.o file) for each source file
# -c is a compiler flag that is used to compile the source file ($<) into an object file ($@) without linking 
# linking - linker is responsible for combining object files and libraries to produce the final executable program
# '$<' this is an automatic representation (variable) of source files
# -o $@  tells the compiler to output the resulting object file ($@). 
# '$@' this is used to represent the target of the rule i.e (object file)
# Grab all my .c ($<) files compile using error flags give me the output (-o) of the same file names as .o files ($@), (-c) compile the source file into an object file without combinng the  multiple object files that were just created
%.o: %.c
	@$(COMPILE) $(CFLAGS) -c $< -o $@
# 'clean' forcefully removes all object files and prints a message letting the user know object files have been deleted
clean:
	@rm -f $(OBJ)
	@echo "Object files deleted"
# 'fclean' forcefully removes all the executable or library specified in libftprintf.a additionally to cleaning up the object files
fclean:
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
# 're' rebuild will first cleans up all files, then rebuilds the project from scratch
re: fclean all
# Phony targets do not represent files, but rather actions. This will make them run even if there are files with the same names in the directory.
.PHONY: all clean fclean re
