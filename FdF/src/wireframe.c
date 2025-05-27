#include "fdf.h"
#include <stdlib.h>

int  main(int argc, char **argv)
{
    t_data  data;

    if (argc != 2)
        return (1);

    /* 1. Load your map */
    data.map = ft_fd_to_map(argv[1]);
    if (!data.map || !data.map->points)
        return (2);  // failed to parse map

    /* 2. Initialize MLX */
    data.mlx = mlx_init();
    if (!data.mlx)
        return (3);

    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF");
    if (!data.win)
        return (4);

    /* 3. Prepare your off-screen image buffer */
    ft_buff_image(&data);

    /* 4. Set the drawing function (your wireframe routine) */
    data.draw_func = draw_map;  // implement this to project + draw lines

    /* 5. Hook your per-frame update */
    mlx_loop_hook(data.mlx, ft_update_frame, &data);

    /* 6. Enter MLX’s event loop */
    mlx_loop(data.mlx);

    /* Cleanup would go here, but mlx_loop never returns */
    return (0);
}



