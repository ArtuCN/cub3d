==1085932== Memcheck, a memory error detector
==1085932== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1085932== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==1085932== Command: ./cub3d maps/map1.cub
==1085932== 
==1085932== Conditional jump or move depends on uninitialised value(s)
==1085932==    at 0x115AD2: is_same (raycasting3.c:49)
==1085932==    by 0x113FEA: init_ray (dda.c:87)
==1085932==    by 0x1144FF: start_dda (dda.c:149)
==1085932==    by 0x10FA2A: init_cube (init_win.c:79)
==1085932==    by 0x10F5FF: main (main.c:26)
==1085932== 
==1085932== Conditional jump or move depends on uninitialised value(s)
==1085932==    at 0x115AD2: is_same (raycasting3.c:49)
==1085932==    by 0x113FEA: init_ray (dda.c:87)
==1085932==    by 0x1144FF: start_dda (dda.c:149)
==1085932==    by 0x112B97: key_handler (some_mlx.c:59)
==1085932==    by 0x116455: mlx_loop (in /nfs/homes/aconti/cub3d_git/cub3d)
==1085932==    by 0x112CE9: calling_mlx (some_mlx.c:84)
==1085932==    by 0x10FA36: init_cube (init_win.c:80)
==1085932==    by 0x10F5FF: main (main.c:26)
==1085932== 
==1085932== Conditional jump or move depends on uninitialised value(s)
==1085932==    at 0x115B07: is_same (raycasting3.c:49)
==1085932==    by 0x113FEA: init_ray (dda.c:87)
==1085932==    by 0x1144FF: start_dda (dda.c:149)
==1085932==    by 0x112B97: key_handler (some_mlx.c:59)
==1085932==    by 0x116455: mlx_loop (in /nfs/homes/aconti/cub3d_git/cub3d)
==1085932==    by 0x112CE9: calling_mlx (some_mlx.c:84)
==1085932==    by 0x10FA36: init_cube (init_win.c:80)
==1085932==    by 0x10F5FF: main (main.c:26)
==1085932== 
==1085932== 
==1085932== Process terminating with default action of signal 2 (SIGINT)
==1085932==    at 0x11509B: get_color (draw.c:53)
==1085932==    by 0x115233: adding_pix_to_img (draw.c:95)
==1085932==    by 0x114541: start_dda (dda.c:153)
==1085932==    by 0x112B97: key_handler (some_mlx.c:59)
==1085932==    by 0x116455: mlx_loop (in /nfs/homes/aconti/cub3d_git/cub3d)
==1085932==    by 0x112CE9: calling_mlx (some_mlx.c:84)
==1085932==    by 0x10FA36: init_cube (init_win.c:80)
==1085932==    by 0x10F5FF: main (main.c:26)
==1085932== 
==1085932== HEAP SUMMARY:
==1085932==     in use at exit: 598,623 bytes in 2,157 blocks
==1085932==   total heap usage: 184,862 allocs, 182,705 frees, 21,125,650 bytes allocated
==1085932== 
==1085932== LEAK SUMMARY:
==1085932==    definitely lost: 0 bytes in 0 blocks
==1085932==    indirectly lost: 0 bytes in 0 blocks
==1085932==      possibly lost: 0 bytes in 0 blocks
==1085932==    still reachable: 598,623 bytes in 2,157 blocks
==1085932==         suppressed: 0 bytes in 0 blocks
==1085932== Rerun with --leak-check=full to see details of leaked memory
==1085932== 
==1085932== Use --track-origins=yes to see where uninitialised values come from
==1085932== For lists of detected and suppressed errors, rerun with: -s
==1085932== ERROR SUMMARY: 184366 errors from 3 contexts (suppressed: 1 from 1)
