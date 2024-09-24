==1073506== Memcheck, a memory error detector
==1073506== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1073506== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==1073506== Command: ./cub3d maps/map1.cub
==1073506== 
==1073506== Conditional jump or move depends on uninitialised value(s)
==1073506==    at 0x115AC9: is_same (raycasting3.c:49)
==1073506==    by 0x113FF7: init_ray (dda.c:87)
==1073506==    by 0x1144F6: start_dda (dda.c:147)
==1073506==    by 0x10FA2A: init_cube (init_win.c:79)
==1073506==    by 0x10F5FF: main (main.c:26)
==1073506== 
==1073506== Conditional jump or move depends on uninitialised value(s)
==1073506==    at 0x11286C: key_handler (some_mlx.c:31)
==1073506==    by 0x116445: mlx_loop (in /nfs/homes/aconti/cub3d_git/cub3d)
==1073506==    by 0x112CE9: calling_mlx (some_mlx.c:84)
==1073506==    by 0x10FA36: init_cube (init_win.c:80)
==1073506==    by 0x10F5FF: main (main.c:26)
==1073506== 
==1073506== Conditional jump or move depends on uninitialised value(s)
==1073506==    at 0x115AC9: is_same (raycasting3.c:49)
==1073506==    by 0x113FF7: init_ray (dda.c:87)
==1073506==    by 0x1144F6: start_dda (dda.c:147)
==1073506==    by 0x112B97: key_handler (some_mlx.c:59)
==1073506==    by 0x116445: mlx_loop (in /nfs/homes/aconti/cub3d_git/cub3d)
==1073506==    by 0x112CE9: calling_mlx (some_mlx.c:84)
==1073506==    by 0x10FA36: init_cube (init_win.c:80)
==1073506==    by 0x10F5FF: main (main.c:26)
==1073506== 
==1073506== 
==1073506== Process terminating with default action of signal 2 (SIGINT)
==1073506==    at 0x1150D2: get_color (draw.c:54)
==1073506==    by 0x11522A: adding_pix_to_img (draw.c:95)
==1073506==    by 0x114538: start_dda (dda.c:151)
==1073506==    by 0x112B97: key_handler (some_mlx.c:59)
==1073506==    by 0x116445: mlx_loop (in /nfs/homes/aconti/cub3d_git/cub3d)
==1073506==    by 0x112CE9: calling_mlx (some_mlx.c:84)
==1073506==    by 0x10FA36: init_cube (init_win.c:80)
==1073506==    by 0x10F5FF: main (main.c:26)
==1073506== 
==1073506== HEAP SUMMARY:
==1073506==     in use at exit: 512,719 bytes in 1,744 blocks
==1073506==   total heap usage: 91,877 allocs, 90,133 frees, 10,756,550 bytes allocated
==1073506== 
==1073506== LEAK SUMMARY:
==1073506==    definitely lost: 0 bytes in 0 blocks
==1073506==    indirectly lost: 0 bytes in 0 blocks
==1073506==      possibly lost: 0 bytes in 0 blocks
==1073506==    still reachable: 512,719 bytes in 1,744 blocks
==1073506==         suppressed: 0 bytes in 0 blocks
==1073506== Rerun with --leak-check=full to see details of leaked memory
==1073506== 
==1073506== Use --track-origins=yes to see where uninitialised values come from
==1073506== For lists of detected and suppressed errors, rerun with: -s
==1073506== ERROR SUMMARY: 89941 errors from 3 contexts (suppressed: 1 from 1)
