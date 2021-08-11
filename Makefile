NAME =		cub3D

SRC =		src/main.c\
			src/list/ft_list.c\
			src/parse_file/parse_file.c\
			src/parse_file/parse_utils1.c\
			src/parse_file/parse_utils2.c\
			src/parse_file/parse_resolution.c\
			src/parse_file/parse_map.c\
			src/parse_file/parse_c.c\
			src/parse_file/parse_ea.c\
			src/parse_file/parse_f.c\
			src/parse_file/parse_no.c\
			src/parse_file/parse_s.c\
			src/parse_file/parse_so.c\
			src/parse_file/parse_we.c\
			src/parse_file/parse_pos.c\
			src/parse_file/validate_map.c\
			src/parse_file/check_player.c\
			src/parse_file/parse_sprites.c\
			src/img/body.c\
			src/img/init_img.c\
			src/img/print_sky_ground.c\
			src/img/get_textures.c\
			src/img/custom_funcs_img.c\
			src/img/rgb_to_hex.c\
			src/img/take_screenshot.c\
			src/dda/dda_utils1.c\
			src/dda/dda_utils2.c\
			src/dda/dda_utils3.c\
			src/dda/dda.c\
			src/dda/sort_sprites.c\
			src/key_hook/button_hook.c\
			src/key_hook/key_hook_a.c\
			src/key_hook/key_hook_arw_left.c\
			src/key_hook/key_hook_arw_right.c\
			src/key_hook/key_hook_d.c\
			src/key_hook/key_hook_esc.c\
			src/key_hook/key_hook_s.c\
			src/key_hook/key_hook_w.c\
			src/key_hook/key_hook.c\
			src/gnl/get_next_line_utils.c\
			src/gnl/get_next_line_utils2.c\
			src/gnl/get_next_line.c

OBJ =		$(SRC:.c=.o)

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

MLX =		src/minilibx_mms_20200219

LIBFT =		src/Libft

$(NAME): $(OBJ)
			make -C $(MLX)
			make -C $(LIBFT)
			mv $(MLX)/libmlx.dylib .
			$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
			rm -rf $(OBJ)
			make clean -C $(MLX)
			make clean -C $(LIBFT)

fclean: clean
			rm -rf $(NAME) ./libmlx.dylib
			rm -rf ./src/libft.a
			make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all
